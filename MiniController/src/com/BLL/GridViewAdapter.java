package com.BLL;

import java.io.File;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.Vector;

import android.R.integer;
import android.content.ContentResolver;
import android.content.Context;
import android.content.res.Resources;
import android.database.SQLException;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.ThumbnailUtils;
import android.provider.MediaStore.Images.Thumbnails;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AbsListView.LayoutParams;
import android.widget.BaseAdapter;
import android.widget.ImageView;

import com.example.minicontroller.R;

public class GridViewAdapter extends BaseAdapter
{
	  private Map<String,Bitmap> itemMap;
	  private LayoutInflater mInflater;
	  private Context context;
	  private ArrayList<String> imagepath;
	  private Vector<Boolean> mImage_bs = new Vector<Boolean>();    // 定义一个向量作为选中与否容器  
	  
	  public GridViewAdapter(Context context, Map<String,Bitmap> itemMap)
	  {
	    mInflater = LayoutInflater.from(context);
	    this.context = context;
	    this.itemMap = itemMap;
	    
	    int length = itemMap.keySet().toArray().length;
	    imagepath = new ArrayList<String>();
	    for (int i = 0; i < length; i++) {
	    	imagepath.add((String) itemMap.keySet().toArray()[i]);
			mImage_bs.add(false);
		}
	    
	  }
	  
	  public int getCount()
	  {
	    return itemMap.size();
	  }

	  public Object getItem(int position)
	  {
		  return position;
	  }
	  
	  public long getItemId(int position)
	  {
	    return position;
	  }
	  

	  public View getView(int position,View convertView,ViewGroup parent)
	  {
		  GridItem item;
          if (convertView == null) {
              item = new GridItem(context);
              item.setLayoutParams(new LayoutParams(LayoutParams.FILL_PARENT,
                      LayoutParams.FILL_PARENT));
          } else {
              item = (GridItem) convertView;
          }
//          item.setImgBitmap(itemMap.get(imagepath[position]));
          item.setImgBitmap(itemMap.get(imagepath.get(position)));
          
//          System.out.println("position:"+position+"getView:"+imagepath.get(position));  
          
          item.setChecked(mImage_bs.elementAt(position) == null ? false
                  : mImage_bs.elementAt(position));
          return item;
	  }
	  
	  public void changeState(int position)
	  {
		  mImage_bs.setElementAt(!mImage_bs.elementAt(position), position);
		  notifyDataSetChanged();
	  }
	  
	  public void allNotChoose()
	  {
		  for (int i = 0; i < mImage_bs.size(); i++){
			  if(mImage_bs.elementAt(i) == true){
				  mImage_bs.setElementAt(false, i);
			  }
		  }
		  notifyDataSetChanged();
	  }
	  
	  public void delSelectedImages()
	  {
		  for (int i = 0; i < mImage_bs.size(); i++) {
			if(mImage_bs.elementAt(i) == true)
			{
				File f = new File(imagepath.get(i));
				if (f.exists()) {
					f.delete();
//					imagepath.remove(i);
//
//					itemMap.remove(imagepath.get(i));
//					mImage_bs.remove(i);
				}
			}
		  }	
	  }
	  
	  public ArrayList<String> getSelectedItems()
	  {
		  ArrayList<String> iList = new ArrayList<String>();
		  
		  for (int i = 0; i < mImage_bs.size(); i++) {
			if(mImage_bs.elementAt(i) == true)
			{

				iList.add(imagepath.get(i));
			}
		  }	
		  return iList;
	  }
}