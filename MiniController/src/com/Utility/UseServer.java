package com.Utility;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;

public class UseServer   {
	
	//判断是否有网络连接
	public static boolean isNetworkConnected(Context context) { 
		if (context != null) { 
		ConnectivityManager mConnectivityManager = (ConnectivityManager)context.getSystemService(Context.CONNECTIVITY_SERVICE);  
		NetworkInfo mNetworkInfo = mConnectivityManager.getActiveNetworkInfo(); 
		if (mNetworkInfo != null) { 
		return mNetworkInfo.isAvailable(); 
		} 
		}
		return false; 
		}


	//判断WIFI网络是否可用 
	public static boolean isWifiConnected(Context context) { 		
		if(context != null){		
			ConnectivityManager mConnectivityManager = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);  
			NetworkInfo mWiFiNetworkInfo = mConnectivityManager.getNetworkInfo(ConnectivityManager.TYPE_WIFI); 
			if (mWiFiNetworkInfo != null) { 
				return mWiFiNetworkInfo.isAvailable(); 
			}		
		}
		return false; 
 	}
	
	//判断MOBILE网络是否可用
	public boolean isMobileConnected(Context context) { 
		if (context != null) { 
			ConnectivityManager mConnectivityManager = (ConnectivityManager)context.getSystemService(Context.CONNECTIVITY_SERVICE); 
			NetworkInfo mMobileNetworkInfo = mConnectivityManager.getNetworkInfo(ConnectivityManager.TYPE_MOBILE); 
			if (mMobileNetworkInfo != null) { 
			return mMobileNetworkInfo.isAvailable(); 
			} 
		} 
		return false; 
		}


 	 //获取当前网络连接的类型信息
	//1.无网络（这种状态可能是因为手机停机，网络没有开启，信号不好等原因） 2.使用WIFI上网 3.CMWAP（中国移动代理） 4.CMNET上网   
	public static int getConnectedType(Context context) { 
	if (context != null) { 
			ConnectivityManager mConnectivityManager = (ConnectivityManager)context.getSystemService(Context.CONNECTIVITY_SERVICE); 
			NetworkInfo mNetworkInfo = mConnectivityManager.getActiveNetworkInfo(); 
			if (mNetworkInfo != null && mNetworkInfo.isAvailable()) { 
			return mNetworkInfo.getType(); 
		} 
	} 
	return -1; 
	}

 

}
