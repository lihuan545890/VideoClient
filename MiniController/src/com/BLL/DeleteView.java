package com.BLL;

import android.content.Context;
import android.graphics.Color;
import android.view.LayoutInflater;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.example.minicontroller.R;

public class DeleteView extends LinearLayout{
	/**记录删除悬浮窗的宽度*/
	public static int viewWidth;
	/** 记录删除悬浮窗的高度*/
	public static int viewHeight;
	
	private TextView textView;
	
	public DeleteView(Context context) {
		// TODO Auto-generated constructor stub
		super(context);
		LayoutInflater.from(context).inflate(R.layout.float_window_delete, this);
		textView=(TextView) findViewById(R.id.delete_textview);
	}
	
	public void setDeletePicture(int picture)
	{
		textView.setBackgroundResource(picture);
	}

}
