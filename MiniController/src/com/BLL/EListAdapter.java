package com.BLL;

import java.util.ArrayList;  

import android.app.Activity;
import android.content.Context;  
import android.content.Intent;
import android.graphics.Color;
import android.util.Log;
import android.view.LayoutInflater;  
import android.view.View;  
import android.view.View.OnClickListener;  
import android.view.ViewGroup;  
import android.widget.BaseExpandableListAdapter;  
import android.widget.CheckBox;  
import android.widget.ExpandableListView;  
import android.widget.TextView;  

import com.Activity.Preview;
import com.example.minicontroller.R;
  
  
public class EListAdapter extends BaseExpandableListAdapter {  
      
    private Context context;  
    private ArrayList<Group> groups;  
   
    public EListAdapter(Context context, ArrayList<Group> groups) {  
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
        Group group = (Group) getGroup(groupPosition);  
   
        if (convertView == null) {  
            LayoutInflater infalInflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);  
            convertView = infalInflater.inflate(R.layout.group_layout, null);  
        }  
   
        TextView tv = (TextView) convertView.findViewById(R.id.tvGroup);  
        tv.setTextColor(Color.WHITE);
        tv.setText(group.getIp());  
   
        return convertView;  
    }  
   
    /** 勾選 Group CheckBox 時，存 Group CheckBox 的狀態，以及改變 Child CheckBox 的狀態 */  
   
    /** 設定 Children 資料 */  
    public View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {  
        Child child = groups.get(groupPosition).getChildItem(childPosition);  
   
        if (convertView == null) {  
            LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);  
            convertView = inflater.inflate(R.layout.child_layout, null);  
        }  
   
        TextView tv = (TextView) convertView.findViewById(R.id.tvChild);  
        tv.setTextColor(Color.WHITE);
        tv.setText("通道"+child.getChannel());  
   
        return convertView;  
    }  
   
      
}  
