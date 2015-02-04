package com.BLL;

import android.content.Context;
import android.support.v4.view.ViewPager;
import android.util.AttributeSet;
import android.view.MotionEvent;

public class MyViewPager extends ViewPager {
	 private boolean willIntercept=false;
		public MyViewPager(Context context) {
			super(context);
			// TODO Auto-generated constructor stub
		}
		public MyViewPager(Context context, AttributeSet attrs) {
			super(context, attrs);
			// TODO Auto-generated constructor stub
		}
		
	    public boolean onInterceptTouchEvent(MotionEvent event) {
	    	/**
	    	 * 打断父控件的触屏
	    	 */
	        if(willIntercept){
	        	return false;
	        }else{
	            //直接返回true会很卡
	            return super.onInterceptTouchEvent(event);
	        }
	    }
	   
	    public void setTouchIntercept(boolean value){
	        willIntercept = value;
	}
	    
}
