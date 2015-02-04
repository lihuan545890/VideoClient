package com.Activity;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.nio.ShortBuffer;
import java.text.SimpleDateFormat;
import java.util.Date;

 







import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.media.MediaCodec;
import android.media.MediaFormat;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.opengl.GLSurfaceView;
import android.opengl.GLSurfaceView.Renderer;
import android.opengl.GLUtils;
import android.os.Environment;
import android.provider.ContactsContract.Contacts.Data;
import android.util.AttributeSet;
import android.util.Log;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.ViewGroup.LayoutParams;

public class Preview4LowVersion extends GLSurfaceView implements Renderer {

	public boolean playState = false;
    public String  deviceType;
    public String  szIp;
    public int     nPort;
    public String  szUserName;
    public String  szPsw;
	public int     nChannel;
	public int     byResolution;
	public int	   realPlayId;
	public int	   nUserId;
	public int	   decodeId;
	public int	   handle;
	public boolean initState = false;
	
    private int mVideoWidth  = 2048;
    private int mVideoHeight = 2048;
    
    int changedWidth; 
    int changedHeight;
    
    byte [] mPixel ;
    ByteBuffer buffer;
//    byte[] mPixel;
//    ByteBuffer buffer;
    
	FloatBuffer vertices;
	FloatBuffer texture;
	ShortBuffer indices;
	private int textureId;
	private int textureIds[] = new int[1];  
	private int count = 0;  
	public boolean flag = false;
	
	private GL10 gl10;
	private long firsttime, lasttime;
    
	//网络库
	public native boolean  Init();  
	public native boolean  Cleanup();
	public native int      Login(String ip,int port,String Username,String Passwd);
	public native int	   Start(int UserId,int Channel,int LinkMode,int x,int y,int Width,int Height); //码流请求函数
	public native boolean  Stop(int RealPlayId);
	public native boolean  Logout(int uid);
	public native boolean  GetDeviceAbility(int UserId, int Channel);
	public native String[] GetResolutionAbility();
	public native String[] GetFramerateAbility();
	public native String[] GetBitrateAbility();
	public native String[] GetBitrateTypeAbility();
	public native String   GetClientVideoParam(int UserId, int Channel);
	public native boolean  SetClientVideoParam(int UserId, int Channel, String Resolution, String Framerate, String Bitrate, String BitrateType, int BitrateValue);	
	  
	//解码库   
    public native int  DecodeInit(int width,int height);
    public native int  UninitDecoder(); 
    public native int  DecoderNal(int nHandle, byte[] in, int insize, byte[] out);
	
    static {
    	System.loadLibrary("Ants_H264");	
    }
     
	public Preview4LowVersion(Context context) {
		super(context);   
	}     
	
	public Preview4LowVersion(Context context, AttributeSet attrs) {
		super(context, attrs);
		// TODO Auto-generated constructor stub
		//对于XML这种引用方式是必须实现的
		
		setFocusable(true); 

//        this.holder = this.getHolder();   
//        holder.addCallback(this); 
       	mPixel = new byte[mVideoWidth*mVideoHeight*2];
       	buffer = ByteBuffer.wrap( mPixel );
       	int i = mPixel.length;
		ByteBuffer byteBuffer = ByteBuffer.allocateDirect(4 * 2 * 4);
        byteBuffer.order(ByteOrder.nativeOrder());            
        vertices = byteBuffer.asFloatBuffer();  

        vertices.put( new float[] {  -300f,   100f,
                                     0f,  100f, 
                                     -300f, 600f,
                                     0f,  600f});
        
        ByteBuffer indicesBuffer = ByteBuffer.allocateDirect(6 * 2);
        indicesBuffer.order(ByteOrder.nativeOrder()); 
        indices = indicesBuffer.asShortBuffer();
        indices.put(new short[] { 0, 1, 2,1,2,3});
        
        ByteBuffer textureBuffer = ByteBuffer.allocateDirect(4 * 2 * 4);
        textureBuffer.order(ByteOrder.nativeOrder());            
        texture = textureBuffer.asFloatBuffer();
        texture.put( new float[] { 0,1f,
                                    1f,1f,
                                    0f,0f,
                                    1f,0f});
        
        indices.position(0);
        vertices.position(0);
        texture.position(0);    	
    	
        
        setRenderer(this);
        setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
        for(i=0; i<mPixel.length; i++)
        {
        	mPixel[i]=(byte)0x00;
        }
        System.out.println("===================>Preview4LowVersion");
	}
	
	public Preview4LowVersion(Context context, AttributeSet attrs, int defStyle){
		super(context, attrs);
	}
	
    public void setVideoScale(int width , int height){
    	LayoutParams lp = getLayoutParams();
    	lp.height = height;
		lp.width = width;
		setLayoutParams(lp);
    }
  
	public int InitDecoder(int width, int height)
	{
		mVideoWidth  = width;
		mVideoHeight = height;
//		mPixel = new byte[mVideoWidth*mVideoHeight*2];
		int nHandle = DecodeInit(mVideoWidth, mVideoHeight);
		
		setPosition();
		return nHandle;
	}
	  
    public void Decode_V1(int nHandle, byte[] Buffer,int Size,int FrameType)
    {
			DecoderNal(nHandle, Buffer, Size, mPixel); 
			flag = false;
			requestRender();
    }      
    	
    public boolean CapturePicture()
    {
    	Date date = new Date();
    	SimpleDateFormat dateFormat = new SimpleDateFormat("yyyyMMddHHmmss");
    	String dateStr = dateFormat.format(date);
    	
    	Bitmap bitmap= Bitmap.createBitmap(mVideoWidth, mVideoHeight, Config.RGB_565); 
    	bitmap.copyPixelsFromBuffer(buffer);
    	buffer.position(0);
    	saveMyBitmap(bitmap,dateStr);
		return true;
    	
    }
    
    private void updateGallery(Context context, String filename)//filename是我们的文件全名，包括后缀哦  
    {  
    	MediaScannerConnection.scanFile(context, new String[] { filename }, new String[] { "image/jpg" }, new MediaScannerConnection.OnScanCompletedListener() {
			
			@Override
			public void onScanCompleted(String path, Uri uri) {
				// TODO Auto-generated method stub
              Log.i("ExternalStorage", "Scanned " + path + ":");  
              Log.i("ExternalStorage", "-> uri=" + uri);  				
			}
		});
 
    }  
    
    private String saveMyBitmap(Bitmap mBitmap,String bitName)  {
    	String savefilePath = null;
    	
    	if (Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED)) {
    		savefilePath = Environment.getExternalStorageDirectory().getPath()+"/ants_mobile/";
		}else {
			savefilePath = "/ants_mobile/";
		}
    	new File(savefilePath).mkdir();
    	
        File f = new File(savefilePath +bitName + ".jpg");
        FileOutputStream fOut = null;
        try {
                fOut = new FileOutputStream(f);
        } catch (FileNotFoundException e) {
                e.printStackTrace();
        }
        mBitmap.compress(Bitmap.CompressFormat.JPEG, 100, fOut);
        try {
                fOut.flush();
        } catch (IOException e) {
                e.printStackTrace();
        }
        try {
                fOut.close();
        } catch (IOException e) {
                e.printStackTrace();
        }
        
        return f.getName();
    }
    
	@Override 
	public void onDrawFrame(GL10 gl) {
		// TODO Auto-generated method stub
					
					if (flag) {

					
						gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT); // 清除屏幕和深度缓存

					}else {
						try {
							textureId = loadTexture(gl, textureIds[0]);
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}

						//定义显示在屏幕上的什么位置(opengl 自动转换)   
						gl.glMatrixMode(GL10.GL_PROJECTION);
						gl.glLoadIdentity();
						gl.glOrthof(-300, 0, 100, 600, 1, -1); 
						

						  
						gl.glEnable(GL10.GL_TEXTURE_2D);
						//绑定纹理ID
						gl.glBindTexture(GL10.GL_TEXTURE_2D, textureId);
						
						gl.glTexSubImage2D(GL10.GL_TEXTURE_2D, 0, 0,0, mVideoWidth, mVideoHeight, GL10.GL_RGB, GL10.GL_UNSIGNED_SHORT_5_6_5, buffer);
						
						gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
						gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
						
						gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertices);  
						
						gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, texture);
						
						gl.glDrawElements(GL10.GL_TRIANGLE_STRIP, 6,
								GL10.GL_UNSIGNED_SHORT, indices);	
						
					}

	}    
    
	@Override  
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		// TODO Auto-generated method stub
		gl.glViewport(0, 0, width, height);
		System.out.println("onSurfaceChanged");
		if (flag) {
			gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT); // 清除屏幕和深度缓存
			System.out.println("onSurfaceChanged====================>onclear");
		}
	}  
 
	@Override
	public void onSurfaceCreated(GL10 gl,
			javax.microedition.khronos.egl.EGLConfig config) {
		// TODO Auto-generated method stub
		gl.glGenTextures(1, textureIds, 0); //创建纹理ID

	}  
    
	public int loadTexture(GL10 gl, int textureId) throws IOException {

		gl.glBindTexture(GL10.GL_TEXTURE_2D, textureId);
		
//		Log.i("Size", "mVideoWidth="+mVideoWidth+" mVideoHeight:"+mVideoHeight);
		
		gl.glTexImage2D(GL10.GL_TEXTURE_2D, 0, GL10.GL_RGB, 2048, 2048, 0, GL10.GL_RGB, GL10.GL_UNSIGNED_SHORT_5_6_5, null);
		gl.glTexParameterf(GL10.GL_TEXTURE_2D,
				GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_NEAREST);
		gl.glTexParameterf(GL10.GL_TEXTURE_2D,
				GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_NEAREST);   
		return textureId;
	}  
  
	public void onClear()
	{
		flag = true;
		System.out.println("1111===========>onClear");

	}
	
	public void setPosition()
	{
	    float glX = (float) ((double) mVideoWidth/ (double)2048);
	    float glY = (float) ((double) mVideoHeight/ (double)2048);
	    
        ByteBuffer textureBuffer = ByteBuffer.allocateDirect(4 * 2 * 4);
        textureBuffer.order(ByteOrder.nativeOrder());            
        texture = textureBuffer.asFloatBuffer();
        
        texture.put( new float[] { 0,glY,
        		glX,glY,
                0f,0f,
                glX,0f});
        
        texture.position(0);    		
	}
 
	
}
