package com.Activity;

import com.BLL.Child;
import com.BLL.DeleteView;
import com.BLL.DrawImageView;
import com.BLL.EListAdapter;
import com.BLL.Group;
import com.BLL.PChild;
import com.BLL.PGroup;
import com.BLL.PListAdapter;
import com.Activity.Preview4LowVersion;
import com.Utility.DataDefine;
import com.Utility.SysApplication;
import com.example.minicontroller.R;

import android.util.Log;
import android.view.ViewGroup.LayoutParams;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.res.Configuration;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorFilter;
import android.graphics.PixelFormat;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.media.AudioManager;
import android.media.MediaCodec;
import android.media.MediaFormat;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.os.MessageQueue.IdleHandler;
import android.view.Display;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceHolder.Callback;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.view.ViewGroup;
import android.view.ViewGroup.MarginLayoutParams;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.ExpandableListView.OnChildClickListener;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.GridView;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.PopupMenu;
import android.widget.PopupMenu.OnMenuItemClickListener;
import android.widget.PopupWindow;
import android.widget.RelativeLayout;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.Executors;

import org.json.JSONException;
import org.json.JSONObject;

public class PTZControl extends Activity {

	private String TAG = "PTZControl";          
	  
	private native boolean  Init();
	private native boolean  Cleanup();
	private native int   	Login(String ip,int port,String Username,String Passwd);
	private native boolean  Logout(int uid);
	private native boolean	PTZControl(int uid, int Channel, int Command, int Stop, int Speed);
	private native boolean  PTZPreset(int uid, int Channel, int Command, int Index);
	private native boolean  PTZCruise(int UserId, int Channel, int Command, int Route, int Point, int Input);
	private native boolean  PTZTrack(int uid, int Channel, int Command);
	private native int  	GetLastError();	
	private native boolean  SetVideoEffect(int UserId, int Channel, int Bright,int Contrast,int Saturation,int Hue);
	private native String   GetVideoEffect(int UserId, int Channel); 
	
	private String szIP=null;    
	private int nPort;   
	private String szUsername;
	private String szPsw;   
	private String szDevType;
	private int nUserid  = 0;
	private int ChanNum  = 0;  
	private int PressNum = 0;	
	
	private AlertDialog.Builder builder;
	private SQLiteDatabase devDatabase;
	private Cursor cursor;
	private String id;
	private int chanOpen = 0;
	private Button funcBtn1[] = new Button[7];
	private Button funcBtn2[] = new Button[7];
	private int windowId = 0;
	private int nChannel = 1;
	private int ChannelId = 1;
   
	private DrawImageView  mDrawIV[] = new DrawImageView[4];
	private int 		   mDrawIVId[] = {R.id.mDrawIV0,R.id.mDrawIV1,R.id.mDrawIV2,R.id.mDrawIV3};
	private View		   mView[] = new View[4];
	private int 		   mViewId[] = {R.id.mView0,R.id.mView1,R.id.mView2,R.id.mView3};
	private Preview4LowVersion surfaceView4L[] = new Preview4LowVersion[4];  //低于android4.1.2的版本采用软解
	private Preview        surfaceView[] = new Preview[4];//高于android4.1.2的采用硬解，鉴于硬解不稳定，此版本未采用硬解方案，
	private int			   surfaceViewId[] = {R.id.surfaceView0,R.id.surfaceView1,R.id.surfaceView2,R.id.surfaceView3};
	private SurfaceHolder  mSurfaceHolder[] = new SurfaceHolder[4]; 
	private FrameLayout    frameLayout[] = new FrameLayout[4];
	private int 		   frameLayoutId[] = {R.id.famelayout0,R.id.famelayout1,R.id.famelayout2,R.id.famelayout3};
	private LayoutParams   lp[] = new LayoutParams[4];
	private LinearLayout   LinearFourview,LinearLayout1,LinearLayout2,LinearDeleteLayout,LinearPannelLayout;
	private RelativeLayout titleLayout;
	private TextView	   titleTextView;
	private DeleteView	   delChlView;
	private TextView	   titleView;
	private TextView	   devtypeTv, szipTv, channelTv;
	private Button		   menuBtn;
	private TextView	   stateInfo;
	private int			   channelNo;
	private String		   columns[] = {DataDefine.KEY_USERNAME, DataDefine.KEY_PASSWORD,DataDefine.KEY_LOCALIP,DataDefine.KEY_PORT,DataDefine.KEY_CHANNELNO, DataDefine.KEY_RTSPPORT };
	private int			   imageResource1[] = {R.drawable.selector_ptz_up,R.drawable.selector_ptz_left,R.drawable.selector_zoom_in,R.drawable.selector_focus_near,
							R.drawable.selector_iris_in,R.drawable.selector_bri_increase,R.drawable.selector_con_increase};
	private int			   imageResource2[] = {R.drawable.selector_ptz_down,R.drawable.selector_ptz_right,R.drawable.selector_zoom_out,R.drawable.selector_focus_far,
							R.drawable.selector_iris_out,R.drawable.selector_bri_reduce,R.drawable.selector_con_reduce};
	
	private int  screenWidth;
	private int  screenHeight;
	
	private int  firstId;
    private long firstClick;  
    private long lastClick;  
    // 计算点击的次数  
    private int count;
    private boolean flag = true; 
    private boolean downstate = false; 
    
    private String videoEffect;
    private String jsonstatus;
    private String resultContent;
    private int    bright;
    private int    contrast;
    private int    saturation;  
    private int    hue;
    
    private String  videoParam;
    private String  jsonstatus1;
    private String  resultContent1;
    private String  resolution;
    private String  framerate;
    private String  bitrate;
    private String  bitratetype;
    private int     selfdefinebitrate;
//    private static int     AndroidVersion = 17;
    private static int     AndroidVersion = 60;
    
	private View 		   menuControlView = null;
	private PopupWindow    menuController = null, ptzWindow, lensWindow, colorWindow, videoparamWindow;
	private GridView menuGrid, ptzGrid, lensGrid, colorGrid;
	private boolean  isControllerShow = true;
    
    private int currentVersion;

	private ExpandableListView expandList;
	private View viewList;
    private Dialog  deviceDialog;
    private ArrayList<Group> groups; 
    private EListAdapter adapter; 
    
	private ExpandableListView pexpandList;
	private Button confirmBtn;
	private Button cancelBtn;
	private EditText selfdefineET;
	private RelativeLayout selfdefineLayout;
	private View paramView;
    private Dialog  paramDialog;
    private ArrayList<PGroup> pgroups; 
    private PListAdapter padapter;     
    private PGroup resolutionGroup; 
    private PGroup framerateGroup;
    private PGroup bitrateGroup;
    private PGroup bitratetypeGroup;
    
	private String[] menu_name_array = { "远程预览", "远程回放", "远程控制", "设备管理","图像管理"};
	int[] menu_image_array = {R.drawable.menu_preview,
			R.drawable.menu_playback, R.drawable.menu_control,
			R.drawable.menu_devicemanage,R.drawable.menu_test};
	
	int[] ptz_image_array = {R.drawable.ptz_up,R.drawable.ptz_down,R.drawable.ptz_left,R.drawable.ptz_right};
	int[] ptz_image_array_pressed = {R.drawable.ptz_up_pressed,R.drawable.ptz_down_pressed,R.drawable.ptz_left_pressed,R.drawable.ptz_right_pressed};
	
	int[] ptz_commands = {DataDefine.PTZ_UP,DataDefine.PTZ_DOWN,DataDefine.PTZ_LEFT,DataDefine.PTZ_RIGHT};
	
	int[] lens_image_array = {R.drawable.zoom_in, R.drawable.zoom_out, R.drawable.focus_near, R.drawable.focus_far, R.drawable.iris_in, R.drawable.iris_out};
	int[] lens_image_array_pressed = {R.drawable.zoom_in_pressed, R.drawable.zoom_out_pressed, R.drawable.focus_near_pressed, R.drawable.focus_far_pressed, R.drawable.iris_in_pressed, R.drawable.iris_out_pressed};
    
    int[] lens_commands = {DataDefine.ZOOM_IN,DataDefine.ZOOM_OUT,DataDefine.FOCUS_NEAR,DataDefine.FOCUS_FAR,DataDefine.IRIS_OPEN,DataDefine.IRIS_CLOSE};
    int[] color_image_array = {R.drawable.selector_bri_increase,R.drawable.selector_bri_reduce,R.drawable.selector_con_increase,R.drawable.selector_con_reduce};
    
	public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);	
		currentVersion = android.os.Build.VERSION.SDK_INT;  
        setContentView(R.layout.ptzcontrol);   
        
        SysApplication.getInstance().addActivity(this); //退出程序
    	devDatabase = openOrCreateDatabase(DataDefine.DBNAME, SQLiteDatabase.CREATE_IF_NECESSARY, null); //创建数据库
		
	    initView();
	    
	    for(int i=0; i<4; i++)
	    {
	    	if (currentVersion<AndroidVersion) {
	    		surfaceView4L[i].setOnTouchListener(new PreviewTouchListener());
			}else {
				surfaceView[i].setOnTouchListener(new PreviewTouchListener());
			}
	    
	    	//添加通道视图监听器
			mView[i].setOnClickListener(new OnClickListener() {
				
				@Override  
				public void onClick(View arg0) {
					// TODO Auto-generated method stub
					CreateDeviceDialog();
					deviceDialog.show();
				}
			});	    		
	    }
	}
	
	
	//监听手机屏幕横竖屏切换
	@Override
	public void onConfigurationChanged(Configuration newConfig) {
		// TODO Auto-generated method stub
		super.onConfigurationChanged(newConfig);

		//横屏
        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE){
        	
    		Display localDisplay = getWindowManager().getDefaultDisplay();
    		screenWidth  = localDisplay.getWidth();
    		screenHeight = localDisplay.getHeight();
    		
        	LinearFourview.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenHeight));
        	titleLayout.setVisibility(View.GONE);
        	LinearDeleteLayout.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
        	LinearLayout1.setLayoutParams( new LinearLayout.LayoutParams(screenWidth, screenHeight/2));
        	LinearLayout2.setLayoutParams( new LinearLayout.LayoutParams(screenWidth, screenHeight/2));
	    	for (int i = 0; i < 4; i++) {
	    		frameLayout[i].setLayoutParams( new LinearLayout.LayoutParams(screenWidth/2, screenHeight/2));
	    		mDrawIV[i].setCoordinate(0, 0, screenWidth/2, screenHeight/2);
			}
    		
    	    mDrawIV[0].setColor(Color.RED);
    	    mDrawIV[0].onDraw(new Canvas());	
    	    
    	    mDrawIV[1].setColor(Color.GRAY);
    	    mDrawIV[1].onDraw(new Canvas());
    	    
    	    mDrawIV[2].setColor(Color.GRAY);
    	    mDrawIV[2].onDraw(new Canvas());
    	    
    	    mDrawIV[3].setColor(Color.GRAY);
    	    mDrawIV[3].onDraw(new Canvas());
    	    
    	    if (ptzWindow!=null&&lensWindow!=null&&colorWindow!=null) {
        	    if (ptzWindow.isShowing()&&lensWindow.isShowing()&&colorWindow.isShowing()) {
    				ptzWindow.update(0, 0, 0, 0);
    				lensWindow.update(0, 0, 0, 0);
    				colorWindow.update(0, 0, 0, 0);
    			}				
			}

    	    
        }else {//竖屏
    		Display localDisplay = getWindowManager().getDefaultDisplay();
    		screenWidth  = localDisplay.getWidth();
    		screenHeight = localDisplay.getHeight();
			float rate = (float) screenWidth/320;
			if (screenWidth > 1000) {
				titleTextView.setTextSize(6*rate);
			}else {  
				titleTextView.setTextSize(10*rate);
			}
    		
    		LinearFourview.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth));
        	titleLayout.setVisibility(View.VISIBLE);
        	LinearDeleteLayout.setVisibility(View.VISIBLE);
			LinearDeleteLayout.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth/6));
			LinearFourview.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth));
        	LinearLayout1.setLayoutParams( new LinearLayout.LayoutParams(screenWidth, screenWidth/2));
        	LinearLayout2.setLayoutParams( new LinearLayout.LayoutParams(screenWidth, screenWidth/2));
        	LinearPannelLayout.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth/8));
        	
	    	for (int i = 0; i < 4; i++) {
	    		frameLayout[i].setLayoutParams( new LinearLayout.LayoutParams(screenWidth/2, screenWidth/2));
	    		mDrawIV[i].setCoordinate(0, 0, screenWidth/2, screenWidth/2);
	    		
	    		if (!surfaceView4L[i].playState) {
			    	FrameLayout.LayoutParams lytp = new FrameLayout.LayoutParams(screenWidth/6,screenWidth/6);
			    	lytp .gravity = Gravity.CENTER;
			    	mView[i].setLayoutParams(lytp);					
				}

			}
    		
    	    mDrawIV[0].setColor(Color.RED);
    	    mDrawIV[0].onDraw(new Canvas());	
    	    
    	    mDrawIV[1].setColor(Color.GRAY);
    	    mDrawIV[1].onDraw(new Canvas());
    	    
    	    mDrawIV[2].setColor(Color.GRAY);
    	    mDrawIV[2].onDraw(new Canvas());
    	    
    	    mDrawIV[3].setColor(Color.GRAY);
    	    mDrawIV[3].onDraw(new Canvas());
        	
		}
	}
	
	protected void onResume(){
		super.onResume();
		System.out.println("============>onResume");
		for (int i = 0; i < 4; i++) {
		}
	}   
	 
	@Override
	protected void onStart() {
		// TODO Auto-generated method stub 
		super.onStart();
		System.out.println("============>onStart"); 
	}  
	@Override
	protected void onStop() {
		// TODO Auto-generated method stub
		super.onStop();
		System.out.println("============>onStop");
	}
	
	@Override
	protected void onRestart() {
		// TODO Auto-generated method stub
		super.onRestart();
		System.out.println("============>onRestart");
	}
	protected void onPause(){
		super.onPause();
		System.out.println("============>onPause");

	}
	
	protected void onDestroy() {  
	    super.onDestroy();  
	    System.out.println("============>onDestroy");
	    if (devDatabase != null)
	    {  
	    	devDatabase.close();  
	    }  
	    
	    for(int i=0; i<4; i++)
	    {
	    	if (currentVersion<AndroidVersion) {
		    	if (surfaceView4L[i].playState == true) 
		    	{
		    		surfaceView4L[i].Stop(surfaceView4L[i].realPlayId);
					surfaceView4L[i].playState  = false;
					if (surfaceView4L[i].nUserId > 0) {
						surfaceView4L[i].Logout(surfaceView4L[i].nUserId);
						surfaceView4L[i].Cleanup();
					}
				}
		    	
			}else {
		    	if (surfaceView[i].playState == true) 
		    	{
		    		surfaceView[i].Stop(surfaceView4L[i].realPlayId);
					surfaceView[i].playState  = false;
				}
			}

	    }
	    
	    if (nUserid > 0)
	    {
			Logout(nUserid);
			Cleanup();
		}  
	} 
	
	static{
		System.loadLibrary("i8_netsdk"); //加载网络库
		System.loadLibrary("i8_net_sdk");//该库对网络库重新封装，以便上层java调用
	}
	
	int i = 0;
	public class PreviewTouchListener implements OnTouchListener{
		
		int lastX, lastY; 
		int l, t, r, b;
		boolean isDoubleClicked = false;
		boolean isDelWindowShow = false;
		boolean state = false;
		@SuppressLint("WrongCall")
		@Override
		public boolean onTouch(View v, MotionEvent event) {
			// TODO Auto-generated method stub
			int j = (Integer)v.getTag();
			
			switch (event.getAction()) {
			case MotionEvent.ACTION_DOWN:
				i++;
				
                lastX = (int) event.getRawX(); 
                lastY = (int) event.getRawY();
                
                l = v.getLeft(); 
                t = v.getTop(); 
                r = v.getRight(); 
                b = v.getBottom(); 
				
				windowId = j;
				
				if (currentVersion<AndroidVersion) {
					ChannelId = surfaceView4L[windowId].nChannel;

				}else {
					ChannelId = surfaceView[windowId].nChannel;
				}
                
				if (flag) {
					if (getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT){
						mDrawIV[j].clear();
					    mDrawIV[j].setColor(Color.RED);
					    mDrawIV[j].setCoordinate(0, 0, screenWidth/2, screenWidth/2);
					    mDrawIV[j].onDraw(new Canvas());
					    
					    for(int i=0; i<4; i++){
					    	if(i != j){
								mDrawIV[i].clear();
							    mDrawIV[i].setColor(Color.GRAY);
							    mDrawIV[i].setCoordinate(0, 0, screenWidth/2, screenWidth/2);
							    mDrawIV[i].onDraw(new Canvas());					    		
					    		}
					    	}	
					}else {
						mDrawIV[j].clear();
					    mDrawIV[j].setColor(Color.RED);
					    mDrawIV[j].setCoordinate(0, 0, screenWidth/2, screenHeight/2);
					    mDrawIV[j].onDraw(new Canvas());
					    
					    for(int i=0; i<4; i++){
					    	if(i != j){
								mDrawIV[i].clear();
							    mDrawIV[i].setColor(Color.GRAY);
							    mDrawIV[i].setCoordinate(0, 0, screenWidth/2, screenHeight/2);
							    mDrawIV[i].onDraw(new Canvas());					    		
					    	}
					    }					
					}
				
				}
				
					
	            if (firstClick != 0 && System.currentTimeMillis() - firstClick > 300) {  
	                count = 0;  
	            }    
	            count++;  
	            if (count == 1) {  
	            	firstId = (Integer)v.getTag();
	                firstClick = System.currentTimeMillis();  
	            } else if (count == 2) {  
	                lastClick = System.currentTimeMillis();  
	                // 两次点击小于300ms 也就是连续点击  
	                if (lastClick - firstClick < 600) {// 判断是否是执行了双击事件  
	                	isDoubleClicked = true;
	                	int id = (Integer)v.getTag();
	                	if (id == firstId) {
		                    System.out.println(">>>>>>>>执行了双击事件"); 
		                    if (flag) {
		                    	showFullScreen(j);
		                    	flag = false;
							} else {
								showFourScreen(j);
								flag = true;
							} 
	                	}
	                }else {
						isDoubleClicked = false;
					}  
	                
	            }	
	            
				break;
				
			case MotionEvent.ACTION_MOVE: 	
                // 移动事件
                // 获得移动的横纵距离
				System.out.println("isDoubleClicked="+isDoubleClicked+"\nstate="+state+"\ni="+i);
				if (!isDoubleClicked) {
					if (i <= 1) {
						if (currentVersion<AndroidVersion) {
							state = surfaceView4L[windowId].playState;
						}else {
							state = surfaceView[windowId].playState;
						}
						System.out.println("state=>"+state);
						if (state) {
			                int dx = (int) event.getRawX() - lastX; 
			                int dy = (int) event.getRawY() - lastY; 
			                // 获得移动后的上下左右边距
			                int left = v.getLeft() + dx; 
			                int top = v.getTop() + dy; 
			                int right = v.getRight() + dx; 
			                int bottom = v.getBottom() + dy; 
			 
			                if (right > screenWidth) { 
			                    right = screenWidth; 
			                    left = right - v.getWidth(); 
			                } 
			 
			                if (bottom > screenWidth) { 
			                    bottom = screenWidth; 
			                    top = bottom - v.getHeight(); 
			                } 
			                // 设置移动后的布局
			                v.layout(left, top, right, bottom); 
			                // 重新设置移动前的位置
			                lastX = (int) event.getRawX(); 
			                lastY = (int) event.getRawY();		
			                
			                if (!isDelWindowShow) {
			                	createDeleteWindow();
							}
			                
			                if (isInDeleteArea(lastY)) {
								delChlView.setDeletePicture(R.drawable.perview_delete1);
								closeStream();
							}else {
								delChlView.setDeletePicture(R.drawable.perview_delete);
							}
						}					
					}					
				} 
                break; 	
			case MotionEvent.ACTION_UP:
				i--;
				if (!isDoubleClicked) {
					removeDeleteWindow();
					v.layout(l, t, r, b);
				}else {
					isDoubleClicked = false;
				}
				break;

			default:
				break;
			}
			return true;
		}
		
	}
	
	private void initView()
	{
		titleLayout = (RelativeLayout)findViewById(R.id.titleLayout);
		
		LinearDeleteLayout = (LinearLayout)findViewById(R.id.LinearDelLayout);
		LinearFourview = (LinearLayout)findViewById(R.id.LinearFourview);
		LinearPannelLayout = (LinearLayout)findViewById(R.id.linearPannelLayout);
		LinearLayout1 = (LinearLayout)findViewById(R.id.linear1);
		LinearLayout2 = (LinearLayout)findViewById(R.id.linear2);
		titleTextView = (TextView)findViewById(R.id.title_preview);
		
		
		menuBtn = (Button)findViewById(R.id.menu_preview);
		menuBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				showController();
			}
		});	
		
		for (int i = 0; i < 4; i++) {
			frameLayout[i] = (FrameLayout)findViewById(frameLayoutId[i]);
			mDrawIV[i] = (DrawImageView)findViewById(mDrawIVId[i]);
			mView[i] = (View)findViewById(mViewId[i]);	
			
			if (currentVersion<AndroidVersion){
				surfaceView4L[i] = (Preview4LowVersion)findViewById(surfaceViewId[i]);
		    	surfaceView4L[i].setTag(i);
		    	surfaceView4L[i].setClickable(true);
		    	surfaceView4L[i].setFocusable(true);	   
				surfaceView4L[i].setZOrderOnTop(false);
				surfaceView4L[i].getHolder().setFormat(PixelFormat.TRANSPARENT);				
			}else {
				surfaceView[i] = (Preview)findViewById(surfaceViewId[i]);
		    	surfaceView[i].setTag(i);
		    	surfaceView[i].setClickable(true);
		    	surfaceView[i].setFocusable(true);	   
				surfaceView[i].setZOrderOnTop(false);
				surfaceView[i].getHolder().setFormat(PixelFormat.TRANSPARENT);				
			}

			
		}
		
		if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT){
			Display localDisplay = getWindowManager().getDefaultDisplay();
			screenWidth  = localDisplay.getWidth();
			screenHeight = localDisplay.getHeight();
			float rate = (float) screenWidth/320;
			if (screenWidth > 1000) {
				titleTextView.setTextSize(6*rate);
			}else {  
				titleTextView.setTextSize(10*rate);
			}
			
			LinearDeleteLayout.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth/6));
			LinearFourview.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth));
	    	FrameLayout.LayoutParams lytp = new FrameLayout.LayoutParams(screenWidth/6,screenWidth/6);
	    	lytp .gravity = Gravity.CENTER;
	    	for (int i = 0; i < 4; i++) {
		    	mView[i].setLayoutParams(lytp);
		    	mDrawIV[i].setCoordinate(0, 0, screenWidth/2, screenWidth/2);
	    	}
	    	LinearPannelLayout.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth/8));
		}else {
			Display localDisplay = getWindowManager().getDefaultDisplay();
			screenWidth  = localDisplay.getWidth();
			screenHeight = localDisplay.getHeight();
			titleLayout.setVisibility(View.GONE);
	    	FrameLayout.LayoutParams lytp = new FrameLayout.LayoutParams(screenHeight/6,screenHeight/6);
	    	lytp .gravity = Gravity.CENTER;
	    	for (int i = 0; i < 4; i++) {
		    	mView[i].setLayoutParams(lytp);
		    	mDrawIV[i].setCoordinate(0, 0, screenWidth/2, screenHeight/2); 
	    	}
		} 
		
	    mDrawIV[0].setColor(Color.RED);
	    mDrawIV[0].onDraw(new Canvas());	 
	    
	    mDrawIV[1].setColor(Color.GRAY);
	    mDrawIV[1].onDraw(new Canvas());
	    
	    mDrawIV[2].setColor(Color.GRAY);
	    mDrawIV[2].onDraw(new Canvas());
	    
	    mDrawIV[3].setColor(Color.GRAY);
	    mDrawIV[3].onDraw(new Canvas());
	    
	    paramView = LayoutInflater.from(this).inflate(R.layout.resolution_dialog, null);
		if (videoparamWindow == null) {
			videoparamWindow = new PopupWindow(paramView, dip2px(PTZControl.this, 250), dip2px(PTZControl.this, 260));
		}
		 
		videoparamWindow.setFocusable(true);
		videoparamWindow.setBackgroundDrawable(new BitmapDrawable());//设置一个空的背景图 当点击时popwindow就消失了	
	    
	}  
	    
	//云台控制
	public void onPtzClick(View v)
	{
		if (surfaceView4L[windowId].nUserId>0){  //只有登录设备，即nUserId>0时才可进行相应的操作
			View view = LayoutInflater.from(this).inflate(R.layout.ptz_menu, null);
			ptzGrid = (GridView)view.findViewById(R.id.ptz_gridview);
			ptzGrid.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, screenWidth/8));
			ptzGrid.setAdapter(new GridAdapter(ptz_image_array, ptz_image_array_pressed ,ptz_commands, PTZControl.this));
			ptzGrid.setSelector(new ColorDrawable(Color.TRANSPARENT)); 
			
			ptzWindow = new PopupWindow(view, LayoutParams.MATCH_PARENT, screenWidth/8);
			ptzWindow.setFocusable(true);
			ptzWindow.setBackgroundDrawable(new BitmapDrawable());//设置一个空的背景图 当点击时popwindow就消失了
			ptzWindow.showAsDropDown(LinearPannelLayout); 
		}		 
	}     
	     
	//镜头控制
	public void onLensClick(View v)
	{ 
		
		if (surfaceView4L[windowId].nUserId>0){
			View view = LayoutInflater.from(this).inflate(R.layout.lens_menu, null);
			
			lensGrid = (GridView)view.findViewById(R.id.lens_gridview);
			lensGrid.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, screenWidth/8));
			lensGrid.setAdapter(new GridAdapter(lens_image_array, lens_image_array_pressed,lens_commands, PTZControl.this));
			lensGrid.setSelector(new ColorDrawable(Color.TRANSPARENT));
			
			lensWindow = new PopupWindow(view, LayoutParams.MATCH_PARENT, screenWidth/8);
			lensWindow.setFocusable(true);
			lensWindow.setBackgroundDrawable(new BitmapDrawable());
	        
			lensWindow.showAsDropDown(LinearPannelLayout);				
		}
	 
	}
	
	//颜色
	public void onColorClick(View v)
	{
		if (surfaceView4L[windowId].nUserId>0){
			View view = LayoutInflater.from(this).inflate(R.layout.color_menu, null);
			
			colorGrid = (GridView)view.findViewById(R.id.color_gridview);
			colorGrid.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, screenWidth/8));
			colorGrid.setAdapter(new ColorGridAdapter(color_image_array, PTZControl.this));
			colorGrid.setSelector(new ColorDrawable(Color.TRANSPARENT));
			
			colorWindow = new PopupWindow(view, LayoutParams.MATCH_PARENT, screenWidth/8);
			colorWindow.setFocusable(true);
			colorWindow.setBackgroundDrawable(new BitmapDrawable());//设置一个空的背景图 当点击时popwindow就消失了
	        
			colorWindow.showAsDropDown(LinearPannelLayout);				
		}
		
	}
	
	//抓拍
	public void onCapturePicClick(View v)
	{
		
		if (surfaceView4L[windowId].nUserId>0){
			MediaPlayer shootMP = null;
		    AudioManager meng = (AudioManager) this.getSystemService(Context.AUDIO_SERVICE);  
		    int volume = meng.getStreamVolume( AudioManager.STREAM_NOTIFICATION);  
		  
		    if (volume != 0)  
		    {  
		        if (shootMP == null)  
		            shootMP = MediaPlayer.create(this, Uri.parse("android.resource://" + getApplicationContext().getPackageName() + "/" + R.raw.snapshot));  
		        if (shootMP != null)  
		            shootMP.start();  
		    }  
		    
		    if (currentVersion<AndroidVersion){
		    	if(!surfaceView4L[windowId].CapturePicture()){
		    		System.out.println("抓拍失败！");
		    	}
		    }			
		}

	} 
	
	//视频参数获取与设置
	public void onResolutionClick(View v)
	{
		if (surfaceView4L[windowId].nUserId>0) {
			pgroups = new ArrayList<PGroup>();
			surfaceView4L[windowId].GetDeviceAbility(surfaceView4L[windowId].nUserId,surfaceView4L[windowId].nChannel);
			String result = surfaceView4L[windowId].GetClientVideoParam(surfaceView4L[windowId].nUserId,surfaceView4L[windowId].nChannel);
			GetVideoParam(result);
			readParams();
			
			pexpandList = (ExpandableListView)paramView.findViewById(R.id.paramlistview);
			pexpandList.setGroupIndicator(null);
			
			confirmBtn = (Button)paramView.findViewById(R.id.confirmBtn); 
			confirmBtn.setOnClickListener(new OnClickListener() { 
				 
				@Override  
				public void onClick(View arg0) {
					// TODO Auto-generated method stub 
					boolean result = false;
					String Resolution = resolutionGroup.getResolution();
					String Framerate  = framerateGroup.getFrameRate(); 
					String Bitrate    = bitrateGroup.getBitrate();
					String BitrateType= bitratetypeGroup.getBitrateType();
					
					if (Bitrate.equals("Self-Define(16-8000kbps)")) {
						int BitrateValue = Integer.parseInt(selfdefineET.getText().toString());  
						result = surfaceView4L[windowId].SetClientVideoParam(surfaceView4L[windowId].nUserId,surfaceView4L[windowId].nChannel, Resolution, Framerate, Bitrate, BitrateType, BitrateValue);
					}else {
						result = surfaceView4L[windowId].SetClientVideoParam(surfaceView4L[windowId].nUserId,surfaceView4L[windowId].nChannel, Resolution, Framerate, Bitrate, BitrateType, 0);
					}
					
					if (result) {
						videoparamWindow.dismiss();
					}else {
						Toast.makeText(PTZControl.this, "设置参数失败！",
						Toast.LENGTH_SHORT).show();
					}
				}  
			});        
			   
			cancelBtn = (Button)paramView.findViewById(R.id.cancelBtn);
			cancelBtn.setOnClickListener(new OnClickListener() {
				
				@Override
				public void onClick(View arg0) {
					// TODO Auto-generated method stub
					if (videoparamWindow != null) {
						videoparamWindow.dismiss();
					}

				}
			});
			
			selfdefineET = (EditText)paramView.findViewById(R.id.selfdefineET);
			selfdefineLayout = (RelativeLayout)paramView.findViewById(R.id.selfdefineLayout);
	    	padapter = new PListAdapter(PTZControl.this, pgroups);
	    	pexpandList.setAdapter(padapter);
	    	pexpandList.setOnChildClickListener(new OnChildClickListener() {
				
				@Override
				public boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
					// TODO Auto-generated method stub
			        PChild child = pgroups.get(groupPosition).getChildItem(childPosition);    
			        PGroup group = pgroups.get(groupPosition);
			        
			    	switch (groupPosition) {
					case 0:
						group.setResolution(child.getParam());
						break;
					case 1:
						group.setFrameRate(child.getParam());
						break;
					case 2:
						group.setBitrateType(child.getParam());
						break;				
					case 3:
						group.setBitrate(child.getParam());
						if (child.getParam().equals("Self-Define(16-8000kbps)")){  //此处是个Bug，有些NVR设备自定义码率范围值不一样
							selfdefineLayout.setVisibility(View.VISIBLE);
							selfdefineET.setText("2000"); //默认2000kbps
						}else {
							selfdefineLayout.setVisibility(View.GONE);
						}
						break;				
					default:
						break;
					}
			        	
			    	padapter.notifyDataSetChanged();
			    	parent.collapseGroup(groupPosition);
			    	
					return true;
				}
			});   
	    	
	    	if (selfdefinebitrate != 0) {
				selfdefineLayout.setVisibility(View.VISIBLE);
				selfdefineET.setText(selfdefinebitrate+"");
			}else {
				selfdefineLayout.setVisibility(View.GONE);
			}
			
			videoparamWindow.showAsDropDown(v);		
		} 
		
	}
	
	@SuppressLint("WrongCall")     
	
	private void createDeleteWindow()
	{
		if (delChlView == null) {
			delChlView = new DeleteView(PTZControl.this);
			delChlView.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT));
			delChlView.setDeletePicture(R.drawable.perview_delete);
			delChlView.setBackgroundColor(Color.RED);
			LinearDeleteLayout.addView(delChlView);
			System.out.println("createDeleteWindow");
		}
	}
	
	private void removeDeleteWindow()
	{
		if (delChlView != null){
			LinearDeleteLayout.removeView(delChlView);
			delChlView = null;
		}
	}
	
	//判断视频显示控件是否进入通道删除区域
	private boolean isInDeleteArea(int positionY)
	{
		if (positionY < delChlView.getHeight() + titleLayout.getHeight()) {
			return true;
		}
		return false;
	}
	
	//关闭码流
	private void closeStream() 
	{
		if (currentVersion<AndroidVersion) {
			surfaceView4L[windowId].Stop(surfaceView4L[windowId].realPlayId);
			surfaceView4L[windowId].Logout(surfaceView4L[windowId].nUserId);
			surfaceView4L[windowId].Cleanup();
			surfaceView4L[windowId].nUserId = 0;
			surfaceView4L[windowId].setZOrderOnTop(false);
			surfaceView4L[windowId].getHolder().setFormat(PixelFormat.TRANSLUCENT);
			surfaceView4L[windowId].realPlayId = 0;
			surfaceView4L[windowId].playState = false;
			surfaceView4L[windowId].onClear();
			surfaceView4L[windowId].setBackgroundResource(R.drawable.black);
		}else {
			surfaceView[windowId].Stop(surfaceView[windowId].realPlayId);
			surfaceView[windowId].setZOrderOnTop(false);
			surfaceView[windowId].getHolder().setFormat(PixelFormat.TRANSLUCENT);
			surfaceView[windowId].realPlayId = 0;
			surfaceView[windowId].playState = false;
		}
		
		if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT){
	    	FrameLayout.LayoutParams lytp = new FrameLayout.LayoutParams(screenWidth/6,screenWidth/6);
	    	lytp.gravity = Gravity.CENTER;
	    	mView[windowId].setLayoutParams(lytp);
		}else {
	    	FrameLayout.LayoutParams lytp = new FrameLayout.LayoutParams(screenHeight/6,screenHeight/6);
	    	lytp.gravity = Gravity.CENTER;
	    	mView[windowId].setLayoutParams(lytp);			
		}
	}
	
	private void readParams()
	{
		String[] resolution_array = null;
		String[] bitrate_array = null;
		String[] framerate_array = null;
		String[] bitratetype_array = null;
		
		if (resolutionGroup!=null && framerateGroup!=null && bitrateGroup!=null && bitratetypeGroup!=null) {
			resolution_array = surfaceView4L[windowId].GetResolutionAbility();
			bitrate_array    = surfaceView4L[windowId].GetBitrateAbility();
			framerate_array  = surfaceView4L[windowId].GetFramerateAbility();
			bitratetype_array  = surfaceView4L[windowId].GetBitrateTypeAbility();
			
			for (int i = 0; i < resolution_array.length; i++) {
				PChild child = new PChild(resolution_array[i]);
				resolutionGroup.addChildrenItem(child);
			}
			
			for (int i = 0; i < framerate_array.length; i++) {
				PChild child = new PChild(framerate_array[i]);
				framerateGroup.addChildrenItem(child);
			}
			
			for (int i = 0; i < bitrate_array.length; i++) {
				PChild child = new PChild(bitrate_array[i]);
				bitrateGroup.addChildrenItem(child);
			}
			
			for (int i = 0; i < bitratetype_array.length; i++) {
				PChild child = new PChild(bitratetype_array[i]);
				bitratetypeGroup.addChildrenItem(child);
			}
		
		}
		
		pgroups.add(resolutionGroup);
		pgroups.add(framerateGroup);
		pgroups.add(bitratetypeGroup);
		pgroups.add(bitrateGroup);
		
	}
	
    private void readData() {  
        try {  
    		cursor = devDatabase.query(DataDefine.TABLE_DEVIDE,null,null, null, null, null, null);	
    		for(cursor.moveToFirst();!cursor.isAfterLast();cursor.moveToNext())  
    		{  
    			String DevType = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_DEVICETYPE));
    			
    			String Ip       = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_LOCALIP)); 
    			int    Port     = Integer.parseInt(cursor.getString(cursor.getColumnIndex(DataDefine.KEY_PORT)));
    			String UserName = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_USERNAME));
    			String PassWord = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_PASSWORD));
    			String DeviceType = DevType.substring(0, 3);
    			
    			if (!UserName.equals("")) {
        			Group  group = new Group(Ip, Port, UserName, PassWord, DeviceType);
        			
                    String ChannelNo = null;
                    if (DeviceType.equals("IPC")) {
                    	ChannelNo = "1";
    				}else {
    					if (DeviceType.length() == 3) {
							ChannelNo = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_CHANNELNO));
						}else {
							ChannelNo = DevType.substring(8).replaceAll("CH", "");
						}
    					
    				}
                    
                    for (int j = 0; j < Integer.parseInt(ChannelNo); j++) {  
                        Child child = new Child(j+1);
                        group.addChildrenItem(child);  
                    }  
                    groups.add(group);  					
				}

    		}  

        } catch (Exception e) {  
            Log.d("PTZControl", e.toString());  
        }  
    }     
    
	private void CreateDeviceDialog() 
	{
		// TODO Auto-generated method stub
		viewList = PTZControl.this.getLayoutInflater().inflate(R.layout.preview_choose, null);
		deviceDialog = new Dialog(PTZControl.this);
		deviceDialog.setTitle("设备列表");
		
		deviceDialog.setContentView(viewList);
		
		expandList = (ExpandableListView)viewList.findViewById(R.id.explistView); 
		groups = new ArrayList<Group>();  
		readData(); 
        adapter = new EListAdapter(PTZControl.this, groups);
        expandList.setAdapter(adapter);  
        expandList.setOnChildClickListener(new OnChildClickListener() {
			
			public boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
				// TODO Auto-generated method stub  
				
				szIP        = groups.get(groupPosition).getIp();
				nPort       = groups.get(groupPosition).getPort();
				szUsername  = groups.get(groupPosition).getUserName();
				szPsw 		= groups.get(groupPosition).getPassWord();
				szDevType   = groups.get(groupPosition).getDeviceType();
				nChannel    = groups.get(groupPosition).getChildItem(childPosition).getChannel();
		         
				if (currentVersion<AndroidVersion){
					if (surfaceView4L[windowId].playState) {
						Toast.makeText(PTZControl.this, "请先关闭通道再进行其他操作！",
						Toast.LENGTH_SHORT).show();
					}else {
						surfaceView4L[windowId].setBackgroundResource(0);//去掉背景图片
						surfaceView4L[windowId].setZOrderOnTop(false);
						surfaceView4L[windowId].getHolder().setFormat(PixelFormat.TRANSPARENT);
						surfaceView4L[windowId].deviceType = szDevType;
						surfaceView4L[windowId].szIp	= szIP;
						surfaceView4L[windowId].nChannel = nChannel;
						    
						Init();
						
						surfaceView4L[windowId].nUserId = surfaceView4L[windowId].Login(szIP,nPort,szUsername,szPsw);
			            if (surfaceView4L[windowId].nUserId > 0) {

			            	surfaceView4L[windowId].realPlayId = surfaceView4L[windowId].Start(surfaceView4L[windowId].nUserId, nChannel, 0x80000000, 0, 0, 0, 0);
		
			            	surfaceView4L[windowId].playState = true;
			            	surfaceView4L[windowId].flag = false;
				            mView[windowId].setLayoutParams(new FrameLayout.LayoutParams(1, 1));
						}else {
							Toast.makeText(PTZControl.this, "通道登陆失败，请重新登陆！",
									Toast.LENGTH_SHORT).show();
						}
					}  
				}else { 
					if (surfaceView[windowId].playState) { 
						Toast.makeText(PTZControl.this, "请先关闭通道再进行其他操作！",
						Toast.LENGTH_SHORT).show();
					}else {
						surfaceView[windowId].setZOrderOnTop(false);
						surfaceView[windowId].getHolder().setFormat(PixelFormat.TRANSPARENT);
						surfaceView[windowId].InitDecoder(surfaceView[windowId].getHolder().getSurface());
						surfaceView[windowId].deviceType = szDevType;
						surfaceView[windowId].szIp	= szIP;
						surfaceView[windowId].nChannel = nChannel;
						Init();
						surfaceView[windowId].streamUid = surfaceView[windowId].Login(szIP,nPort,szUsername,szPsw);
			            if (surfaceView[windowId].streamUid > 0) {
			            	surfaceView[windowId].realPlayId = surfaceView[windowId].Start(surfaceView[windowId].streamUid, nChannel, 0x80000000, 0, 0, 0, 0); //LinkMode=0x80000000,子码流；LinkMode=0x80000000,主码流
			            	surfaceView[windowId].playState = true;
				            mView[windowId].setLayoutParams(new FrameLayout.LayoutParams(1, 1));
						}else {
							Toast.makeText(PTZControl.this, "通道登陆失败，请重新登陆！",
									Toast.LENGTH_SHORT).show();
						}

					}
				}
				
	            deviceDialog.dismiss();
				return true;
			}
		});
		
	}
	
	//全屏显示
	private void showFullScreen(int WinId)
	{
		for(int i=0; i<4; i++)
		{
			if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT){
				if (i == WinId)
				{
					frameLayout[i].setLayoutParams(new LinearLayout.LayoutParams(screenWidth-1, screenWidth-1));
				}
				else
				{
					frameLayout[i].setLayoutParams(new LinearLayout.LayoutParams(1, 1)); //宽高设为1px，相当于隐藏该控件
				}
				
				if(WinId < 2)
				{
					LinearLayout2.setLayoutParams(new LinearLayout.LayoutParams(1, 1));
				    LinearLayout1.setLayoutParams(new LinearLayout.LayoutParams(screenWidth-1, screenWidth-1));	
				}
				else
				{
					LinearLayout1.setLayoutParams(new LinearLayout.LayoutParams(1, 1));
				    LinearLayout2.setLayoutParams(new LinearLayout.LayoutParams(screenWidth-1, screenWidth-1));				
				}
				
				mDrawIV[WinId].clear();
			    mDrawIV[WinId].setColor(Color.RED);
			    mDrawIV[WinId].setCoordinate(0, 0, screenWidth-1, screenWidth-1);
			    
			    mDrawIV[WinId].onDraw(new Canvas());
			}else {
				if (i == WinId)
				{
					frameLayout[i].setLayoutParams(new LinearLayout.LayoutParams(screenWidth-1, screenHeight-1));
				}
				else
				{
					frameLayout[i].setLayoutParams(new LinearLayout.LayoutParams(1, 1));
				}
				
				if(WinId < 2)
				{
					LinearLayout2.setLayoutParams(new LinearLayout.LayoutParams(1, 1));
				    LinearLayout1.setLayoutParams(new LinearLayout.LayoutParams(screenWidth-1, screenHeight-1));	
				}
				else
				{
					LinearLayout1.setLayoutParams(new LinearLayout.LayoutParams(1, 1));
				    LinearLayout2.setLayoutParams(new LinearLayout.LayoutParams(screenWidth-1, screenHeight-1));				
				}	
				
				mDrawIV[WinId].clear();
			    mDrawIV[WinId].setColor(Color.RED);
			    mDrawIV[WinId].setCoordinate(0, 0, screenWidth-1, screenHeight-1);
			    
			    mDrawIV[WinId].onDraw(new Canvas());
			}

		}
		
	}
	
	private void showFourScreen(int WinId)
	{
		for(int i = 0; i<4; i++)
		{
			if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT){
				if (i != WinId)
				{
					frameLayout[i].setLayoutParams(new LinearLayout.LayoutParams(screenWidth/2, screenWidth/2));
				}
				
			    LinearLayout1.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth/2));	
			    LinearLayout2.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenWidth/2));					
			}else {
				if (i != WinId)
				{
					frameLayout[i].setLayoutParams(new LinearLayout.LayoutParams(screenWidth/2, screenHeight/2));
				}
				
			    LinearLayout1.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenHeight/2));	
			    LinearLayout2.setLayoutParams(new LinearLayout.LayoutParams(screenWidth, screenHeight/2));	
			}

		}
		  
		mDrawIV[WinId].clear();
	    mDrawIV[WinId].setColor(Color.RED);
	    if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT){
	    	mDrawIV[WinId].setCoordinate(0, 0, screenWidth/2, screenWidth/2);
	    	frameLayout[WinId].setLayoutParams(new LinearLayout.LayoutParams(screenWidth/2, screenWidth/2));
	    }else {
	    	mDrawIV[WinId].setCoordinate(0, 0, screenWidth/2, screenHeight/2);
	    	frameLayout[WinId].setLayoutParams(new LinearLayout.LayoutParams(screenWidth/2, screenHeight/2));
		}
	    
	    mDrawIV[WinId].onDraw(new Canvas());
	    
	}
	
	private void GetVideoParam(String VideoParam)
	{
		try {
			jsonstatus1 = new JSONObject(VideoParam).getString("ResultCode");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
		
		if (jsonstatus1.equals("true")) {
			try {
				resultContent1 = new JSONObject(VideoParam).getString("ResultContent");
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			try {
				resolution = new JSONObject(resultContent1).getString("Resolution");
				bitrate    = new JSONObject(resultContent1).getString("VideoBitrate");
				framerate  = new JSONObject(resultContent1).getString("VideoFrameRate");
				bitratetype = new JSONObject(resultContent1).getString("BitrateType");
				selfdefinebitrate = new JSONObject(resultContent1).getInt("SelfDefineValue");
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}  
		
		if (resolution!=null && framerate!=null && bitrate!=null && bitratetype!=null) {
			resolutionGroup = new PGroup(resolution, framerate, bitrate, bitratetype);
			framerateGroup    = new PGroup(resolution, framerate, bitrate, bitratetype);
			bitrateGroup  = new PGroup(resolution, framerate, bitrate, bitratetype);
			bitratetypeGroup  = new PGroup(resolution, framerate, bitrate, bitratetype);	
		}else {
			System.out.println("null");
			resolutionGroup = new PGroup("", "", "", "");
			framerateGroup = new PGroup("", "", "", "");
			bitrateGroup = new PGroup("", "", "", "");
			bitratetypeGroup  = new PGroup("", "", "", "");
		}

	}
	
	private void GetValue(String videoEffect)
	{
		try {
			jsonstatus = new JSONObject(videoEffect).getString("ResultCode");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		if (jsonstatus.equals("true"))
		{
			try {
				resultContent = new JSONObject(videoEffect).getString("ResultContent");
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			try {
				hue		   = new JSONObject(resultContent).getInt("Hue");
				bright     = new JSONObject(resultContent).getInt("Bright");
				contrast   = new JSONObject(resultContent).getInt("Contrast");
				saturation = new JSONObject(resultContent).getInt("Saturation");
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}
	
	private Handler handler = new Handler();		
	private void GetDevicesInfo() {
		final  ProgressDialog dialog = new ProgressDialog(PTZControl.this);
		dialog.setMessage("登录设备,请稍候...");
		dialog.show();
		Executors.newFixedThreadPool(10).submit(new Runnable() {
			public void run() {
				try {
					Thread.sleep(1000);
				} catch (Exception e) {
					e.printStackTrace();
				}

				handler.post(new Runnable() {
					public void run() {					
						Init();
						surfaceView4L[windowId].nUserId = surfaceView4L[windowId].Login(szIP,nPort,szUsername,szPsw);		
				        dialog.dismiss();
					}
				});
			}
		});
	
	}	
	

	private void HandlePTZControl(int key, int channel, int state)
	{
		if (surfaceView4L[windowId].nUserId <= 0) {
			builder = new AlertDialog.Builder(this);
			builder.setTitle(R.string.alerttitle);
		    builder.setIcon(android.R.drawable.ic_dialog_info);	
		    builder.setPositiveButton(R.string.okLabel, new DialogInterface.OnClickListener() {
				 
				@Override
				public void onClick(DialogInterface arg0, int arg1) {
					// TODO Auto-generated method stub
					GetDevicesInfo();
				}
			});
		    
		    builder.setNegativeButton(R.string.cancel,new DialogInterface.OnClickListener()
		    {

				@Override
				public void onClick(DialogInterface dialog, int which) {
					// TODO Auto-generated method stub
					dialog.dismiss();
				}
		    	
		    });
		    
		    if (state == 0) {
		    	 builder.show();//避免重复显示
			}
		   
		}
		else
		{
			if(!PTZControl(surfaceView4L[windowId].nUserId, channel, key, state, 10))
			{
				Toast.makeText(PTZControl.this, "操作失败",
						Toast.LENGTH_SHORT).show();
			}
		}
			
	}
	
	class ColorGridAdapter extends BaseAdapter{
		private int[] images;
		private int[] commands;
		private Context   context;
		
		public ColorGridAdapter(int[] images, Context context){
			this.images   = images;
			this.context  = context;
		}
		
		@Override
		public int getCount() {
			// TODO Auto-generated method stub
			return images.length;
		}

		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return position;
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return position;
		} 
   
		@Override 
		public View getView(final int position, View convertView, ViewGroup parent) {
			// TODO Auto-generated method stub
	 	    ViewHolder holder = null;
	 	      
	 	    if (convertView == null) {  
				holder = new ViewHolder();
				convertView = LayoutInflater.from(context).inflate(R.layout.item_ptz, null);
				holder.imgView = (ImageView)convertView.findViewById(R.id.item_image1);
				convertView.setTag(holder);
			}else {
				holder = (ViewHolder)convertView.getTag(); 
			}  
	 	        
	 	    holder.imgView.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, screenWidth/8));
	 	    holder.imgView.setImageResource(images[position]);
	 	    holder.imgView.setOnTouchListener(new OnTouchListener() {
				
				@Override 
				public boolean onTouch(View arg0, MotionEvent arg1) {
					// TODO Auto-generated method stub
					System.out.println("position:"+position);
					switch (position) {
					case 0:
						videoEffect = GetVideoEffect(surfaceView4L[windowId].nUserId, surfaceView4L[windowId].nChannel);
					    GetValue(videoEffect);
					    
					    boolean state = false;
					      
					    if ((bright+2) < 256) 
					    {
					    	state = SetVideoEffect(surfaceView4L[windowId].nUserId, surfaceView4L[windowId].nChannel, bright+2, contrast, saturation, hue); //亮度增加，每点击一次加2
//					    	Log.i("nUserid", nUserid+":"+ChannelId);
					    	System.out.println("state:"+state+" bright:"+bright+"  contrast:"+contrast+"  saturation:"+saturation+"  hue:"+hue);
						}
						break;
					case 1:
						videoEffect = GetVideoEffect(surfaceView4L[windowId].nUserId, surfaceView4L[windowId].nChannel);
					    GetValue(videoEffect);
					    
					    if (bright > 0)
					    {
					    	state = SetVideoEffect(surfaceView4L[windowId].nUserId, surfaceView4L[windowId].nChannel, bright-2, contrast, saturation, hue);
					    	Log.i("nUserid", surfaceView4L[windowId].nUserId+":"+ChannelId);
						}
						break;
					case 2:
						videoEffect = GetVideoEffect(surfaceView4L[windowId].nUserId, surfaceView4L[windowId].nChannel);
					    GetValue(videoEffect);
					    
					    if ((contrast+2) < 256) 
					    {
					    	state = SetVideoEffect(surfaceView4L[windowId].nUserId, surfaceView4L[windowId].nChannel, bright, contrast+2, saturation, hue);
						}					
						break;	
					case 3:
						videoEffect = GetVideoEffect(surfaceView4L[windowId].nUserId, surfaceView4L[windowId].nChannel);
					    GetValue(videoEffect);
					    
					    if (contrast > 0) 
					    {
					    	state = SetVideoEffect(surfaceView4L[windowId].nUserId, surfaceView4L[windowId].nChannel, bright, contrast-2, saturation, hue);
						}					
						break;		
					default:
						break;
					}
					return false;  //返回true时，那么touch事件就被拦截了
				}
			});
	 	    
			return convertView;
		}
		
	}	
	
	
	class GridAdapter extends BaseAdapter{
		private int[] images;
		private int[] images_pressed;
		private int[] commands;
		private Context   context;
		
		public GridAdapter(int[] images, int[] images_pressed, int[] commands, Context context){
			this.images   = images;
			this.commands = commands;
			this.context  = context;
			this.images_pressed   = images_pressed;
		}
		
		@Override
		public int getCount() {
			// TODO Auto-generated method stub
			return images.length;
		}

		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return position;
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return position;
		} 
   
		@Override 
		public View getView(final int position, View convertView, ViewGroup parent) {
			// TODO Auto-generated method stub
//	 	    final ViewHolder holder = new ViewHolder();
			ViewHolder holder = null;
			
	 	    if (convertView == null) {  
	 	    	holder = new ViewHolder();
				convertView = LayoutInflater.from(context).inflate(R.layout.item_ptz, null);
				holder.imgView = (ImageView)convertView.findViewById(R.id.item_image1);
				convertView.setTag(holder);
			}else {
				holder = (ViewHolder)convertView.getTag(); 
			}  
	 	        
	 	    System.out.println("===============>getView");
	 	    holder.imgView.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, screenWidth/8));
	 	    holder.imgView.setBackgroundResource(images[position]);
	 	    holder.imgView.setOnTouchListener(new OnTouchListener() {
				
				@Override 
				public boolean onTouch(View arg0, MotionEvent arg1) {
					// TODO Auto-generated method stub
					
					switch (arg1.getAction()) {
					case MotionEvent.ACTION_DOWN:
			    	  	 System.out.println("ACTION_DOWN");
			    	  	arg0.setBackgroundResource(images_pressed[position]);
						 HandlePTZControl(commands[position], surfaceView4L[windowId].nChannel, 0);	
						 break;
					case MotionEvent.ACTION_UP:
						 
						 System.out.println("ACTION_UP");
						 arg0.setBackgroundResource(images[position]);
						 HandlePTZControl(commands[position], surfaceView4L[windowId].nChannel, 1);
						 break;
					default:
						 break;
					} 
					
					return true;  //返回true时，那么touch事件就被拦截了
				}
			});
	 	    
			return convertView;
		}
		
	}
	
	public class ViewHolder{
		public ImageView imgView;
	}
	
	private ListAdapter getMenuAdapter(String[] menuNameArray,
			int[] menuImageArray) {
		
		ArrayList<HashMap<String, Object>> data = new ArrayList<HashMap<String, Object>>();
		
		if (menuNameArray == null) {
			
			for (int i = 0; i < menuImageArray.length; i++) {
				HashMap<String, Object> map = new HashMap<String, Object>();
				map.put("itemImage", menuImageArray[i]);
				data.add(map);
			}
			
			View view = LayoutInflater.from(this).inflate(R.layout.item_ptz, null);
			ImageView imageView = (ImageView)view.findViewById(R.id.item_image1);  
			imageView.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, screenWidth/8));
			
			SimpleAdapter simperAdapter = new SimpleAdapter(this, data,
					R.layout.item_ptz, new String[] { "itemImage"},
					new int[] { R.id.item_image1});
			 

			return simperAdapter;	
		}else {
			if (menuImageArray == null) {
				for (int i = 0; i < menuNameArray.length; i++) {
					HashMap<String, Object> map = new HashMap<String, Object>();
					map.put("itemText", menuNameArray[i]);
					data.add(map);
				}
				SimpleAdapter simperAdapter = new SimpleAdapter(this, data,
						R.layout.item_resolution, new String[] { "itemText" },
						new int[] { R.id.item_text_resolution });
				return simperAdapter;
			}else { 
				for (int i = 0; i < menuNameArray.length; i++) {
					HashMap<String, Object> map = new HashMap<String, Object>();
					map.put("itemImage", menuImageArray[i]);
					map.put("itemText", menuNameArray[i]);
					data.add(map);
				}
				SimpleAdapter simperAdapter = new SimpleAdapter(this, data,
						R.layout.item_menu, new String[] { "itemImage", "itemText" },
						new int[] { R.id.item_image, R.id.item_text });		
				return simperAdapter;
			}

		}

	}
	
	
	private void showController(){
		LayoutInflater mLayoutInflater = (LayoutInflater) getSystemService(LAYOUT_INFLATER_SERVICE);
		ViewGroup menuView = (ViewGroup) mLayoutInflater.inflate(
				R.layout.gridview_pop, null, true);
//		View root = this.getLayoutInflater().inflate(R.layout.gridview_pop, null);
		menuGrid = (GridView) menuView.findViewById(R.id.gridview);
		menuGrid.setAdapter(getMenuAdapter(menu_name_array, menu_image_array));
		menuGrid.setSelector(new ColorDrawable(Color.TRANSPARENT));
		menuGrid.requestFocus();
		menuGrid.setOnItemClickListener(new OnItemClickListener() {
 
			@Override 
			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
					long arg3) {
				// TODO Auto-generated method stub 
				boolean state = false;
				
				for (int i = 0; i < 4; i++) {
					if (currentVersion<AndroidVersion){
	            		if (surfaceView4L[i].playState == true)
	            		{
	    					state = true;
	    				}		
					}else {
	            		if (surfaceView[i].playState == true)
	            		{
	    					state = true;
	    				}
					}

				}
				
        		if (state == true)
        		{
					Toast.makeText(PTZControl.this, "请先关闭通道再退出！",
							Toast.LENGTH_SHORT).show();
					menuController.dismiss(); 
				}else {
					switch (arg2) {
					case 0:
						menuController.dismiss();              
						break;       
					case 1:
						Intent intent1 = new Intent(PTZControl.this, QueryRemoteFile.class);
						startActivity(intent1);	
						android.os.Process.killProcess(android.os.Process.myPid());
						break;
					case 2:
						Intent intent2 = new Intent(PTZControl.this, RemoteControl.class);
						startActivity(intent2);		
						android.os.Process.killProcess(android.os.Process.myPid());
						break;
					case 3:
						Intent intent3 = new Intent(PTZControl.this, Discovery.class);
						startActivity(intent3);		
						android.os.Process.killProcess(android.os.Process.myPid());
						break;
					case 4:
						Intent intent4 = new Intent(PTZControl.this, ImagesManage.class);
						startActivity(intent4);	
						android.os.Process.killProcess(android.os.Process.myPid());
						break;
					default:
						break;
					}
				}

			} 
		});
				
		menuController = new PopupWindow(menuView, LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
		// 创建PopupWindow对象
		menuController.setFocusable(true);
		menuController.setBackgroundDrawable(new BitmapDrawable());
		menuController.showAsDropDown(menuBtn);

		menuController.update();
		isControllerShow = false;
	}

    /**
     * 菜单、返回键响应
     */
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        // TODO Auto-generated method stub
        if(keyCode == KeyEvent.KEYCODE_BACK)
           {
               exitBy2Click();      //调用双击退出函数
           }
        return false;
    }
    /**
     * 双击退出函数
     */
    private static Boolean isExit = false;

    private void exitBy2Click() {
        Timer tExit = null;
        if (isExit == false) {
            isExit = true; // 准备退出
            Toast.makeText(this, "再按一次退出程序", Toast.LENGTH_SHORT).show();
            tExit = new Timer();
            tExit.schedule(new TimerTask() {
                @Override
                public void run() {
                    isExit = false; // 取消退出
                }
            }, 2000); // 如果2秒钟内没有按下返回键，则启动定时器取消掉刚才执行的任务

        } else {
            SysApplication.getInstance().exit(); 
        }
    }

    //码流回调函数，有码流时回调，通过Start()函数请求码流
    public void StreamCallBack(int Handle,byte[] Buffer,int Size,int FrameType,int FrameNo,int FrameTime,int FrameTickCount,int RelativeTime, int Width, int Height)
	{

    	if (currentVersion<AndroidVersion){
    		
    		for(int i=0; i<4; i++)
    		{      
    		//	System.out.println("surfaceView4L[i].flag :"+surfaceView4L[i].flag );
				if(surfaceView4L[i].flag == true)
				{
			//		Log.i("haha", "StreamCallBack Stop!!!");			
					return;
				}

    			if (surfaceView4L[i].playState == true) {
        			if(surfaceView4L[i].realPlayId == Handle)
        			{ 
        				if (FrameType != 8) //过滤掉音频帧   
        	  			{
        					if (surfaceView4L[i].changedWidth != Width || surfaceView4L[i].changedHeight != Height) {
        						surfaceView4L[i].initState = false;
        					}
        					
        					if (!surfaceView4L[i].initState) {
        						surfaceView4L[i].decodeId = surfaceView4L[i].InitDecoder(Width, Height);
        						surfaceView4L[i].initState = true;
        						surfaceView4L[i].changedWidth  = Width;
        						surfaceView4L[i].changedHeight = Height;
        					}
        					
        					
        					surfaceView4L[i].Decode_V1(surfaceView4L[i].decodeId, Buffer, Size, FrameType);	
        				}
        					  
        			}						
				}  
			     
    		}  
		}else {  
			for (int i = 0; i < 4; i++) {
				if (surfaceView[i].realPlayId == Handle) {
					surfaceView[i].Decode(Buffer, Size, FrameType);
					System.out.println(Buffer);
				}
				
			}
			
		}
		
	}	    
	
    //dip转px函数，以便适配不同分辨率手机
	public static int dip2px(Context context, float dpValue) { 
		final float scale = context.getResources().getDisplayMetrics().density ; 
		return (int) (dpValue * scale + 0.5f) ;
	}   
	
}

