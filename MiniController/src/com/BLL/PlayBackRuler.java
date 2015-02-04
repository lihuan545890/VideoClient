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
import android.util.Log;
import android.view.GestureDetector;
import android.view.View;

public class PlayBackRuler extends View {

	private float mGradientWidth; // 渐变条的宽度

	private Canvas canvas;
	
	private Paint paint = new Paint();
	
	private boolean flag = false;
	
	private int times = 0;
	
	public  int pos = 0;
	
	public  float position = 0.0f;
	
//	int lastX ,lastY;
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
	
	public PlayBackRuler(Context context, AttributeSet abu)
	{

		super(context, abu);
		Activity a = (Activity) context;
		DisplayMetrics mDisplayMetrics = new DisplayMetrics();
		a.getWindowManager().getDefaultDisplay().getMetrics(mDisplayMetrics);
		mGradientWidth = (float) ( mDisplayMetrics.widthPixels);
		
//		mGradientWidth = this.getWidth();
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
		
		
		canvas.drawLine(0, 70,
				mGradientWidth , 70, paint);
		
		canvas.drawLine(0, 30,
				mGradientWidth , 30, paint);

		
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
								15, paint);
					}

					canvas.drawLine( pos, 25,
							pos, 30, paint);
				}
				
			}			
			
			break;
		case 1:
			for(int i = begintime; i <= endtime; i++)
			{
				
				
				if (i % 1800 == 0)
				{
					float pos = (i - begintime)*mGradientWidth / 43200;
					
					if (i % 3600 == 0)
					{
						
						canvas.drawText(i/3600+"", pos,
								15, paint);
					}

					canvas.drawLine( pos, 25,
							pos, 30, paint);
				}
				
			}
			
			break;				
		case 2:
			for(int i = begintime; i <= endtime; i++)
			{
				
				
				if (i % 900 == 0)
				{
					float pos = (i - begintime)*mGradientWidth / 21600;
					
					
					if (i % 3600 == 0)
					{
						canvas.drawText(i/3600+"", pos,
								15, paint);
					}

					canvas.drawLine( pos, 25,
							pos, 30, paint);
				}
				
			}	
			break;
		case 3:
			for(int i = begintime; i <= endtime; i++)
			{
				
				
				if (i % 300 == 0)
				{
					float pos = (i - begintime)*mGradientWidth / 7200;
					
					
					if (i % 3600 == 0)
					{
						canvas.drawText(i/3600+"", pos,
								15, paint);
					}

					canvas.drawLine( pos, 25,
							pos, 30, paint);
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
//	        	Log.i("QueryResult", QueryResult.get(i));
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

				
				Rect rect = new Rect(left, 34, right, 68);
				canvas.drawRect(rect, paint);
//				Log.i("TimeRuler", left+"");
				
	        }
			

//				float pos = (i - 0)*mGradientWidth / 86400;
//			canvas.drawLine( pos, 30,
//					pos, 70, paint);
//			Log.i("TimeRuler", pos+"");
		}
		
	}

	public void zoomOut(float pos, int timestamp)
	{
		if (times < 3)
		{
			flag = true;
			times++;	
			
//			this.position = pos;
//			this.curtimestamp = timestamp;
			
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

			Log.i("begintime", begintime+"");
			Log.i("endtime",   endtime+"");
			invalidate(); //触发ondraw重绘事件			
		}
		else
		{
			times = 3;
		}
		
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
		
//			float pos = (i - 0)*mGradientWidth / 86400;
//		canvas.drawLine( pos, 30,
//				pos, 70, paint);
//		
//		Rect rect = new Rect(left, 32, right, 68);
//		canvas.drawRect(rect, paint);
//		Log.i("TimeRuler", left+"");
		   
		invalidate();
	}
	
	
}

