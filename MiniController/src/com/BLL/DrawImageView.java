package com.BLL;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Style;
import android.graphics.PorterDuff.Mode;
import android.graphics.PorterDuffXfermode;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.widget.ImageView;

public class DrawImageView extends ImageView{

	int left, top, right, bottom;
	int color;
	Canvas canvas;
	
	public DrawImageView(Context context, AttributeSet attrs) {
		super(context, attrs);
		// TODO Auto-generated constructor stub
		
	}
	 
	Paint paint = new Paint();
	
	@Override
	public void onDraw(Canvas canvas) {
		// TODO Auto-generated method stub
		super.onDraw(canvas);
		this.canvas = canvas;
		canvas.drawRect(new Rect(left, top, right, bottom), paint);//绘制矩形		
	}
	
	public void setCoordinate(int left, int top, int right, int bottom) {
		this.left   = left;
		this.top    = top;
		this.right  = right;
		this.bottom = bottom;
	}
	
	public void setColor(int color){
		this.color = color;		
		paint.setAntiAlias(true);
		paint.setColor(color);
		paint.setStyle(Style.STROKE);
		paint.setStrokeWidth(5f);//设置线宽
		paint.setAlpha(100);	
	}
	
	public void clear(){
		invalidate(); 
	}

	

}
