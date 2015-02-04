package com.BLL;

import java.util.ArrayList;

import android.R.integer;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PointF;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.util.DisplayMetrics;
import android.util.FloatMath;
import android.util.Log;
import android.view.GestureDetector;
import android.view.GestureDetector.OnGestureListener;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.HorizontalScrollView;

public class TimeRuler extends View implements OnGestureListener, OnTouchListener {

	private static final float SPACING_HEIGHT = 120f; // 距离底部的高度

	private static final float SPACING = 4f; // 距离左边的间距

	private float mGradientWidth; // 渐变条的宽度

	private float mButtonWidth;
	
	private Canvas canvas;
	
	private Paint paint = new Paint();
	
	private float smallDotted;
	
	private float dottedSpacing; 
	
	private boolean flag = false;
	
	private int times = 0;
	
	public  int pos = 0;
	
	public  float position = 0.0f;
	
	private GestureDetector mGestureDetector;
	
	private Context context;

	PointF start = new PointF();// 其实点

	PointF mid = new PointF();// 中点

	float oldDist;
	
	float newDist;

	// 模式
	static final int NONE = 0;

	static final int DRAG = 1;

	static final int ZOOM = 2;

	int mode = NONE;

	int lastX ,lastY;
	
	int begintime = 0, endtime = 86400;
	
	int RecBeginTime, RecEndTime;
	
	int curtimestamp;

	boolean isRec = false;
	
	ArrayList<String> QueryResult;
	
	public TimeRuler(Context context, AttributeSet abu)
	{

		super(context, abu);
		Activity a = (Activity) context;
		DisplayMetrics mDisplayMetrics = new DisplayMetrics();
		a.getWindowManager().getDefaultDisplay().getMetrics(mDisplayMetrics);
		mGradientWidth = (float) (0.8 * mDisplayMetrics.widthPixels);
		mButtonWidth   = (float) (0.1 * mDisplayMetrics.widthPixels);
		this.context = context;
		mGestureDetector = new GestureDetector(this);
	}

	@SuppressLint("DrawAllocation")
	@Override
	protected void onDraw(Canvas canvas) {

		// 重写onDraw方法
		super.onDraw(canvas);
//		Paint paint = new Paint();
		// 初始化绘制
		this.canvas = canvas;
		initDraw();
	}

	private void initDraw() {

		paint.setColor(Color.WHITE);
		paint.setAntiAlias(true);
		paint.setStrokeWidth(1);
		paint.setTextSize(dip2px(context, 10));
		
		// 单位长度
	    dottedSpacing = mGradientWidth / 24;
		// 每个刻度长度
		smallDotted = dottedSpacing / 10;
		
//		canvas.drawLine(0,  dip2px(context, 15+mButtonWidth),
//				mGradientWidth , dip2px(context, 15+mButtonWidth), paint);
//		
//		canvas.drawLine(0, dip2px(context, 15),
//				mGradientWidth , dip2px(context, 15), paint);

		
		canvas.drawLine(0,   dip2px(context, 15)+mButtonWidth,
				mGradientWidth ,  dip2px(context, 15)+mButtonWidth, paint);
		
		canvas.drawLine(0, dip2px(context, 15),
				mGradientWidth , dip2px(context, 15), paint);
		
		switch (times) {
		case 0:
			for(int i = 0; i <= 86400; i++)
			{
				
				if (i % 3600 == 0)
				{
					float pos = (i - 0)*mGradientWidth / 86400;
					
					if (i % 3600 == 0)
					{
						canvas.drawText(i/3600+"", pos,
								dip2px(context, 9), paint);
					}

					canvas.drawLine( pos, dip2px(context, 10),
							pos, dip2px(context, 15), paint);
				}
				
			}			
			
			break;
		case 1:
			for(int i = begintime; i <= endtime; i++)
			{
				if (i % 1800 == 0)
				{
					float pos = (i - begintime)*mGradientWidth / 43200;
					
					if ((i/3600) >= 0 && (i/3600) <= 24)
					{
						if (i % 3600 == 0)
						{
							canvas.drawText(i/3600+"", pos,
									dip2px(context, 9), paint);
						}

						if (i >= 0) {
							canvas.drawLine( pos, dip2px(context, 10),
									pos, dip2px(context, 15), paint);							
						}

					}
				}
				
			}
			
			break;				
		case 2:
			for(int i = begintime; i <= endtime; i++)
			{
				if (i % 900 == 0)
				{
					if ((i/3600) >= 0 && (i/3600) <= 24)
					{
						float pos = (i - begintime)*mGradientWidth / 21600;
						if (i % 3600 == 0)
						{
							canvas.drawText(i/3600+"", pos,
									dip2px(context, 9), paint);
							
							Log.i("position", pos+":"+i);
						}

						if (i >= 0) {
							canvas.drawLine( pos, dip2px(context, 10),
									pos, dip2px(context, 15), paint);
						}

					}

				}
				
			}	
			break;
		case 3:
			for(int i = begintime; i <= endtime; i++)
			{
				if ((i/3600) >= 0 && (i/3600) <= 24)
				{
					
					if (i % 300 == 0)
					{
						float pos = (i - begintime)*mGradientWidth / 7200;
					
						if (i % 3600 == 0)
						{
							canvas.drawText(i/3600+"", pos,
									dip2px(context, 9), paint);
						}

						if (i >= 0) {
							canvas.drawLine( pos, dip2px(context, 10),
									pos, dip2px(context, 15), paint);
						}
					}
				}
				
			}			
			  
			break;					
		default:
			break;				
		}
		   
		if (isRec)
		{
			paint.setColor(Color.BLUE);
   	        for(int i=0; i<QueryResult.size(); i++)
	        {
	        	String str = QueryResult.get(i);
	        	int left = 0;
	        	int right = 0;
				String starthour = str.substring(13,15);
				String startmin = str.substring(15,17);
				String startsec = str.substring(17,19);
				
				String endhour = str.substring(28,30);
				String endmin = str.substring(30,32);
				String endsec = str.substring(32,34);		
				
				RecBeginTime = Integer.parseInt(starthour)*3600 + Integer.parseInt(startmin)*60 +
						Integer.parseInt(startsec);
				
				RecEndTime = Integer.parseInt(endhour)*3600 + Integer.parseInt(endmin)*60 +
						Integer.parseInt(endsec);
				
				if (times == 3)
				{
				    left = (int) ((RecBeginTime - begintime) * mGradientWidth / 7200);
				    right = (int) ((RecEndTime - begintime) * mGradientWidth / 7200);					
				}
				else
				{
				    left = (int) ((RecBeginTime - begintime) * mGradientWidth / (86400/(Math.pow(2, times))));
				    right = (int) ((RecEndTime - begintime) * mGradientWidth / (86400/(Math.pow(2, times))));					
				}
				
				Rect rect = new Rect(left, dip2px(context, 16), right, (int) (dip2px(context, 14)+mButtonWidth));
				canvas.drawRect(rect, paint);
	        }
      
		}                    
		               
	}  

	public void zoomOut(float pos, int timestamp)
	{
		if (times < 3)
		{
			flag = true;
			times++;	
			
			if (times == 3)
			{
//				begintime = (int) (timestamp - (7200 / mGradientWidth)*pos);
				begintime = (int) (timestamp - (7200/mGradientWidth)*pos);
				endtime   = (int) (begintime + 7200);				
			}
			else
			{
				begintime = (int) (timestamp - ((86400/(Math.pow(2, times))) / mGradientWidth)*pos);
				endtime   = (int) (begintime + 86400/(Math.pow(2, times)));				
			}

			invalidate(); //触发ondraw重绘事件			
		}
		else
		{
			times = 3;
		}
		
//		invalidate(); //触发ondraw重绘事件	
	}   
	
	public void zoomIn(float pos, int timestamp)
	{
		if (times > 0)
		{
			flag = true;
			times--;
			
			this.position = pos;
			
			if (times == 0)
			{
				begintime = 0;
			}
			else
			{
				if (times == 3)
				{
					begintime = (int) ((int) ((timestamp - 7200) / mGradientWidth)*pos);
				}
				else
				{
					begintime = (int) (timestamp - ((86400/(Math.pow(2, times))) / mGradientWidth)*pos);
				}
								
			}

			if (times == 3) 
			{
				endtime   = (int) (begintime + 7200);
			}
			else
			{
				endtime   = (int) (begintime + 86400/(Math.pow(2, times)));				
			}

			invalidate(); //触发ondraw重绘事件	
		}
		else
		{
			times = 0;
		}

	}
	
	public int gettimes()
	{
		return times;
	}

	public int getbegintime()
	{
		return begintime;
	}
	
	public void drawRecArea(ArrayList<String> result)
	{
		
		isRec = true;
		this.QueryResult = result;
		   
		invalidate();
	}
	
	@Override
	public boolean onDown(MotionEvent e) {
		// TODO Auto-generated method stub
		Log.i("onDown", "========>onDown");
		return true;
	}

	@Override
	public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
			float velocityY) {
		// TODO Auto-generated method stub
		return true;
	}

	@Override
	public void onLongPress(MotionEvent e) {
		// TODO Auto-generated method stub
	}

	float x;
	float lastx;
	@Override
	public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX,
			float distanceY) {
		// TODO Auto-generated method stub
//		Log.i("onScroll", "========>onScroll");
		x = e2.getX() - e1.getX();
		
		if ((x - lastx) > 0)
		{
			 pos = pos + 5;
		}
		else
		{      
			 pos = pos - 5;
		}
		invalidate();
 	    lastx = x;
		return true;
	}

	@Override
	public void onShowPress(MotionEvent e) {
		// TODO Auto-generated method stub
//		Log.i("onShowPress", "========>onShowPress");
	}

	@Override
	public boolean onSingleTapUp(MotionEvent e) {
		// TODO Auto-generated method stub
//		Log.i("onSingleTapUp", "========>onSingleTapUp");
		return true;
	}

	@Override
	public boolean onTouch(View v, MotionEvent event) {
		// TODO Auto-generated method stub
//		Log.i("onTouch", "========>onTouch");
		return mGestureDetector.onTouchEvent(event);
	}
	
	public static int dip2px(Context context, float dpValue) { 
		final float scale = context.getResources().getDisplayMetrics().density ; 
		return (int) (dpValue * scale + 0.5f) ;
	}
}
