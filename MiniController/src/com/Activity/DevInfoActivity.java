package com.Activity;


import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import com.Utility.DataDefine;
import com.Utility.SysApplication;
import com.example.minicontroller.R;


import android.R.integer;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.ContentValues;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.Display;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RadioGroup.OnCheckedChangeListener;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;



public class DevInfoActivity extends Activity {
	
	private TextView devinfoTitle;
	private Button saveBtn;
	private Button cancelBtn;
	private EditText devName; //设备名
	private EditText devIP;	//设备IP
	private EditText devPort; //设备端口
	private EditText devUserName; //用户名
	private EditText devPasswd; //密码
	private	EditText channelNo; //通道数
	private RadioGroup devTypeRg; //设备类型组
	private String   devType="NVR";
	private ContentValues values;
	private SQLiteDatabase devDatabase;
	private Cursor Result;

	private RadioButton NVR;
	private RadioButton DVR;
	private RadioButton IPC;
	
	private String option;
	private String id;
	
	private int screenWidth;
	private int screenHeight;
	
	public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);		
		setContentView(R.layout.devinfo);

        SysApplication.getInstance().addActivity(this);
		Display localDisplay = getWindowManager().getDefaultDisplay();
		screenWidth  = localDisplay.getWidth();  
		screenHeight = localDisplay.getHeight();
		
		devinfoTitle= (TextView)findViewById(R.id.title_devinfo);
		saveBtn     = (Button)findViewById(R.id.savebtn);
		cancelBtn   = (Button)findViewById(R.id.cancelbtn);
 
		devName     = (EditText)findViewById(R.id.devnameEditText);
		devIP       = (EditText)findViewById(R.id.devIpEditText);
		devPort     = (EditText)findViewById(R.id.devPortEditText);
		devUserName = (EditText)findViewById(R.id.devUserEditText);
		devPasswd   = (EditText)findViewById(R.id.devPasswdEditText);
		channelNo   = (EditText)findViewById(R.id.channelNo);	
		devTypeRg	= (RadioGroup)findViewById(R.id.devtypeRadioGroup);
		NVR			= (RadioButton)findViewById(R.id.nvr);
		DVR			= (RadioButton)findViewById(R.id.dvr);
		IPC			= (RadioButton)findViewById(R.id.ipc);
		
		InitData();
        
        if("".equals(devIP.getText().toString().trim())){
        	devIP.setFocusable(true);
        }else {
			devIP.setFocusable(false);
		}        
         
//        if("".equals(devType.getText().toString().trim())){
//        	devType.setFocusable(true);
//        }else {
//        	devType.setFocusable(false);
//		} 
		float rate = (float) screenWidth/320;
        
		if (screenWidth > 1000) {
			devinfoTitle.setTextSize(6*rate);
		}else {  
			devinfoTitle.setTextSize(10*rate);
		}
        
        if("".equals(channelNo.getText().toString().trim())){
        	channelNo.setFocusable(true);
        }else {
        	channelNo.setFocusable(false);
		}     
        
        devTypeRg.setOnCheckedChangeListener(new OnCheckedChangeListener() {
			
			@Override
			public void onCheckedChanged(RadioGroup group, int checkedId) {
				// TODO Auto-generated method stub
				if (checkedId == NVR.getId()) {
					NVR.setChecked(true);
					devType = "NVR";
				}else if (checkedId == DVR.getId()) {
					DVR.setChecked(true);
					devType = "DVR";
				}else if (checkedId == IPC.getId()) {
					IPC.setChecked(true);
					devType = "IPC";
				}
			}
		});
        
		saveBtn.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				AddorModify();
			}
		});
		
		cancelBtn.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				finish();
			}
		});
	
	}
	
	protected void onDestroy() {  
	    super.onDestroy();  
	    if (devDatabase  != null) {  
	    	devDatabase.close();  
	    }  
	}	
	
	private void InitData(){
		Bundle bundle = this.getIntent().getExtras();		
		
        option = bundle.getString("option");
        id = bundle.getString("id"); //获取id  		
        
        switch (Integer.parseInt(option)) {
		case 0:
			moreData(id);
			break;

		case 1:	
			addData();
			break;
		default:
			break;
		}
		
	}
	
	private void moreData(String id){
		String selectionArgs[]={id};
		String select = DataDefine.KEY_DEV_ID_AUTO_INCREMENT + "=?";
		String otherInfo[] = {DataDefine.KEY_SHOWNAME,DataDefine.KEY_DEVICETYPE, DataDefine.KEY_LOCALIP,DataDefine.KEY_PORT,DataDefine.KEY_USERNAME,DataDefine.KEY_PASSWORD,DataDefine.KEY_CHANNELNO};
		devDatabase= openOrCreateDatabase(DataDefine.DBNAME, SQLiteDatabase.CREATE_IF_NECESSARY, null);
		Result = devDatabase.query(DataDefine.TABLE_DEVIDE,otherInfo,select, selectionArgs, null, null, null);	
		Result.moveToFirst();
		
	    String showname  = Result.getString(Result.getColumnIndex(DataDefine.KEY_SHOWNAME));
	    String devtype	 = Result.getString(Result.getColumnIndex(DataDefine.KEY_DEVICETYPE));
	    String ip        = Result.getString(Result.getColumnIndex(DataDefine.KEY_LOCALIP));  
	    String port      = Result.getString(Result.getColumnIndex(DataDefine.KEY_PORT));
	    String username  = Result.getString(Result.getColumnIndex(DataDefine.KEY_USERNAME));
	    String passwd    = Result.getString(Result.getColumnIndex(DataDefine.KEY_PASSWORD));		
	    String channelno = Result.getString(Result.getColumnIndex(DataDefine.KEY_CHANNELNO)); 
	    
	    System.out.println(devtype);
	    String DeviceType = devtype.substring(0, 3);
	    
		NVR.setEnabled(false);
		DVR.setEnabled(false);
		IPC.setEnabled(false);
	    if (DeviceType.equals(NVR.getText())) {
			NVR.setChecked(true);
		}else if (DeviceType.equals(DVR.getText())) {
			DVR.setChecked(true);
		}else if (DeviceType.equals(IPC.getText())) {
			IPC.setChecked(true);
		}
	    
	 	if (iStr(showname)) {
	 		devName.setText(showname);
	 	 } else {
	 		devName.setText(ip);
	 	}
	 	
	    devIP.setText(ip); 
	    devPort.setText(port);
	    devUserName.setText(username);
	    devPasswd.setText(passwd);
	    channelNo.setText(channelno);
	    
	    devName.setSelection(devName.length());
//	    devType.setSelection(devType.length());
	    devIP.setSelection(devIP.length());
	    devPort.setSelection(devPort.length());
	    devUserName.setSelection(devUserName.length());
	    devPasswd.setSelection(devPasswd.length());
	    channelNo.setSelection(channelNo.length());
	}
	
	private void addData()
	{
	    devName.setText("");
//	    devType.setText("");
	    NVR.setChecked(true);
	    devIP.setText("");
	    devPort.setText("");
	    devUserName.setText("");
	    devPasswd.setText("");	
	    channelNo.setText("");
	}
	
	private void AddorModify(){
		
		String DevName      = devName.getText().toString();
		String DevType		= devType;
		String DevIP        = devIP.getText().toString();
		String DevPort      = devPort.getText().toString();
		String DevUserName  = devUserName.getText().toString();
		String DevPasswd    = devPasswd.getText().toString();		
		String DevSerial    = getrandom(); //手动添加的设备序列号
		String devChannelNo = channelNo.getText().toString();
	        
		int count = 0;
		String Ip[] = {DataDefine.KEY_LOCALIP};
		SQLiteDatabase devDatabase= openOrCreateDatabase(DataDefine.DBNAME, SQLiteDatabase.CREATE_IF_NECESSARY, null);
		Cursor cursor = devDatabase.query(DataDefine.TABLE_DEVIDE,Ip,null, null, null, null, null);
	
		if(iStr(DevIP)||iStr(DevPort))
	 	{
			if (!iStr(DevIP))
			{				
		        new AlertDialog.Builder(this) 
		        .setTitle("设备地址不能为空！")
		        .setPositiveButton("确认", new DialogInterface.OnClickListener() {
		            public void onClick(DialogInterface dialog, int which) {
		            	dialog.dismiss();
		            }
		        })
		        .show();
			} 
			else
			{
				if (!iStr(DevPort))
				{
			        new AlertDialog.Builder(this) 
			        .setTitle("端口号不能为空！")
			        .setPositiveButton("确认", new DialogInterface.OnClickListener() {
			            public void onClick(DialogInterface dialog, int which) {
			            	dialog.dismiss();
			            }
			        })
			        .show();					
				}
				else 
				{
					 if (!iStr(devChannelNo))
					 {
				         new AlertDialog.Builder(this) 
				         .setTitle("通道数不能为空！")
				         .setPositiveButton("确认", new DialogInterface.OnClickListener() {
				             public void onClick(DialogInterface dialog, int which) {
				               	 dialog.dismiss();
				             }
				         })
				         .show();
					 }
					 else
					 {
						
					 
						 if (!iStr(DevName))
						 {
					        new AlertDialog.Builder(this) 
					        .setTitle("设备名称不能为空！")
					        .setPositiveButton("确认", new DialogInterface.OnClickListener() {
					            public void onClick(DialogInterface dialog, int which) {
					            	dialog.dismiss();
					            }
					        })
					        .show();												
					     } 
						 else
						 {
							 if(id.equals(""))
							 {	 		 			
								 if(isShowNameExist(DevName,id))
								 {
								        new AlertDialog.Builder(this) 
								        .setTitle("设备名称已存在！")
								        .setPositiveButton("确认", new DialogInterface.OnClickListener() {
								            public void onClick(DialogInterface dialog, int which) {
								            //	dialog.dismiss();
								            }
								        })
								        .show();
								 }
								 else
								 {					 		 	
							 			for(cursor.moveToFirst();!cursor.isAfterLast();cursor.moveToNext())
							 			{
							 			    int IpColumn = cursor.getColumnIndex(DataDefine.KEY_LOCALIP);
		
							 			    String ip = cursor.getString(IpColumn);
							 					 //	 Log.i("Debug3", "LocalIP:"+LocalIP);
							 			 	 if(ip.equals(DevIP)){
							 			 		count++;
										        new AlertDialog.Builder(this) 
										        .setTitle("该设备已存在，不可重复添加！")
										        .setPositiveButton("确认", new DialogInterface.OnClickListener() {
										            public void onClick(DialogInterface dialog, int which) {
										            //	dialog.dismiss();
										            }
										        })
										        .show();					 			 		
		//					 					Toast.makeText(DevInfoActivity.this, "该设备已存在，不可重复添加！",
		//					 							Toast.LENGTH_SHORT).show();		 		
		//					 					 		Log.i("count", "count:"+count);
							 			 		break;
							 			 	 }
							 			 }
							 			 if(count==0)  // 增加通道
							 			 {
										 		    values = new ContentValues();
										 		    values.put(DataDefine.KEY_SHOWNAME, DevName);
										 		    values.put(DataDefine.KEY_DEVICETYPE, DevType);
													values.put(DataDefine.KEY_LOCALIP, DevIP);
													values.put(DataDefine.KEY_PORT, DevPort);
													values.put(DataDefine.KEY_USERNAME, DevUserName);
													values.put(DataDefine.KEY_PASSWORD, DevPasswd);		
													values.put(DataDefine.KEY_SERIALNO, DevSerial);	
													values.put(DataDefine.KEY_CHANNELNO, devChannelNo);
													devDatabase.insert(DataDefine.TABLE_DEVIDE, null, values);		
													Intent intent = new Intent(DevInfoActivity.this,Discovery.class);
													startActivity(intent);										
							 			 }						 			
	
								 
								 
								 } 
	 	 
						      }
							  else
							  {
									 if(isShowNameExist(DevName,id))
									 {
										 	
									        new AlertDialog.Builder(this) 
									        .setTitle("设备名称已存在！")
									        .setPositiveButton("确认", new DialogInterface.OnClickListener() {
									            public void onClick(DialogInterface dialog, int which) {
									            //	dialog.dismiss();
									            }
									        })
									        .show();
									 }
									 else //修改通道
									 {
									 		values = new ContentValues();
									 		String where = DataDefine.KEY_DEV_ID_AUTO_INCREMENT+"="+id;
								 		    values.put(DataDefine.KEY_SHOWNAME, DevName);
//								 		    values.put(DataDefine.KEY_DEVICETYPE, DevType);
											values.put(DataDefine.KEY_LOCALIP, DevIP);
											values.put(DataDefine.KEY_PORT, DevPort);
											values.put(DataDefine.KEY_USERNAME, DevUserName);
											values.put(DataDefine.KEY_PASSWORD, DevPasswd);		
											values.put(DataDefine.KEY_CHANNELNO, devChannelNo);
											devDatabase.update(DataDefine.TABLE_DEVIDE, values, where, null);
											Intent intent = new Intent(DevInfoActivity.this,Discovery.class);
											startActivity(intent);													
										 
									}					    	  
							
							  }
								 							 
				        }
					 
				}	 
			}
				
		 }	
			 
			

	 	}
		else
		{
	        new AlertDialog.Builder(this) 
	        .setTitle("设备地址不能为空！")
	        .setPositiveButton("确认", new DialogInterface.OnClickListener() {
	            public void onClick(DialogInterface dialog, int which) {
	            	dialog.dismiss();
	            }
	        })
	        .show(); 
		}
		
        cursor.close();
        devDatabase.close();	 	 	
	
	}
	
	//判断设备名是否存在
	private  boolean isShowNameExist(String Str, String id){
		String ShowName[] = {DataDefine.KEY_SHOWNAME};
		SQLiteDatabase devDatabase= openOrCreateDatabase(DataDefine.DBNAME, SQLiteDatabase.CREATE_IF_NECESSARY, null); ;
		Cursor cursor = devDatabase.query(DataDefine.TABLE_DEVIDE,ShowName,null, null, null, null, null);
	
		if(id.equals(""))
		{
			for(cursor.moveToFirst();!cursor.isAfterLast();cursor.moveToNext())
			{
			    int ShowNameColumn = cursor.getColumnIndex(DataDefine.KEY_SHOWNAME);
			    String showname = cursor.getString(ShowNameColumn);
			    
			 	 if(showname.equals(Str)){
				         cursor.close();
				         devDatabase.close();	
					   	return true;
			 	 }		 	 
			}				
		}	
		else 
		{
			for(cursor.moveToFirst();!cursor.isAfterLast();cursor.moveToNext())
			{
			    int ShowNameColumn = cursor.getColumnIndex(DataDefine.KEY_SHOWNAME);
			    String showname = cursor.getString(ShowNameColumn);
			    
			    System.out.println("showname======"+showname);
			    
			 	 if(showname.equals(Str)){
			 		    String ID = getid(Str, devDatabase);
			 		   System.out.println("ID="+ID);
			 		    if(ID.equals(id))
			 		    {
					        cursor.close();
					        devDatabase.close();			 		    	
			 		    	return false;
			 		    }else {
					        cursor.close();
					        devDatabase.close();
					        
					        return true;
						}
	
					   	
			 	 }	
			 	 else {
				        cursor.close();
				        devDatabase.close();
	
				        return false;					       				
				}
			}				
		}

        cursor.close();
        devDatabase.close();		
		
		return false;
	}
	
	private String getid(String Str, SQLiteDatabase database)
	{
		String Columns[] = {DataDefine.KEY_DEV_ID_AUTO_INCREMENT};
		String selectionArgs[]={Str};
		String select = DataDefine.KEY_SHOWNAME + "=?";
		Cursor cursor = database.query(DataDefine.TABLE_DEVIDE,Columns,select, selectionArgs, null, null, null);			
		cursor.moveToFirst();
	    String id = cursor.getString(cursor.getColumnIndex(DataDefine.KEY_DEV_ID_AUTO_INCREMENT));	
	      
	    return id;  
	}
	
	private String getrandom(){
		Calendar time = Calendar.getInstance();

		SimpleDateFormat sDateFormat = new SimpleDateFormat("yyyyMMddhhmmssSS");
		Date date = time.getTime();
		String curTime = sDateFormat.format(date);
		return curTime;
	}
	
    public static boolean iStr(String str) {

        if (!"".equals(str) && null != str) return true;

        return false;
    }
		    
}
