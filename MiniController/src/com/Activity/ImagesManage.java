package com.Activity;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import com.BLL.GridViewAdapter;
import com.BLL.ImageCommon;
import com.Utility.SysApplication;
import com.example.minicontroller.R;

import android.R.integer;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.ActionMode;
import android.view.Display;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.AbsListView.MultiChoiceModeListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemSelectedListener;
import android.widget.Button;
import android.widget.GridView;
import android.widget.ListAdapter;
import android.widget.PopupWindow;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.LinearLayout.LayoutParams;


public class ImagesManage extends Activity {
	 
	 final String   path = "/mnt/sdcard/ants_mobile/";
	 private static ArrayList<String> paths = new ArrayList<String>();
	 
	 private Button        menuBtn;
	 private TextView	   imagesTitle;
	 private Button		   delBtn;
	 boolean flag = true;
	 private boolean       isdeleted = false;
	 private View		   delView;
 	 private View 		   menuControlView = null;
	 private PopupWindow   menuController = null;  
	 private View 		   delControlView = null;
	 private PopupWindow   delController = null;	 
	 private GridView 	   menuGrid;
	 private GridView      gView;
	 private Bitmap        bitmap;
	 private boolean       isControllerShow = true;
	 private boolean       isDelCtrlShow = true;
	 private GridViewAdapter mGridAdapter;
	 private static int   screenWidth   = 0;
	 private Map<String,Bitmap> maps = new TreeMap<String,Bitmap>();
	 private ArrayList<String> iList = new ArrayList<String>();
	 
		private String[] menu_name_array = { "远程预览", "远程回放", "远程控制", "设备管理","图像管理"};
		int[] menu_image_array = { R.drawable.menu_preview,
				R.drawable.menu_playback, R.drawable.menu_control,
				R.drawable.menu_devicemanage,R.drawable.menu_test};			 
	 
	 @SuppressLint("NewApi")
	 @Override  
	 public void onCreate(Bundle savedInstanceState) {  
	    super.onCreate(savedInstanceState);  
	    setContentView(R.layout.grid_view);  
	    
	    SysApplication.getInstance().addActivity(this);
	    Display localDisplay = getWindowManager().getDefaultDisplay();
	    screenWidth  = localDisplay.getWidth();
	    
	    imagesTitle = (TextView)findViewById(R.id.images_Title);
		float rate = (float) screenWidth/320;
		if (screenWidth > 1000) {
			imagesTitle.setTextSize(6*rate);
		}else {  
			imagesTitle.setTextSize(10*rate);
		}
	    menuBtn = (Button)findViewById(R.id.menu_images);
	    menuBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				showController();
			}
		});
	    
	    delBtn = (Button)findViewById(R.id.delBtn);
	    delBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				
				if (flag) {
					isdeleted = true;
					flag = false;
					showDelController();
				}else {
					isdeleted = false;
					flag = true;
					hideDelController();
					mGridAdapter.allNotChoose();
				}
				
			}
		});
	    
	    gView = (GridView) this.findViewById(R.id.gridview);  
	    
	    try {
			maps = getThumbnailsPhotos(path);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	   
	   mGridAdapter = new GridViewAdapter(this, maps);
       gView.setAdapter(mGridAdapter);
       gView.setSelector(new ColorDrawable(Color.TRANSPARENT));

	   gView.setOnItemClickListener(new OnItemClickListener(){  
	          public void onItemClick(AdapterView<?> parent, View view, int position,long id) 
	          {  
	        	 if (isdeleted) {
//	        		 mSelectMap.put(position, true);
	        		 
	        		 mGridAdapter.changeState(position);
				 }else {
		        	 Intent intent = new Intent();  
		        	 intent.setClass(ImagesManage.this, ImageGalleryView.class);  
		        	 intent.putExtra("path", paths);
		        	 intent.putExtra("id", position);
		        	 startActivity(intent);  					
				 } 

	           }    
	   });  
	   
	   delControlView = getLayoutInflater().inflate(R.layout.delcontrol, null);
	   delController  = new PopupWindow(delControlView);
	   delView = (View)delControlView.findViewById(R.id.delview);
	   delView.setOnClickListener(new OnClickListener() {
		
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				
				iList = mGridAdapter.getSelectedItems();
				for (int i = 0; i < iList.size(); i++) {
					maps.remove(iList.get(i));
				}
				mGridAdapter.delSelectedImages();
				   mGridAdapter = new GridViewAdapter(ImagesManage.this, maps);
			       gView.setAdapter(mGridAdapter);
			}
		});
	   
	 }
	 
	 
	 @Override
	protected void onDestroy() {
		// TODO Auto-generated method stub
		super.onDestroy();
		System.out.println("==================>onDestroy");
		for(Map.Entry<String, Bitmap> entry : maps.entrySet()){
			   String key = entry.getKey().toString();  
			   String value = entry.getValue().toString();  
			   entry.getValue().recycle();
			   
			   System.out.println("key=" + key + " value=" + value); 			
		}
	}




	static{
		 System.loadLibrary("i8_netsdk");
		 System.loadLibrary("i8_net_sdk");
	 }	 
	 
	/**
	 * 获取图片地址列表
	 * @param file
	 * @return
	 */
	private static ArrayList<String> imagePath(File file) {
		ArrayList<String> list = new ArrayList<String>();

		File[] files = file.listFiles();
		for (File f : files) {
			list.add(f.getAbsolutePath());
		}
		Collections.sort(list);
		return list;
	}	 

    private Map<String,Bitmap> getThumbnailsPhotos(String path) throws FileNotFoundException
    {
		File baseFile = new File(path);
		// 使用TreeMap，排序问题就不需要纠结了
		Map<String,Bitmap> maps = new TreeMap<String, Bitmap>();
		if (baseFile != null && baseFile.exists()) {
			paths = imagePath(baseFile);

			if (!paths.isEmpty()) {
				for (int i = 0; i < paths.size(); i++) {
					 BitmapFactory.Options options = new BitmapFactory.Options();
					 options.inJustDecodeBounds = true; // 设置了此属性一定要记得将值设置为false
					 bitmap =BitmapFactory.decodeFile(paths.get(i),options);
					 options.inJustDecodeBounds = false;
					 int be = options.outHeight/40;
					 if (be <= 0) {
						 be = 10;
					 }
					 options.inSampleSize = be;
					 bitmap = BitmapFactory.decodeFile(paths.get(i),options);					
//					 InputStream inputStream = null;
//					 try {
//						 inputStream = new FileInputStream(paths.get(i));
//					 } catch (FileNotFoundException e) {
//						 e.printStackTrace();
//				 	 }
//					 BitmapFactory.Options options = new BitmapFactory.Options();
////					 options.inJustDecodeBounds = true; // 设置了此属性一定要记得将值设置为false
////					 bitmap = BitmapFactory.decodeStream(inputStream, null, options);
//					 
//					 options.inJustDecodeBounds = false;
//					 int be = options.outHeight/40;
//					 if (be <= 0) {
//						 be = 10;
//					 }
//					 options.inSampleSize = be;
//					 bitmap = BitmapFactory.decodeStream(inputStream, null, options);
					 maps.put(paths.get(i), bitmap);
				}
//				bitmap.recycle();
			}
		}

		return maps;
      
    }	 
	
	private ListAdapter getMenuAdapter(String[] menuNameArray,
			int[] menuImageArray) {
		ArrayList<HashMap<String, Object>> data = new ArrayList<HashMap<String, Object>>();
		for (int i = 0; i < menuNameArray.length; i++) {
			HashMap<String, Object> map = new HashMap<String, Object>();
			map.put("itemImage", menuImageArray[i]);
			map.put("itemText", menuNameArray[i]);
			data.add(map);
		}
		SimpleAdapter simperAdapter = new SimpleAdapter(this, data,
				R.layout.item_menu, new String[] { "itemImage", "itemText" },
				new int[] { R.id.item_image, R.id.item_text });
		return simperAdapter;

	}	
	
	private void showDelController()
	{
		delController.showAtLocation(gView, Gravity.BOTTOM, 0, 0);
		delController.update(0, 0, screenWidth, dip2px(this, 60));
		isDelCtrlShow = false;
	}
	
	private void hideDelController()
	{
		if (delController.isShowing()) {
			delController.update(0, 0, 0, 0);
			isDelCtrlShow = true;
		}
	}
	
	private void showController(){
		LayoutInflater mLayoutInflater = (LayoutInflater) getSystemService(LAYOUT_INFLATER_SERVICE);
		ViewGroup menuView = (ViewGroup) mLayoutInflater.inflate(
				R.layout.gridview_pop, null, true);
		menuGrid = (GridView) menuView.findViewById(R.id.gridview);
		menuGrid.setAdapter(getMenuAdapter(menu_name_array, menu_image_array));
		menuGrid.setSelector(new ColorDrawable(Color.TRANSPARENT));
		menuGrid.requestFocus();
		menuGrid.setOnItemClickListener(new OnItemClickListener() {

			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
					long arg3) {
				// TODO Auto-generated method stub
				for(Map.Entry<String, Bitmap> entry : maps.entrySet()){
					   String key = entry.getKey().toString();  
					   String value = entry.getValue().toString();  
					   entry.getValue().recycle();
					   bitmap.recycle();
					   System.gc();
				}
				
				switch (arg2) {
				case 0:
					Intent intent0 = new Intent(ImagesManage.this, PTZControl.class);
					startActivity(intent0);	
//					System.exit(1);
					break;
				case 1:
					Intent intent1 = new Intent(ImagesManage.this, QueryRemoteFile.class);
					startActivity(intent1);		
					break;
				case 2:
					Intent intent2 = new Intent(ImagesManage.this, RemoteControl.class);
					startActivity(intent2);	
					break;
				case 3:
					Intent intent3 = new Intent(ImagesManage.this, Discovery.class);
					startActivity(intent3);		
					break;
				case 4:
					menuController.dismiss();					
					break;
				default:
					break;
				}
			}
		});
		
		menuController = new PopupWindow(menuView, LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
		// 创建PopupWindow对象
		menuController.setFocusable(true);
		menuController.setBackgroundDrawable(new BitmapDrawable());
		menuController.showAsDropDown(menuBtn);

		menuController.update();
		isControllerShow = false;
	}

	public static int dip2px(Context context, float dpValue) { 
		final float scale = context.getResources().getDisplayMetrics().density ; 
		return (int) (dpValue * scale + 0.5f) ;
	}   
}
