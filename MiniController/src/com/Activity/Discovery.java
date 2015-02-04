package com.Activity;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.Executors;
import org.json.JSONException;


import android.R.integer;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Bundle;
import android.os.Handler;
import android.view.ContextMenu;
import android.view.Display;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnCreateContextMenuListener;
import android.app.AlertDialog;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemLongClickListener;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.GridView;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.LinearLayout.LayoutParams;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.PopupWindow;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.AdapterView.OnItemClickListener;
import android.util.Log;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Color;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.view.ViewGroup;
import android.view.ContextMenu.ContextMenuInfo;

import com.example.minicontroller.R;
import com.Utility.DataDefine;
import com.Utility.SysApplication;
import com.BLL.HandleSearchList;

public class Discovery extends Activity { 

	public native boolean  Init();
	public native boolean  Start();
	public native boolean  Stop();
	public native int  	   GetCount();
	public native String   GetAllDevices(); 
	 
	private final static String TAG = "Discovery";
	private static int j = 0;    
	
    private Button searchButton;
    private TextView deviceTitle;
    private Button menuBtn;   
	private ListView listView;   
	private HashMap<String, Object> map; 
	private SimpleAdapter listItemAdapter; 
	private MyAdapter cursorAdapter; 
	private Handler handler = new Handler();	  
	private SQLiteDatabase devDatabase;
	public  Cursor cursor; 
	private ImageView imageView;
	private ContentValues values;  
	private String option;
	
	List<HashMap<String, Object>> listItem = new ArrayList<HashMap<String, Object>>();  
	  
	private View 		   menuControlView = null;
	private PopupWindow    menuController = null;
	private GridView 	   menuGrid;
	private LinearLayout   listLayout;
	private boolean        isControllerShow = true;	
	private int			   screenWidth, screenHeight;
	
	private String[] menu_name_array = {"远程预览", "远程回放", "远程控制", "设备管理","图像管理"};
	int[] menu_image_array = { R.drawable.menu_preview,
			R.drawable.menu_playback, R.drawable.menu_control,
			R.drawable.menu_devicemanage,R.drawable.menu_test};	
	
	public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.device);  
        SysApplication.getInstance().addActivity(this); 
		Display localDisplay = getWindowManager().getDefaultDisplay(); 
		screenWidth  = localDisplay.getWidth();
		screenHeight = localDisplay.getHeight();        
        
    	listView = (ListView) findViewById(R.id.listView);
    	menuBtn = (Button)findViewById(R.id.menu_search);
    	deviceTitle = (TextView)findViewById(R.id.title_device);
    	searchButton = (Button)findViewById(R.id.searchButton);    	
    	imageView = (ImageView)findViewById(R.id.moreinfo);
    	
    	devDatabase = openOrCreateDatabase(DataDefine.DBNAME, SQLiteDatabase.CREATE_IF_NECESSARY, null);
		devDatabase.execSQL(DataDefine.CREATE_TABLE_DEVIDE);
    	
    	InitView();  
    	
	    menuBtn.setOnClickListener(new OnClickListener() {
			
			@Override 
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				showController();
			}
		});
    	
    	searchButton.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				if(!isWifiConnected(Discovery.this)){ //判断手机wifi是否打开，若打开可进行搜索操作，没打开的话先打开wifi
					WifiSet();
				}else {	
					GetDevices();
				}
			}
		});
    	
    	listView.setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
					long arg3) {
                  TextView showNameTextView = (TextView)arg1.findViewById(R.id.ShowName);
                  TextView idTextView = (TextView)arg1.findViewById(R.id.ID);
                  TextView userNameTextView = (TextView)arg1.findViewById(R.id.DevUserName);
                  
                  final	String showName = showNameTextView.getText().toString().trim();
                  final String id = idTextView.getText().toString().trim();
                  String userName = userNameTextView.getText().toString().trim();
                   
                  if (userName.equals("")) {
                      new AlertDialog.Builder(Discovery.this) 
                      .setTitle("请输入用户名和密码！")
                      .setPositiveButton("确定", new DialogInterface.OnClickListener() {
                          public void onClick(DialogInterface dialog, int which) {
        					  Intent intent = new Intent(Discovery.this,DevInfoActivity.class);
        					  intent.putExtra("option", "0");  
        					  intent.putExtra("id",id);
        					  startActivity(intent);                        	  
                          }
                      })
				      .setNegativeButton("取消", new DialogInterface.OnClickListener() {
							
				    	  @Override
					   public void onClick(DialogInterface dialog, int which) {
								// TODO Auto-generated method stub
							dialog.dismiss();
						}
					 })
				     .show();		
				} else {
//					  Intent intent = new Intent(Discovery.this,DevCtrActivity.class);
//					  intent.putExtra("showName", showName);  
//					  intent.putExtra("id",id);
//					  startActivity(intent);
				}

			}

		});
    	
    	listView.setOnCreateContextMenuListener(new OnCreateContextMenuListener() {
			
			@Override
			public void onCreateContextMenu(ContextMenu menu, View v,
					ContextMenuInfo menuInfo) {
				// TODO Auto-generated method stub
				menu.setHeaderTitle("操作");
                menu.add(0, 0, 0, "添加"); 
                menu.add(0, 1, 0, "删除"); 	
			}
		});
    	
    }

	static{
		System.loadLibrary("i8_netsdk");
		System.loadLibrary("i8_net_sdk");
	}
	
    public boolean onContextItemSelected(MenuItem item) { 

        AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) item 
                        .getMenuInfo(); 

        switch (item.getItemId()) { 
        case 0: 
                // 添加操作 
        		addData();
                break; 

        case 1: 
                // 删除操作 
        		String id = ((TextView)info.targetView.findViewById(R.id.ID))
        					.getText().toString();
        		long ID = Integer.valueOf(id).longValue();
				deleteData(ID);
				InitView();
                break; 
                
        default: 
                break; 
        } 

        return super.onContextItemSelected(item); 
    }     		
	
	
	@Override
	protected void onResume() {
		super.onResume();	
		 Log.i(TAG, "=============>onResume");
		 InitView();
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();	
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
		menuGrid.requestFocus();
		menuGrid.setSelector(new ColorDrawable(Color.TRANSPARENT));
		menuGrid.setOnItemClickListener(new OnItemClickListener() {

			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
					long arg3) {
				// TODO Auto-generated method stub
				switch (arg2) {
				case 0:
					Intent intent0 = new Intent(Discovery.this, PTZControl.class);
					startActivity(intent0);	
					break;
				case 1:
					Intent intent1 = new Intent(Discovery.this, QueryRemoteFile.class);
					startActivity(intent1);		
					break;
				case 2:
					Intent intent2 = new Intent(Discovery.this, RemoteControl.class);
					startActivity(intent2);	
					break;
				case 3:
					menuController.dismiss();	
					break;
				case 4:
					Intent intent4 = new Intent(Discovery.this, ImagesManage.class);
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

    private void clearAll(){ 

        new AlertDialog.Builder(this) 
        .setTitle("确认要删除所有吗？")
        .setPositiveButton("确定", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int which) {
				devDatabase.delete(DataDefine.TABLE_DEVIDE, null, null);
				cursor = devDatabase.query(DataDefine.TABLE_DEVIDE,null,null, null, null, null, null);	
		        cursorAdapter = new MyAdapter(cursor,Discovery.this);
		        listView.setAdapter(cursorAdapter); 
            }
        })
        .setNegativeButton("取消", new DialogInterface.OnClickListener() {
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				dialog.dismiss();
			}
		})
        .show(); 
}    
    
    
    private void deleteData(long rowId){ 
       String[] str = {String.valueOf(rowId)};              
       devDatabase.delete(DataDefine.TABLE_DEVIDE,"_id=?",str); 
    } 
    
    private void addData(){
		  Intent intent = new Intent(Discovery.this,DevInfoActivity.class);
		  intent.putExtra("option", "1"); 
		  intent.putExtra("ip", ""); 
		  intent.putExtra("port", ""); 
		  intent.putExtra("username", ""); 
		  intent.putExtra("passwd", "");
		  intent.putExtra("id", "");

		  startActivity(intent);    	  	
    }
    
	private void GetDevices() {
		final  ProgressDialog dialog = new ProgressDialog(Discovery.this);
		dialog.setMessage("正在搜索设备,请稍后...");
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
						System.out.println("开始查询");				
						boolean Result = Init();
						Result = Start();
						
						
						
//						String str = I8_NET_DVR_GetAllIPCContent();
//						System.out.println("开始结果"+str);
				//		System.out.println("Result:"+Result);
						String str = GetAllDevices(); //获取所有设备信息，设备信息以json格式返回
						Result = Stop();
						HandleSearchList list = new HandleSearchList(); 
						try {
							devDatabase.delete(DataDefine.TABLE_DEVIDE, null, null);
							list.HandleQuertyList(str, devDatabase);//设备信息入库排序操作
						} catch (JSONException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();  
						} 					
						
						cursor = devDatabase.query(DataDefine.TABLE_DEVIDE,null,null, null, null, null, null);	
						
				        cursorAdapter = new MyAdapter(cursor,Discovery.this);
				        listView.setAdapter(cursorAdapter); 
				        
				        dialog.dismiss();
					} 
				});
			}
		});
	
	}

	void InitView()
	{
		float rate = (float) screenWidth/320;
		if (screenWidth > 1000) {
			deviceTitle.setTextSize(6*rate);
		}else {  
			deviceTitle.setTextSize(10*rate);
		}
		cursor = devDatabase.query(DataDefine.TABLE_DEVIDE,null,null, null, null, null, null);	
        cursorAdapter = new MyAdapter(cursor, Discovery.this);
        listView.setAdapter(cursorAdapter);    
        
	}
	
	public class MyAdapter extends BaseAdapter{
		private Cursor cursor;
		private LayoutInflater mInflater;
		private ViewHolder holder;
		private Context    context;
		
		public MyAdapter(Cursor c, Context context){
					super();
					this.context = context;
					this.cursor = c;	
					mInflater = LayoutInflater.from(context);
			    }
		@Override
		public int getCount(){
			return cursor.getCount();
		}
		
		@Override
		public Object getItem(int position){
			return position;
		}
		
		@Override
		public long getItemId(int position){
			return position;
		}

	    public View getView(int position, View convertView, ViewGroup parent){
	 	   ViewHolder holder = null;
	 	   View view;

	 	   if (convertView==null) {
	 		    holder = new ViewHolder(); 
	 		    convertView  = mInflater.inflate(
	 		      R.layout.list_items, null);
	 		    
	 		    listLayout = (LinearLayout) convertView.findViewById(R.id.listLayout);
	 		    
	 		    holder.device = (ImageView) convertView
	 		      .findViewById(R.id.Device);
	 		    holder.showName = (TextView) convertView
	 		      .findViewById(R.id.ShowName);
	 		    holder.devtype = (TextView) convertView
	 		 	  .findViewById(R.id.DevType);	
	 		    holder.devport = (TextView) convertView
	 		      .findViewById(R.id.DevPort);		
	 		    holder.moreinfo = (ImageView) convertView
	 		      .findViewById(R.id.moreinfo);
	 		    holder.id = (TextView) convertView
	 		 	  .findViewById(R.id.ID); 
	 		    holder.username = (TextView) convertView
	 		      .findViewById(R.id.DevUserName);		
	 		      convertView.setTag(holder);
	 		      
	 		   }else{ 
	 			   holder = (ViewHolder)convertView.getTag();	 	
	 		   }	 

	       cursor.moveToPosition(position);
//	       listLayout.setLayoutParams(new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, 80));
	 	   final String Id = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_DEV_ID_AUTO_INCREMENT));    
	 	   String Ip= cursor.getString(cursor.getColumnIndex(DataDefine.KEY_LOCALIP));    
	 	   String ShowName= cursor.getString(cursor.getColumnIndex(DataDefine.KEY_SHOWNAME));
	 	   String devType = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_DEVICETYPE));
	 	   String devPort = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_PORT));
	 	   String devUserName = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_USERNAME));
	 	   final  String serial = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_SERIALNO));
	 	   
	 	  String DeviceType = devType.substring(0, 3);
	// 	  System.out.println("DeviceType: "+DeviceType);
	 	  
//	 	  if (DeviceType.equals("IPC")) {
//	 		 holder.device.setBackgroundResource(R.drawable.device);
//		  }else {
//			 holder.device.setBackgroundResource(R.drawable.device_nvr); 
//		  }
			 
		  holder.device.setBackgroundResource(R.drawable.device_nvr); 	 
			 
	 	   if (iStr(ShowName)) {
	 		  holder.showName.setText(ShowName);
	 	   } else {
	 		  holder.showName.setText(Ip);
	 	   }	
	 	   
	 	   holder.id.setText(Id);
	 	   holder.devtype.setText(devType);
	 	   holder.devport.setText(devPort);
	 	   holder.username.setText(devUserName);
	 	   
	 	   holder.moreinfo.setOnClickListener(new View.OnClickListener() {
				
				@Override
				public void onClick(View arg0) {
					// TODO Auto-generated method stub

					  Intent intent = new Intent(Discovery.this,DevInfoActivity.class);
					  intent.putExtra("option", "0"); 
					  intent.putExtra("id", Id);
					  startActivity(intent);
				}
			}); 
	 	    
	 	   return convertView;	    	   
	 }	

	}
	
	public class ViewHolder{
		public ImageView device;
		public TextView showName;
		public TextView id;
		public TextView username;
		public TextView devtype;
		public TextView devport;
		public ImageView moreinfo;
	}	
	
	 static 
	 {		
	        System.loadLibrary("i8_net_sdk");
	 }
	
    public static boolean isWifiConnected(Context context)
    {
        ConnectivityManager connectivityManager = (ConnectivityManager)context.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo wifiNetworkInfo = connectivityManager.getNetworkInfo(ConnectivityManager.TYPE_WIFI);
        if(wifiNetworkInfo.isConnected())
        {
            return true ;
        }
     
        return false ;
    }	 
	 
    public void WifiSet(){
        new AlertDialog.Builder(this) 
        .setTitle("Wifi尚未连接，确认打开Wifi？")
        .setPositiveButton("确认", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int which) {
				Intent intent = new Intent(android.provider.Settings.ACTION_WIRELESS_SETTINGS);
				startActivity(intent);
            }
        })
        .setNegativeButton("取消", new DialogInterface.OnClickListener() {
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				dialog.dismiss();
			}
		})
        .show();     	
    	
    }
    
    public static boolean iStr(String str) {

        if (!"".equals(str) && null != str) return true;

        return false;   
    }



}
