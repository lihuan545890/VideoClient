package com.Utility;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class CheckData {
	
	
	//IP地址输入检测
	public static boolean isIPAddress(String ipaddr) {
		boolean flag = false;
		Pattern pattern = Pattern.compile("\\b((?!\\d\\d\\d)\\d+|1\\d\\d|2[0-4]\\d|25[0-5])\\.((?!\\d\\d\\d)\\d+|1\\d\\d|2[0-4]\\d|25[0-5])\\.((?!\\d\\d\\d)\\d+|1\\d\\d|2[0-4]\\d|25[0-5])\\.((?!\\d\\d\\d)\\d+|1\\d\\d|2[0-4]\\d|25[0-5])\\b");
		Matcher m = pattern.matcher(ipaddr);
		flag = m.matches();
		return flag;
		} 
	
	//检测是否输入为空
	public static boolean IsNull(String str)
	{
		boolean flag = false;
		if(str.trim().length() == 0)
		{
			flag = true;
		}
		return flag;
	}
		
	
	

}
