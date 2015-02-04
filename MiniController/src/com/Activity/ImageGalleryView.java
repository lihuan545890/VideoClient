package com.Activity;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import com.BLL.MyViewPager;
import com.Utility.SysApplication;
import com.example.minicontroller.R;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.graphics.PointF;
import android.graphics.RectF;
import android.os.Bundle;
import android.os.Handler;
import android.os.Parcelable;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.support.v4.view.ViewPager.OnPageChangeListener;
import android.util.FloatMath;
import android.view.Display;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.view.ViewGroup;
import android.view.ViewTreeObserver;
import android.view.ViewTreeObserver.OnGlobalLayoutListener;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.ImageView.ScaleType;
import android.widget.LinearLayout;
import android.widget.LinearLayout.LayoutParams;

public class ImageGalleryView extends Activity implements OnTouchListener, OnPageChangeListener {

	private Matrix matrix; // 初始化的matrix
	private Matrix savedMatrix = new Matrix();	
	private List<Bitmap> bitmaps;
	private float[] p;
	private int  screenWidth;
	private float x_down, y_down; // 开始按下的点
	private float dist = 1f;
	private PointF mid = new PointF(); // X,Y 坐标量	
	private Bitmap bitmap;
	private MyViewPager  mPager;
	private ViewPagerAdapter viewPagerAdapter;
	private int			 position;
	private ArrayList<String> imagepaths;
	private TextView   imagesViewTitle;
	private List<View> views;
	private List<Matrix> matrixs;
	private ArrayList<Float> fitscales;
	private int mpagerPosition;
	private int mPagerWidth, mPagerHeight; // mpager 宽和高
//	private boolean isInited = true; // 是否已经初始化
	
	static final int NONE = 0;// 初始状态
	static final int DRAG = 1;// 拖动
	static final int ZOOM = 2;// 缩放
	private int mode = NONE; // 模式
	private boolean isZoomed; // 是否缩放
	private boolean isRightExceed, isLeftExceed; // 右边偏移，左边偏移
	private float autoFitMinScale;
	private Handler handler = new Handler() {
		public void handleMessage(android.os.Message msg) {
			switch (msg.what) {
			case 0:
				mPager.setCurrentItem(position + 1);// 切换到后一页卡
				break;
			case 1:
				mPager.setCurrentItem(position - 1);// 切换到前一页卡
				break;
			}
		};
	};
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.singleimage);
		SysApplication.getInstance().addActivity(this);
	    Display localDisplay = getWindowManager().getDefaultDisplay();
	    screenWidth  = localDisplay.getWidth();
		initView();
	}
	
	@Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		super.onDestroy();
		
		bitmap.recycle();
		bitmap = null;
		System.gc();
	}



	static{
		System.loadLibrary("i8_netsdk");
		System.loadLibrary("i8_net_sdk");
	}
	
	private void initView(){
		
		imagesViewTitle = (TextView)findViewById(R.id.imagesView_Title);
		float rate = (float) screenWidth/320;
		if (screenWidth > 1000) {
			imagesViewTitle.setTextSize(6*rate);
		}else {  
			imagesViewTitle.setTextSize(10*rate);
		}
		mPager = (MyViewPager)findViewById(R.id.mPager);
		ViewTreeObserver vObserver = mPager.getViewTreeObserver();
		vObserver.addOnGlobalLayoutListener(new OnGlobalLayoutListener() {
			
			@Override
			public void onGlobalLayout() {
				// TODO Auto-generated method stub
				mPager.getViewTreeObserver().removeGlobalOnLayoutListener(this);
				mPagerWidth  = mPager.getWidth();
				mPagerHeight = mPager.getHeight();
				initImage();
			}
		});
	}
	
	private void initImage(){
		
		position      = getIntent().getIntExtra("id", 1);
		imagepaths    = getIntent().getStringArrayListExtra("path");
		int length	  = imagepaths.size();
		bitmaps   = new ArrayList<Bitmap>();
		matrixs   = new ArrayList<Matrix>();
		fitscales = new ArrayList<Float>();
		views     = new ArrayList<View>();
		imagesViewTitle.setText(String.valueOf(position + 1) + "/" + imagepaths.size());
		
		viewPagerAdapter = new ViewPagerAdapter();
		mPager.setAdapter(viewPagerAdapter);
		mPager.setPageMargin(0);//设置当前页卡
		mPager.setCurrentItem(position);
		mpagerPosition = position;
		mPager.setOnPageChangeListener(this);
	}

	@Override
	public void onPageScrollStateChanged(int arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onPageScrolled(int arg0, float arg1, int arg2) {
		// TODO Auto-generated method stub
	}

	@Override
	public void onPageSelected(int arg0) {
		// TODO Auto-generated method stub
		imagesViewTitle.setText(String.valueOf(arg0 + 1) + "/" + imagepaths.size());
		mpagerPosition = arg0;
		mode = NONE;
		isZoomed = false;
		mPager.setTouchIntercept(false);
		if (mpagerPosition > 0) {
			isRightExceed = false;
			isLeftExceed = false;
		}
	}

	@Override
	public boolean onTouch(View v, MotionEvent event) {
		// TODO Auto-generated method stub
		ImageView image = (ImageView) v;
		switch (event.getAction() & MotionEvent.ACTION_MASK) { // 主点按下
		case MotionEvent.ACTION_DOWN:
			mode = NONE;
			if (isZoomed) { // 在图片放大的形式下可进行拖动
				mode = DRAG;
				x_down = event.getX();//获取x点
				y_down = event.getY();//获取y点
				savedMatrix.set(matrix);//savedMatrix 局部缓存
			}
			break;
		case MotionEvent.ACTION_POINTER_DOWN:
			dist = spacing(event); // 如果连续两点距离大于10，判定为多点模式
			if (spacing(event) > 10f) {
//				System.out.println("matrixs:"+matrix);
				savedMatrix.set(matrix); // matrix 默认0,0
				midPoint(mid, event); // 中点的X,Y
				mode = ZOOM;
			}
			break;
		case MotionEvent.ACTION_MOVE:
			if (mode == DRAG) { // 拖动模式
				matrix.set(savedMatrix);
				matrix.postTranslate(
						event.getX() - x_down, event.getY() - y_down);
			} else if (mode == ZOOM) { // 缩放模式
				float newDist = spacing(event);
				if (newDist > 10f) {
					matrix.set(savedMatrix);
					float tScale = newDist / dist;
					matrix.postScale(tScale, tScale,
							mid.x, mid.y);
				}
			}
			break;
		case MotionEvent.ACTION_UP:
		case MotionEvent.ACTION_POINTER_UP:
			mode = NONE;
			if (isRightExceed) { // 切换后 初始化前一页卡
				matrix.setValues(p);//初始化当前页卡
				/**
				 * 不建议new Message 以handler.obtainMessage(0)形式从MessageQue队列中获取个对象 
				 * 不能在主线程切换页卡 否则会造成前一页卡无法初始化 用handler来切换
				 */
				handler.sendMessageDelayed(handler.obtainMessage(0),100);
			}
			if (isLeftExceed) { // 切换后  初始化后一页卡
				if (mpagerPosition > 0) {
					matrix.setValues(p);
					handler.sendMessageDelayed(handler.obtainMessage(1),100);
				}
			}
			break;
		}

//		image.setImageMatrix(matrix);
//		CheckView(image, mpagerPosition); // 限制图片放大或缩小到一定的比例，且对父控件mpager Intercept事件是否进行禁止		
		return true;
	}

	private void CheckView(ImageView imageView, int position) {
		float pi[] = new float[9];
		matrix.getValues(pi);

		System.out.println("pi[0]="+pi[0]+" autoFitMinScale="+fitscales.get(position));
		if (mode == ZOOM) {
			if (pi[0] == fitscales.get(position)) {//如果当前缩放倍数 等于初始化的倍数 则恢复父控件切换
				mPager.setTouchIntercept(true);
			} else if (pi[0] < fitscales.get(position)) {//如果当前缩放倍数  小于 初始化的倍数 则初始化图片
				matrix.setScale(fitscales.get(position),
						fitscales.get(position));
				isZoomed = false;
				mPager.setTouchIntercept(false);
			} else if (pi[0] > fitscales.get(position)) {//如果当前缩放倍数 大于初始化的倍数 则处于缩放状态
				mPager.setTouchIntercept(true);
				isZoomed = true;
			} 
		} 
		center(imageView, false);//对图片偏移量 调整
	}	
	
	// 计算两点的距离    
	private float spacing(MotionEvent event) {
		float x = event.getX(1) - event.getX(0);
		float y = event.getY(1) - event.getY(0);
		return FloatMath.sqrt(x * x + y * y);
	}
  
	// 取手势中心点
	private void midPoint(PointF mid, MotionEvent event) {
		float x = event.getX(0) + event.getX(1);
		float y = event.getY(0) + event.getY(1);
		mid.set(x / 2, y / 2);
	} 
	
	protected void center(ImageView imgView, boolean isInited) { // 初始化居中 图片拖动居中
		Matrix m = new Matrix();
		RectF rect = null;
		if (isInited) { // 当图片初始化过
			Bitmap mybitBitmap = (Bitmap) imgView.getTag();
			m.set(matrix);
			rect = new RectF(0, 0, mybitBitmap.getWidth(),
					mybitBitmap.getHeight());
		} else { // 当图片进行缩放拖拉操作后
//			matrix.set(matrix);  
			m.set(matrix);
			rect = new RectF(0, 0, bitmaps.get(mpagerPosition).getWidth(),
					bitmaps.get(mpagerPosition).getHeight());
		}
		m.mapRect(rect);
		float height = rect.height();
		float width = rect.width();
		float deltaX = 0, deltaY = 0;
		// 图片小于屏幕大小，则居中显示。大于屏幕，上方留空则往上移，下放留空则往下移
		
		int screenHeight = mPagerHeight;
		System.out.println("height:"+height+" screenHeight:"+screenHeight);
		if (height < screenHeight) {
			deltaY = (screenHeight - height) / 2 - rect.top;
		} else if (rect.top > 0) {
			// topExcee=rect.top;//上偏移量
			deltaY = -rect.top;
		} else if (rect.bottom < screenHeight) {

			deltaY = imgView.getHeight() - rect.bottom;
			// bottomExcee=deltaY;//下偏移量
		}
		
		int screenWidth = mPagerWidth;
		if (width < screenWidth) {
			deltaX = (screenWidth - width) / 2 - rect.left;
		} else if (rect.left > 0) { // 左边偏移量大于0
			deltaX = -rect.left;
			if (deltaX <= -screenWidth / 3) {
				if (mpagerPosition > 0) {
					isLeftExceed = true;
				} else if (mpagerPosition == 0) {
					isLeftExceed = false;
				}
			} else {
				isLeftExceed = false;
			}
		} else if (rect.right < screenWidth) {
			deltaX = screenWidth - rect.right;
			if (deltaX >= screenWidth / 3) { // 右边偏移量大于等于屏幕分辨率宽度的三分之一时，恢复父控件viewpager的拖动事件，再强制跳转到下一页卡

				if (mpagerPosition < imagepaths.size() - 1) { // 若页卡为最后一页卡
														// 则不支持跳转到下一页
					isRightExceed = true;
				}

			} else if (deltaX <= screenWidth / 3) {
				isRightExceed = false;
			}
		}
		
		System.out.println("deltaX="+deltaX+" deltaY="+deltaY);
		if (isInited) {
			matrix.postTranslate(deltaX, deltaY);
		} else {
			matrix.postTranslate(deltaX, deltaY);//回位
		}
	}
	
	
	public class ViewPagerAdapter extends PagerAdapter{

		private LayoutInflater inflater;
		
		public ViewPagerAdapter() {
			inflater = getLayoutInflater();
		}

		@Override
		public void destroyItem(View arg0, int arg1, Object arg2) {
			((ViewPager) arg0).removeView((View) arg2);
		}

		@Override
		public void finishUpdate(View arg0) {

		}
   
		@Override
		public int getCount() {
			return imagepaths.size();
		}

		@Override
		public Object instantiateItem(ViewGroup container, int position) {
			InputStream inputStream = null;
			try {
				inputStream = new FileInputStream(imagepaths.get(position));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			
			BitmapFactory.Options options=new BitmapFactory.Options();
			options.inPreferredConfig = Config.ARGB_8888;
			options.inPurgeable = true;// 允许可清除
			options.inJustDecodeBounds = false;
			options.inInputShareable = true;
			options.inSampleSize = 1;
			bitmap = BitmapFactory.decodeStream(inputStream, null, options);
			try {
				inputStream.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			autoFitMinScale = Math.min((float) mPagerWidth / bitmap.getWidth(),
					(float) mPagerHeight / bitmap.getHeight()); // 取每张图片最小比例
			
//			for(int i=0; i<imagepaths.size(); i++)
//			{
				matrix = new Matrix();
				matrix.postScale(autoFitMinScale, autoFitMinScale);
				p = new float[9];
//				matrix.getValues(p);// 矩阵值数组
//				matrixs.add(matrix);
//				bitmaps.add(bitmap);
//			}
			
			View imageLayout = inflater.inflate(R.layout.imageshow,
					container, false);
			
			ImageView imageView = (ImageView)imageLayout.findViewById(R.id.image);
			imageView.setTag(bitmap);
			imageView.setScaleType(ScaleType.MATRIX); // 设置ScaleType为MATRIX
			center(imageView, true); // 将图片初始化居中  
			fitscales.add(autoFitMinScale);
			imageView.setImageMatrix(matrix);
			imageView.setImageBitmap(bitmap);
			imageView.setOnTouchListener(ImageGalleryView.this);
			((ViewPager) container).addView(imageLayout, 0);
			
			return imageLayout;
		}
 
		@Override
		public boolean isViewFromObject(View arg0, Object arg1) {
			return arg0 == arg1;
		}
  
		@Override
		public void restoreState(Parcelable arg0, ClassLoader arg1) {

		}

		@Override
		public Parcelable saveState() {
			return null;
		}

		@Override
		public void startUpdate(View arg0) {

		}


	}
	
}
