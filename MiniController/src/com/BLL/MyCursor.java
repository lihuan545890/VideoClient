package com.BLL;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PointF;
import android.util.AttributeSet;
import android.util.DisplayMetrics;
import android.util.FloatMath;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View.OnTouchListener;
import android.view.View;
import android.widget.ScrollView;
/**
 * 
 * @author lis
 * 
 */
public class MyCursor extends View  {

	private static final float SPACING_HEIGHT = 120f; // 距离底部的高度

	private static final float SPACING = 4f; // 距离左边的间距

	private float mGradientWidth; // 渐变条的宽度

	private float mButtonWidth; // 渐变条的宽度
	
	private float mGradientHeight; // 渐变条的高度
	
	private Canvas canvas;
	
	private Paint paint = new Paint();
	
	private float smallDotted;
	
	private float dottedSpacing;
	
	private boolean flag = false;
	
	private int times = 1;
	
	private Context context;
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
	
	private boolean state = false;
	
	private float pos = 0.0f;
	
	public MyCursor(Context context, AttributeSet abu) 
	{
		super(context, abu);
		Activity a = (Activity) context;
		DisplayMetrics mDisplayMetrics = new DisplayMetrics();
		a.getWindowManager().getDefaultDisplay().getMetrics(mDisplayMetrics);
		mGradientWidth = (float) (0.8 * mDisplayMetrics.widthPixels);
		mButtonWidth = (float) (0.1 * mDisplayMetrics.widthPixels);
		mGradientHeight = mDisplayMetrics.heightPixels;
		this.context = context;
//		setOnTouchListener(this);
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

		paint.setColor(Color.RED);
		paint.setAntiAlias(true);
		paint.setStrokeWidth(3);
		// 单位长度
	    dottedSpacing = (mGradientHeight - SPACING_HEIGHT) / 20;
		// 每个刻度长度
		smallDotted = dottedSpacing / 10;
		
		/* 绘制底部的横线、文字、以及向上的线条 */
		// 底部的横线
		
		if (state) 
		{
			canvas.drawLine(pos, dip2px(context, 15),
					pos, dip2px(context, 15) +mButtonWidth, paint);
			state = false;
		}
		else
		{
			canvas.drawLine(0, dip2px(context, 15),
					0, dip2px(context, 15) +mButtonWidth, paint);			
		}
		
	}
	
	
	public void setState()  
	{
		state = true;
	}
	
	public void refresh()
	{
		invalidate();
	}
	
	public static int dip2px(Context context, float dpValue) { 
		final float scale = context.getResources().getDisplayMetrics().density ; 
		return (int) (dpValue * scale + 0.5f) ;
	}

}
