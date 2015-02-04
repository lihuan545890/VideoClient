package com.Activity;
 

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.concurrent.Executors;

import org.json.JSONException;
import org.json.JSONObject;

import com.BLL.Calendarview;
import com.BLL.EListAdapter;
import com.BLL.Group;
import com.BLL.MyCursor;
import com.BLL.TimeRuler;
import com.Utility.DataDefine;
import com.Utility.HandleData;
import com.Utility.SysApplication;
import com.example.minicontroller.R;

import android.R.integer;
import android.app.Activity;
import android.app.Dialog;
import android.app.DownloadManager.Query;
import android.app.ProgressDialog;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Color;
import android.graphics.PointF;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.os.Handler;
import android.text.InputType;
import android.util.AttributeSet;
import android.util.DisplayMetrics;
import android.util.FloatMath;
import android.util.Log;
import android.view.Display;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.webkit.WebView.FindListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CalendarView;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ExpandableListView;
import android.widget.ExpandableListView.OnGroupClickListener;
import android.widget.GridView;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.PopupWindow;
import android.widget.SimpleAdapter;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

public class QueryRemoteFile extends Activity implements View.OnTouchListener{
	private Handler handler = new Handler();	
	private SQLiteDatabase devDatabase;
	private Cursor cursor;
	private String id;
	
	private Button chooseBtn;
	private Button menuBtn;
	private TextView playbackTitle;
	
	private Calendarview calendar;
	private ImageButton  calendarLeft;
	private ImageButton  calendarRight;
	private TextView     calendarCenter;
	private TextView	 timeView; //时间显示view
	private TimeRuler    timeRuler; //时间标尺
	private MyCursor	 myCursor;
	private Button       zoomIn;
	private Button       zoomOut;
	
	private int          QueryDays;
	private int 		 FindFileId;
	private EditText     etStartTime;
	private EditText     etEndTime;  
	private String       strStart;
	private String       strEnd;
	private Spinner      spi; 
	private Spinner 	 fileTypeSp;
	private int 		 fileType;
	private LinearLayout queryblank;
	private Button btnquery;
	private Button btnplay;
	private ArrayAdapter<String> adapter,fileTypeadapter;  
	private int channelNo;
	private int channel;
	private static final String columns[] = {DataDefine.KEY_CHANNELNO};
	private static final String TAG = "";  
	private String FindCondString;
	private String QueryResultString;
	private String filename ="";
	private String ResultContent; 
	private ArrayList<String> QueryResult=new ArrayList<String>();
	private String szIP; 
	private int nPort;
	private String szUsername;
	private String szPsw;
	private int nUserid  = 0;
	private int startyear;
	private int startmonth;
	private int startday;
	private int starthour;
	private int startmin;
	private int startsec;
	
	private int endyear;
	private int endmonth;
	private int endday;
	private int endhour;
	private int endmin;
	private int endsec;	

	private String startTime;
	private String endTime;
	
	private native boolean  Init();
	private native boolean  Cleanup();
	private native int   	Login(String ip,int port,String Username,String Passwd);
	private native boolean  Logout(int UserId);	
	private native int      GetLastError();
	private native int      FindFile4Monthly(int UserId, int StartYear, int StartMonth, int DayNumOfMonth); //查找当月有录像的天数
	private native int 		Start(int UserId, String FindCondStr);//开始查找录像文件
	private native String   GetFile(int FindFileId); //获取录像文件名
	private native boolean  Stop(int FindFileId);
	
	PointF start = new PointF();// 其实点
	PointF mid = new PointF();// 中点
	float oldDist;
	float newDist;

	// 模式
	static final int NONE = 0;
	static final int DRAG = 1;
	static final int ZOOM = 2;

	int mode = NONE;
	int lastX ,lastY;
	float mGradientWidth;
    boolean flag = true;    
    boolean isQuery = false;

	private View 		   menuControlView = null;
	private PopupWindow    menuController = null;
	private GridView 	   menuGrid;
	private boolean        isControllerShow = true;	
	
	private String[] menu_name_array = { "远程预览", "远程回放", "远程控制", "设备管理","图像管理"};
	int[] menu_image_array = { R.drawable.menu_preview,
			R.drawable.menu_playback, R.drawable.menu_control,
			R.drawable.menu_devicemanage,R.drawable.menu_test};	
	
	private ExpandableListView expandList;
	private View viewlist;
    private Dialog  deviceDialog;
    private ArrayList<Group> groups; 
    private EListAdapter elistadapter;     
     
	private int  screenWidth;
	private int  screenHeight; 
    
	@Override
	protected void onCreate(Bundle savedInstanceState) {  
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		SysApplication.getInstance().addActivity(this); 
	    setContentView(R.layout.playbackquery);

		DisplayMetrics mDisplayMetrics = new DisplayMetrics();
		this.getWindowManager().getDefaultDisplay().getMetrics(mDisplayMetrics);
		mGradientWidth = (float) (0.8 * mDisplayMetrics.widthPixels);
		
        SysApplication.getInstance().addActivity(this);
		Display localDisplay = getWindowManager().getDefaultDisplay();
		screenWidth  = localDisplay.getWidth();  
		screenHeight = localDisplay.getHeight();
          
		chooseBtn	   = (Button)findViewById(R.id.chooseDev_playback);
		menuBtn		   = (Button)findViewById(R.id.menu_playback);
		playbackTitle  = (TextView)findViewById(R.id.title_playback);
	    calendar       = (Calendarview)findViewById(R.id.calendar);
	    calendarLeft   = (ImageButton)findViewById(R.id.calendarLeft);
	    calendarRight  = (ImageButton)findViewById(R.id.calendarRight);
	    calendarCenter = (TextView)findViewById(R.id.calendarCenter);
	    timeView	   = (TextView)findViewById(R.id.timeView);
	    timeRuler      = (TimeRuler)findViewById(R.id.timeRuler);
	    myCursor	   = (MyCursor)findViewById(R.id.myCursor);
	    zoomIn		   = (Button)findViewById(R.id.zoomIn);
	    zoomOut		   = (Button)findViewById(R.id.zoomOut);
	    
        startyear  = endyear  = calendar.getYear();
        startmonth = endmonth = calendar.getMonth();
        startday   = endday   = calendar.getDay();
        starthour  = 0;
        startmin   = 0;
        endhour  = 23;
        endmin   = 59;        
	    
		float rate = (float) screenWidth/320;
		if (screenWidth > 1000) {
			playbackTitle.setTextSize(6*rate);
		}else {  
			playbackTitle.setTextSize(10*rate);
		}
		
	    timeView.setText("00:00:00");
	    chooseBtn.setOnClickListener(new OnClickListener() {
			  
			@Override    
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				CreateDeviceDialog();
				deviceDialog.show();
			}
		});
	    
	    menuBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				showController();
			}
		});
	    
	    zoomIn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				
				if (myCursor.getX() >= 0 && myCursor.getX() <= mGradientWidth)
				{
					timeRuler.zoomIn(myCursor.getX(), getTimeStamp());	
					
					if (timeRuler.gettimes() == 0) 
					{
						if(flag)
						{
							int pos = (int) (getTimeStamp()*mGradientWidth / 86400);
							myCursor.setLeft((int) pos);	
							flag = false;
						}
					}
				}
			}
		});
	    
	    zoomOut.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				if (myCursor.getX() >= 0 && myCursor.getX() <= mGradientWidth)
				{
					timeRuler.zoomOut(myCursor.getX(), getTimeStamp());
					flag = true;
				}
				
			}
		});
	    
	    myCursor.setOnTouchListener(new OnTouchListener() {
			
			@Override
			public boolean onTouch(View v, MotionEvent event) {
				// TODO Auto-generated method stub
				switch (event.getAction()& MotionEvent.ACTION_MASK) {
				case MotionEvent.ACTION_DOWN:
		        	
		            lastX = (int) event.getRawX();
		            lastY = (int) event.getRawY();   	
		            mode = DRAG;
					break;
				case MotionEvent.ACTION_UP:
				case MotionEvent.ACTION_POINTER_UP:
					mode = NONE;
					break;
				// 设置多点触摸模式
				case MotionEvent.ACTION_POINTER_DOWN:
					mode = ZOOM;
					break;
				case MotionEvent.ACTION_MOVE :
		            //   移动的时候距离屏幕左上角的距离
		        	
		        	if (mode == DRAG) 
		        	{
			            int nowX = (int)event.getRawX();
			            int nowY = (int)event.getRawY();
			            // X轴和Y轴移动的距离
			            int moveX = nowX - lastX;
			            // 分别计算距离
			            int left   = v.getLeft()   + moveX;  
			            int right  = v.getRight()  + moveX;
			            
  			             
			            if (v.getLeft() >= 0 && left >= 0 && left < mGradientWidth )
			            {

			            	v.layout(left, 0, right, v.getHeight());
						}
			            
			            lastX = (int) event.getRawX();
			            myCursor.refresh();
			            	
			            if (myCursor.getX() >= 0 && myCursor.getX() <= mGradientWidth)
			            {				            
				            timeView.setText(getTime(myCursor.getX(), timeRuler.gettimes())+"");
						}
					
					}

		            break;
				default:
					break;
				}
				return false;
			}
		});
	    
	    calendar.setOnTouchListener(new OnTouchListener() {
			
			@Override
			public boolean onTouch(View v, MotionEvent event) {
				// TODO Auto-generated method stub
				switch (event.getAction()) {
				case MotionEvent.ACTION_DOWN:
					
					if (event.getY() > calendar.getWeekHeight()) {
						
						calendar.setSelectedDateByCoor(event.getX(), event.getY());
						SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
						String date = sdf.format(calendar.getDownDate());
						
				        startyear  = endyear  = Integer.parseInt(date.substring(0,4));
				        startmonth = endmonth = Integer.parseInt(date.substring(5,7));
				        startday   = endday   = Integer.parseInt(date.substring(8,10));
				        
				        System.out.println("startday="+startday);
				        
				        starthour  = 0;
				        startmin   = 0;
				        
				        endhour  = 23;
				        endmin   = 59;
					}

					break;
				case MotionEvent.ACTION_UP:
					if (calendar.downDate != null) {
						calendar.selectedStartDate = calendar.selectedEndDate = calendar.downDate;
						calendar.downDate = null;
						calendar.invalidate();
					}
					break;
				}
				return true;
			}
		});
	    
	    calendarLeft.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				calendar.clickLeftMonth();   
				calendarCenter.setText(calendar.getYearAndmonth());
				QueryDays = FindFile4Monthly(nUserid, calendar.getYear(), calendar.getMonth(), calendar.getDayNum());
				
				calendar.SetRecordDay(QueryDays);
			} 
		});
	    
	    calendarRight.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				calendar.clickRightMonth();   
				calendarCenter.setText(calendar.getYearAndmonth());
				QueryDays = FindFile4Monthly(nUserid, calendar.getYear(), calendar.getMonth(), calendar.getDayNum());
				
				calendar.SetRecordDay(QueryDays);
			}
		});
	    
	    calendarCenter.setText(calendar.getYearAndmonth());
	    
	}
	
	
	static{
		System.loadLibrary("i8_netsdk");
		System.loadLibrary("i8_net_sdk");
	}
	
   
	private void readData() {  
        try {  

        	devDatabase = openOrCreateDatabase(DataDefine.DBNAME, SQLiteDatabase.CREATE_IF_NECESSARY, null);
    		cursor = devDatabase.query(DataDefine.TABLE_DEVIDE,null,null, null, null, null, null);	
    		
    		for(cursor.moveToFirst();!cursor.isAfterLast();cursor.moveToNext())  
    		{  
    			int    ChannelNo = 0;
    			String DevType = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_DEVICETYPE));
    			String Ip       = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_LOCALIP)); 
    			int    Port     = Integer.parseInt(cursor.getString(cursor.getColumnIndex(DataDefine.KEY_PORT)));
    			String UserName = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_USERNAME));
    			String PassWord = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_PASSWORD));
    			String DeviceType = DevType.substring(0, 3);
    			
    			if (!UserName.equals("")){
        			if (!DeviceType.equals("IPC")) { //过滤掉IPC设备
    					if (DeviceType.length() == 3) {
    						ChannelNo  = Integer.parseInt(cursor.getString(cursor.getColumnIndex(DataDefine.KEY_CHANNELNO)));
						}else {
							ChannelNo  = Integer.parseInt(DevType.substring(8).replaceAll("CH", ""));
						}
        				
            			Group  group = new Group(Ip, Port, UserName, PassWord, DeviceType, ChannelNo);
        				groups.add(group); 
    				}   				
    			}

    		}         	

        } catch (Exception e) {  
            Log.d("remoteCtrl", e.toString());  
        }  
    }	
	
	private void CreateDeviceDialog() {
		// TODO Auto-generated method stub
		viewlist = QueryRemoteFile.this.getLayoutInflater().inflate(R.layout.remote_choose, null);
		deviceDialog = new Dialog(QueryRemoteFile.this);
		deviceDialog.setTitle("设备列表");
		deviceDialog.setContentView(viewlist);
		
		expandList = (ExpandableListView)viewlist.findViewById(R.id.explistView1);
		groups = new ArrayList<Group>();  
		readData(); 
        elistadapter = new EListAdapter(QueryRemoteFile.this, groups);
        expandList.setAdapter(elistadapter);
        expandList.setGroupIndicator(null);//去掉默认的向下箭头
        expandList.setOnGroupClickListener(new OnGroupClickListener() {
			
			@Override
			public boolean onGroupClick(ExpandableListView parent,  
                    View v, int groupPosition, long id) {
				// TODO Auto-generated method stub
				
				szIP        = groups.get(groupPosition).getIp();
				nPort       = groups.get(groupPosition).getPort();
				szUsername  = groups.get(groupPosition).getUserName();
				szPsw 		= groups.get(groupPosition).getPassWord();
				channelNo   = groups.get(groupPosition).getChannelNo();
				
				InitQueryPara();
				
				deviceDialog.dismiss();
				return true;
			}
		});
        
	}
	
	private ListAdapter getMenuAdapter(String[] menuNameArray,
			int[] menuImageArray) {
		ArrayList<HashMap<String, Object>> data = new ArrayList<HashMap<String, Object>>();
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
	
	private void showController(){
		LayoutInflater mLayoutInflater = (LayoutInflater) getSystemService(LAYOUT_INFLATER_SERVICE);
		ViewGroup menuView = (ViewGroup) mLayoutInflater.inflate(
				R.layout.gridview_pop, null, true);
		menuGrid = (GridView) menuView.findViewById(R.id.gridview);
		menuGrid.setAdapter(getMenuAdapter(menu_name_array, menu_image_array));
		menuGrid.setSelector(new ColorDrawable(Color.TRANSPARENT));
		menuGrid.requestFocus();
		menuGrid.setOnItemClickListener(new OnItemClickListener() {

			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
					long arg3) {
				// TODO Auto-generated method stub
				switch (arg2) {
				case 0:
					Intent intent0 = new Intent(QueryRemoteFile.this, PTZControl.class);
					startActivity(intent0);	
//					System.exit(0);
					break;
				case 1:
//					Intent intent1 = new Intent(RemoteControl.this, QueryRemoteFile.class);
//					startActivity(intent1);		
					menuController.dismiss();
					break;
				case 2:
					Intent intent2 = new Intent(QueryRemoteFile.this, RemoteControl.class);
					startActivity(intent2);	
					break;
				case 3:
					Intent intent3 = new Intent(QueryRemoteFile.this, Discovery.class);
					startActivity(intent3);		
					break;
				case 4:
					Intent intent4 = new Intent(QueryRemoteFile.this, ImagesManage.class);
					startActivity(intent4);	
					break;
				default:
					break;  
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

	private void GetDevicesInfo() {
		final  ProgressDialog dialog = new ProgressDialog(QueryRemoteFile.this);
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
						InitQueryPara();		
				        dialog.dismiss();    
					}
				});
			}    
		});
	   
	}
	
	private void InitQueryPara()
	{
		int Uid = 0;
			  
		if(!Init())
		{
			Toast.makeText(QueryRemoteFile.this, "设备初始化失败！",
					Toast.LENGTH_SHORT).show();
			playbackTitle.setText(R.string.playback);
		}	
		
		Uid = Login(szIP,nPort,szUsername,szPsw);
		
		if(Uid >0){
			nUserid = Uid;
			QueryDays = FindFile4Monthly(nUserid, calendar.getYear(), calendar.getMonth(), calendar.getDayNum());
			calendar.SetRecordDay(QueryDays);
			playbackTitle.setText(szIP);
		}else
		{
			Toast.makeText(QueryRemoteFile.this, "登录设备失败！",
					Toast.LENGTH_SHORT).show();
			System.out.println("Login Failure:"+Uid);
			playbackTitle.setText(R.string.playback);
		}
	
		InitData();
	}
	
	
	//初始化数据
	@SuppressWarnings("deprecation")
	private void InitData()
	{			
		String[] m = new String[channelNo];
        for (int i = 0; i < channelNo; i++) {
			m[i] = "通道"+(i+1);
		}

        
        spi = (Spinner)findViewById(R.id.checkenc);
	    
		adapter = new ArrayAdapter<String>(this,android.R.layout.simple_spinner_item,m);   
		//设置下拉列表的风格   
        adapter.setDropDownViewResource(android.R.layout.select_dialog_singlechoice);  
        spi.setAdapter(adapter);
        
        spi.setOnItemSelectedListener(new OnItemSelectedListener() {

			@Override
			public void onItemSelected(AdapterView<?> arg0, View arg1,
					int arg2, long arg3) {
				// TODO Auto-generated method stub
				channel = (int)arg3 + 1;
				query();
			}

			@Override
			public void onNothingSelected(AdapterView<?> arg0) {
				// TODO Auto-generated method stub
				
			}
		});
        
        btnplay = (Button)findViewById(R.id.btnplay);
        btnplay.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				if (isQuery) {
					String Startmonth = null, Startday = null;
					String Hour = null,Min = null,Sec = null;
					
					if (getTimeStamp() >= 0)
					{
						int   hour = getTimeStamp() / 3600;
						int   min  = getTimeStamp() % 3600 / 60;
						int   sec  = getTimeStamp() % 60;		
						
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
					}
					
					if(startmonth > 0 && startmonth < 10)
					{
						Startmonth = "0" + startmonth;
					}
					else
					{
						Startmonth = "" + startmonth;
					}
					
					if(startday > 0 && startday < 10)
					{
						Startday = "0" + startday;
					}
					else
					{
						Startday = "" + startday;
					}
					
				    startTime = startyear + Startmonth + Startday + Hour + Min + Sec;
				    endTime   = startyear + Startmonth + Startday + "23" + "59" + "59";
				    
				    Intent intent = new Intent();
				    intent.setClass(QueryRemoteFile.this, HistoryStream.class);
				    
				    intent.putExtra("nUserid",  nUserid);
				    intent.putExtra("HostIP",   szIP);
				    intent.putExtra("CtrlPort", nPort);
				    intent.putExtra("UserName", szUsername);
				    intent.putExtra("Password", szPsw);
				    intent.putExtra("nChannel", channel);
				    intent.putExtra("StartTime",startTime);
				    intent.putExtra("EndTime", endTime);
				    
				    startActivity(intent);						
				}
				else
				{
					Toast.makeText(QueryRemoteFile.this, "请先查询录像再进行操作！",
							Toast.LENGTH_SHORT).show();
				}
				
			}
		});
        
        btnquery =(Button)this.findViewById(R.id.btnquery);
        btnquery.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				query();
			}
		});
        
	}  
	
	protected void onResume(){
		super.onResume();
	    System.loadLibrary("i8_net_sdk");
	}
	
	protected void onDestroy() {  
	    super.onDestroy();  
	    if (devDatabase  != null) {  
	    	devDatabase.close();  
	    }  
	    
	    Logout(nUserid);
	    Cleanup();
	}
	@Override
	public boolean onTouch(View v, MotionEvent event) {
		// TODO Auto-generated method stub
		
		return false;
	}	  
	
	public int getTimeStamp()
	{
		String timeStr = timeView.getText().toString();
		int time = Integer.parseInt(timeStr.substring(0,2))*3600 + Integer.parseInt(timeStr.substring(3,5))*60
				+Integer.parseInt(timeStr.substring(6,8));
		
		return time;
	}
	
	@SuppressWarnings("unused")
	public String getTime(float pos, int times)
	{
		int   time = 0;
		if (times == 3)
		{
		   time = (int) (timeRuler.getbegintime() + pos * 7200/mGradientWidth);	
		}
		else
		{
		   time = (int) (timeRuler.getbegintime() + pos * (86400/(Math.pow(2, times)))/mGradientWidth);
		}
		   
		String Hour = "00",Min = "00",Sec = "00";
		
		if (time >= 0 && time <= 86400)
		{
			int   hour = time / 3600;
			int   min  = time % 3600 / 60;
			int   sec  = time % 60;		
			
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
		}
		
		return Hour+":"+Min+":"+Sec;
	}
	
	private void query()
	{
		//查询格式
	    FindCondString = 
	    		"{" + "\n" + 
					"\"FindCond\":{" + "\n" +
						"\"Channel\":"  +    channel  + "," + "\n" +
						"\"FileType\":" +    0xff  + "," + "\n" +
						"\"Locked\":"   +    0 	  + "," + "\n" +
						"\"CardNo\":"   +    0 	  + "," + "\n" +
						"\"CardSerailNo\":"+ "\"202210255255\""      + "," + "\n" +
						"\"StartTime\":{" + "\n" +
						     "\"Year\":"  + startyear  + "," + "\n" +
						     "\"Month\":" + startmonth + "," + "\n" +
						     "\"Day\":"   + startday   + "," + "\n" +
						     "\"Hour\":"  + starthour  + "," + "\n" +
						     "\"Minute\":"+ startmin   + "," + "\n" +
						     "\"Second\":"+ startsec   + ""  + "\n" +
						"}," + "\n" +
						"\"StopTime\":{" + "\n" +
						     "\"Year\":"  + endyear    + "," + "\n" +
						     "\"Month\":" + endmonth   + "," + "\n" +
						     "\"Day\":"   + endday     + "," + "\n" +
						     "\"Hour\":"  + endhour    + "," + "\n" +
						     "\"Minute\":"+ endmin     + "," + "\n" +
						     "\"Second\":"+ endsec     + ""  + "\n" +
					     "}" + "\n" +
					"}"	+ "\n" +
			"}";						
	       
			final  ProgressDialog dialog = new ProgressDialog(QueryRemoteFile.this);
			dialog.setMessage("正在检索文件,请稍后...");
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
							 
							// TODO Auto-generated method stub
							try {
								FindFileId = Start(nUserid, FindCondString);
								Thread.sleep(3000);
							} catch (Exception e) {
								e.printStackTrace();
							}

							String jsonstatus = "";
							 
							QueryResult.clear();
							do {
								QueryResultString = GetFile(FindFileId);
//							
								try {
									jsonstatus = new JSONObject(QueryResultString).getString("ResultCode");
								} catch (JSONException e) {
									// TODO Auto-generated catch block
									e.printStackTrace();
								}  
								
								if(jsonstatus.equals("1000"))//获得文件信息	
								{
									try {
										ResultContent = new JSONObject(QueryResultString).getString("ResultContent");
										filename = new JSONObject(ResultContent).getString("FileName");
									} catch (JSONException e) {
										// TODO Auto-generated catch block
										e.printStackTrace();
									}	
																				
									QueryResult.add(filename);
								}
								
							} while (!jsonstatus.equals("1003"));//1003查找文件时没有更多的文件
							
					        dialog.dismiss();
					        if (QueryResult.size() != 0) {
						        HandleData.removeDuplicateAndSort(QueryResult);
						        timeRuler.drawRecArea(QueryResult);
						        isQuery = true;
							}else {
								Toast.makeText(QueryRemoteFile.this, "没有查询到录像文件！",
										Toast.LENGTH_SHORT).show();
								QueryResult.clear();
								timeRuler.drawRecArea(QueryResult);
							}  
						}
					});
				}
			});		
	}
	
}
