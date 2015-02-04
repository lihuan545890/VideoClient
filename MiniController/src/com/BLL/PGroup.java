package com.BLL;

import java.util.ArrayList;  

public class PGroup {  
	private String resolution;
	private String frameRate;
	private String bitrate;
	private String bitratetype;
	private boolean isChecked;  
    private ArrayList<PChild> children;  
    
    public PGroup(String resolution, String frameRate, String bitrate, String bitratetype) {  
        this.resolution  = resolution;  
        this.frameRate   = frameRate;
        this.bitrate 	 = bitrate;
        this.bitratetype = bitratetype;
        this.isChecked = false;  
        children = new ArrayList<PChild>();  
    }  
    
    public void setChecked(boolean isChecked) {  
        this.isChecked = isChecked;  
    }  
   
    public void toggle() {  
        this.isChecked = !this.isChecked;  
    }  
   
    public boolean getChecked() {  
        return this.isChecked;  
    }      
   
    public String getResolution() {
		return resolution;
	}
    
    public String getFrameRate()
    {
    	return frameRate;
    }
    
    public String getBitrateType()
    {
    	return bitratetype;
    }
   
    public String getBitrate() {
		return bitrate;
	}
    
    public void setResolution(String resolution) {
    	this.resolution = resolution;
    }
    
    public void setFrameRate(String frameRate)
    {
    	this.frameRate = frameRate;
    }
   
    public void setBitrate(String bitrate) {
    	this.bitrate = bitrate;
    }
    
    public void setBitrateType(String bitratetype) {
    	this.bitratetype = bitratetype;
    }
    
    public void addChildrenItem(PChild child) {  
        children.add(child);  
    }  
   
    public int getChildrenCount() {  
        return children.size();  
    }  
   
    public PChild getChildItem(int index) {  
        return children.get(index);  
    }  
}  
