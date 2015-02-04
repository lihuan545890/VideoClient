package com.Activity;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.Executors;

import com.BLL.EListAdapter;
import com.BLL.Group;
import com.Utility.DataDefine;
import com.Utility.SysApplication;
import com.Utility.UseServer;
import com.example.minicontroller.R;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.app.Service;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Color;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.Vibrator;
import android.util.Log;
import android.view.ViewGroup;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.PagerTabStrip;
import android.support.v4.view.ViewPager;
import android.support.v4.view.ViewPager.OnPageChangeListener;
import android.view.Display;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.ExpandableListView.OnGroupClickListener;
import android.widget.GridView;
import android.widget.LinearLayout.LayoutParams;
import android.widget.ListAdapter;
import android.widget.PopupWindow;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.Toast;
import android.view.View.OnClickListener;


public class RemoteControl extends Activity {
	 
	//jni接口
	private static final String TAG = null;
	public native boolean  Init();
	public native boolean  Cleanup();
	public native String   Login(String ip,int port,String Username,String PSW);
	public native boolean  Logout(int uid);
	public native String   GetLastError();
	public native boolean  Send(int UserId,int Command,byte[] para,int Size);
	public native boolean  SendV2(int UserId,int Command,int para);

 	private SQLiteDatabase devDatabase;
	public Cursor cursor;
	public String szIP = "192.168.0.51";
	public int nPort = 5050;
	public String szUsername = "admin";
	public String szPsw = "";
	public int nUserid = 0;
	public int ChanNum = 0;
	public int PressNum=0;
	 
	AlertDialog.Builder builder; 
	
	private Vibrator mVibrator; 
	private Boolean State = false; //表示按下/-- 键
	
	//按键声明
	private Button btn0;//按键0
	private Button btn1;//按键1
	private Button btn2;//按键2
	private Button btn3;//按键3
	private Button btn4;//按键4
	private Button btn5;//按键5
	private Button btn6;//按键6
	private Button btn7;//按键7
	private Button btn8;//按键8
	private Button btn9;//按键9
	
	private Button btnmult;//按键
	private Button btnalarm;//按键
	private Button btnmultidigital;//按键
	private Button btnrec;//按键
	private Button btnfn;//按键
	private Button btnesc;//按键
	
	private Button btnup;//按键上
	private Button btnleft;//按键左
	private Button btnmenu;//按键menu
	private Button btnright;//按键右
	private Button btndown;//按键下
	
	private Button btnplay;//
	private Button btnstop;//
	private Button btnplayfast;//
	private Button btnplayslow;//
	private Button btnplayfoward;//
	private Button btnplayback;//
 
	private Button menuBtn;
	private Button chooseBtn;
	
	private TextView remoteCtrlTitle;
	private View view1;
	private View view2;
	private List<View> viewList;
	private ViewPager viewPager;
	private PagerTabStrip pagerTabStrip;
	
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
    private EListAdapter adapter; 
    private int	screenWidth;
    private int	screenHeight;  
	
	public void onCreate(Bundle savedInstanceState){   
        super.onCreate(savedInstanceState);
		setContentView(R.layout.remotectrl);  
		SysApplication.getInstance().addActivity(this); 
		

		remoteCtrlTitle = (TextView)findViewById(R.id.remoteCtrl_Title);
		viewPager = (ViewPager)findViewById(R.id.viewpager);
		viewPager.setCurrentItem(0);
		
		view1 = (View)findViewById(R.layout.layout1);
		view2 = (View)findViewById(R.layout.layout2); 
		
        SysApplication.getInstance().addActivity(this);
		Display localDisplay = getWindowManager().getDefaultDisplay();
		screenWidth  = localDisplay.getWidth();
		screenHeight = localDisplay.getHeight();
		float rate = (float) screenWidth/320;
		
		@SuppressWarnings("static-access")   
		LayoutInflater lf = getLayoutInflater().from(this);
		view1 = lf.inflate(R.layout.layout1, null);
		view2 = lf.inflate(R.layout.layout2, null);		
 		
		btn0 = (Button)view1.findViewById(R.id.btn0);
		btn1 = (Button)view1.findViewById(R.id.btn1);
		btn2 = (Button)view1.findViewById(R.id.btn2);
		btn3 = (Button)view1.findViewById(R.id.btn3);
		btn4 = (Button)view1.findViewById(R.id.btn4);
		btn5 = (Button)view1.findViewById(R.id.btn5);
		btn6 = (Button)view1.findViewById(R.id.btn6);
		btn7 = (Button)view1.findViewById(R.id.btn7);
		btn8 = (Button)view1.findViewById(R.id.btn8);
		btn9 = (Button)view1.findViewById(R.id.btn9);
		
		btnmult = (Button)view1.findViewById(R.id.btnMult);//
		btnrec = (Button)view1.findViewById(R.id.btnRec);
		btnfn = (Button)view1.findViewById(R.id.btnFN);
		btnmultidigital = (Button)view1.findViewById(R.id.btnMultiDigital);	
		btnalarm = (Button)view1.findViewById(R.id.btnAlarm);
		btnesc   = (Button)view1.findViewById(R.id.btnESC);	
		
		if (screenWidth > 1000) { //针对大于1000的高分辨率手机
			remoteCtrlTitle.setTextSize(6*rate);
			btn0.setTextSize(6*rate);
			btn1.setTextSize(6*rate);
			btn2.setTextSize(6*rate);
			btn3.setTextSize(6*rate);
			btn4.setTextSize(6*rate);
			btn5.setTextSize(6*rate);
			btn6.setTextSize(6*rate);
			btn7.setTextSize(6*rate);
			btn8.setTextSize(6*rate);
			btn9.setTextSize(6*rate);
			btnmult.setTextSize(6*rate);
			btnrec.setTextSize(6*rate);
			btnfn.setTextSize(6*rate);
			btnmultidigital.setTextSize(6*rate);
			btnalarm.setTextSize(6*rate);
			btnesc.setTextSize(6*rate);
		}else {  
			remoteCtrlTitle.setTextSize(10*rate);
			btn0.setTextSize(10*rate);
			btn1.setTextSize(10*rate);
			btn2.setTextSize(10*rate);
			btn3.setTextSize(10*rate);
			btn4.setTextSize(10*rate);
			btn5.setTextSize(10*rate);
			btn6.setTextSize(10*rate);
			btn7.setTextSize(10*rate);
			btn8.setTextSize(10*rate);
			btn9.setTextSize(10*rate);
			btnmult.setTextSize(10*rate);
			btnrec.setTextSize(10*rate);
			btnfn.setTextSize(10*rate);
			btnmultidigital.setTextSize(10*rate);
			btnalarm.setTextSize(10*rate);
			btnesc.setTextSize(10*rate);
		}		
		

		
		btnup 	 = (Button)findViewById(R.id.btnUP);
		btndown  = (Button)findViewById(R.id.btn_DOWN);
		btnleft  = (Button)findViewById(R.id.btnLEFT);
		btnright = (Button)findViewById(R.id.btn_RIGHT);	
		btnmenu  = (Button)findViewById(R.id.btn_MENU);
 		
		btnplay = (Button)view2.findViewById(R.id.btnPlay);
		btnstop = (Button)view2.findViewById(R.id.btnStop);
		btnplayfast = (Button)view2.findViewById(R.id.btnPlayFast);
		btnplayslow = (Button)view2.findViewById(R.id.btnPlaySlow);
		btnplayback = (Button)view2.findViewById(R.id.btnPlayBack);
		btnplayfoward = (Button)view2.findViewById(R.id.btnPlayFoward);
		
		viewList = new ArrayList<View>();
		viewList.add(view1);
		viewList.add(view2);	
		
 		
		viewPager.setAdapter(new MyPagerAdapter(viewList));
		
		viewPager.setOnPageChangeListener(new OnPageChangeListener() {
			
			@Override
			public void onPageSelected(int arg0) {
				viewPager.setCurrentItem(arg0);
			}
			
			@Override
			public void onPageScrolled(int arg0, float arg1, int arg2) {
			}
			
			@Override
			public void onPageScrollStateChanged(int arg0) {
				
			}
		});
		
		chooseBtn = (Button)findViewById(R.id.chooseDev_ctrl);
		chooseBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				CreateDeviceDialog();
				deviceDialog.show();
			}
		});
		
		menuBtn = (Button)findViewById(R.id.menu_ctrl);
		menuBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
//				finish();
				showController();
			}
		});
		
		btn0.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_0,true);
			} 	 
		});
  
		btn1.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_1,true);				
			} 	
		});
 
		btn2.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_2,true); 
			} 	
		});

		btn3.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {			
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_3,true);		
			} 	
		});

		btn4.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_4,true);
			} 	
		});

		btn5.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_5,true);
			} 	
		});

		btn6.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
			 
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_6,true);
			} 	
		});

		btn7.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_7,true);
			} 	
		});

		btn8.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_8,true);
			} 	
		});

		btn9.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_9,true);
			} 	
		});
		
		btnalarm.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
 				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_AlarmShow,true);
			} 	
		});
		
		//多位数显示
		btnmultidigital.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				if(!State){
					v.setBackgroundResource(R.drawable.ctrl_pressed);
					State = true;
					Log.i("State", ""+State);
				}else {
					v.setBackgroundResource(R.drawable.ctrl); 
					State =false;
					Log.i("State", ""+State);
				}
			}
		});		
		
		btnup.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {		
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Up,true);
			} 	
		});
	 
		btndown.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {		
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Down,true);
			} 	
		});

		btnleft.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {	
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Left,true);	
			} 	
		});

		btnright.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Right,true);
			} 	
		});		
		
		btnmenu.setOnTouchListener(new OnTouchListener(){

				@Override
				public boolean onTouch(View v, MotionEvent event) {
					// TODO Auto-generated method stub
					if(event.getAction() == MotionEvent.ACTION_UP){
						HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_EnterRelease,true);
					}
					else if(event.getAction() == MotionEvent.ACTION_DOWN){
						HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Enter,false);
					}
					return false;
				}				
		 });
		 

		btnesc.setOnClickListener(new OnClickListener(){ 
			
			@Override
			public void onClick(View v) {	
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Escape,true);
			} 	
		});
		
		btnmult.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {	
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Multi,true);
			} 	
		});
		
		 
		btnrec.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Record,true);
			} 	
		});
		
		btnfn.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {	
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_PTZ,true);
			} 	
		});
 
		btnplay.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {	
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_Play,true);	
			} 	
		});

		btnstop.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_PlayStop,true);
			} 	
		});

		btnplayfast.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_PlayFast,true);
			} 	
		});

		btnplayslow.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {	
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_PlaySlow,true);
			} 	
		});

		btnplayfoward.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_PlayFoward,true);
			} 	
		});

		btnplayback.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				HandleRemoteCtlOrder(com.Utility.DataDefine.I8Key_PlayBack,true);
			} 	
		});
		
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
    			
    			String DevType = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_DEVICETYPE));
    			
    			String Ip       = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_LOCALIP)); 
    			int    Port     = Integer.parseInt(cursor.getString(cursor.getColumnIndex(DataDefine.KEY_PORT)));
    			String UserName = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_USERNAME));
    			String PassWord = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_PASSWORD));
    			String DeviceType = DevType.substring(0, 3);
    			
    			if (!UserName.equals("")){
        			Group  group = new Group(Ip, Port, UserName, PassWord, DeviceType);
        			if (!DeviceType.equals("IPC")) {
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
		viewlist = RemoteControl.this.getLayoutInflater().inflate(R.layout.remote_choose, null);
		deviceDialog = new Dialog(RemoteControl.this);
		deviceDialog.setTitle("设备列表");
		deviceDialog.setContentView(viewlist);
		
		expandList = (ExpandableListView)viewlist.findViewById(R.id.explistView1);
		groups = new ArrayList<Group>();  
		readData(); 
        adapter = new EListAdapter(RemoteControl.this, groups);
        expandList.setAdapter(adapter);
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
				
				InitiaRemotePara();
				
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
					Intent intent0 = new Intent(RemoteControl.this, PTZControl.class);
					startActivity(intent0);	
					break;
				case 1:
					Intent intent1 = new Intent(RemoteControl.this, QueryRemoteFile.class);
					startActivity(intent1);		
					break;
				case 2:
//					Intent intent2 = new Intent(RemoteControl.this, RemoteControl.class);
//					startActivity(intent2);	
					menuController.dismiss();
					break;
				case 3:
					Intent intent3 = new Intent(RemoteControl.this, Discovery.class);
					startActivity(intent3);		
					break;
				case 4:
					Intent intent4 = new Intent(RemoteControl.this, ImagesManage.class);
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
	
	private Handler handler = new Handler();	
	
	private void GetDevicesInfo() {
		final  ProgressDialog dialog = new ProgressDialog(RemoteControl.this);
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
 						 
						InitiaRemotePara();		
 
				        dialog.dismiss();
					}
				});
			}
		});
	
	}
	
	@SuppressLint("HandlerLeak")
	private void HandleRemoteDate() {
		// 判断是否弹出要求输入云服务密码
		final ProgressDialog mProgress ;
		mProgress=ProgressDialog.show(RemoteControl.this,"", "登录设备,请稍候...");
		new Thread() { // 开启一个线程 
			public void run() {
				 
					try {
						 
						InitiaRemotePara();
					} finally {
						mProgress.dismiss();
					}
 				 
				Log.i("注册状态","自线程");
 			}
		}.start();
	}
	
	@SuppressLint("HandlerLeak")
	Handler RemoteDate = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			HandleRemoteDate();
		}

	};
	
	
//	@Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		
		if(nUserid > 0)
		{		
			Logout(nUserid);
			Cleanup();
		}
		super.onDestroy();
		Log.i(TAG, "=============>onDestroy");
	}
 	
	protected void onResume(){
		super.onResume();
		 		
	    System.loadLibrary("i8_net_sdk");
	}
	
	//处理参数传递
	public void InitiaRemotePara()
	{
		int Uid = 0;
		
		if(!Init())
		{
			Toast.makeText(RemoteControl.this, "设备初始化失败！",
					Toast.LENGTH_SHORT).show();
			remoteCtrlTitle.setText(R.string.remotectrl);
		}	
		
		String LoginContent = Login(szIP,nPort,szUsername,szPsw);
		Log.i("LoginContent", LoginContent);
		
		if(LoginContent.length() >0)
		{
			Uid = com.BLL.HandleLogin.GetUserId(LoginContent);
		}else
		{
			remoteCtrlTitle.setText(R.string.remotectrl);
			Toast.makeText(RemoteControl.this, "登录设备失败！",
					Toast.LENGTH_SHORT).show();
		}
		
		if(Uid >0){
			nUserid = Uid;
			
			remoteCtrlTitle.setText(szIP);
		}else
		{
			remoteCtrlTitle.setText(R.string.remotectrl);
			Toast.makeText(RemoteControl.this, "登录设备失败！",
					Toast.LENGTH_SHORT).show();
		}
	}
	
	 
	
	//处理远程指令
	public void HandleRemoteCtlOrder(int key,boolean isVib){	
		
		if(!UseServer.isWifiConnected(this))
		{
			Toast.makeText(RemoteControl.this, "网络出错啦！！",
					Toast.LENGTH_SHORT).show();
			return; 
		}		
		
		if (key != com.Utility.DataDefine.I8Key_EnterRelease) {
			if(nUserid <= 0)
			{
				builder = new AlertDialog.Builder(this);
				builder.setTitle(R.string.alerttitle);
			    builder.setIcon(android.R.drawable.ic_dialog_info);
			    builder.setPositiveButton(R.string.okLabel,new DialogInterface.OnClickListener()
			    {

					@Override
					public void onClick(DialogInterface dialog, int which) {
						// TODO Auto-generated method stub
						dialog.dismiss();
					}
			    	
			    });
			    builder.show();
			}
		}
		
		if(State)
		{
			if(PressNum == 0)
			{				
				PressNum = key;
				mVibrator = ( Vibrator ) getApplication().getSystemService(Service.VIBRATOR_SERVICE);  
				mVibrator.vibrate( new long[]{10, 100},-1);  
				return;

			}else
			{
				key = PressNum*10+key;
				PressNum = 0;
				}
		} 
		
		Log.i("key", ""+key);
		
		byte[] para = int2byte(key);
	
		if(!Send(nUserid,DataDefine.Command,para,4))
		{
			Toast.makeText(RemoteControl.this, "操作失败",
					Toast.LENGTH_SHORT).show();
			return;
			
		}
		else
		{
			if(isVib){
				mVibrator = ( Vibrator ) getApplication().getSystemService(Service.VIBRATOR_SERVICE);  
				mVibrator.vibrate( new long[]{10, 100},-1);  
			}
		}				
						

	}
	
	public static byte[] int2byte(int res) {
		byte[] targets = new byte[4];

		targets[0] = (byte) (res & 0xff);// 最低位 
		targets[1] = (byte) ((res >> 8) & 0xff);// 次低位 
		targets[2] = (byte) ((res >> 16) & 0xff);// 次高位 
		targets[3] = (byte) (res >>> 24);// 最高位,无符号右移。 
		return targets; 
		} 
	 
		  public class MyPagerAdapter extends PagerAdapter{
			private List<View> mListViews;
			
			public MyPagerAdapter(List<View> mListViews) {
				this.mListViews = mListViews;
			}
			@Override
			public boolean isViewFromObject(View arg0, Object arg1) {
				return arg0 == arg1;
			}
			
			@Override
			public int getCount() {
				return mListViews.size();
			}
			
			@Override
			 public void destroyItem(ViewGroup container, int position,
			         Object object) {
				container.removeView(mListViews.get(position));
			}				 
	
			@Override
			public int getItemPosition(Object object) {
				return super.getItemPosition(object);
			}
			
			@Override
			public Object instantiateItem(ViewGroup container, int position) {
				 container.addView(mListViews.get(position), 0);
				 return mListViews.get(position);
			}
			@Override
			public CharSequence getPageTitle(int position) {
				return null;
			}
			
		};	

}
