package com.BLL;

public class PChild {  
    private String paramStr;
    private boolean isChecked;  
    
    public PChild(String paramStr)
    {
    	this.paramStr = paramStr;
    }
   
    public String getParam() {  
        return paramStr;  
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
   
}  
