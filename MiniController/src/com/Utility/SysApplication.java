package com.Utility;
import java.util.LinkedList;
import java.util.List;

import android.app.Activity;
import android.app.Application;


/**
 * @Description 按退出键退出整个应用程序
 * @ClassName SysApplication
 * @author By 徐 军
 * @Created 2013-10-28 下午15:43:05
 */
public class SysApplication extends Application {
	
	@SuppressWarnings("rawtypes")
//	private List mList = new LinkedList(); 
	private List<Activity> activityList = new LinkedList<Activity>(); 
	
	private static SysApplication instance;
 
	private SysApplication() {   
	} 
	
	public synchronized static SysApplication getInstance() { 
	    if (null == instance) { 
	        instance = new SysApplication(); 
	    } 
	    return instance; 
	}
	
	public void addActivity(Activity activity) { 
		activityList.add(activity); 
	} 
	
	public void exit() { 
	    try { 
	        for (Activity activity:activityList) { 
	            if (activity != null) 
	                activity.finish(); 
	        } 
	    } catch (Exception e) { 
	        e.printStackTrace(); 
	    } finally { 
	        System.exit(0); 
	    } 
	} 
	
	public void onLowMemory() { 
	    super.onLowMemory();     
	    System.gc(); 
	} 
 


 
}
