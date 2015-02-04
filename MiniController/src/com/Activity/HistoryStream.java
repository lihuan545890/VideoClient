package com.Activity;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import org.json.JSONException;
import org.json.JSONObject;


import com.Activity.Preview4LowVersion;
import com.Utility.DataDefine;
import com.Utility.SysApplication;
import com.example.minicontroller.R;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.PixelFormat;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.os.MessageQueue.IdleHandler;
import android.util.Log;
import android.view.Display;
import android.view.GestureDetector;
import 	android.view.GestureDetector.SimpleOnGestureListener;
import android.view.DragEvent;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.SeekBar.OnSeekBarChangeListener;

/**
 * @author Lihuan
 *
 */
@SuppressLint("WrongCall")
public class HistoryStream extends Activity{
	private native boolean	Init();
	private native boolean  Cleanup();
	private native boolean  Logout(int UserId);
	private native int      Login(String ip,int port,String Username,String Passwd);
	private native int		Start(int UserId,int Channel,String BeginTime,String EndTime);
	private native boolean  Stop(int PlayHandle);
	private native int      Control(int PlayHandleId, int ControlCode, int Param);
	private native boolean  SetTime(int PlayHandleId, String Param);
	private native String   GetTime(int PlayHandleId);
	
	private int    nUserid  = 0;
	private int    realPlayId;
	private int    nChannel = 0;
	private String szIP; 
	private int    nPort;
	private String szUsername;
	private String szPsw;
	private String startTime;
	private String endTime;
	private int    year;
	private int    month;
	private int    day;
	private int    hour;
	private int    minute;
	private int    second;
	private boolean flag = true;
	private boolean state = true;
	private static  boolean scrollstate = true;
	private int     streamRequest = 1;
	private int     nCount = 0;
	private boolean requested = true;
	
	private Preview4LowVersion    playBack4L ;
	private	Preview		   playBack;
	private Button		   backBtn;
	private Button		   hisPlay;
	private Button		   hisStop;
	private SeekBar        mProgress;
	private TextView       absTime;
	Handler handler, ctrlHandler; 
	private View 		   controlView = null;
	private PopupWindow    controller = null;
	private GestureDetector mGestureDetector = null;
	private boolean isControllerShow = true;
	private boolean isFullScreen = false;
	private final static int TIME = 8000;
	private int nProgress = 0;
	
	private static int screenWidth   = 0;
	private static int screenHeight  = 0;
	private static int controlHeight = 0;  
	private static int currentVersion= 0;  
    
	private int  firstId;
    private long firstClick;  
    private long lastClick;  
	
	private ScheduledExecutorService executorService;
	private Handler playhandler;
	private int mPos = 0;
	
	private static int AndroidVersion = 30;
	private boolean  threadflag = false;
	private boolean  isTouched  = false;
	   
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.playback);
//		SysApplication.getInstance().addActivity(this); 
		initial();
	}
	
	@Override
	protected void onPause() {
		// TODO Auto-generated method stub
		super.onPause();
		System.out.println("==================>onPause");
//		controller.dismiss();
		
	}
	protected void onDestroy() {  
	    super.onDestroy();  
	    
	    if (nUserid > 0)
	    {
			Logout(nUserid);
			Cleanup();
		}
	}  
	
	protected void onResume(){
		super.onResume();
	}
	
	@SuppressWarnings("deprecation")
	private void initial()
	{

		currentVersion=android.os.Build.VERSION.SDK_INT;
		
    	if (currentVersion<AndroidVersion) {
    		playBack4L = (Preview4LowVersion)findViewById(R.id.playBack);
    		playBack4L.setZOrderOnTop(false);
    		playBack4L.getHolder().setFormat(PixelFormat.TRANSPARENT);
    		playBack4L.flag = false;
		}else {
			playBack = new Preview(this);
			playBack.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.FILL_PARENT, LayoutParams.FILL_PARENT));
			playBack.setZOrderOnTop(false);
			playBack.getHolder().setFormat(PixelFormat.TRANSPARENT);
		}
	    
    	//后台线程
		Looper.myQueue().addIdleHandler(new IdleHandler() {
			
			@Override
			public boolean queueIdle() {
				// TODO Auto-generated method stub
		    	if (currentVersion<AndroidVersion) {
					if (controller != null && playBack4L.isShown()) {
						controller.showAtLocation(playBack4L, Gravity.BOTTOM, 0, 0);
						controller.update(0, 0, screenWidth, controlHeight);
						hideControllerDelay();
					}
				}else {
					if (controller != null && playBack.isShown()) {
						controller.showAtLocation(playBack, Gravity.BOTTOM, 0, 0);
						controller.update(0, 0, screenWidth, controlHeight);
					}
				}
				return false;
			}
		});
        controlView = getLayoutInflater().inflate(R.layout.controller, null);
        controller = new PopupWindow(controlView);
		
		executorService = Executors.newScheduledThreadPool(1);
		Display localDisplay = getWindowManager().getDefaultDisplay();
		screenWidth  = localDisplay.getWidth();
	    screenHeight = localDisplay.getHeight();
		
		Bundle bundle  = this.getIntent().getExtras();

		nChannel   = bundle.getInt("nChannel");
		szIP	   = bundle.getString("HostIP");
		nPort	   = bundle.getInt("CtrlPort");
		szUsername = bundle.getString("UserName");
		szPsw	   = bundle.getString("Password");
		startTime  = bundle.getString("StartTime");
		endTime    = bundle.getString("EndTime");
		
		year   = Integer.parseInt(startTime.substring(0,4));
		month  = Integer.parseInt(startTime.substring(4,6));
		day    = Integer.parseInt(startTime.substring(6,8));
		
//		Log.i("startTime", startTime+"");
//		Log.i("year", year+"");
//		Log.i("month", month+"");
//		Log.i("day", day+"");
		
		hisPlay		  = (Button)controlView.findViewById(R.id.HisPlay);
		hisStop		  = (Button)controlView.findViewById(R.id.HisStop);
		mProgress     = (SeekBar)controlView.findViewById(R.id.progress_bar);
		absTime		  = (TextView)controlView.findViewById(R.id.abstime);
		StringBuilder sb = new StringBuilder(startTime.substring(0, 8));
		sb.insert(4, "-").insert(7, "-");
		absTime.setText(sb.toString()+" 00:00:00");
		
        playhandler = new Handler(new Handler.Callback() {
            @Override 
            public boolean handleMessage(Message msg) {
            	
				if (currentVersion >= AndroidVersion)
				{
					playBack.InitDecoder(playBack.getHolder().getSurface());
				}
				
				Init();
				nUserid = Login(szIP, nPort, szUsername, szPsw);
				realPlayId=Start(nUserid, nChannel, startTime, endTime);

                return true;
            }
        });  
        
	    executorService.schedule(new Runnable() {
	            @Override
	            public void run() {
	            	playhandler.sendEmptyMessage(0);
	            }
	    }, 10000, TimeUnit.MICROSECONDS);
		
		final GetTimeThread gettimeThread = new GetTimeThread(); //获取播放时间线程
		gettimeThread.start();
	    
		hisPlay.setOnTouchListener(new OnTouchListener() {
			
			@Override
			public boolean onTouch(View arg0, MotionEvent arg1) {
				// TODO Auto-generated method stub
				switch (arg1.getAction()) 
				{ 
					case MotionEvent.ACTION_DOWN:
						if (streamRequest == 0)
						{
							threadflag = false;
							
							streamRequest++;   
					    	if (currentVersion<AndroidVersion) {
								playBack4L.setZOrderOnTop(false);
								playBack4L.getHolder().setFormat(PixelFormat.TRANSPARENT);
								playBack4L.playState = true;
								
							}else {
								playBack.setZOrderOnTop(false);
								playBack.getHolder().setFormat(PixelFormat.TRANSPARENT);
								playBack.InitDecoder(playBack.getHolder().getSurface());
								playBack.playState = true;
							}

							Init();
							nUserid = Login(szIP, nPort, szUsername, szPsw);
							realPlayId=Start(nUserid, nChannel, startTime, endTime);
							scrollstate = true;
						}
						break;
					case MotionEvent.ACTION_UP:  
						if (state)
						{
							Control(realPlayId, DataDefine.ANTS_NET_DVR_PLAYPAUSE, 0);
							
							scrollstate = false;
							hisPlay.setBackgroundResource(R.drawable.selector_play);
							state = false;
						}
						else
						{
							Control(realPlayId, DataDefine.ANTS_NET_DVR_PLAYSTART, 0);
							hisPlay.setBackgroundResource(R.drawable.selector_pause);	
							scrollstate = true;
							state = true;							
						}
						
						break;
					default:
						break;
				}
				
				return false;
			}  
		}); 
		
		hisStop.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				System.out.println("realPlayId="+realPlayId);
				if (realPlayId != 0) {
					Stop(realPlayId);
					playBack4L.onClear();
					streamRequest = 0;
			    	if (currentVersion<AndroidVersion) {
						playBack4L.setZOrderOnTop(false);
						playBack4L.getHolder().setFormat(PixelFormat.TRANSLUCENT);		  
						playBack4L.playState=false;
						realPlayId = 0;
					}else {
						playBack.setZOrderOnTop(false);
						playBack.getHolder().setFormat(PixelFormat.TRANSLUCENT);
						playBack.playState=false;
					}

					hisPlay.setBackgroundResource(R.drawable.selector_play);
					hour   = 0;
					minute = 0;
					second = 0;
					GetStartTime();  
					state = false;	
//					scrollstate = false;	
					threadflag = true;
				}

			}
		});   
		
		mProgress.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
			
			@Override
			public void onStopTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				
				threadflag = false;
				streamRequest++;
				hisPlay.setBackgroundResource(R.drawable.selector_pause);	
				state = true;	
				hour    = seekBar.getProgress() / 3600;
				minute  = seekBar.getProgress() % 3600 / 60;
				second  = seekBar.getProgress() % 60;		
				
				String setTimeString = 
	    		"{" + "\n" + 
						"\"SetTime\":{" + "\n" +
						     "\"Year\":"  + year    + "," + "\n" +
						     "\"Month\":" + month   + "," + "\n" +
						     "\"Day\":"   + day     + "," + "\n" +
						     "\"Hour\":"  + hour    + "," + "\n" +
						     "\"Minute\":"+ minute     + "," + "\n" +
						     "\"Second\":"+ second     + "}"  + "\n" +
				"}";	
				
				GetStartTime();
				
				realPlayId=Start(nUserid, nChannel, startTime, endTime);
				
				nCount = 0;
				
				if(SetTime(realPlayId, setTimeString))
				{
					scrollstate = true;
				}
				else   
				{ 
					Log.d("Settime", "Failure!!!");
				}	
				  
				hideControllerDelay();
			}  
			
			@Override  
			public void onStartTrackingTouch(SeekBar seekBar) {
				// TODO Auto-generated method stub
				scrollstate = false;
			    Stop(realPlayId);
			}    
			
			@Override
			public void onProgressChanged(SeekBar seekBar, int progress,
					boolean fromUser) {
				// TODO Auto-generated method stub
				nProgress = progress;
				System.out.println("scrollstate="+scrollstate);
				absTime.setText(progress2Date(progress));
				if (!scrollstate) {
					cancelDelayHide();   //滑块滑动过程取消发送延时隐藏seekBar消息
				}
				  
			}
		});
		
		getScreenSize();
		
		setVideoScale(SCREEN_DEFAULT);
		
		mGestureDetector = new GestureDetector(new SimpleOnGestureListener(){
			@Override
			public boolean onDoubleTap(MotionEvent e) {
				// TODO Auto-generated method stub
				
				if(isControllerShow){ 
					showController();
				}
				
				return true;
			}
	
			@Override
			public boolean onSingleTapConfirmed(MotionEvent e) {
				// TODO Auto-generated method stub
				if(!isControllerShow){
					showController();
					hideControllerDelay();
				}else {
					cancelDelayHide();
					hideController();
				}
				
				return true;
			}
	
			@Override
			public void onLongPress(MotionEvent e) {
				// TODO Auto-generated method stub
			}		
				
		});
		
	}
	
    private final static int SCREEN_FULL = 0;
    private final static int SCREEN_DEFAULT = 1;
    
    private void setVideoScale(int flag){
    	
    	switch (flag) {
		case SCREEN_FULL:
	    	if (currentVersion<AndroidVersion) {
	    		playBack4L.setVideoScale(screenWidth, screenHeight);
			}else {
				playBack.setVideoScale(screenWidth, screenHeight);
			}
			break;
		case SCREEN_DEFAULT:
			int mWidth = screenWidth;
			int mHeight = screenHeight;
	    	if (currentVersion<AndroidVersion) {
	    		playBack4L.setVideoScale(mWidth, mHeight);
			}else {
				playBack.setVideoScale(mWidth, mHeight);
			}
			
			break;
		default:
			break;
		}
    }
	
	private void showController(){
		controller.update(0,0,screenWidth, controlHeight);
		setVideoScale(SCREEN_DEFAULT);
		isControllerShow = true;
	}
	
	private void hideControllerDelay(){
		myHandler.sendEmptyMessageDelayed(HIDE_CONTROLER, TIME);
	}
	
	private void cancelDelayHide(){
		myHandler.removeMessages(HIDE_CONTROLER);
	}
	
	private void getScreenSize()
	{
		Display display = getWindowManager().getDefaultDisplay();
        screenHeight = display.getHeight();
        screenWidth = display.getWidth();
        controlHeight = screenHeight* 3/10;
	}
	
	private void hideController(){
		if(controller.isShowing()){
			controller.update(0,0,0, 0);
			setVideoScale(SCREEN_FULL);
			isControllerShow = false;
		}

	}
	
	@Override
	public boolean onTouchEvent(MotionEvent event) {
		// TODO Auto-generated method stub
		
		boolean result = mGestureDetector.onTouchEvent(event);
		
		if(!result){
			if(event.getAction()==MotionEvent.ACTION_UP){
				System.out.println("MotionEvent.ACTION_UP");
			}else {
				System.out.println("mGestureDetector");
			}
			result = super.onTouchEvent(event);
		}
		
		return result;
	}
	
	private final static int PROGRESS_CHANGED = 0;
    private final static int HIDE_CONTROLER = 1;
    
    Handler myHandler = new Handler(){
    
		@Override
		public void handleMessage(Message msg) {
			// TODO Auto-generated method stub
			
			switch(msg.what){
				case PROGRESS_CHANGED:
					
					break;
					
				case HIDE_CONTROLER:
					hideController();
					break;
			}
			
			super.handleMessage(msg);
		}	
    };	
	
	int currentTime;
	int lastTime;
	int count = 0;
	StringBuffer date = new StringBuffer();
	StringBuffer time = new StringBuffer();
	private void StreamCallBack(int Handle,byte[] Buffer,int Size,int FrameType,int FrameNo,  int FrameTime,int FrameTickCount,int RelativeTime, int Width, int Height)
	{	//此处回调机制跟预览一样
		currentTime = RelativeTime;
		String timeStamp = FrameTime - (3600 * 8) + "";
		String curTime = TimeStamp2Date(timeStamp);
		
		Message msg = new Message();  
		msg.obj = curTime; 
//		System.out.println(curTime);
		curTime = curTime.replace("-", "").replace(":", "").replace(" ", "");
		
    	if (currentVersion<AndroidVersion) {
    		if (FrameType != 8)
    		{
    			if (!playBack4L.initState) {
    				playBack4L.decodeId = playBack4L.InitDecoder(Width, Height);
    				playBack4L.initState = true;
    			}
    			playBack4L.Decode_V1(playBack4L.decodeId, Buffer, Size, FrameType);		
//    			System.out.println("Width="+Width+" Height="+Height);
    		}
		}else {
			playBack.Decode(Buffer, Size, FrameType);
		}
		
	}	
	
	//时间戳转日期
	private String TimeStamp2Date(String timestampString){  
		  Long timestamp = Long.parseLong(timestampString)*1000;  
		  String date = new java.text.SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new java.util.Date(timestamp));  
		  return date;  
		} 
	
	//进度值转日期
	private String progress2Date(int progress)
	{
		String Hour = null,Min = null,Sec = null;
		String date = null;
		
		int   hour = progress / 3600;
		int   min  = progress % 3600 / 60;
		int   sec  = progress % 60;		 
		
		Hour = hour +"";
		Min  = min  +"";
		Sec  = sec  +"";
		
		if(hour >= 0 && hour < 10)
		{
			Hour = "0" + Hour;
		}
		
		if(min >= 0 && min < 10)
		{
			Min = "0" + Min;
		}
		
		if(sec >= 0 &&sec < 10)
		{
			Sec = "0" + Sec;
		}			
	
		StringBuilder sb=new StringBuilder(startTime.substring(0, 8));
//		System.out.println(startTime);
//		System.out.println(sb.toString());
		sb.insert(4, "-").insert(7, "-");
		
		return sb.toString() + " " +Hour+":" + Min+":" +Sec;
	}
	
	//日期转时间戳
    public long Date2Timestamp(String dateString){
        Date date1 = null;
		try {
			date1 = new SimpleDateFormat("yyyyMMddHHmmss").parse(dateString);
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
        long temp = date1.getTime();//JAVA的时间戳长度是13位
        return temp;
    }
	
	public boolean onKeyDown(int keyCode, KeyEvent event)
	{
        if (keyCode == KeyEvent.KEYCODE_BACK
                 && event.getRepeatCount() == 0) {
        	
//    		if (realPlayId != 0) {
//				Stop(realPlayId);
//				threadflag = true;
//    		}  
//    		if (controller.isShowing()) {
//    			controller.dismiss();
//			}
    		
//        	finish();
        	System.exit(0);
            return true;
         }
         return super.onKeyDown(keyCode, event);
     }
	
	public class GetTimeThread extends Thread{
		public boolean flag = true;
		
		public void run(){
			super.run();
			
			while(true){
				if (!threadflag) {
					
					if (scrollstate) {
//						System.out.println("GetTimeThread...............");
						int hour   = 0;
						int minute = 0;
						int second = 0;
						final int progress;
						String jsonCurTime = null;
						try {
							if (GetTime(realPlayId) != null) {
							    jsonCurTime = new JSONObject(GetTime(realPlayId)).getString("CurTime");
							    hour   = new JSONObject(jsonCurTime).getInt("Hour");
							    minute = new JSONObject(jsonCurTime).getInt("Minute");
							    second = new JSONObject(jsonCurTime).getInt("Second");							
							}
							
						} catch (JSONException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}
						        
						progress = hour*3600 + minute*60 + second;
						mProgress.setProgress(progress);						
					}
					
				}
			}
		}
	}
	
	private void GetStartTime()
	{
		String Hour = hour +"";
		String Min  = minute  +"";
		String Sec  = second  +"";
		
		String startyear  = year +"";
		String Startmonth = month + "";
		String Startday   = day  + "";
		
		if(hour >= 0 && hour < 10)
		{
			Hour = "0" + Hour;
		}
		
		if(minute >= 0 && minute < 10)
		{
			Min = "0" + Min;
		}
		
		if(second >= 0 &&second < 10)
		{
			Sec = "0" + Sec;
		}			

		if(month > 0 && month < 10)
		{
			Startmonth = "0" + Startmonth;
		}
		else
		{
			Startmonth = "" + Startmonth;
		}
		
		if(day > 0 && day < 10)
		{
			Startday = "0" + Startday;
		}
		else
		{
			Startday = "" + Startday;
		}
		
		startTime = startyear + Startmonth + Startday + Hour + Min + Sec;

		Log.i("startTime", startTime);
	}
	
 
	
}
