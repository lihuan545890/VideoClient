package com.Utility;

import org.apache.http.client.CookieStore;

import android.R.integer;

public class DataDefine {

	public static CookieStore mCookieStore;
	 
	// 成功
	public static int SUCCESS = 0;
	//失败
	public static int FAILURE = 1;
	// 超时
	public static int TimeOut = 3004;
	public static String UserID =""; // 用户ID，服务器返回
	public static String Message; // 服务器注册后返回的信息，暂时没用
	public static String userName ="admin";
	public static String cloudpassword = "";// 云服务密码
	public static String password = "admin"; // 软件密码
	public static String client = ""; // 用户手机号码
	 
	//视频请求
	
	public static String Ip="";
	public static String Port="";
	public static String Identification="";//视频请求
	// 只有开关的几个状态的字符串输出
	public static String getSwitch(int value) {
		switch (value) {
		case 0:
			return "关闭";
		case 1:
			return "开启";
		default:
			return "无效";
		}
	}

	 

	// =============================================//
	// 数据库名称
	// =============================================//
	public static String DBNAME = "dev.db";
	
	
	//模拟json格式，正式发布删除
		public static final String JSONExample = 
				"{" +   
						"   \"status\" : \"0\"," + 
						"   \"SerResult\" : [" +
						"{\"LocalIP\":\"192.168.0.50\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e021\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.51\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e022\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.52\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e023\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.53\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e024\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.54\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e025\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.55\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e026\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.56\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e027\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.57\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e028\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.58\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e029\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.59\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e030\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}," +
						"{\"LocalIP\":\"192.168.0.60\",\"SubNetMask\":\"255.255.255.0\",\"DefaultGateWay\":\"192.168.0.1\",\"PreferredDNS\":\"202.103.24.168\",\"AlternateDNS\":\"202.103.24.68\",\"MACAddress\":\"00:62:9f:59:e0:21\",\"PrivatePort\":5050,\"HTTPPort\":80,\"RSTPPort\":554,\"HTTPSPort\":443\"SerialNo\":\"0150101061629f59e031\",\"UserName\":\"admin\",\"Password\":\"\",\"DeviceType\":\"NVR-16\"}]" +
					 
				"}"; 
		
		
		//	//模拟json格式，正式发布删除
		public static final String JSONQueryResult = 
				"{" +   
						"   \"ResultCode\" : \"0\"," + 
						"   \"ResultContent\" : [" +
						"{\"Content\":\"Ch_0020131115000001_20131115000853\"}," +
						"{\"Content\":\"Ch_0020131115100853_20131115003700\"}," +
						"{\"Content\":\"Ch_0020131115003701_20131115010520\"}," +
						"{\"Content\":\"Ch_0020131115010521_20131115013348\"}," +
						"{\"Content\":\"Ch_0020131115013348_20131115020219\"}," +
						"{\"Content\":\"Ch_0020131115020220_20131115023016\"}," +
						"{\"Content\":\"Ch_0020131115023016_20131115025820\"}," +
						"{\"Content\":\"Ch_0020131115025821_20131115032616\"}," +
						"{\"Content\":\"Ch_0020131115032617_20131115035441\"}," +
 						"{\"Content\":\"Ch_0020131115035441_20131115042240\"}]" +
				"}"; 
		
		
		// ==============================================================//
		// 设备信息表
		// ==============================================================//
		public static String TABLE_DEVIDE 				= "tb_devices"; 	// 表名
		public static String TABLE_DEVIDE1 				= "tb1_devices"; 	// 临时表名
		public static String KEY_DEV_ID_AUTO_INCREMENT 	= "_id"; 			// 自增字段，固定格式,主键
		public static String KEY_LOCALIP 				= "LocalIP"; 		// 本机地址
		public static String KEY_MASK 					= "SubNetMask"; 	// 设备子网掩码
		public static String KEY_GATEWAY 				= "DefaultGateWay"; // 设备默认网关
		public static String KEY_PDNS 					= "PreferredDNS"; 	// 当前DNS
		public static String KEY_ADNS 					= "AlternateDNS"; 	// 备用DNS
		public static String KEY_MACADDRESS 			= "MACAddress"; 	// 设备MAC地址
		public static String KEY_PORT 					= "PrivatePort"; 	// 设备控制通信端口
		public static String KEY_HTTPPORT 				= "HTTPPort"; 		// HTTPPort序列号
		public static String KEY_RTSPPORT 				= "RTSPPort"; 		// RTSPPort序列号
		public static String KEY_HTTPSPort 				= "HTTPSPort"; 		// HTTPSPort
		public static String KEY_SERIALNO 				= "SerialNo"; 		// 设备序列号(唯一)
		public static String KEY_USERNAME 				= "UserName"; 		// 超级用户名
		public static String KEY_PASSWORD 				= "Password"; 		// UserName对应密码
		public static String KEY_DEVICETYPE 			= "DeviceType"; 	// 设备类型
		public static String KEY_SHOWNAME 				= "ShowName"; 	    // 设备名称别名
		public static String KEY_CHANNELNO				= "ChannelNo";      // 设备通道数
		public static String CREATE_TABLE_DEVIDE 		= "CREATE TABLE IF NOT EXISTS " + TABLE_DEVIDE
				+ "(" + KEY_DEV_ID_AUTO_INCREMENT + " INTEGER PRIMARY KEY,"
				+ KEY_LOCALIP + " TEXT,"  
				+ KEY_MASK + " TEXT,"
				+ KEY_GATEWAY + " TEXT,"
				+ KEY_PDNS + " TEXT,"
				+ KEY_ADNS + " TEXT,"
				+ KEY_MACADDRESS + " TEXT,"
				+ KEY_PORT + " INTEGER,"
				+ KEY_HTTPPORT + " INTEGER,"
				+ KEY_RTSPPORT + " INTEGER,"
				+ KEY_HTTPSPort + " INTEGER,"
				+ KEY_SERIALNO + " TEXT,"
				+ KEY_USERNAME + " TEXT,"
				+ KEY_PASSWORD + " TEXT,"
				+ KEY_DEVICETYPE + " TEXT,"
				+ KEY_SHOWNAME + " TEXT,"
				+ KEY_CHANNELNO + " TEXT)";
		
		public static String CREATE_TABLE_TMPDEVIDE 		= "CREATE TABLE IF NOT EXISTS " + TABLE_DEVIDE1
				+ "(" + KEY_DEV_ID_AUTO_INCREMENT + " INTEGER PRIMARY KEY,"
				+ KEY_LOCALIP + " TEXT,"  
				+ KEY_MASK + " TEXT,"
				+ KEY_GATEWAY + " TEXT,"
				+ KEY_PDNS + " TEXT,"
				+ KEY_ADNS + " TEXT,"
				+ KEY_MACADDRESS + " TEXT,"
				+ KEY_PORT + " INTEGER,"
				+ KEY_HTTPPORT + " INTEGER,"
				+ KEY_RTSPPORT + " INTEGER,"
				+ KEY_HTTPSPort + " INTEGER,"
				+ KEY_SERIALNO + " TEXT,"
				+ KEY_USERNAME + " TEXT,"
				+ KEY_PASSWORD + " TEXT,"
				+ KEY_DEVICETYPE + " TEXT,"
				+ KEY_SHOWNAME + " TEXT,"
				+ KEY_CHANNELNO + " TEXT)";		
	
		// ==============================================================//
		// 定义遥控器键值
		// ==============================================================//
		public enum I8_Remote_Key{
			I8Key_0,
			I8Key_1,
			I8Key_2,
			I8Key_3,
			I8Key_4,
			I8Key_5,
			I8Key_6,
			I8Key_7,
			I8Key_8,
			I8Key_9,
			
			I8Key_Up,
			I8Key_Down,
			I8Key_Left,
			I8Key_Right,
			I8Key_Enter,
			I8Key_Escape,
			
			I8Key_Play,  //回放
			I8Key_Record,
			I8Key_PTZ,
			
			I8Key_PlayFrame, //帧播
			I8Key_PlayFoward, //往前
			I8Key_PlayBack,  //往后
			I8Key_PlayFast, //快放
			I8Key_PlaySlow  //慢放
		}
		
//		enum I8_Remote_Key {
//			I8Key_0 = 0,
//			I8Key_1,
//			I8Key_2,
//			I8Key_3,
//			I8Key_4,
//			I8Key_5,
//			I8Key_6,
//			I8Key_7,
//			I8Key_8,
//			I8Key_9,//数字与值相同，操作通道
//
//			I8Key_EndNum = 1000,
//
//			I8Key_Up = 1001,
//			I8Key_Down,
//			I8Key_Left,
//			I8Key_Right,
//			I8Key_Enter,
//
//			I8Key_EnterRelease,//1006
//			I8Key_Escape,
//			I8Key_Play,
//			I8Key_Record,
//			I8Key_PTZ,
//
//			I8Key_PlayFrame,//1011
//			I8Key_PlayFoward,
//			I8Key_PlayBack,
//			I8Key_PlayFast,
//			I8Key_PlaySlow,
//
//			I8Key_PlayStop, //1016
//			I8Key_Capture,
//			I8Key_AlarmShow,
//			I8Key_Multi,
//			I8Key_Backup,
//
//			I8Key_PowerOff,
//			I8Key_Setting,
//
//
//			};
		public static int Command = 100;//命令
		public static int I8Key_0 = 0;  
		public static int I8Key_1 = 1;  
		public static int I8Key_2 = 2;  
		public static int I8Key_3 = 3;  
		public static int I8Key_4 = 4;  
		public static int I8Key_5 = 5;  
		public static int I8Key_6 = 6;  
		public static int I8Key_7 = 7;  
		public static int I8Key_8 = 8;  
		public static int I8Key_9 = 9; 
		public static int I8Key_EndNum = 1000;
		public static int I8Key_Up = 1001;  
		public static int I8Key_Down = 1002;  
		public static int I8Key_Left = 1003;  
		public static int I8Key_Right = 1004;  
		public static int I8Key_Enter = 1005;  
		public static int I8Key_EnterRelease = 1006;
		public static int I8Key_Escape = 1007;  
		public static int I8Key_Play = 1008;  
		public static int I8Key_Record = 1009;  
		public static int I8Key_PTZ = 1010;  
		public static int I8Key_PlayFrame = 1011;  
		public static int I8Key_PlayFoward = 1012;  
		public static int I8Key_PlayBack = 1013;  
		public static int I8Key_PlayFast = 1014;  
		public static int I8Key_PlaySlow = 1015;  

		public static int I8Key_PlayStop = 1016;  
		public static int I8Key_Capture = 1017;  
		public static int I8Key_AlarmShow = 1018;  
		public static int I8Key_Multi = 1019;  
		public static int I8Key_Backup = 1020;  
		public static int I8Key_PowerOff = 1021;  
		public static int I8Key_Setting = 1022;  

	// ==============================================================//
	// 定义遥控器键值
	// ==============================================================//
	public static int CTRL_KEY_0 = 0;  //数字0 I8Key_0
	public static int CTRL_KEY_1 = 1;  //数字1 I8Key_1
	public static int CTRL_KEY_2 = 2;  //数字2 I8Key_2
	public static int CTRL_KEY_3 = 3;  //数字3 I8Key_3
	public static int CTRL_KEY_4 = 4;  //数字4 I8Key_4
	public static int CTRL_KEY_5 = 5;  //数字5 I8Key_5
	public static int CTRL_KEY_6 = 6;  //数字6 I8Key_6
	public static int CTRL_KEY_7 = 7;  //数字7 I8Key_7
	public static int CTRL_KEY_8 = 8;  //数字8 I8Key_8
	public static int CTRL_KEY_9 = 9;  //数字9 I8Key_9
	
	public static int CTRL_KEY_MULT = 9;  //屏幕切换
	public static int CTRL_KEY_ADD = 9;  //ADD功能	
	
	public static int CTRL_KEY_MULTDIGITER = 9;  //"-/--"	
	public static int CTRL_KEY_ESC = 9;  //9	
	public static int CTRL_KEY_REC = 9;  //9	
	public static int CTRL_KEY_Fn = 9;  //9	
	public static int CTRL_KEY_UP = 9;  //I8Key_Up
	public static int CTRL_KEY_LEFT = 9;  //I8Key_Left	
	public static int CTRL_KEY_DOWN = 9;  //I8Key_Down	
	public static int CTRL_KEY_RIGHT = 9;  //9	
	public static int CTRL_KEY_MENU = 9;  //9	
	public static int CTRL_KEY_QUICKPLAY = 9;  //9	
	public static int CTRL_KEY_SLOWPLAY = 9;  //9	
	public static int CTRL_KEY_PAUSE = 9;  //9	
	public static int CTRL_KEY_PLAY = 9;  //9	
	public static int CTRL_KEY_FRAMEPLAY = 9;  //9	
	public static int CTRL_KEY_STOP = 9;  //9	
	
	public static int PTZ_UP = 21;
	public static int PTZ_DOWN = 22;
	public static int PTZ_LEFT = 23;
	public static int PTZ_RIGHT = 24;
	
	public static int ZOOM_IN    = 11;
	public static int ZOOM_OUT   = 12;
	public static int FOCUS_NEAR = 13;
	public static int FOCUS_FAR  = 14;
	public static int IRIS_OPEN  = 15;
	public static int IRIS_CLOSE = 16;
		
	// ==============================================================//
	// 文件播放命令
	// ==============================================================//	
	public static int ANTS_NET_DVR_PLAYSTART	    =	1;//!开始播放
	public static int ANTS_NET_DVR_PLAYSTOP		    =	2;//!停止播放
	public static int ANTS_NET_DVR_PLAYPAUSE	    =   3;//!暂停播放
	public static int ANTS_NET_DVR_PLAYRESTART	    =	4;//!恢复播放
	public static int ANTS_NET_DVR_PLAYFAST		    =	5;//!快放
	public static int ANTS_NET_DVR_PLAYSLOW		    =	6;//!慢放
	public static int ANTS_NET_DVR_PLAYNORMAL		=	7;//!正常速度
	public static int ANTS_NET_DVR_PLAYSTARTAUDIO	=	9;//!打开声音
	public static int ANTS_NET_DVR_PLAYSTOPAUDIO	=	10;//!关闭声音
	public static int ANTS_NET_DVR_PLAYSETPOS		=	12;//!改变文件回放的进度	
	public static int ANTS_NET_DVR_PLAYGETPOS		=	13;//!改变文件回放的进度	
	public static int ANTS_ANDROID_NET_DVR_PLAYSETTIME	    =   26;	//!按绝对时间定位
	// ==============================================================//
	// 短信数据表
	// ==============================================================//
	public static String TABLE_MSG = "MIDEA_MSG";
	public static String KEY_MSG_ID_AUTO_INCREMENT = "_id"; // 自增字段，固定格式
	public static String KEY_MSG_CONTENT = "MSG_CONTENT"; // 短信内容
	public static String KEY_MSG_STATUS = "MSG_STATUS"; // 短信状态
	public static String KEY_MSG_USERNAME = "MSG_USERNAME"; // 当前短信的用户
	public static String CREATE_MSG = "CREATE TABLE IF NOT EXISTS " + TABLE_MSG
			+ "(" + KEY_MSG_ID_AUTO_INCREMENT + " INTEGER PRIMARY KEY,"
			+ KEY_MSG_CONTENT + " TEXT," + KEY_MSG_STATUS + " INTEGER,"
			+ KEY_MSG_USERNAME + " TEXT)";

	// ==============================================================//
	// 用户表 表有userid,username,password,client,mode,flag字段
	// flag 1 表示当前进入的默认用户
	// ==============================================================//
	public static String TABLE_USER = "MIDEA_USER";
	public static String KEY_USER_ID_AUTO_INCREMENT = "_id"; // 自增字段，固定格式
	public static String KEY_USER_ID = "USER_ID";
	public static String KEY_USER_NAME = "USER_NAME";
	public static String KEY_USER_PASSWORD = "USER_PASSWORD";
	public static String KEY_USER_CLIENT = "USER_CLIENT";
	public static String KEY_USER_MODE = "USER_MODE";
	public static String KEY_USER_FLAG = "USER_FLAG";
	public static String CREATE_USER = "CREATE TABLE IF NOT EXISTS "
			+ TABLE_USER + "(" + KEY_USER_ID_AUTO_INCREMENT
			+ " INTEGER PRIMARY KEY, " + KEY_USER_ID + " TEXT ,"
			+ KEY_USER_NAME + " TEXT," + KEY_USER_PASSWORD + " TEXT,"
			+ KEY_USER_CLIENT + " TEXT," + KEY_USER_MODE + " TEXT,"
			+ KEY_USER_FLAG + " INTEGER)";
	// 告警方式状态
	public static int chnNo = 0; // 通道号
	public static int alarmOpen = 0; // 只要有告警就报警，不管布撤防计划,//midNetStatus_em
	public static int alertSwitch = 0;// 安防设置总开关设置,0关闭，1打开
	public static int smsAlarmEnable = 0; // 短信告警使能,//midNetStatus_em
	public static int soundAlarmEnable = 0; // 声音告警使能,//midNetStatus_em
	public static int picAlarmEnable = 0; // 抓图告警使能,//midNetStatus_em
	public static int videoAlarmEnable = 0; // 录像告警使能,//midNetStatus_em
	public static int phoneNoCount = 0; // 告警手机号个数
	public static String phoneNo1 = ""; // 告警手机1
	public static String phoneNo2 = ""; // 告警手机2
	public static String phoneNo3 = ""; // 告警手机3
	public static String phoneNo4 = ""; // 告警手机4
	public static String phoneNo5 = ""; // 告警手机5

	public static String getPhoneNo(int num[], int i, int j) {
		String no = "";
		for (; j >= i; j--) {
			no += String.valueOf(num[j]);
		}
		return no;
	}
}
