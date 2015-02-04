package com.BLL;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import android.database.sqlite.SQLiteDatabase;
import android.database.Cursor;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.ContentValues;

import com.Utility.DataDefine;

import android.util.Log;

public class HandleSearchList extends Activity{
	
	//处理检索设备信息，更新数据库
	private ContentValues values;


	@SuppressLint("DefaultLocale")
	public void HandleQuertyList(String szStr, SQLiteDatabase devDatabase) throws JSONException
	{

		String SerialNo[] = {DataDefine.KEY_SERIALNO};
		String No,IP,Mask,Gateway,Dns1,Dns2,Mac,Port,HTTPPort,RTSPPort,Name,Pwd,DevType,ShowName,ChannelNo = null;

	    Cursor cursor = devDatabase.query(DataDefine.TABLE_DEVIDE,SerialNo,null, null, null, null, null);	
	    System.out.println(szStr);
		String jsonObject = new JSONObject(szStr).getString("ResultCode");
		JSONArray jsonArray = new JSONObject(szStr).getJSONArray("ResultContent");
		
		List<Map<String, Object>> list = null;
		list = new ArrayList<Map<String, Object>>();
		Map<String, Object> map;
		
		for(int i = 0; i < jsonArray.length() ; i++)
		{
			JSONObject jsonObj = jsonArray.getJSONObject(i);

			
			if(!jsonObj.get(DataDefine.KEY_LOCALIP).toString().equals("") && jsonObj.get(DataDefine.KEY_LOCALIP).toString().length()<=15)
			{
				map = getMap(jsonObj.toString());
				list.add(map);							
			}

		}
		 
		Collections.sort(list, new Comparator<Map<String, Object>>() {
 
			@Override
			public int compare(Map<String, Object> arg0,
					Map<String, Object> arg1) {
				// TODO Auto-generated method stub	
				return (int) (getIp10((String) arg0.get(DataDefine.KEY_LOCALIP)) - getIp10((String) arg1.get(DataDefine.KEY_LOCALIP)));								
			}
		});

		for(int i = 0; i < list.size() ; i++){  
//			JSONObject jsonObj = ((JSONObject)jsonArray.opt(i));  
			values = new ContentValues();
			
			No        = (String) list.get(i).get(DataDefine.KEY_SERIALNO);   
			IP        = (String) list.get(i).get(DataDefine.KEY_LOCALIP); 
			Mask      = (String) list.get(i).get(DataDefine.KEY_MASK);
			Gateway   = (String) list.get(i).get(DataDefine.KEY_GATEWAY);
			Dns1      = (String) list.get(i).get(DataDefine.KEY_PDNS);
			Dns2      = (String) list.get(i).get(DataDefine.KEY_ADNS);
			Mac       = (String) list.get(i).get(DataDefine.KEY_MACADDRESS); 
			Port      =  list.get(i).get(DataDefine.KEY_PORT)+""; 
			HTTPPort  =  list.get(i).get(DataDefine.KEY_HTTPPORT)+""; 
			RTSPPort  =  list.get(i).get(DataDefine.KEY_RTSPPORT)+""; 
			Name      = "";
			Pwd       = "";
			DevType   = (String) list.get(i).get(DataDefine.KEY_DEVICETYPE);
			ShowName  = (String) list.get(i).get(DataDefine.KEY_LOCALIP);

            if (DevType.length() < 8) {
            	ChannelNo = "1";
			}else {
				ChannelNo = DevType.substring(8).replaceAll("CH", "");
			}
		 	 
			String DeviceType = DevType.substring(0, 3);
			
			if (!DeviceType.equals("DEC") && !DeviceType.equals("DEM") && !DeviceType.equals("DES")) {
			 	   if(cursor.getCount() == 0){
                       
						values.put(DataDefine.KEY_SERIALNO, No);
						values.put(DataDefine.KEY_LOCALIP, IP);
						values.put(DataDefine.KEY_MASK, Mask);
						values.put(DataDefine.KEY_GATEWAY, Gateway);
						values.put(DataDefine.KEY_PDNS, Dns1);
						values.put(DataDefine.KEY_ADNS, Dns2);
						values.put(DataDefine.KEY_MACADDRESS, Mac);
						values.put(DataDefine.KEY_HTTPPORT, HTTPPort);
						values.put(DataDefine.KEY_RTSPPORT, RTSPPort);
						values.put(DataDefine.KEY_PORT, Port);
						values.put(DataDefine.KEY_USERNAME, Name);
						values.put(DataDefine.KEY_PASSWORD, Pwd);
						values.put(DataDefine.KEY_DEVICETYPE, DevType);	
						values.put(DataDefine.KEY_SHOWNAME, ShowName);
						values.put(DataDefine.KEY_CHANNELNO, ChannelNo);
						devDatabase.insert(DataDefine.TABLE_DEVIDE, null, values);	
			 	   }
			 	   else 
			 	   {
			 			int count = 0;			 		   
						for(cursor.moveToFirst();!cursor.isAfterLast();cursor.moveToNext())
						{
						    int SerialColumn = cursor.getColumnIndex(DataDefine.KEY_SERIALNO);

						    String Serial = cursor.getString(SerialColumn);
						 	 if(Serial.equals(No)){
						 		count++;
						 		break;
						 	 }
						}		//比较表和搜索的设备序列号，若count为0，则没有相同项
					 	 if(count == 0){
								values.put(DataDefine.KEY_SERIALNO, No);
								values.put(DataDefine.KEY_LOCALIP, IP);
								values.put(DataDefine.KEY_MASK, Mask);
								values.put(DataDefine.KEY_GATEWAY, Gateway);
								values.put(DataDefine.KEY_PDNS, Dns1);
								values.put(DataDefine.KEY_ADNS, Dns2);
								values.put(DataDefine.KEY_MACADDRESS, Mac);
								values.put(DataDefine.KEY_HTTPPORT, HTTPPort);
								values.put(DataDefine.KEY_RTSPPORT, RTSPPort);								
								values.put(DataDefine.KEY_PORT, Port);
								values.put(DataDefine.KEY_USERNAME, Name);
								values.put(DataDefine.KEY_PASSWORD, Pwd);
								values.put(DataDefine.KEY_DEVICETYPE, DevType);			
								values.put(DataDefine.KEY_CHANNELNO, ChannelNo);
								devDatabase.insert(DataDefine.TABLE_DEVIDE, null, values);						 		 				 		 
					 	 }						
								
			 	   }
			}
			
		
		}
	}

	public static long getIp10(String ip) {     
        String[] ips = ip.replace("\n","").split("[.]");  //去掉某些设备ip地址最后面的"\n"字符
        
        long num =  16777216L*Long.parseLong(ips[0]) + 65536L*Long.parseLong(ips[1]) + 256*Long.parseLong(ips[2]) + Long.parseLong(ips[3]);  
        return num;      
	   } 	 
	
    // 将json 数组转换为Map 对象
	public static Map<String, Object> getMap(String jsonString)
	{
		JSONObject jsonObject;
		try
		{
			jsonObject = new JSONObject(jsonString);   @SuppressWarnings("unchecked")
			Iterator<String> keyIter = jsonObject.keys();
			String key;
			Object value;
			Map<String, Object> valueMap = new HashMap<String, Object>();
			while (keyIter.hasNext())
			{
	  		 key = (String) keyIter.next();
			 value = jsonObject.get(key);
			 valueMap.put(key, value);
			}
			return valueMap;
		}
		catch (JSONException e)
		{
			e.printStackTrace();
		}
		return null;
	
	}
	


}
