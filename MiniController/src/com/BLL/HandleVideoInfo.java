package com.BLL;

import java.util.ArrayList;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.R.string;
import android.util.Log;

import com.Data.ResultVideo;
import com.Utility.DataDefine;

public class HandleVideoInfo {

	
	//处理录像查询结果，让用户显示更便捷
	
	public static ArrayList<String> HandleVideoFile(ArrayList<String> VideoFileList)
	{
		ArrayList<String> listReq = new ArrayList<String>();
		for(int i = 0; i < VideoFileList.size() ; i++)
		{
			
			String str = VideoFileList.get(i);
			
			String year = str.substring(5,9);
			String month = str.substring(9,11);
			String day = str.substring(11,13);
			String starthour = str.substring(13,15);
			String startmin = str.substring(15,17);
			String startsec = str.substring(17,19);
			String endhour = str.substring(28,30);
			String endmin = str.substring(30,32);
			String endsec = str.substring(32,34);
			
			String showNameString =year+"-"+month+"-"+day+"  "+starthour+":"+startmin+":"+startsec+"-"+endhour+":"+endmin+":"+endsec;
//				objVideo.setShowFileName(showNameString);
			
			listReq.add(showNameString);
		}
			
			
		return listReq;
	}		
	
/*	public static List<ResultVideo> HandleVideoFile(String JSONQueryResult)
	{
		List<ResultVideo> listReq =new ArrayList<ResultVideo>();
		 

		try {
			String jsonstatus = new JSONObject(JSONQueryResult).getString("ResultCode");
			
			if(jsonstatus.equals("1000"))
			{
				System.out.println("11111111111111111");

//				JSONObject jsonObject  = new JSONObject(JSONQueryResult).getJSONObject("ResultContent");
//				Log.i("jsonObject", jsonObject.toString());
				JSONArray jsonArray = new JSONObject(JSONQueryResult).getJSONArray("ResultContent");
				Log.i("jsonArray", jsonArray.toString());
		/*		for(int i = 0; i < jsonResultContent.length() ; i++)
				{
					System.out.println("2222222222222222");
					ResultVideo objVideo = new ResultVideo();
					JSONObject jsonObj = ((JSONObject)jsonArray.opt(i));
					String str = jsonObj.getString("Content");
					objVideo.setChannel(Integer.parseInt(str.substring(3, 5)));
					objVideo.setFileName(str);
					objVideo.setStartTime(str.substring(5, 19));
					objVideo.setStopTime(str.substring(20, 33));

//					Log.i("year", "============="+str.substring(5,9));
//					Log.i("month", "============="+str.substring(9,11));
//					Log.i("day", "============="+str.substring(11,13));
//					Log.i("hour", "============="+str.substring(13,15));
//					Log.i("min", "============="+str.substring(15,17));
//					Log.i("sec", "============="+str.substring(17,19));
//					Log.i("hour", "============="+str.substring(28,30));
//					Log.i("min", "============="+str.substring(30,32));
//					Log.i("sec", "============="+str.substring(32,34));
					
					String year = str.substring(5,9);
					String month = str.substring(9,11);
					String day = str.substring(11,13);
					String starthour = str.substring(13,15);
					String startmin = str.substring(15,17);
					String startsec = str.substring(17,19);
					String endhour = str.substring(28,30);
					String endmin = str.substring(30,32);
					String endsec = str.substring(32,34);
					
					String showNameString =year+"-"+month+"-"+day+" "+starthour+":"+startmin+":"+startsec+"-"+endhour+":"+endmin+":"+endsec;
					objVideo.setShowFileName(showNameString);
					
					listReq.add(objVideo);
				}
			}
			
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return listReq;
	}*/
}
