package com.BLL;

import java.util.ArrayList;  

import android.app.Activity;
import android.content.Context;  
import android.content.Intent;
import android.graphics.Color;
import android.opengl.Visibility;
import android.util.Log;
import android.view.LayoutInflater;  
import android.view.View;  
import android.view.View.OnClickListener;  
import android.view.ViewGroup;  
import android.widget.BaseExpandableListAdapter;  
import android.widget.CheckBox;  
import android.widget.CompoundButton;
import android.widget.CompoundButton.OnCheckedChangeListener;
import android.widget.EditText;
import android.widget.ExpandableListView;  
import android.widget.ExpandableListView.OnChildClickListener;
import android.widget.LinearLayout;
import android.widget.LinearLayout.LayoutParams;
import android.widget.RadioButton;
import android.widget.RelativeLayout;
import android.widget.TextView;  
import com.Activity.PTZControl;
import com.Activity.Preview;
import com.example.minicontroller.R;
  
public class PListAdapter extends BaseExpandableListAdapter{  
      
    private Context  context;  
    private ArrayList<PGroup> groups;  
    private TextView name;
    private TextView value;
   
    public PListAdapter(Context  context, ArrayList<PGroup> groups) {  
        this.context = context;  
        this.groups = groups;  
    }  
   
    public Object getChild(int groupPosition, int childPosition) {  
        return groups.get(groupPosition).getChildItem(childPosition);  
    }  
   
    public long getChildId(int groupPosition, int childPosition) {  
        return childPosition;  
    }  
   
    public int getChildrenCount(int groupPosition) {  
        return groups.get(groupPosition).getChildrenCount();  
    }  
   
    public Object getGroup(int groupPosition) {  
        return groups.get(groupPosition);  
    }  
   
    public int getGroupCount() {  
        return groups.size();  
    }  
   
    public long getGroupId(int groupPosition) {  
        return groupPosition;  
    }  
   
    public boolean hasStableIds() {  
        return true;  
    }  
   
    public boolean isChildSelectable(int groupPosition, int childPosition) {  
        return true;  
    }  
   
    /** 設定 Group 資料 */  
    public View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {  
        PGroup group = (PGroup) getGroup(groupPosition);  
   
        if (convertView == null) {  
            LayoutInflater infalInflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);  
            convertView = infalInflater.inflate(R.layout.group_layout1, null);  
        }  
 
        name = (TextView) convertView.findViewById(R.id.paraName);  
        name.setTextColor(Color.WHITE);  
        value = (TextView) convertView.findViewById(R.id.paraValue);  
        value.setTextColor(Color.WHITE);      
        
        String nameStr = null;
        String valueStr = null;
        
        switch (groupPosition) {
		case 0:
			nameStr = "分辨率";
			valueStr = group.getResolution();
			break;
		case 1:
			nameStr = "帧率";
			valueStr = group.getFrameRate();
			break;
		case 2:
			nameStr = "位率类型";
			valueStr = group.getBitrateType();
			break;				
		case 3:
			nameStr = "位率上限";
			valueStr = group.getBitrate();
			break;			
		default:
			break;
		}

        name.setText(nameStr);  
        value.setText(valueStr);   

        return convertView;  
    }    
        
    /** 設定 Children 資料 */  
    public View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {  
        PChild child = groups.get(groupPosition).getChildItem(childPosition);  
        PGroup group = groups.get(groupPosition);
        ViewHolder holder = null;

    	holder = new ViewHolder();
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);  
        convertView = inflater.inflate(R.layout.pchild_layout, null);  
        
        holder.radioBtn = (RadioButton)convertView.findViewById(R.id.radioBtn);
        holder.paramText = (TextView)convertView.findViewById(R.id.paramText);
        
        holder.paramText.setTextColor(Color.WHITE);
        holder.paramText.setText(child.getParam());

        holder.radioBtn.setEnabled(false);
        
        switch (groupPosition) {
		case 0:
	        if (group.getResolution()!=null&&group.getResolution().equals(child.getParam())) {
	        	holder.radioBtn.setChecked(true);
			}else {
				holder.radioBtn.setChecked(false); 
			}			
			break;
		case 1:
	        if (group.getFrameRate()!=null&&group.getFrameRate().equals(child.getParam())) {
	        	holder.radioBtn.setChecked(true);
			}else {
				holder.radioBtn.setChecked(false);
			}			
			break;
		case 2:
	        if (group.getBitrateType()!=null&&group.getBitrateType().equals(child.getParam())) {
	        	holder.radioBtn.setChecked(true);
			}else {
				holder.radioBtn.setChecked(false);
			}	
	        
	        break;
		case 3:
	        if (group.getBitrate()!=null&&group.getBitrate().equals(child.getParam())) {
	        	holder.radioBtn.setChecked(true);
			}else {
				holder.radioBtn.setChecked(false);
			}			
	        
			break;			
		default:
			break;
		} 

        holder.radioBtn.setTag(childPosition);

        notifyDataSetChanged();
        return convertView;  
    }

	public class ViewHolder{
		public TextView paramText;
		public RadioButton radioBtn;
	}
      
}  

