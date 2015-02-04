package com.Activity;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.Canvas;
import android.media.MediaCodec;
import android.media.MediaFormat;
import android.util.AttributeSet;
import android.util.Log;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.ViewGroup.LayoutParams;

public class Preview extends SurfaceView {

	public boolean playState = false;
    public String  deviceType;
    public String  szIp;
    public int     streamUid;
	public int     nChannel;
	public int	   realPlayId;
	public int	   handle;
	
	private byte[] frame;
	private int	   frameNo=0;
	private int    sampleSize = 0 ;
	private int    frameType;
	private int    absoluteTime, relativeTime;
	private int	   lastFrameNo = 0;
	private SurfaceHolder holder; 
	private MediaCodec decoder; 
	private Surface surface;
	private String  mimeType = "video/avc";
    private boolean flag = true;
    private ByteBuffer[] inputBuffers,outputBuffers;
    public boolean isEOS = false;
    
	//网络库
	public native boolean Init();
	public native boolean Cleanup();
	public native int     Login(String ip,int port,String Username,String Passwd);
	public native int	  Start(int UserId,int Channel,int LinkMode,int x,int y,int Width,int Height);
	public native boolean Stop(int RealPlayId);
	public native boolean Logout(int uid);
	
	
    
	public Preview(Context context) {
		super(context);
		setFocusable(true);
//        this.holder = this.getHolder();  
//        holder.addCallback(this); 
    	holder = this.getHolder();
	}  

	public Preview(Context context, AttributeSet attrs) {
		super(context, attrs);
		// TODO Auto-generated constructor stub

	}

	public Preview(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		// TODO Auto-generated constructor stub
	}
	
	public void StopDecoder()
	{
		isEOS = true;
		if (decoder != null) 
		{
	        decoder.stop();  
	        decoder.release();  
			decoder=null;			
		}

	}
	
    public void setVideoScale(int width , int height){
    	LayoutParams lp = getLayoutParams();
    	lp.height = height;
		lp.width = width;
		setLayoutParams(lp);
    }
	
	@SuppressLint("InlinedApi")
	public void InitDecoder(Surface surface)
	{
		isEOS = false;
		decoder = MediaCodec.createDecoderByType(mimeType);
    	MediaFormat format = MediaFormat.createVideoFormat(mimeType, 352, 288);
    	format.setInteger(MediaFormat.KEY_BIT_RATE, 512000);
    	format.setInteger(MediaFormat.KEY_FRAME_RATE, 25);
    	format.setInteger(MediaFormat.KEY_CHANNEL_COUNT, 1);
    	decoder.configure(format, surface, null, 0);
        if (decoder == null) 
        {  
            return;  
        }  
        
        decoder.start();    
        
        inputBuffers = decoder.getInputBuffers(); 
	}
	
	public void Decode(byte[] Buffer,int Size,int FrameType)
	{
		int inIndex=0;
		if (FrameType != 8)
		{
        	if (Buffer != null) 
        	{
		        if (!isEOS) 
		        {	
					try {
						inIndex = decoder.dequeueInputBuffer(10000); 
					} catch (Exception e) {
						e.printStackTrace();
					}
		            
		            if (inIndex >= 0)
		            { 
	                    ByteBuffer inputBuffer = inputBuffers[inIndex];  
	                    inputBuffer.clear();	
	                    inputBuffer.put(Buffer, 0, Size);
	                    decoder.queueInputBuffer(inIndex, 0, Size, 1000, 0); 
		            }  
		        }  
	        
		        MediaCodec.BufferInfo info = new MediaCodec.BufferInfo();
		        int outIndex = decoder.dequeueOutputBuffer(info, 0);  //获取接收到结果的ByteBuffer索引位置
	
		        while(outIndex >= 0) 
		        {
			        decoder.releaseOutputBuffer(outIndex, true);  //释放所有权
			        outIndex = decoder.dequeueOutputBuffer(info, 0);        		
				}
	        
	     }  		
		}
	}
	
	
}
