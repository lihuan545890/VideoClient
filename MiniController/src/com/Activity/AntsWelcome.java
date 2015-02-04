package com.Activity;

import com.Utility.SysApplication;
import com.example.minicontroller.R;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;

public class AntsWelcome extends Activity {
    @Override  
    protected void onCreate(Bundle savedInstanceState)  
    {  
        super.onCreate(savedInstanceState);  
        setContentView(R.layout.main);  
        
        SysApplication.getInstance().addActivity(this);
        new Handler().postDelayed(new Runnable()  
        {  
    
            @Override  
            public void run()  
            {  
                // TODO Auto-generated method stub  
                Intent intent=new Intent(AntsWelcome.this,PTZControl.class);  
                startActivity(intent);  
                AntsWelcome.this.finish();  
            }  
        }, 2000);  
    }  
}
