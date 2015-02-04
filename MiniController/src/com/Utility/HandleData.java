package com.Utility;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.util.Log;

import com.Data.ResultVideo;

public class HandleData {
	
	public static void removeDuplicateAndSort(ArrayList<String> list) 
	{
	   HashSet<String> hashSet = new HashSet<String>(list);	
	   
	   list.clear();
	   list.addAll(hashSet);
		
	   for ( int i = 0 ; i < list.size() - 1 ; i ++ )
	   {
		   for(int j=1;j<list.size()-i;j++)
		   {
			   String tmp;
			   long tmp1 = Long.parseLong(list.get(j-1).substring(13, 19));
			   long tmp2 = Long.parseLong(list.get(j).substring(13, 19));
			   
			   if (tmp1 > tmp2)
			   {
				   tmp = list.get(j-1);
				   list.set((j-1),list.get(j));
				   list.set(j, tmp);
			   }	
			   
		   }
	   }
//	    System.out.println(list.toString());
	}
	
	public static int byteToInt2(byte[] b,int offset) {
        int n=0;  
        int temp = 0;
        
        for(int i=3;i>=0;i--)
       {  
           n<<=8; 
           temp = b[i+offset]&0xff;
           n |= temp;
       } 
        return n;  
	 }  

}
