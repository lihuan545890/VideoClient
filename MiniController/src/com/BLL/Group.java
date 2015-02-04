package com.BLL;

import java.util.ArrayList;  

public class Group {  
	private String ip;
	private int    port;
	private String username;
	private String password;
	private String devicetype;
    private int    channelno;
    private ArrayList<Child> children;  
    
    public Group(String ip, int port, String username, String password, String devicetype) {  
        this.ip       = ip;  
        this.port     = port;
        this.username = username;
        this.password = password;
        this.devicetype = devicetype;
        children = new ArrayList<Child>();  
    } 
    
    public Group(String ip, int port, String username, String password, String devicetype, int channelno) {  
        this.ip       = ip;  
        this.port     = port;
        this.username = username;
        this.password = password;
        this.devicetype = devicetype;
        this.channelno = channelno;
        children = new ArrayList<Child>();  
    } 
   
    public String getIp() {
		return ip;
	}
    
    public int getPort()
    {
    	return port;
    }
   
    public String getUserName() {
		return username;
	}
    
    public String getPassWord() {
		return password;
	}
    
    public String getDeviceType()
    {
    	return devicetype;
    }
    
    public int getChannelNo()
    {
    	return channelno;
    }
    
    public void addChildrenItem(Child child) {  
        children.add(child);  
    }  
   
    public int getChildrenCount() {  
        return children.size();  
    }  
   
    public Child getChildItem(int index) {  
        return children.get(index);  
    }  
}  
