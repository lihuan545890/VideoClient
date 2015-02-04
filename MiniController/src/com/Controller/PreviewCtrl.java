package com.Controller;

import android.content.Context;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class PreviewCtrl extends SurfaceView    {

	
	public PreviewCtrl(Context context) {
		super(context);
		m_surfaceHolder = getHolder();
		// TODO Auto-generated constructor stub
	}
 
	
	public static native int SetServer(String sSvrAddr, int nPort, String sn);

	public static native int SetCryptoPolicy_Key(byte[] pKey);

	public static native int SetCryptoPolicy_ssrc_Value(int ssrc);

	public static native int Stop();

	public static native int Start();


	 
	static SurfaceHolder m_surfaceHolder;
	 
}
