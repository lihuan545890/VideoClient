package com.BLL;

import org.json.JSONException;
import org.json.JSONObject;

import android.app.Activity;
import android.util.Log;

public class HandleLogin extends Activity{
	
	
	/** 解析用户登录句柄*/
	public  static int GetUserId(String szStr){
	
		int UserId = 0;
		if(szStr.length() >0){
			
			JSONObject jsonObject = null;
			try {
				jsonObject = new JSONObject(szStr).getJSONObject("LoginContent");
				UserId = Integer.parseInt(jsonObject.getString("UserId"));
				
				//com.Data.LoginContent LoginCon = new com.Data.LoginContent();
				
				
				
				
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
 		
			Log.i("UserId", "" +UserId);
		}
		
		return UserId;
		
	}

}
