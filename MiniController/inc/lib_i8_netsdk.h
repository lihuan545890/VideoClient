/*
*	IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
*
*	By downloading, copying, installing or using the software you agree to this license.
*	If you do not agree to this license, do not download, install,
*	Copy or use the software.
*
*	Copyright (C) 2012, ANTS, Inc, All Rights Reserved.
*
*	Project Name:AntsNetSDK
*	File Name:AntsNetSDK.h
*
*	注:V2 表示针对36路DVR/NVR开发的数据结构
*
*	Writed by ItmanLee at 2013 - 10 - 08 Ants,WuHan,HuBei,China
*/
#include <string.h>
#include <jni.h>

#ifndef __lib_i8_netsdk_base_on_android__
#define __lib_i8_netsdk_base_on_android__

#ifdef __cplusplus
extern "C" {
#endif

//!宏定义
#define ANTS_ANDROID_MAX_NAMELEN			    		16			//!DVR本地登陆名
#define ANTS_ANDROID_MAX_RIGHT			    			32			//!设备支持的权限（1-12表示本地权限，13-32表示远程权限）
#define ANTS_ANDROID_NAME_LEN			    			32      	//!用户名长度
#define ANTS_ANDROID_PASSWD_LEN			    			16      	//!密码长度
#define ANTS_ANDROID_SERIALNO_LEN		    			48      	//!序列号长度
#define ANTS_ANDROID_MACADDR_LEN			    		6       	//!mac地址长度
#define ANTS_ANDROID_MAX_ETHERNET		    			2       	//!设备可配以太网络
#define ANTS_ANDROID_MAX_NETWORK_CARD        			4       	//!设备可配最大网卡数目
#define ANTS_ANDROID_PATHNAME_LEN		    			128    		//!路径长度

#define ANTS_ANDROID_MAX_TIMESEGMENT	    			8       	//!设备最大时间段数

#define ANTS_ANDROID_MAX_SHELTERNUM						4       	//!设备最大遮挡区域数
#define ANTS_ANDROID_MAX_DAYS							7       	//!每周天数
#define ANTS_ANDROID_PHONENUMBER_LEN					32      	//!pppoe拨号号码最大长度

#define ANTS_ANDROID_MAX_DISKNUM						8			//!设备最大硬盘数/* 最多33个硬盘(包括16个内置SATA硬盘、1个eSATA硬盘和16个NFS盘) */
#define ANTS_ANDROID_MAX_DISKNUM_V2						24

#define ANTS_ANDROID_MAX_WINDOW							32      	//!设备本地显示最大播放窗口数
#define ANTS_ANDROID_MAX_VGA							4       	//!设备最大可接VGA数

#define ANTS_ANDROID_MAX_USERNUM						8      		//!设备最大用户数
#define ANTS_ANDROID_MAX_EXCEPTIONNUM					32      	//!设备最大异常处理数
#define ANTS_ANDROID_MAX_LINK							6       	//!设备单通道最大视频流连接数
#define ANTS_ANDROID_MAX_NETDECNUM						32
#define ANTS_ANDROID_MAX_NETDECNUM_V2					64

#define ANTS_ANDROID_MAX_DECPOOLNUM						4       	//!单路解码器每个解码通道最大可循环解码数
#define ANTS_ANDROID_MAX_DECNUM							4       	//!单路解码器的最大解码通道数（实际只有一个，其他三个保留）
#define ANTS_ANDROID_MAX_TRANSPARENTNUM					2       	//!单路解码器可配置最大透明通道数
#define ANTS_ANDROID_MAX_CYCLE_CHAN      				64      	//!单路解码器最大轮循通道数
#define ANTS_ANDROID_MAX_DIRNAME_LENGTH					80      	//!最大目录长度
#define ANTS_ANDROID_MAX_WINDOWS						16      	//!最大窗口数

#define ANTS_ANDROID_MAX_STRINGNUM						1			//!设备最大OSD字符行数数
#define ANTS_ANDROID_MAX_AUXOUT							16      	//!设备最大辅助输出数
#define ANTS_ANDROID_MAX_HD_GROUP						16      	//!设备最大硬盘组数
#define ANTS_ANDROID_MAX_NFS_DISK						8      		//!设备最大NFS硬盘数

#define ANTS_ANDROID_IW_ESSID_MAX_SIZE	    			32	      	//!WIFI的SSID号长度
#define ANTS_ANDROID_IW_ENCODING_TOKEN_MAX				32     		//!WIFI密锁最大字节数
#define ANTS_ANDROID_MAX_SERIAL_NUM						64	    	//!最多支持的透明通道路数
#define ANTS_ANDROID_MAX_DDNS_NUMS	        			10      	//!设备最大可配ddns数
#define ANTS_ANDROID_MAX_DOMAIN_NAME		    		64			//!最大域名长度 
#define ANTS_ANDROID_MAX_EMAIL_ADDR_LEN	    			48      	//!最大email地址长度
#define ANTS_ANDROID_MAX_EMAIL_PWD_LEN					32      	//!最大email密码长度

#define ANTS_ANDROID_MAXPROGRESS		        		100     	//!回放时的最大百分率
#define ANTS_ANDROID_MAX_SERIALNUM	        			2       	//!设备支持的串口数 1-232， 2-485
#define ANTS_ANDROID_CARDNUM_LEN		        		20      	//!卡号长度
#define ANTS_ANDROID_MAX_VIDEOOUT		        		4	       	//!设备的视频输出数

#define ANTS_ANDROID_MAX_PRESET							256			//!设备支持的云台预置点数 
#define ANTS_ANDROID_MAX_TRACK							256			//!设备支持的云台轨迹数 
#define ANTS_ANDROID_MAX_CRUISE							256			//!设备支持的云台巡航数 

#define ANTS_ANDROID_CRUISE_MAX_PRESET_NUMS				32 	    	//!一条巡航最多的巡航点 

#define ANTS_ANDROID_MAX_SERIAL_PORT             		8       	//!设备支持232串口数
#define ANTS_ANDROID_MAX_PREVIEW_MODE            		8       	//!设备支持最大预览模式数目 1画面,4画面,9画面,16画面.... 
#define ANTS_ANDROID_MAX_MATRIXOUT               		16      	//!最大模拟矩阵输出个数 
#define ANTS_ANDROID_LOG_INFO_LEN                		11840   	//!日志附加信息 
#define ANTS_ANDROID_DESC_LEN                    		16      	//!云台描述字符串长度 
#define ANTS_ANDROID_DESC_LEN_32	           			32			//!描述字长度
#define ANTS_ANDROID_PTZ_PROTOCOL_NUM            		200     	//!最大支持的云台协议数 
#define ANTS_ANDROID_MAX_NODE_NUM         				256			//!节点个数
#define ANTS_ANDROID_MAX_AUDIO							2      		//!语音对讲通道数
#define ANTS_ANDROID_MAX_CHANNUM			        	16      	//!设备最大通道数
#define ANTS_ANDROID_MAX_CHANNUM_V2						64			//!36路DVR
#define ANTS_ANDROID_MAX_ALARMIN			        	16      	//!设备最大报警输入数
#define ANTS_ANDROID_MAX_ALARMIN_V2						64			//!36路DVR
#define ANTS_ANDROID_MAX_ALARMOUT		        		4      		//!设备最大报警输出数

#define ANTS_ANDROID_MAX_ANALOG_CHANNUM          		32      	//!最大32个模拟通道
#define ANTS_ANDROID_MAX_ANALOG_ALARMOUT         		32      	//!最大32路模拟报警输出 
#define ANTS_ANDROID_MAX_ANALOG_ALARMIN          		32      	//!最大32路模拟报警输入

#define ANTS_ANDROID_MAX_IP_DEVICE               		32      	//!允许接入的最大IP设备数
#define ANTS_ANDROID_MAX_IP_CHANNEL              		32      	//!允许加入的最多IP通道数
#define ANTS_ANDROID_MAX_IP_ALARMIN              		128     	//!允许加入的最多报警输入数
#define ANTS_ANDROID_MAX_IP_ALARMOUT             		64      	//!允许加入的最多报警输出数

#define ANTS_ANDROID_MAX_RECORD_FILE_NUM         		20      	//!每次删除或者刻录的最大文件数

#define ANTS_ANDROID_MAX_ACTION_TYPE	        				12	    	//!自定义协议叠加交易行为最大行为个数 
#define ANTS_ANDROID_MAX_ATM_PROTOCOL_NUM    					256  		//!每种输入方式对应的ATM最大协议数
#define ANTS_ANDROID_ATM_CUSTOM_PROTO       					1025   		//!自定义协议 值为1025
#define ANTS_ANDROID_ATM_PROTOCOL_SORT       					4      		//!ATM协议段数 
#define ANTS_ANDROID_ATM_DESC_LEN            					32      	//!ATM描述字符串长度

#define ANTS_ANDROID_MAX_LANERECT_NUM        					5    		//!最大车牌识别区域数
#define ANTS_ANDROID_MAX_FORTIFY_NUM     						10	   		//!最大布防个数
#define ANTS_ANDROID_MAX_INTERVAL_NUM    						4    		//!最大时间间隔个数
#define ANTS_ANDROID_MAX_CHJC_NUM        						3    		//!最大车辆省份简称字符个数
#define ANTS_ANDROID_MAX_VL_NUM          						5    		//!最大虚拟线圈个数

#define ANTS_ANDROID_MAX_MANAGERHOST_NUM						2

//!全局错误码 
#define ANTS_ANDROID_NET_DVR_NOERROR 											0	//!没有错误
#define ANTS_ANDROID_NET_DVR_PASSWORD_ERROR 									1	//!用户名密码错误
#define ANTS_ANDROID_NET_DVR_NOENOUGHPRI 										2	//!权限不足
#define ANTS_ANDROID_NET_DVR_NOINIT 											3	//!没有初始化
#define ANTS_ANDROID_NET_DVR_CHANNEL_ERROR 										4	//!通道号错误
#define ANTS_ANDROID_NET_DVR_OVER_MAXLINK 										5	//!连接到DVR的客户端个数超过最大
#define ANTS_ANDROID_NET_DVR_VERSIONNOMATCH										6	//!版本不匹配
#define ANTS_ANDROID_NET_DVR_NETWORK_FAIL_CONNECT								7	//!连接服务器失败
#define ANTS_ANDROID_NET_DVR_NETWORK_SEND_ERROR									8	//!向服务器发送失败
#define ANTS_ANDROID_NET_DVR_NETWORK_RECV_ERROR									9	//!从服务器接收数据失败
#define ANTS_ANDROID_NET_DVR_NETWORK_RECV_TIMEOUT								10	//!从服务器接收数据超时
#define ANTS_ANDROID_NET_DVR_NETWORK_ERRORDATA									11	//!传送的数据有误
#define ANTS_ANDROID_NET_DVR_ORDER_ERROR										12	//!调用次序错误
#define ANTS_ANDROID_NET_DVR_OPERNOPERMIT										13	//!无此权限
#define ANTS_ANDROID_NET_DVR_COMMANDTIMEOUT										14	//!DVR命令执行超时
#define ANTS_ANDROID_NET_DVR_ERRORSERIALPORT									15	//!串口号错误
#define ANTS_ANDROID_NET_DVR_ERRORALARMPORT										16	//!报警端口错误
#define ANTS_ANDROID_NET_DVR_PARAMETER_ERROR 									17  //!参数错误
#define ANTS_ANDROID_NET_DVR_CHAN_EXCEPTION										18	//!服务器通道处于错误状态
#define ANTS_ANDROID_NET_DVR_NODISK												19	//!没有硬盘
#define ANTS_ANDROID_NET_DVR_ERRORDISKNUM										20	//!硬盘号错误
#define ANTS_ANDROID_NET_DVR_DISK_FULL											21	//!服务器硬盘满
#define ANTS_ANDROID_NET_DVR_DISK_ERROR											22	//!服务器硬盘出错
#define ANTS_ANDROID_NET_DVR_NOSUPPORT											23	//!服务器不支持
#define ANTS_ANDROID_NET_DVR_BUSY												24	//!服务器忙
#define ANTS_ANDROID_NET_DVR_MODIFY_FAIL										25	//!服务器修改不成功
#define ANTS_ANDROID_NET_DVR_PASSWORD_FORMAT_ERROR								26	//!密码输入格式不正确
#define ANTS_ANDROID_NET_DVR_DISK_FORMATING										27	//!硬盘正在格式化，不能启动操作
#define ANTS_ANDROID_NET_DVR_DVRNORESOURCE										28	//!DVR资源不足
#define ANTS_ANDROID_NET_DVR_DVROPRATEFAILED									29  //!DVR操作失败
#define ANTS_ANDROID_NET_DVR_OPENHOSTSOUND_FAIL 								30  //!打开PC声音失败
#define ANTS_ANDROID_NET_DVR_DVRVOICEOPENED 									31  //!服务器语音对讲被占用
#define ANTS_ANDROID_NET_DVR_TIMEINPUTERROR										32  //!时间输入不正确
#define ANTS_ANDROID_NET_DVR_NOSPECFILE											33  //!回放时服务器没有指定的文件
#define ANTS_ANDROID_NET_DVR_CREATEFILE_ERROR									34	//!创建文件出错
#define ANTS_ANDROID_NET_DVR_FILEOPENFAIL										35  //!打开文件出错
#define ANTS_ANDROID_NET_DVR_OPERNOTFINISH										36  //!上次的操作还没有完成
#define ANTS_ANDROID_NET_DVR_GETPLAYTIMEFAIL									37  //!获取当前播放的时间出错
#define ANTS_ANDROID_NET_DVR_PLAYFAIL											38  //!播放出错
#define ANTS_ANDROID_NET_DVR_FILEFORMAT_ERROR									39  //!文件格式不正确
#define ANTS_ANDROID_NET_DVR_DIR_ERROR											40	//!路径错误
#define ANTS_ANDROID_NET_DVR_ALLOC_RESOURCE_ERROR								41  //!资源分配错误
#define ANTS_ANDROID_NET_DVR_AUDIO_MODE_ERROR									42	//!声卡模式错误
#define ANTS_ANDROID_NET_DVR_NOENOUGH_BUF										43	//!缓冲区太小
#define ANTS_ANDROID_NET_DVR_CREATESOCKET_ERROR									44	//!创建SOCKET出错
#define ANTS_ANDROID_NET_DVR_SETSOCKET_ERROR									45	//!设置SOCKET出错
#define ANTS_ANDROID_NET_DVR_MAX_NUM											46	//!个数达到最大
#define ANTS_ANDROID_NET_DVR_USERNOTEXIST										47	//!用户不存在
#define ANTS_ANDROID_NET_DVR_WRITEFLASHERROR									48  //!写FLASH出错
#define ANTS_ANDROID_NET_DVR_UPGRADEFAIL										49  //!DVR升级失败
#define ANTS_ANDROID_NET_DVR_CARDHAVEINIT										50  //!解码卡已经初始化过
#define ANTS_ANDROID_NET_DVR_PLAYERFAILED										51	//!调用播放库中某个函数失败
#define ANTS_ANDROID_NET_DVR_MAX_USERNUM										52  //!设备端用户数达到最大
#define ANTS_ANDROID_NET_DVR_GETLOCALIPANDMACFAIL								53  //!获得客户端的IP地址或物理地址失败
#define ANTS_ANDROID_NET_DVR_NOENCODEING										54	//!该通道没有编码
#define ANTS_ANDROID_NET_DVR_IPMISMATCH											55	//!IP地址不匹配
#define ANTS_ANDROID_NET_DVR_MACMISMATCH										56	//!MAC地址不匹配
#define ANTS_ANDROID_NET_DVR_UPGRADELANGMISMATCH								57	//!升级文件语言不匹配
#define ANTS_ANDROID_NET_DVR_MAX_PLAYERPORT										58	//!播放器路数达到最大
#define ANTS_ANDROID_NET_DVR_NOSPACEBACKUP										59	//!备份设备中没有足够空间进行备份
#define ANTS_ANDROID_NET_DVR_NODEVICEBACKUP										60	//!没有找到指定的备份设备
#define ANTS_ANDROID_NET_DVR_PICTURE_BITS_ERROR									61	//!图像素位数不符，限24色
#define ANTS_ANDROID_NET_DVR_PICTURE_DIMENSION_ERROR							62	//!图片高*宽超限， 限128*256
#define ANTS_ANDROID_NET_DVR_PICTURE_SIZ_ERROR									63	//!图片大小超限，限100K
#define ANTS_ANDROID_NET_DVR_LOADPLAYERSDKFAILED								64	//!载入当前目录下Player Sdk出错
#define ANTS_ANDROID_NET_DVR_LOADPLAYERSDKPROC_ERROR							65	//!找不到Player Sdk中某个函数入口
#define ANTS_ANDROID_NET_DVR_LOADDSSDKFAILED									66	//!载入当前目录下DSsdk出错
#define ANTS_ANDROID_NET_DVR_LOADDSSDKPROC_ERROR								67	//!找不到DsSdk中某个函数入口
#define ANTS_ANDROID_NET_DVR_DSSDK_ERROR										68	//!调用硬解码库DsSdk中某个函数失败
#define ANTS_ANDROID_NET_DVR_VOICEMONOPOLIZE									69	//!声卡被独占
#define ANTS_ANDROID_NET_DVR_JOINMULTICASTFAILED								70	//!加入多播组失败
#define ANTS_ANDROID_NET_DVR_CREATEDIR_ERROR									71	//!建立日志文件目录失败
#define ANTS_ANDROID_NET_DVR_BINDSOCKET_ERROR									72	//!绑定套接字失败
#define ANTS_ANDROID_NET_DVR_SOCKETCLOSE_ERROR									73	//!socket连接中断，此错误通常是由于连接中断或目的地不可达
#define ANTS_ANDROID_NET_DVR_USERID_ISUSING										74	//!注销时用户ID正在进行某操作
#define ANTS_ANDROID_NET_DVR_SOCKETLISTEN_ERROR									75	//!监听失败
#define ANTS_ANDROID_NET_DVR_PROGRAM_EXCEPTION									76	//!程序异常
#define ANTS_ANDROID_NET_DVR_WRITEFILE_FAILED									77	//!写文件失败
#define ANTS_ANDROID_NET_DVR_FORMAT_READONLY									78  //!禁止格式化只读硬盘
#define ANTS_ANDROID_NET_DVR_WITHSAMEUSERNAME									79  //!用户配置结构中存在相同的用户名
#define ANTS_ANDROID_NET_DVR_DEVICETYPE_ERROR            						80  //!导入参数时设备型号不匹配
#define ANTS_ANDROID_NET_DVR_LANGUAGE_ERROR              						81  //!导入参数时语言不匹配
#define ANTS_ANDROID_NET_DVR_PARAVERSION_ERROR           						82  //!导入参数时软件版本不匹配
#define ANTS_ANDROID_NET_DVR_IPCHAN_NOTALIVE             						83  //!预览时外接IP通道不在线
#define ANTS_ANDROID_NET_DVR_RTSP_SDK_ERROR										84	//!加载高清IPC通讯库StreamTransClient.dll失败
#define ANTS_ANDROID_NET_DVR_CONVERT_SDK_ERROR									85	//!加载转码库失败
#define ANTS_ANDROID_NET_DVR_IPC_COUNT_OVERFLOW									86  //!超出最大的ip接入通道数
#define ANTS_ANDROID_NET_DVR_PARAMMODE_ERROR             						88 	//!图像增强仪，参数模式错误（用于硬件设置时，客户端进行软件设置时错误值）
#define ANTS_ANDROID_NET_DVR_CODESPITTER_OFFLINE								89 	//!视频综合平台，码分器不在线
#define ANTS_ANDROID_NET_DVR_BACKUP_COPYING										90  //!设备正在备份
#define ANTS_ANDROID_NET_DVR_CHAN_NOTSUPPORT             						91 	//!通道不支持该操作
#define ANTS_ANDROID_NET_DVR_CALLINEINVALID              						92  //!高度线位置太集中或长度线不够倾斜 
#define ANTS_ANDROID_NET_DVR_CALCANCELCONFLICT           						93  //!取消标定冲突，如果设置了规则及全局的实际大小尺寸过滤
#define ANTS_ANDROID_NET_DVR_CALPOINTOUTRANGE            						94 	//!标定点超出范围 
#define ANTS_ANDROID_NET_DVR_FILTERRECTINVALID            						95  //!尺寸过滤器不符合要求
#define ANTS_ANDROID_NET_DVR_CREATEXMLFILE_ERROR 	   							96
#define ANTS_ANDROID_NET_DVR_ACCEPTXMLFILE_ERROR    							97

//! 阵列错误码
#define ANTS_ANDROID_RAID_ERROR_INDEX								200
#define ANTS_ANDROID_NET_DVR_NAME_NOT_ONLY               			(ANTS_RAID_ERROR_INDEX + 0)  //! 用户名不唯一
#define ANTS_ANDROID_NET_DVR_OVER_MAX_ARRAY              			(ANTS_RAID_ERROR_INDEX + 1 ) //! 阵列达到上限
#define ANTS_ANDROID_NET_DVR_OVER_MAX_VD                 			(ANTS_RAID_ERROR_INDEX + 2 ) //! 虚拟磁盘达到上限
#define ANTS_ANDROID_NET_DVR_VD_SLOT_EXCEED              			(ANTS_RAID_ERROR_INDEX + 3 ) //! 虚拟硬盘槽位已满
#define ANTS_ANDROID_NET_DVR_PD_STATUS_INVALID           			(ANTS_RAID_ERROR_INDEX + 4 ) //! 重建阵列所需物理硬盘状态错误
#define ANTS_ANDROID_NET_DVR_PD_BE_DEDICATE_SPARE        			(ANTS_RAID_ERROR_INDEX + 5 ) //! 重建阵列所需物理硬盘为指定热备
#define ANTS_ANDROID_NET_DVR_PD_NOT_FREE                 			(ANTS_RAID_ERROR_INDEX + 6 ) //! 重建阵列所需物理硬盘非空闲
#define ANTS_ANDROID_NET_DVR_CANNOT_MIG2NEWMODE          			(ANTS_RAID_ERROR_INDEX + 7 ) //! 不能从当前的raid类型迁移到新的RAid类型
#define ANTS_ANDROID_NET_DVR_MIG_PAUSE                   			(ANTS_RAID_ERROR_INDEX + 8 ) //! 迁移操作已暂停
#define ANTS_ANDROID_NET_DVR_MIG_ABOUTED                 			(ANTS_RAID_ERROR_INDEX + 9 ) //! 迁移操作已取消
#define ANTS_ANDROID_NET_DVR_EXIST_VD                    			(ANTS_RAID_ERROR_INDEX + 10) //! 阵列上阵列上存在虚拟磁盘，无法删除阵列
#define ANTS_ANDROID_NET_DVR_TARGET_IN_LD_FUNCTIONAL     			(ANTS_RAID_ERROR_INDEX + 11) //! Target physical disk is part of the virtual disk and is functional
#define ANTS_ANDROID_NET_DVR_HD_IS_ASSIGNED_ALREADY      			(ANTS_RAID_ERROR_INDEX + 12) //! Specified physical disk is assigned to a virtual disk
#define ANTS_ANDROID_NET_DVR_INVALID_HD_COUNT            			(ANTS_RAID_ERROR_INDEX + 13) //! Number of physical disks doesn't fit the specified RAID level
#define ANTS_ANDROID_NET_DVR_LD_IS_FUNCTIONAL            			(ANTS_RAID_ERROR_INDEX + 14) //! Specified virtual disk is functional正常工作，不能重建
#define ANTS_ANDROID_NET_DVR_BGA_RUNNING                 			(ANTS_RAID_ERROR_INDEX + 15) //! BGA is running
#define ANTS_ANDROID_NET_DVR_LD_NO_ATAPI                	 		(ANTS_RAID_ERROR_INDEX + 16) //! Can not create virtual disk with ATAPI drive
#define ANTS_ANDROID_NET_DVR_MIGRATION_NOT_NEED          			(ANTS_RAID_ERROR_INDEX + 17) //! Migration is not necessary
#define ANTS_ANDROID_NET_DVR_HD_TYPE_MISMATCH            			(ANTS_RAID_ERROR_INDEX + 18) //! Physical disks are not of the same type
#define ANTS_ANDROID_NET_DVR_NO_LD_IN_DG                 			(ANTS_RAID_ERROR_INDEX + 19) //! No virtual disk exist on the specified array
#define ANTS_ANDROID_NET_DVR_NO_ROOM_FOR_SPARE           			(ANTS_RAID_ERROR_INDEX + 20) //! Disk space is too small to be assigned as spare drive
#define ANTS_ANDROID_NET_DVR_SPARE_IS_IN_MULTI_DG        			(ANTS_RAID_ERROR_INDEX + 21) //! Disk is already assigned as a spare drive for an array
#define ANTS_ANDROID_NET_DVR_DG_HAS_MISSING_PD           			(ANTS_RAID_ERROR_INDEX + 22) //! Disk is missing from an array

//!播放错误码
#define  ANTS_ANDROID_NET_PLAYM4_NOERROR							500	//!no error
#define  ANTS_ANDROID_NET_PLAYM4_PARA_OVER							501	//!input parameter is invalid;
#define  ANTS_ANDROID_NET_PLAYM4_ORDER_ERROR						502	//!The order of the function to be called is error.
#define  ANTS_ANDROID_NET_PLAYM4_TIMER_ERROR						503	//!Create multimedia clock failed;
#define  ANTS_ANDROID_NET_PLAYM4_DEC_VIDEO_ERROR					504	//!Decode video data failed.
#define  ANTS_ANDROID_NET_PLAYM4_DEC_AUDIO_ERROR					505	//!Decode audio data failed.
#define  ANTS_ANDROID_NET_PLAYM4_ALLOC_MEMORY_ERROR					506	//!Allocate memory failed.
#define  ANTS_ANDROID_NET_PLAYM4_OPEN_FILE_ERROR					507	//!Open the file failed.
#define  ANTS_ANDROID_NET_PLAYM4_CREATE_OBJ_ERROR					508	//!Create thread or event failed
#define  ANTS_ANDROID_NET_PLAYM4_CREATE_DDRAW_ERROR					509	//!Create DirectDraw object failed.
#define  ANTS_ANDROID_NET_PLAYM4_CREATE_OFFSCREEN_ERROR				510	//!failed when creating off-screen surface.
#define  ANTS_ANDROID_NET_PLAYM4_BUF_OVER			        		511	//!buffer is overflow
#define  ANTS_ANDROID_NET_PLAYM4_CREATE_SOUND_ERROR	       	 		512	//!failed when creating audio device.	
#define  ANTS_ANDROID_NET_PLAYM4_SET_VOLUME_ERROR	        		513	//!Set volume failed
#define  ANTS_ANDROID_NET_PLAYM4_SUPPORT_FILE_ONLY	        		514	//!The function only support play file.
#define  ANTS_ANDROID_NET_PLAYM4_SUPPORT_STREAM_ONLY	        	515	//!The function only support play stream.
#define  ANTS_ANDROID_NET_PLAYM4_SYS_NOT_SUPPORT		        	516	//!System not support.
#define  ANTS_ANDROID_NET_PLAYM4_FILEHEADER_UNKNOWN          		517	//!No file header.
#define  ANTS_ANDROID_NET_PLAYM4_VERSION_INCORRECT	        		518	//!The version of decoder and encoder is not adapted.  
#define  ANTS_ANDROID_NET_PALYM4_INIT_DECODER_ERROR          		519	//!Initialize decoder failed.
#define  ANTS_ANDROID_NET_PLAYM4_CHECK_FILE_ERROR	        		520	//!The file data is unknown.
#define  ANTS_ANDROID_NET_PLAYM4_INIT_TIMER_ERROR	        		521	//!Initialize multimedia clock failed.
#define  ANTS_ANDROID_NET_PLAYM4_BLT_ERROR			        		522	//!Blt failed.
#define  ANTS_ANDROID_NET_PLAYM4_UPDATE_ERROR		        		523	//!Update failed.
#define  ANTS_ANDROID_NET_PLAYM4_OPEN_FILE_ERROR_MULTI      		524 //!openfile error, streamtype is multi
#define  ANTS_ANDROID_NET_PLAYM4_OPEN_FILE_ERROR_VIDEO      		525 //!openfile error, streamtype is video
#define  ANTS_ANDROID_NET_PLAYM4_JPEG_COMPRESS_ERROR         		526 //!JPEG compress error
#define  ANTS_ANDROID_NET_PLAYM4_EXTRACT_NOT_SUPPORT         		527	//!Don't support the version of this file.
#define  ANTS_ANDROID_NET_PLAYM4_EXTRACT_DATA_ERROR          		528	//!extract video data failed.

/*************************************************
ANTS_NET_DVR_IsSupport()返回值
1－9位分别表示以下信息（位与是TRUE)表示支持
**************************************************/
#define ANTS_ANDROID_NET_DVR_SUPPORT_DDRAW									0x01//!支持DIRECTDRAW，如果不支持，则播放器不能工作；
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLT									0x02//!显卡支持BLT操作，如果不支持，则播放器不能工作；
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTFOURCC								0x04//!显卡BLT支持颜色转换，如果不支持，播放器会用软件方法作RGB转换；
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTSHRINKX								0x08//!显卡BLT支持X轴缩小；如果不支持，系统会用软件方法转换；
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTSHRINKY								0x10//!显卡BLT支持Y轴缩小；如果不支持，系统会用软件方法转换；
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTSTRETCHX							0x20//!显卡BLT支持X轴放大；如果不支持，系统会用软件方法转换；
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTSTRETCHY							0x40//!显卡BLT支持Y轴放大；如果不支持，系统会用软件方法转换；
#define ANTS_ANDROID_NET_DVR_SUPPORT_SSE									0x80//!CPU支持SSE指令，Intel Pentium3以上支持SSE指令；
#define ANTS_ANDROID_NET_DVR_SUPPORT_MMX									0x100//!CPU支持MMX指令集，Intel Pentium3以上支持SSE指令；

//!云台控制命令 	
#define ANTS_ANDROID_LIGHT_PWRON															2	//! 接通灯光电源 
#define ANTS_ANDROID_WIPER_PWRON															3	//! 接通雨刷开关 
#define ANTS_ANDROID_FAN_PWRON																4	//! 接通风扇开关 
#define ANTS_ANDROID_HEATER_PWRON															5	//! 接通加热器开关 
#define ANTS_ANDROID_AUX_PWRON1																6	//! 接通辅助设备开关 
#define ANTS_ANDROID_AUX_PWRON2																7	//! 接通辅助设备开关 
#define ANTS_ANDROID_SET_PRESET																8	//! 设置预置点 
#define ANTS_ANDROID_CLE_PRESET																9	//! 清除预置点 

#define ANTS_ANDROID_ZOOM_IN																11	//! 焦距以速度SS变大(倍率变大) 
#define ANTS_ANDROID_ZOOM_OUT																12	//! 焦距以速度SS变小(倍率变小) 
#define ANTS_ANDROID_FOCUS_NEAR      														13  //! 焦点以速度SS前调 
#define ANTS_ANDROID_FOCUS_FAR       														14  //! 焦点以速度SS后调 
#define ANTS_ANDROID_IRIS_OPEN       														15  //! 光圈以速度SS扩大 
#define ANTS_ANDROID_IRIS_CLOSE      														16  //! 光圈以速度SS缩小 

#define ANTS_ANDROID_TILT_UP																21	//! 云台以SS的速度上仰 
#define ANTS_ANDROID_TILT_DOWN																22	//! 云台以SS的速度下俯 
#define ANTS_ANDROID_PAN_LEFT																23	//! 云台以SS的速度左转 
#define ANTS_ANDROID_PAN_RIGHT																24	//! 云台以SS的速度右转 
#define ANTS_ANDROID_UP_LEFT																25	//! 云台以SS的速度上仰和左转 
#define ANTS_ANDROID_UP_RIGHT																26	//! 云台以SS的速度上仰和右转 
#define ANTS_ANDROID_DOWN_LEFT																27	//! 云台以SS的速度下俯和左转 
#define ANTS_ANDROID_DOWN_RIGHT																28	//! 云台以SS的速度下俯和右转 
#define ANTS_ANDROID_PAN_AUTO																29	//! 云台以SS的速度左右自动扫描 

#define ANTS_ANDROID_FILL_PRE_SEQ															30	//! 将预置点加入巡航序列 
#define ANTS_ANDROID_SET_SEQ_DWELL															31	//! 设置巡航点停顿时间 
#define ANTS_ANDROID_SET_SEQ_SPEED															32	//! 设置巡航速度 
#define ANTS_ANDROID_CLE_PRE_SEQ															33	//! 将预置点从巡航序列中删除 
#define ANTS_ANDROID_STA_MEM_CRUISE															34	//! 开始记录轨迹 
#define ANTS_ANDROID_STO_MEM_CRUISE															35	//! 停止记录轨迹 
#define ANTS_ANDROID_RUN_CRUISE																36	//! 开始轨迹 
#define ANTS_ANDROID_RUN_SEQ																37	//! 开始巡航 
#define ANTS_ANDROID_STOP_SEQ																38	//! 停止巡航 
#define ANTS_ANDROID_GOTO_PRESET															39	//! 快球转到预置点 
#define ANTS_ANDROID_FILL_SEQ_CRUISE														40	//! 将巡航序列设置到云台中 
/*************************************************
回放时播放控制命令宏定义 
ANTS_ANDROID_NET_DVR_PlayBackControl
ANTS_ANDROID_NET_DVR_PlayControlLocDisplay
ANTS_ANDROID_NET_DVR_DecPlayBackCtrl的宏定义
具体支持查看函数说明和代码
**************************************************/	
#define ANTS_ANDROID_NET_DVR_PLAYSTART													1	//!开始播放
#define ANTS_ANDROID_NET_DVR_PLAYSTOP													2	//!停止播放
#define ANTS_ANDROID_NET_DVR_PLAYPAUSE													3	//!暂停播放
#define ANTS_ANDROID_NET_DVR_PLAYRESTART												4	//!恢复播放
#define ANTS_ANDROID_NET_DVR_PLAYFAST													5	//!快放
#define ANTS_ANDROID_NET_DVR_PLAYSLOW													6	//!慢放
#define ANTS_ANDROID_NET_DVR_PLAYNORMAL													7	//!正常速度
#define ANTS_ANDROID_NET_DVR_PLAYFRAME													8	//!单帧放
#define ANTS_ANDROID_NET_DVR_PLAYSTARTAUDIO												9	//!打开声音
#define ANTS_ANDROID_NET_DVR_PLAYSTOPAUDIO												10	//!关闭声音
#define ANTS_ANDROID_NET_DVR_PLAYAUDIOVOLUME											11	//!调节音量
#define ANTS_ANDROID_NET_DVR_PLAYSETPOS													12	//!改变文件回放的进度
#define ANTS_ANDROID_NET_DVR_PLAYGETPOS													13	//!获取文件回放的进度
#define ANTS_ANDROID_NET_DVR_PLAYGETTIME												14	//!获取当前已经播放的时间(按文件回放的时候有效)
#define ANTS_ANDROID_NET_DVR_PLAYGETFRAME												15	//!获取当前已经播放的帧数(按文件回放的时候有效)
#define ANTS_ANDROID_NET_DVR_GETTOTALFRAMES  											16	//!获取当前播放文件总的帧数(按文件回放的时候有效)
#define ANTS_ANDROID_NET_DVR_GETTOTALTIME    											17	//!获取当前播放文件总的时间(按文件回放的时候有效)
#define ANTS_ANDROID_NET_DVR_THROWBFRAME												20	//!丢B帧
#define ANTS_ANDROID_NET_DVR_SETSPEED													24	//!设置码流速度
#define ANTS_ANDROID_NET_DVR_KEEPALIVE													25	//!保持与设备的心跳(如果回调阻塞，建议2秒发送一次)
#define ANTS_ANDROID_NET_DVR_PLAYSETTIME												26	//!按绝对时间定位
#define ANTS_ANDROID_NET_DVR_PLAYGETTOTALLEN											27	//!获取按时间回放对应时间段内的所有文件的总长度

//!远程按键定义如下：
//! key value send to CONFIG program 
#define ANTS_ANDROID_KEY_CODE_1 							1
#define ANTS_ANDROID_KEY_CODE_2 							2
#define ANTS_ANDROID_KEY_CODE_3 							3
#define ANTS_ANDROID_KEY_CODE_4 							4
#define ANTS_ANDROID_KEY_CODE_5 							5
#define ANTS_ANDROID_KEY_CODE_6 							6
#define ANTS_ANDROID_KEY_CODE_7 							7
#define ANTS_ANDROID_KEY_CODE_8 							8
#define ANTS_ANDROID_KEY_CODE_9 							9
#define ANTS_ANDROID_KEY_CODE_0 							10
#define ANTS_ANDROID_KEY_CODE_POWER 						11
#define ANTS_ANDROID_KEY_CODE_MENU 							12
#define ANTS_ANDROID_KEY_CODE_ENTER 						13
#define ANTS_ANDROID_KEY_CODE_CANCEL 						14
#define ANTS_ANDROID_KEY_CODE_UP 							15
#define ANTS_ANDROID_KEY_CODE_DOWN 							16
#define ANTS_ANDROID_KEY_CODE_LEFT 							17
#define ANTS_ANDROID_KEY_CODE_RIGHT 						18
#define ANTS_ANDROID_KEY_CODE_EDIT 							19
#define ANTS_ANDROID_KEY_CODE_ADD 							20
#define ANTS_ANDROID_KEY_CODE_MINUS 						21
#define ANTS_ANDROID_KEY_CODE_PLAY 							22
#define ANTS_ANDROID_KEY_CODE_REC 							23
#define ANTS_ANDROID_KEY_CODE_PAN 							24
#define ANTS_ANDROID_KEY_CODE_M 							25
#define ANTS_ANDROID_KEY_CODE_A 							26
#define ANTS_ANDROID_KEY_CODE_F1 							27
#define ANTS_ANDROID_KEY_CODE_F2 							28

//! for PTZ control 
#define ANTS_ANDROID_KEY_PTZ_UP_START 						ANTS_ANDROID_KEY_CODE_UP
#define ANTS_ANDROID_KEY_PTZ_UP_STOP 						32

#define ANTS_ANDROID_KEY_PTZ_DOWN_START 					ANTS_ANDROID_KEY_CODE_DOWN
#define ANTS_ANDROID_KEY_PTZ_DOWN_STOP 						33

#define ANTS_ANDROID_KEY_PTZ_LEFT_START						ANTS_ANDROID_KEY_CODE_LEFT
#define ANTS_ANDROID_KEY_PTZ_LEFT_STOP						34

#define ANTS_ANDROID_KEY_PTZ_RIGHT_START 					ANTS_ANDROID_KEY_CODE_RIGHT
#define ANTS_ANDROID_KEY_PTZ_RIGHT_STOP 					35

#define ANTS_ANDROID_KEY_PTZ_AP1_START						ANTS_ANDROID_KEY_CODE_EDIT /* 光圈+ */
#define ANTS_ANDROID_KEY_PTZ_AP1_STOP 						36

#define ANTS_ANDROID_KEY_PTZ_AP2_START						ANTS_ANDROID_KEY_CODE_PAN /* 光圈- */
#define ANTS_ANDROID_KEY_PTZ_AP2_STOP						37

#define ANTS_ANDROID_KEY_PTZ_FOCUS1_START 					ANTS_ANDROID_KEY_CODE_A /* 聚焦+ */
#define ANTS_ANDROID_KEY_PTZ_FOCUS1_STOP 					38

#define ANTS_ANDROID_KEY_PTZ_FOCUS2_START 					ANTS_ANDROID_KEY_CODE_M /* 聚焦- */
#define ANTS_ANDROID_KEY_PTZ_FOCUS2_STOP 					39

#define ANTS_ANDROID_KEY_PTZ_B1_START 						40 /* 变倍+ */
#define ANTS_ANDROID_KEY_PTZ_B1_STOP 						41

#define ANTS_ANDROID_KEY_PTZ_B2_START 						42 /* 变倍- */
#define ANTS_ANDROID_KEY_PTZ_B2_STOP 						43

#define ANTS_ANDROID_KEY_CODE_11 							44
#define ANTS_ANDROID_KEY_CODE_12 							45
#define ANTS_ANDROID_KEY_CODE_13 							46
#define ANTS_ANDROID_KEY_CODE_14 							47
#define ANTS_ANDROID_KEY_CODE_15 							48
#define ANTS_ANDROID_KEY_CODE_16 							49

#define ANTS_ANDROID_AUDIOTALKTYPE_G722      				0
#define ANTS_ANDROID_AUDIOTALKTYPE_G711_MU    				1

#define ANTS_ANDROID_NET_DVR_3G_DEVICE_DESC_LEN				32
#define ANTS_ANDROID_NET_DVR_3G_DEVICE_NUM					200

#define ANTS_ANDROID_NET_DVR_DDNS_SERVICE_DESC_LEN			32
#define ANTS_ANDROID_NET_DVR_DDNS_SERVICE_NUM				200

#define ANTS_ANDROID_NET_DVR_GETCFG											100
#define ANTS_ANDROID_NET_DVR_GET_DEVICECFG									(ANTS_ANDROID_NET_DVR_GETCFG+1) 	//!获取设备参数
#define ANTS_ANDROID_NET_DVR_GET_NETCFG										(ANTS_ANDROID_NET_DVR_GETCFG+2) 	//!获取网络参数
#define ANTS_ANDROID_NET_DVR_GET_PICCFG										(ANTS_ANDROID_NET_DVR_GETCFG+3) 	//!获取图象参数
#define ANTS_ANDROID_NET_DVR_GET_COMPRESSCFG								(ANTS_ANDROID_NET_DVR_GETCFG+4) 	//!获取压缩参数
#define ANTS_ANDROID_NET_DVR_GET_RECORDCFG									(ANTS_ANDROID_NET_DVR_GETCFG+5) 	//!获取录像时间参数
#define ANTS_ANDROID_NET_DVR_GET_DECODERCFG									(ANTS_ANDROID_NET_DVR_GETCFG+6) 	//!获取解码器参数
#define ANTS_ANDROID_NET_DVR_GET_RS232CFG									(ANTS_ANDROID_NET_DVR_GETCFG+7) 	//!获取232串口参数
#define ANTS_ANDROID_NET_DVR_GET_ALARMINCFG									(ANTS_ANDROID_NET_DVR_GETCFG+8) 	//!获取报警输入参数
#define ANTS_ANDROID_NET_DVR_GET_ALARMOUTCFG								(ANTS_ANDROID_NET_DVR_GETCFG+9) 	//!获取报警输出参数
#define ANTS_ANDROID_NET_DVR_GET_TIMECFG									(ANTS_ANDROID_NET_DVR_GETCFG+10)	//!获取DVR时间
#define ANTS_ANDROID_NET_DVR_GET_PREVIEWCFG									(ANTS_ANDROID_NET_DVR_GETCFG+11)	//!获取预览参数
#define ANTS_ANDROID_NET_DVR_GET_VIDEOOUTCFG								(ANTS_ANDROID_NET_DVR_GETCFG+12)	//!获取视频输出参数
#define ANTS_ANDROID_NET_DVR_GET_USERCFG									(ANTS_ANDROID_NET_DVR_GETCFG+13)	//!获取用户参数
#define ANTS_ANDROID_NET_DVR_GET_EXCEPTIONCFG								(ANTS_ANDROID_NET_DVR_GETCFG+14)	//!获取异常参数
#define ANTS_ANDROID_NET_DVR_GET_ZONEANDDST									(ANTS_ANDROID_NET_DVR_GETCFG+15)	//!获取时区和夏时制参数
#define ANTS_ANDROID_NET_DVR_GET_SHOWSTRING									(ANTS_ANDROID_NET_DVR_GETCFG+16)	//!获取叠加字符参数
#define ANTS_ANDROID_NET_DVR_GET_EVENTCOMPCFG								(ANTS_ANDROID_NET_DVR_GETCFG+17)	//!获取事件触发录像参数
#define ANTS_ANDROID_NET_DVR_GET_FTPCFG										(ANTS_ANDROID_NET_DVR_GETCFG+18)	//!获取抓图的FTP参数(基线)
#define ANTS_ANDROID_NET_DVR_GET_AUXOUTCFG									(ANTS_ANDROID_NET_DVR_GETCFG+19)	//!获取报警触发辅助输出设置(HS设备辅助输出)
#define ANTS_ANDROID_NET_DVR_GET_PREVIEWCFG_AUX								(ANTS_ANDROID_NET_DVR_GETCFG+20)	//!获取-s系列双输出预览参数(-s系列双输出)
#define ANTS_ANDROID_NET_DVR_GET_RULECFG									(ANTS_ANDROID_NET_DVR_GETCFG+21)	//!获取行为分析规则
#define ANTS_ANDROID_NET_DVR_GET_TRACK_CFG									(ANTS_ANDROID_NET_DVR_GETCFG+22)	//!获取球机的配置参数
#define ANTS_ANDROID_NET_DVR_GET_IVMS_STREAMCFG								(ANTS_ANDROID_NET_DVR_GETCFG+23)	//!获取智能分析仪取流参数
#define ANTS_ANDROID_NET_DVR_GET_VCA_CTRLCFG								(ANTS_ANDROID_NET_DVR_GETCFG+24)	//!获取智能控制参数
#define ANTS_ANDROID_NET_DVR_GET_VCA_MASK_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+25)	//!获取屏蔽区域参数
#define ANTS_ANDROID_NET_DVR_GET_VCA_ENTER_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+26)	//!获取进入区域参数
#define ANTS_ANDROID_NET_DVR_GET_VCA_LINE_SEGMENT							(ANTS_ANDROID_NET_DVR_GETCFG+27)	//!获取标定线
#define ANTS_ANDROID_NET_DVR_GET_IVMS_MASK_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+28)	//!获取IVMS屏蔽区域参数
#define ANTS_ANDROID_NET_DVR_GET_IVMS_ENTER_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+29)	//!获取IVMS进入区域参数
#define ANTS_ANDROID_NET_DVR_GET_IVMS_BEHAVIORCFG							(ANTS_ANDROID_NET_DVR_GETCFG+30)	//!获取智能分析仪行为规则参数
#define ANTS_ANDROID_NET_DVR_GET_IVMS_SEARCHCFG								(ANTS_ANDROID_NET_DVR_GETCFG+31)	//!获取IVMS回放检索参数
#define ANTS_ANDROID_NET_DVR_GET_POSITION_TRACK								(ANTS_ANDROID_NET_DVR_GETCFG+32)	//!获取场景跟踪配置信息
#define ANTS_ANDROID_NET_DVR_GET_CALIBRATION								(ANTS_ANDROID_NET_DVR_GETCFG+33)	//!获取标定信息
#define ANTS_ANDROID_NET_DVR_GET_PDC_RULECFG								(ANTS_ANDROID_NET_DVR_GETCFG+34)	//!获取人流量统计规则
#define ANTS_ANDROID_NET_DVR_GET_PU_STREAMCFG								(ANTS_ANDROID_NET_DVR_GETCFG+35)	//!获取前段取流设备信息
#define ANTS_ANDROID_NET_DVR_GET_DETECT_RULECFG								(ANTS_ANDROID_NET_DVR_GETCFG+36)	//!获取ATM异物监测规则
#define ANTS_ANDROID_NET_DVR_GET_VCA_SIZE_FILTER							(ANTS_ANDROID_NET_DVR_GETCFG+37)	//!获取全局尺寸过滤器
#define ANTS_ANDROID_NET_DVR_GET_TRACK_PARAMCFG								(ANTS_ANDROID_NET_DVR_GETCFG+38)	//!获取球机本地菜单规则
#define ANTS_ANDROID_NET_DVR_GET_DOME_MOVEMENT_PARAM						(ANTS_ANDROID_NET_DVR_GETCFG+39)	//!获取球机机芯参数
#define ANTS_ANDROID_NET_DVR_GET_NETAPPCFG									(ANTS_ANDROID_NET_DVR_GETCFG+40)	//!获取网络应用参数 NTP/DDNS/EMAIL
#define ANTS_ANDROID_NET_DVR_GET_NTPCFG										(ANTS_ANDROID_NET_DVR_GETCFG+41)	//!获取网络应用参数 NTP
#define ANTS_ANDROID_NET_DVR_GET_DDNSCFG									(ANTS_ANDROID_NET_DVR_GETCFG+42)	//!获取网络应用参数 DDNS
#define ANTS_ANDROID_NET_DVR_GET_EMAILCFG									(ANTS_ANDROID_NET_DVR_GETCFG+43)	//!获取网络应用参数 EMAIL
#define ANTS_ANDROID_NET_DVR_GET_NFSCFG										(ANTS_ANDROID_NET_DVR_GETCFG+44)	//!NFS disk config
#define ANTS_ANDROID_NET_DVR_GET_NETCFG_OTHER								(ANTS_ANDROID_NET_DVR_GETCFG+45)	//!获取网络参数
#define ANTS_ANDROID_NET_DVR_GET_EMAILPARACFG								(ANTS_ANDROID_NET_DVR_GETCFG+46)	//!Get EMAIL parameters
#define ANTS_ANDROID_NET_DVR_GET_PTZPOS										(ANTS_ANDROID_NET_DVR_GETCFG+47)	//!云台获取PTZ位置
#define ANTS_ANDROID_NET_DVR_GET_PTZSCOPE									(ANTS_ANDROID_NET_DVR_GETCFG+48)	//!云台获取PTZ范围
#define ANTS_ANDROID_NET_DVR_GET_REFERENCE_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+49)	//!获取参考区域
#define ANTS_ANDROID_NET_DVR_GET_TARFFIC_MASK_REGION						(ANTS_ANDROID_NET_DVR_GETCFG+50)	//!获取交通事件屏蔽区域
#define ANTS_ANDROID_NET_DVR_GET_SCENE_MODE									(ANTS_ANDROID_NET_DVR_GETCFG+51)	//!获取场景模式
#define ANTS_ANDROID_NET_DVR_GET_AID_RULECFG								(ANTS_ANDROID_NET_DVR_GETCFG+52)	//!获取交通事件规则参数
#define ANTS_ANDROID_NET_DVR_GET_TPS_RULECFG								(ANTS_ANDROID_NET_DVR_GETCFG+53)	//!设置交通统计规则参数
#define ANTS_ANDROID_NET_DVR_GET_LANECFG									(ANTS_ANDROID_NET_DVR_GETCFG+54)	//!获取车道规则
#define ANTS_ANDROID_NET_DVR_GET_PLATECFG									(ANTS_ANDROID_NET_DVR_GETCFG+55)	//!获取车牌识别参数
#define ANTS_ANDROID_NET_DVR_GET_CRUISE										(ANTS_ANDROID_NET_DVR_GETCFG+56)	
#define ANTS_ANDROID_NET_DVR_GET_NET_DISKCFG								(ANTS_ANDROID_NET_DVR_GETCFG+57)	//!网络硬盘接入获取
#define ANTS_ANDROID_NET_DVR_GET_HDCFG										(ANTS_ANDROID_NET_DVR_GETCFG+58)	//!获取硬盘管理配置参数
#define ANTS_ANDROID_NET_DVR_GET_HDGROUP_CFG								(ANTS_ANDROID_NET_DVR_GETCFG+59)	//!获取盘组管理配置参数
#define ANTS_ANDROID_NET_DVR_GET_COMPRESSCFG_AUD							(ANTS_ANDROID_NET_DVR_GETCFG+60)	//!获取设备语音对讲编码参数	
#define ANTS_ANDROID_NET_DVR_GET_IOINCFG									(ANTS_ANDROID_NET_DVR_GETCFG+61)	//!获取抓拍机IO输入参数
#define ANTS_ANDROID_NET_DVR_GET_IOOUTCFG									(ANTS_ANDROID_NET_DVR_GETCFG+62)	//!获取抓拍机IO输出参数
#define ANTS_ANDROID_NET_DVR_GET_FLASHCFG									(ANTS_ANDROID_NET_DVR_GETCFG+63)	//!获取IO闪光灯输出参数
#define ANTS_ANDROID_NET_DVR_GET_LIGHTSNAPCFG								(ANTS_ANDROID_NET_DVR_GETCFG+64)	//!获取抓拍机红绿灯参数
#define ANTS_ANDROID_NET_DVR_GET_MEASURESPEEDCFG							(ANTS_ANDROID_NET_DVR_GETCFG+65)	//!获取抓拍机测速参数
#define ANTS_ANDROID_NET_DVR_GET_IMAGEOVERLAYCFG							(ANTS_ANDROID_NET_DVR_GETCFG+66)	//!获取抓拍机图像叠加信息参数
#define ANTS_ANDROID_NET_DVR_GET_SNAPCFG									(ANTS_ANDROID_NET_DVR_GETCFG+67)	//!获取单IO触发抓拍功能配置
#define ANTS_ANDROID_NET_DVR_GET_VTPPARAM									(ANTS_ANDROID_NET_DVR_GETCFG+68)	//!获取虚拟线圈参数
#define ANTS_ANDROID_NET_DVR_GET_SNAPENABLECFG								(ANTS_ANDROID_NET_DVR_GETCFG+69)	//!获取抓拍机使能参数
#define ANTS_ANDROID_NET_DVR_GET_JPEGCFG									(ANTS_ANDROID_NET_DVR_GETCFG+70)	//!获取抓图的JPEG参数(基线)
#define ANTS_ANDROID_NET_DVR_GET_SPRCFG										(ANTS_ANDROID_NET_DVR_GETCFG+71)	//!获取车牌识别参数
#define ANTS_ANDROID_NET_DVR_GET_PLCCFG										(ANTS_ANDROID_NET_DVR_GETCFG+72)	//!获取车牌亮度补偿参数
#define ANTS_ANDROID_NET_DVR_GET_DEVICESTATECFG								(ANTS_ANDROID_NET_DVR_GETCFG+73)	//!获取设备当前状态参数
#define ANTS_ANDROID_NET_DVR_GET_ZEROCHANCFG								(ANTS_ANDROID_NET_DVR_GETCFG+74)	//!获取零通道压缩参数 
#define ANTS_ANDROID_NET_DVR_GET_ZERO_ZOOM									(ANTS_ANDROID_NET_DVR_GETCFG+75)	//!获取零通道的缩放配置
#define ANTS_ANDROID_NET_DVR_GET_NATASSOCIATECFG							(ANTS_ANDROID_NET_DVR_GETCFG+76)	//!获取NAT功能相关信息
#define ANTS_ANDROID_NET_DVR_GET_SNMPCFG									(ANTS_ANDROID_NET_DVR_GETCFG+77)	//!获取SNMP参数 
#define ANTS_ANDROID_NET_DVR_GET_VIDEOPLATFORMALARMCFG						(ANTS_ANDROID_NET_DVR_GETCFG+78)	//!获取视频综合平台报警配置
#define ANTS_ANDROID_NET_DVR_GET_RAID_ADAPTER_INFO							(ANTS_ANDROID_NET_DVR_GETCFG+79)	//!获取适配器信息
#define ANTS_ANDROID_NET_DVR_GET_NETCFG_MULTI								(ANTS_ANDROID_NET_DVR_GETCFG+80)	//!获取多网卡配置
#define ANTS_ANDROID_NET_DVR_GET_IPPARACFG									(ANTS_ANDROID_NET_DVR_GETCFG+81)	//!获取IP接入配置信息 
#define ANTS_ANDROID_NET_DVR_GET_CCDPARAMCFG								(ANTS_ANDROID_NET_DVR_GETCFG+82)	//!IPC获取CCD参数配置
#define ANTS_ANDROID_NET_DVR_GET_IPALARMINCFG								(ANTS_ANDROID_NET_DVR_GETCFG+83)	//!获取IP报警输入接入配置信息 
#define ANTS_ANDROID_NET_DVR_GET_IPALARMOUTCFG								(ANTS_ANDROID_NET_DVR_GETCFG+84)	//!获取IP报警输出接入配置信息 
#define ANTS_ANDROID_NET_DVR_GET_AUTOREBOOT									(ANTS_ANDROID_NET_DVR_GETCFG+85) 	//!获取自动维护参数 
#define ANTS_ANDROID_NET_DVR_GET_PICCFGEX									(ANTS_ANDROID_NET_DVR_GETCFG+86)	//!获取图象参数(扩展)
#define ANTS_ANDROID_NET_DVR_GET_COMPRESSCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+87)	//!获取压缩参数(扩展)
#define ANTS_ANDROID_NET_DVR_GET_RECORDCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+88)	//!获取录像时间参数(扩展)
#define ANTS_ANDROID_NET_DVR_GET_DECODERCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+89)	//!获取解码器参数(扩展)
#define ANTS_ANDROID_NET_DVR_GET_ALARMINCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+90)	//!获取报警输入参数(扩展)
#define ANTS_ANDROID_NET_DVR_GET_ALARMOUTCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+91)	//!获取报警输出参数(扩展)
#define ANTS_ANDROID_NET_DVR_GET_SHOWSTRINGEX								(ANTS_ANDROID_NET_DVR_GETCFG+92)	//!获取叠加字符参数(扩展)
#define ANTS_ANDROID_NET_DVR_GET_EVENTCOMPCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+93)	//!获取事件触发录像参数(扩展)
#define ANTS_ANDROID_NET_DVR_GET_AP_INFO_LIST								(ANTS_ANDROID_NET_DVR_GETCFG+94)	//!获取无线网络资源参数
#define ANTS_ANDROID_NET_DVR_GET_WIFI_CFG									(ANTS_ANDROID_NET_DVR_GETCFG+95)	//!获取IP监控设备无线参数
#define ANTS_ANDROID_NET_DVR_GET_WIFI_WORKMODE								(ANTS_ANDROID_NET_DVR_GETCFG+96)	//!获取IP监控设备网口工作模式参数
#define ANTS_ANDROID_NET_DVR_GET_3G_CFG										(ANTS_ANDROID_NET_DVR_GETCFG+97)	//!获取3G配置参数
#define ANTS_ANDROID_NET_DVR_GET_MANAGERHOST_CFG							(ANTS_ANDROID_NET_DVR_GETCFG+98)	//!获取媒体服务器配置参数
#define ANTS_ANDROID_NET_DVR_GET_3GDEVICE_CFG								(ANTS_ANDROID_NET_DVR_GETCFG+99)	//!获取3G设备集合
#define ANTS_ANDROID_NET_DVR_GET_NETDEV_CFG									(ANTS_ANDROID_NET_DVR_GETCFG+100)	//!获取远程NVR的IPC设备信息

#define ANTS_ANDROID_NET_DVR_SETCFG											200
#define ANTS_ANDROID_NET_DVR_SET_DEVICECFG									(ANTS_ANDROID_NET_DVR_SETCFG+1)		//!设置设备参数
#define ANTS_ANDROID_NET_DVR_SET_NETCFG										(ANTS_ANDROID_NET_DVR_SETCFG+2)		//!设置网络参数
#define ANTS_ANDROID_NET_DVR_SET_PICCFG										(ANTS_ANDROID_NET_DVR_SETCFG+3)		//!设置图象参数
#define ANTS_ANDROID_NET_DVR_SET_COMPRESSCFG								(ANTS_ANDROID_NET_DVR_SETCFG+4)		//!设置压缩参数
#define ANTS_ANDROID_NET_DVR_SET_RECORDCFG									(ANTS_ANDROID_NET_DVR_SETCFG+5)		//!设置录像时间参数
#define ANTS_ANDROID_NET_DVR_SET_DECODERCFG									(ANTS_ANDROID_NET_DVR_SETCFG+6)		//!设置解码器参数
#define ANTS_ANDROID_NET_DVR_SET_RS232CFG									(ANTS_ANDROID_NET_DVR_SETCFG+7)		//!设置232串口参数
#define ANTS_ANDROID_NET_DVR_SET_ALARMINCFG									(ANTS_ANDROID_NET_DVR_SETCFG+8)		//!设置报警输入参数
#define ANTS_ANDROID_NET_DVR_SET_ALARMOUTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+9)		//!设置报警输出参数
#define ANTS_ANDROID_NET_DVR_SET_TIMECFG									(ANTS_ANDROID_NET_DVR_SETCFG+10)	//!设置DVR时间
#define ANTS_ANDROID_NET_DVR_SET_PREVIEWCFG									(ANTS_ANDROID_NET_DVR_SETCFG+11)	//!设置预览参数
#define ANTS_ANDROID_NET_DVR_SET_VIDEOOUTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+12)	//!设置视频输出参数
#define ANTS_ANDROID_NET_DVR_SET_USERCFG									(ANTS_ANDROID_NET_DVR_SETCFG+13)	//!设置用户参数
#define ANTS_ANDROID_NET_DVR_SET_EXCEPTIONCFG								(ANTS_ANDROID_NET_DVR_SETCFG+14)	//!设置异常参数
#define ANTS_ANDROID_NET_DVR_SET_ZONEANDDST									(ANTS_ANDROID_NET_DVR_SETCFG+15)	//!设置时区和夏时制参数
#define ANTS_ANDROID_NET_DVR_SET_SHOWSTRING									(ANTS_ANDROID_NET_DVR_SETCFG+16)	//!设置叠加字符参数
#define ANTS_ANDROID_NET_DVR_SET_EVENTCOMPCFG								(ANTS_ANDROID_NET_DVR_SETCFG+17)	//!设置事件触发录像参数
#define ANTS_ANDROID_NET_DVR_SET_FTPCFG										(ANTS_ANDROID_NET_DVR_SETCFG+18)	//!设置抓图的FTP参数(基线)
#define ANTS_ANDROID_NET_DVR_SET_AUXOUTCFG									(ANTS_ANDROID_NET_DVR_SETCFG+19)	//!设置报警触发辅助输出设置(HS设备辅助输出)
#define ANTS_ANDROID_NET_DVR_SET_PREVIEWCFG_AUX								(ANTS_ANDROID_NET_DVR_SETCFG+20)	//!设置-s系列双输出预览参数(-s系列双输出)
#define ANTS_ANDROID_NET_DVR_SET_RULECFG									(ANTS_ANDROID_NET_DVR_SETCFG+21)	//!设置行为分析规则
#define ANTS_ANDROID_NET_DVR_SET_TRACK_CFG									(ANTS_ANDROID_NET_DVR_SETCFG+22)	//!设置球机的配置参数 
#define ANTS_ANDROID_NET_DVR_SET_IVMS_STREAMCFG								(ANTS_ANDROID_NET_DVR_SETCFG+23)	//!设置智能分析仪取流参数
#define ANTS_ANDROID_NET_DVR_SET_VCA_CTRLCFG								(ANTS_ANDROID_NET_DVR_SETCFG+24)	//!设置智能控制参数
#define ANTS_ANDROID_NET_DVR_SET_VCA_MASK_REGION							(ANTS_ANDROID_NET_DVR_SETCFG+25) 	//!设置屏蔽区域参数
#define ANTS_ANDROID_NET_DVR_SET_VCA_ENTER_REGION							(ANTS_ANDROID_NET_DVR_SETCFG+26)	//!设置进入区域参数
#define ANTS_ANDROID_NET_DVR_SET_VCA_LINE_SEGMENT							(ANTS_ANDROID_NET_DVR_SETCFG+27)	//!设置标定线
#define ANTS_ANDROID_NET_DVR_SET_IVMS_MASK_REGION							(ANTS_ANDROID_NET_DVR_SETCFG+28)	//!设置IVMS屏蔽区域参数
#define ANTS_ANDROID_NET_DVR_SET_IVMS_ENTER_REGION							(ANTS_ANDROID_NET_DVR_SETCFG+29)	//!设置IVMS进入区域参数
#define ANTS_ANDROID_NET_DVR_SET_IVMS_BEHAVIORCFG  							(ANTS_ANDROID_NET_DVR_SETCFG+30)	//!设置智能分析仪行为规则参数
#define ANTS_ANDROID_NET_DVR_SET_IVMS_SEARCHCFG								(ANTS_ANDROID_NET_DVR_SETCFG+31)	//!设置IVMS回放检索参数
#define ANTS_ANDROID_NET_DVR_SET_POSITION_TRACK     						(ANTS_ANDROID_NET_DVR_SETCFG+32) 	//!设置场景跟踪配置信息
#define ANTS_ANDROID_NET_DVR_SET_CALIBRATION       							(ANTS_ANDROID_NET_DVR_SETCFG+33) 	//!设置标定信息
#define ANTS_ANDROID_NET_DVR_SET_PDC_RULECFG       							(ANTS_ANDROID_NET_DVR_SETCFG+34) 	//!设置人流量统计规则
#define ANTS_ANDROID_NET_DVR_SET_PU_STREAMCFG      							(ANTS_ANDROID_NET_DVR_SETCFG+35) 	//!设置前段取流设备信息
#define ANTS_ANDROID_NET_DVR_SET_DETECT_RULECFG      						(ANTS_ANDROID_NET_DVR_SETCFG+36) 	//!设置ATM异物监测规则
#define ANTS_ANDROID_NET_DVR_SET_VCA_SIZE_FILTER         					(ANTS_ANDROID_NET_DVR_SETCFG+37)	//!设置全局尺寸过滤器
#define ANTS_ANDROID_NET_DVR_SET_TRACK_PARAMCFG      						(ANTS_ANDROID_NET_DVR_SETCFG+38) 	//!设置球机本地菜单规则	
#define ANTS_ANDROID_NET_DVR_SET_DOME_MOVEMENT_PARAM						(ANTS_ANDROID_NET_DVR_SETCFG+39) 	//!设置球机机芯参数
#define ANTS_ANDROID_NET_DVR_SET_NETAPPCFG									(ANTS_ANDROID_NET_DVR_SETCFG+40)	//!设置网络应用参数 NTP/DDNS/EMAIL
#define ANTS_ANDROID_NET_DVR_SET_NTPCFG										(ANTS_ANDROID_NET_DVR_SETCFG+41)	//!设置网络应用参数 NTP
#define ANTS_ANDROID_NET_DVR_SET_DDNSCFG									(ANTS_ANDROID_NET_DVR_SETCFG+42)	//!设置网络应用参数 DDNS
#define ANTS_ANDROID_NET_DVR_SET_EMAILCFG									(ANTS_ANDROID_NET_DVR_SETCFG+43)	//!设置网络应用参数 EMAIL
#define ANTS_ANDROID_NET_DVR_SET_NFSCFG										(ANTS_ANDROID_NET_DVR_SETCFG+44)	//!NFS disk config
#define ANTS_ANDROID_NET_DVR_SET_NETCFG_OTHER								(ANTS_ANDROID_NET_DVR_SETCFG+45)	//!设置网络参数
#define ANTS_ANDROID_NET_DVR_SET_EMAILPARACFG								(ANTS_ANDROID_NET_DVR_SETCFG+46)	//!Setup EMAIL parameters
#define ANTS_ANDROID_NET_DVR_SET_PTZPOS										(ANTS_ANDROID_NET_DVR_SETCFG+47)	//!云台设置PTZ位置
#define ANTS_ANDROID_NET_DVR_SET_REFERENCE_REGION   						(ANTS_ANDROID_NET_DVR_SETCFG+48) 	//!设置参考区域
#define ANTS_ANDROID_NET_DVR_SET_TARFFIC_MASK_REGION   						(ANTS_ANDROID_NET_DVR_SETCFG+49)	//!设置交通事件屏蔽区域
#define ANTS_ANDROID_NET_DVR_SET_SCENE_MODE          						(ANTS_ANDROID_NET_DVR_SETCFG+50) 	//!设置场景模式 
#define ANTS_ANDROID_NET_DVR_SET_AID_RULECFG         						(ANTS_ANDROID_NET_DVR_SETCFG+51)	         
#define ANTS_ANDROID_NET_DVR_SET_TPS_RULECFG         						(ANTS_ANDROID_NET_DVR_SETCFG+52)        	
#define ANTS_ANDROID_NET_DVR_SET_LANECFG									(ANTS_ANDROID_NET_DVR_SETCFG+53)	//!设置车道规则
#define ANTS_ANDROID_NET_DVR_SET_PLATECFG            						(ANTS_ANDROID_NET_DVR_SETCFG+54)	//!设置车牌识别参数
#define ANTS_ANDROID_NET_DVR_SET_CRUISE										(ANTS_ANDROID_NET_DVR_SETCFG+55)		
#define ANTS_ANDROID_NET_DVR_SET_NET_DISKCFG								(ANTS_ANDROID_NET_DVR_SETCFG+56)	//!网络硬盘接入设置
#define ANTS_ANDROID_NET_DVR_SET_HDCFG										(ANTS_ANDROID_NET_DVR_SETCFG+57)	//!设置硬盘管理配置参数
#define ANTS_ANDROID_NET_DVR_SET_HDGROUP_CFG								(ANTS_ANDROID_NET_DVR_SETCFG+58)	//!设置盘组管理配置参数
#define ANTS_ANDROID_NET_DVR_SET_COMPRESSCFG_AUD							(ANTS_ANDROID_NET_DVR_SETCFG+60) 	//!设置设备语音对讲编码参数
#define ANTS_ANDROID_NET_DVR_SET_IOINCFG		        					(ANTS_ANDROID_NET_DVR_SETCFG+61)	//!设置抓拍机IO输入参数
#define ANTS_ANDROID_NET_DVR_SET_IOOUTCFG		        					(ANTS_ANDROID_NET_DVR_SETCFG+62)	//!设置抓拍机IO输出参数
#define ANTS_ANDROID_NET_DVR_SET_FLASHCFG		        					(ANTS_ANDROID_NET_DVR_SETCFG+63)	//!设置IO闪光灯输出参数
#define ANTS_ANDROID_NET_DVR_SET_LIGHTSNAPCFG	        					(ANTS_ANDROID_NET_DVR_SETCFG+64)	//!设置抓拍机红绿灯参数
#define ANTS_ANDROID_NET_DVR_SET_MEASURESPEEDCFG							(ANTS_ANDROID_NET_DVR_SETCFG+65)	//!设置交通事件规则参数
#define ANTS_ANDROID_NET_DVR_SET_IMAGEOVERLAYCFG							(ANTS_ANDROID_NET_DVR_SETCFG+66)	//!设置交通统计规则参数
#define ANTS_ANDROID_NET_DVR_SET_SNAPCFG                					(ANTS_ANDROID_NET_DVR_SETCFG+67)	//!设置单IO触发抓拍功能配置
#define ANTS_ANDROID_NET_DVR_SET_VTPPARAM	        						(ANTS_ANDROID_NET_DVR_SETCFG+68)	//!设置虚拟线圈参数
#define ANTS_ANDROID_NET_DVR_SET_SNAPENABLECFG								(ANTS_ANDROID_NET_DVR_SETCFG+69)	//!设置抓拍机使能参数
#define ANTS_ANDROID_NET_DVR_SET_JPEGCFG									(ANTS_ANDROID_NET_DVR_SETCFG+70)	//!设置抓图的JPEG参数(基线)
#define ANTS_ANDROID_NET_DVR_SET_SPRCFG	                 					(ANTS_ANDROID_NET_DVR_SETCFG+71) 	//!设置车牌识别参数
#define ANTS_ANDROID_NET_DVR_SET_PLCCFG  									(ANTS_ANDROID_NET_DVR_SETCFG+72) 	//!设置车牌亮度补偿参数
#define ANTS_ANDROID_NET_DVR_SET_ZEROCHANCFG 								(ANTS_ANDROID_NET_DVR_SETCFG+73)	//!设置零通道压缩参数
#define ANTS_ANDROID_NET_DVR_SET_ZERO_ZOOM									(ANTS_ANDROID_NET_DVR_SETCFG+74) 	//!设置零通道的缩放配置 
#define ANTS_ANDROID_NET_DVR_SET_NATASSOCIATECFG							(ANTS_ANDROID_NET_DVR_SETCFG+75) 	//!设置NAT功能相关信息
#define ANTS_ANDROID_NET_DVR_SET_SNMPCFG	               					(ANTS_ANDROID_NET_DVR_SETCFG+76) 	//!设置SNMP参数
#define ANTS_ANDROID_NET_DVR_SET_VIDEOPLATFORMALARMCFG						(ANTS_ANDROID_NET_DVR_SETCFG+77)	//!设置视频综合平台报警配置
#define ANTS_ANDROID_NET_DVR_SET_RAID_ADAPTER_INFO  						(ANTS_ANDROID_NET_DVR_SETCFG+78) 	//!设置适配器信息   
#define ANTS_ANDROID_NET_DVR_SET_NETCFG_MULTI         						(ANTS_ANDROID_NET_DVR_SETCFG+79) 	//!设置多网卡配置	
#define ANTS_ANDROID_NET_DVR_SET_IPPARACFG									(ANTS_ANDROID_NET_DVR_SETCFG+80)	//!设置IP接入配置信息
#define ANTS_ANDROID_NET_DVR_SET_CCDPARAMCFG								(ANTS_ANDROID_NET_DVR_SETCFG+81)	//!IPC设置CCD参数配置
#define ANTS_ANDROID_NET_DVR_SET_IPALARMINCFG								(ANTS_ANDROID_NET_DVR_SETCFG+82)	//!设置IP报警输入接入配置信息
#define ANTS_ANDROID_NET_DVR_SET_IPALARMOUTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+83)	//!设置IP报警输出接入配置信息
#define ANTS_ANDROID_NET_DVR_SET_AUTOREBOOT               					(ANTS_ANDROID_NET_DVR_SETCFG+84)	//!设置自动维护参数
#define ANTS_ANDROID_NET_DVR_SET_PICCFGEX									(ANTS_ANDROID_NET_DVR_SETCFG+85)	//!设置图象参数(扩展)
#define ANTS_ANDROID_NET_DVR_SET_COMPRESSCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+86)	//!设置压缩参数(扩展)
#define ANTS_ANDROID_NET_DVR_SET_RECORDCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+87)	//!设置录像时间参数(扩展)
#define ANTS_ANDROID_NET_DVR_SET_DECODERCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+88)	//!设置解码器参数(扩展)
#define ANTS_ANDROID_NET_DVR_SET_ALARMINCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+89)	//!设置报警输入参数(扩展)
#define ANTS_ANDROID_NET_DVR_SET_ALARMOUTCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+90)	//!设置报警输出参数(扩展)
#define ANTS_ANDROID_NET_DVR_SET_SHOWSTRINGEX								(ANTS_ANDROID_NET_DVR_SETCFG+91)	//!设置叠加字符参数(扩展)
#define ANTS_ANDROID_NET_DVR_SET_EVENTCOMPCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+92)	//!设置事件触发录像参数(扩展)
#define ANTS_ANDROID_NET_DVR_SET_WIFI_CFG									(ANTS_ANDROID_NET_DVR_SETCFG+93)	//!设置IP监控设备无线参数
#define ANTS_ANDROID_NET_DVR_SET_WIFI_WORKMODE								(ANTS_ANDROID_NET_DVR_SETCFG+94)	//!设置IP监控设备网口工作模式参数
#define ANTS_ANDROID_NET_DVR_SET_3G_CFG										(ANTS_ANDROID_NET_DVR_SETCFG+95)	//!设置3G配置参数
#define ANTS_ANDROID_NET_DVR_SET_MANAGERHOST_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+96)	//!设置媒体服务器配置参数
#define ANTS_ANDROID_NET_DVR_SET_NETDEV_CFG									(ANTS_ANDROID_NET_DVR_SETCFG+97)	//!设置NVR上的IPC配置参数

//!Modify by ItmanLee at 2012-11-22
#define ANTS_ANDROID_NET_DVR_GET_NETDEV_CFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+100)	//!获取远程NVR的IPC设备信息,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_PICCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+101)	//!获取图象参数,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_USERCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+102)	//!获取用户参数,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_ALARMINCFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+103)	//!获取报警输入参数,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_HDGROUP_CFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+104)	//!获取盘组管理配置参数,针对36-DVR/NVR

//!Added by ItmanLee at 2012-11-22
#define ANTS_ANDROID_NET_DVR_GET_VIDEOEFFECTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+105)	//!获取亮度对比度色度参数
#define ANTS_ANDROID_NET_DVR_GET_MOTIONCFG									(ANTS_ANDROID_NET_DVR_SETCFG+106)	//!获取移动侦测参数
#define ANTS_ANDROID_NET_DVR_GET_MOTIONCFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+107)	//!获取移动侦测参数
#define ANTS_ANDROID_NET_DVR_GET_SHELTERCFG									(ANTS_ANDROID_NET_DVR_SETCFG+108)	//!获取视频遮挡参数
#define ANTS_ANDROID_NET_DVR_GET_HIDEALARMCFG								(ANTS_ANDROID_NET_DVR_SETCFG+109)	//!获取视频遮挡报警参数
#define ANTS_ANDROID_NET_DVR_GET_VIDEOLOSTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+110)	//!获取视频丢失参数
#define ANTS_ANDROID_NET_DVR_GET_OSDCFG										(ANTS_ANDROID_NET_DVR_SETCFG+111)	//!获取视频OSD参数
#define ANTS_ANDROID_NET_DVR_GET_VIDEOFORMAT								(ANTS_ANDROID_NET_DVR_SETCFG+112)	//!获取视频制式参数

#define ANTS_ANDROID_NET_DVR_GET_PICCFGEX_V2								(ANTS_ANDROID_NET_DVR_SETCFG+113)	//!获取图象参数(扩展),针对36-DVR/NVR	
#define ANTS_ANDROID_NET_DVR_GET_ALARMINCFGEX_V2							(ANTS_ANDROID_NET_DVR_SETCFG+114)	//!获取报警输入参数,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_VIDEOEFFECTCFGEX							(ANTS_ANDROID_NET_DVR_SETCFG+115)	//!获取亮度对比度色度参数
#define ANTS_ANDROID_NET_DVR_GET_MOTIONCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+116)	//!获取移动侦测参数
#define ANTS_ANDROID_NET_DVR_GET_MOTIONCFGEX_V2								(ANTS_ANDROID_NET_DVR_SETCFG+117)
#define ANTS_ANDROID_NET_DVR_GET_SHELTERCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+118)	//!获取视频遮挡参数
#define ANTS_ANDROID_NET_DVR_GET_HIDEALARMCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+119)	//!获取视频遮挡报警参数
#define ANTS_ANDROID_NET_DVR_GET_VIDEOLOSTCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+120)	//!获取视频丢失参数
#define ANTS_ANDROID_NET_DVR_GET_OSDCFGEX									(ANTS_ANDROID_NET_DVR_SETCFG+121)	//!获取视频OSD参数
#define ANTS_ANDROID_NET_DVR_GET_VIDEOFORMATEX								(ANTS_ANDROID_NET_DVR_SETCFG+122)
#define ANTS_ANDROID_NET_DVR_GET_AUTOSWITCH_CFG								(ANTS_ANDROID_NET_DVR_SETCFG+123)	//!获取远程NVR自动切换模式
#define ANTS_ANDROID_NET_DVR_GET_NETDEVCONNETCTCFG							(ANTS_ANDROID_NET_DVR_SETCFG+124)	//!获取远程NVR通道是否启用		

//!Added by ItmanLee at 2012-01-08
#define ANTS_ANDROID_NET_DVR_GET_DEVCHANNAME_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+125)	//!获取远程设备通道名称,单通道获取方式
#define ANTS_ANDROID_NET_DVR_GET_DEVCHANNAME_CFG_V2							(ANTS_ANDROID_NET_DVR_SETCFG+126)	//!获取远程设备通道名称,多通道获取方式
#define ANTS_ANDROID_NET_DVR_GET_HDCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+127)	//!获取远程设备硬盘扩展结构
#define ANTS_ANDROID_NET_DVR_GET_SENSORCFG									(ANTS_ANDROID_NET_DVR_SETCFG+128)	//!获取IPC Sensor结构
#define ANTS_ANDROID_NET_DVR_GET_NETDEV_CFG_V3								(ANTS_ANDROID_NET_DVR_SETCFG+129)	//!获取远程NVR的IPC设备信息,针对64-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_MANAGERHOSTV2_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+130)	//!获取远程设备管理平台配置参数

#define ANTS_ANDROID_NET_DVR_GET_NETDEVCONNETCTCFG_V2						(ANTS_ANDROID_NET_DVR_SETCFG+131)	//!获取远程NVR所有IP通道连接状态,针对4/8/16/32/64-NVR	
#define ANTS_ANDROID_NET_DVR_GET_DEVCHANNAME_CFGV2							(ANTS_ANDROID_NET_DVR_SETCFG+132)	//!获取远程NVR所有通道名称结构,针对4/8/16/32/64-NVR	
 
#define ANTS_ANDROID_NET_DVR_SET_NETDEV_CFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+300)	//!设置远程NVR的IPC设备信息,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_PICCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+301)	//!设置图象参数,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_USERCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+302)	//!设置用户参数,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_ALARMINCFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+303)	//!设置报警输入参数,针对36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_HDGROUP_CFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+304)	//!设置盘组管理配置参数,针对36-DVR/NVR

#define ANTS_ANDROID_NET_DVR_SET_VIDEOEFFECTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+305)
#define ANTS_ANDROID_NET_DVR_SET_MOTIONCFG									(ANTS_ANDROID_NET_DVR_SETCFG+306)	//!设置移动侦测参数
#define ANTS_ANDROID_NET_DVR_SET_MOTIONCFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+307)	//!设置移动侦测参数(针对36-DVR/NVR)
#define ANTS_ANDROID_NET_DVR_SET_SHELTERCFG									(ANTS_ANDROID_NET_DVR_SETCFG+308)	//!设置视频遮挡参数
#define ANTS_ANDROID_NET_DVR_SET_HIDEALARMCFG								(ANTS_ANDROID_NET_DVR_SETCFG+309)	//!设置视频遮挡报警参数
#define ANTS_ANDROID_NET_DVR_SET_VIDEOLOSTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+310)	//!设置视频丢失参数
#define ANTS_ANDROID_NET_DVR_SET_OSDCFG										(ANTS_ANDROID_NET_DVR_SETCFG+311)	//!设置视频OSD参数
#define ANTS_ANDROID_NET_DVR_SET_VIDEOFORMAT								(ANTS_ANDROID_NET_DVR_SETCFG+312)

#define ANTS_ANDROID_NET_DVR_SET_PICCFGEX_V2								(ANTS_ANDROID_NET_DVR_SETCFG+313)	//!设置图象参数(扩展),针对64-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_ALARMINCFGEX_V2							(ANTS_ANDROID_NET_DVR_SETCFG+314)	//!设置报警输入参数,针对64-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_VIDEOEFFECTCFGEX							(ANTS_ANDROID_NET_DVR_SETCFG+315)	//!设置亮度对比度色度参数
#define ANTS_ANDROID_NET_DVR_SET_MOTIONCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+316)	//!设置移动侦测参数
#define ANTS_ANDROID_NET_DVR_SET_MOTIONCFGEX_V2								(ANTS_ANDROID_NET_DVR_SETCFG+317) 	//!设置移动侦测参数(针对64-DVR/NVR)	
#define ANTS_ANDROID_NET_DVR_SET_SHELTERCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+318)	//!设置视频遮挡参数
#define ANTS_ANDROID_NET_DVR_SET_HIDEALARMCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+319)	//!设置视频遮挡报警参数
#define ANTS_ANDROID_NET_DVR_SET_VIDEOLOSTCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+320)	//!设置视频丢失参数
#define ANTS_ANDROID_NET_DVR_SET_OSDCFGEX									(ANTS_ANDROID_NET_DVR_SETCFG+321)	//!设置视频OSD参数
#define ANTS_ANDROID_NET_DVR_SET_VIDEOFORMATEX								(ANTS_ANDROID_NET_DVR_SETCFG+322)	//!设置远程设备视频制式
#define ANTS_ANDROID_NET_DVR_SET_AUTOSWITCH_CFG								(ANTS_ANDROID_NET_DVR_SETCFG+323)	//!设置远程NVR自动切换模式
#define ANTS_ANDROID_NET_DVR_SET_NETDEVCONNETCTCFG							(ANTS_ANDROID_NET_DVR_GETCFG+324)	//!设置远程NVR通道是否启用	

//!Added by ItmanLee at 2012-01-08
#define ANTS_ANDROID_NET_DVR_SET_DEVCHANNAME_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+325)	//!设置远程设备通道名称,单通道获取
#define ANTS_ANDROID_NET_DVR_SET_DEVCHANNAME_CFG_V2							(ANTS_ANDROID_NET_DVR_SETCFG+326)	//!设置远程设备通道名称,多通道获取
#define ANTS_ANDROID_NET_DVR_SET_HDCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+327)	//!设置远程设备硬盘扩展结构
#define ANTS_ANDROID_NET_DVR_SET_SENSORCFG									(ANTS_ANDROID_NET_DVR_SETCFG+328)	//!设置IPC Sensor结构
#define ANTS_ANDROID_NET_DVR_SET_NETDEV_CFG_V3								(ANTS_ANDROID_NET_DVR_SETCFG+329)	//!设置远程NVR的IPC设备信息,针对64-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_MANAGERHOSTV2_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+330)	//!获取远程设备管理平台配置参数

#define ANTS_ANDROID_NET_DVR_SET_NETDEVCONNETCTCFG_V2						(ANTS_ANDROID_NET_DVR_SETCFG+331)	//!设置远程NVR所有IP通道连接状态,针对4/8/16/32/64-NVR	
#define ANTS_ANDROID_NET_DVR_SET_DEVCHANNAME_CFGV2							(ANTS_ANDROID_NET_DVR_SETCFG+332)	//!设置远程NVR所有通道名称结构,针对4/8/16/32/64-NVR	

//!Added by ItmanLee at 2013-09-02
#define ANTS_ANDROID_NET_DVR_GET_FACTORY_INFO								(ANTS_ANDROID_NET_DVR_SETCFG+333)

#define ANTS_ANDROID_STATIC_ALLOC_MEMORY 							0x0000 	//!静态分配内存
#define ANTS_ANDROID_DYNAMIC_ALLOC_MEMORY 							0x0001	//!动态分配内存,只分配不管内存释放	

//!查找文件和日志函数返回值
#define ANTS_ANDROID_NET_DVR_FILE_SUCCESS							1000		//!获得文件信息
#define ANTS_ANDROID_NET_DVR_FILE_NOFIND							1001		//!没有文件
#define ANTS_ANDROID_NET_DVR_ISFINDING								1002		//!正在查找文件
#define ANTS_ANDROID_NET_DVR_NOMOREFILE								1003		//!查找文件时没有更多的文件
#define ANTS_ANDROID_NET_DVR_FILE_EXCEPTION							1004		//!查找文件时异常

//!回调函数类型 
#define ANTS_ANDROID_COMM_ALARM										0x1100	//!报警信息主动上传
#define ANTS_ANDROID_COMM_TRADEINFO									0x1500 	//!ATMDVR主动上传交易信息
#define ANTS_ANDROID_COMM_IPCCFG			        				0x4001	//!设备IPC接入配置改变报警信息主动上传

//!操作异常类型(消息方式, 回调方式(保留))
#define ANTS_ANDROID_EXCEPTION_EXCHANGE								0x8000	//!用户交互时异常
#define ANTS_ANDROID_EXCEPTION_AUDIOEXCHANGE						0x8001	//!语音对讲异常
#define ANTS_ANDROID_EXCEPTION_ALARM								0x8002	//!报警异常
#define ANTS_ANDROID_EXCEPTION_PREVIEW								0x8003	//!网络预览异常
#define ANTS_ANDROID_EXCEPTION_SERIAL								0x8004	//!透明通道异常
#define ANTS_ANDROID_EXCEPTION_RECONNECT							0x8005	//!预览时重连
#define ANTS_ANDROID_EXCEPTION_ALARMRECONNECT						0x8006	//!报警时重连
#define ANTS_ANDROID_EXCEPTION_SERIALRECONNECT						0x8007	//!透明通道重连
#define ANTS_ANDROID_SERIAL_RECONNECTSUCCESS 						0x8008	//!透明通道重连成功
#define ANTS_ANDROID_EXCEPTION_PLAYBACK	        					0x8010	//!回放异常
#define ANTS_ANDROID_EXCEPTION_DISKFMT	        					0x8011	//!硬盘格式化
#define ANTS_ANDROID_EXCEPTION_PASSIVEDECODE     					0x8012 	//!被动解码异常
#define ANTS_ANDROID_EXCEPTION_EMAILTEST           					0x8013 	//!邮件测试异常    
#define ANTS_ANDROID_EXCEPTION_BACKUP               				0x8014 	//!备份异常
#define ANTS_ANDROID_PREVIEW_RECONNECTSUCCESS      					0x8015 	//!预览时重连成功
#define ANTS_ANDROID_ALARM_RECONNECTSUCCESS     					0x8016 	//!报警时重连成功

#define ANTS_ANDROID_EXCEPTION_OFFLINE								0x9000 //!设备离线状态
#define ANTS_ANDROID_EXCEPTION_ONLINE								0x9001 //!设备在线状态	

//!预览回调函数
#define ANTS_ANDROID_NET_DVR_SYSHEAD								1		//!系统头数据
#define ANTS_ANDROID_NET_DVR_STREAMDATA								2		//!视频流数据（包括复合流和音视频分开的视频流数据）
#define ANTS_ANDROID_NET_DVR_AUDIOSTREAMDATA						3		//!音频流数据
#define ANTS_ANDROID_NET_DVR_STD_VIDEODATA							4		//!标准视频流数据
#define ANTS_ANDROID_NET_DVR_STD_AUDIODATA							5		//!标准音频流数据
#define ANTS_ANDROID_NET_DVR_MOTIONDETECTIONDATA					6		//!移动侦测帧数据

//!设备报警和异常处理方式
#define ANTS_ANDROID_NOACTION										0x00	//!无响应
#define ANTS_ANDROID_WARNONMONITOR									0x01	//!监视器上警告
#define ANTS_ANDROID_WARNONAUDIOOUT									0x02	//!声音警告
#define ANTS_ANDROID_UPTOCENTER										0x04	//!上传中心
#define ANTS_ANDROID_TRIGGERALARMOUT								0x08	//!触发报警输出
#define ANTS_ANDROID_SENDJPG2EMAIL									0x10	//!JPEG抓图并上传至e-mail


//!报警
//!主类型
#define ANTS_ANDROID_MAJOR_ALARM									0x1

//!次类型
#define ANTS_ANDROID_MINOR_ALARM_IN									0x1			/*报警输入 */
#define ANTS_ANDROID_MINOR_ALARM_OUT								0x2			/*报警输出 */
#define ANTS_ANDROID_MINOR_MOTDET_START								0x3			/*移动侦测报警开始 */
#define ANTS_ANDROID_MINOR_MOTDET_STOP								0x4			/*移动侦测报警结束 */
#define ANTS_ANDROID_MINOR_HIDE_ALARM_START							0x5			/*遮挡报警开始 */
#define ANTS_ANDROID_MINOR_HIDE_ALARM_STOP							0x6			/*遮挡报警结束 */
#define ANTS_ANDROID_MINOR_VCA_ALARM_START							0x7			/*智能报警开始*/
#define ANTS_ANDROID_MINOR_VCA_ALARM_STOP							0x8			/*智能报警停止*/
#define ANTS_ANDROID_MINOR_ITS_ALARM_START    						0x09  		/*交通事件报警开始*/
#define ANTS_ANDROID_MINOR_ITS_ALARM_STOP     						0x0A   		/*交通事件报警结束*/

//!异常
//!主类型
#define ANTS_ANDROID_MAJOR_EXCEPTION								0x2

//!次类型
#define ANTS_ANDROID_MINOR_VI_LOST									0x21		/* 视频信号丢失 */
#define ANTS_ANDROID_MINOR_ILLEGAL_ACCESS							0x22		/* 非法访问 */
#define ANTS_ANDROID_MINOR_HD_FULL									0x23		/* 硬盘满 */
#define ANTS_ANDROID_MINOR_HD_ERROR									0x24		/* 硬盘错误 */
#define ANTS_ANDROID_MINOR_DCD_LOST									0x25		/* MODEM 掉线(保留不使用) */
#define ANTS_ANDROID_MINOR_IP_CONFLICT								0x26		/* IP地址冲突 */
#define ANTS_ANDROID_MINOR_NET_BROKEN								0x27		/* 网络断开*/
#define ANTS_ANDROID_MINOR_REC_ERROR          						0x28   		/* 录像出错 */
#define ANTS_ANDROID_MINOR_IPC_NO_LINK        						0x29   		/* IPC连接异常 */
#define ANTS_ANDROID_MINOR_VI_EXCEPTION       						0x2a   		/* 视频输入异常(只针对模拟通道) */
#define ANTS_ANDROID_MINOR_IPC_IP_CONFLICT    						0x2b   		/*ipc ip 地址 冲突*/

//!操作
//!主类型
#define ANTS_ANDROID_MAJOR_OPERATION								0x3

//!次类型
//!2009-12-16 增加视频综合平台日志类型
#define ANTS_ANDROID_MINOR_FANABNORMAL								0x31		/* 视频综合平台：风扇状态异常 */
#define ANTS_ANDROID_MINOR_FANRESUME								0x32		/* 视频综合平台：风扇状态恢复正常 */
#define ANTS_ANDROID_MINOR_SUBSYSTEM_ABNORMALREBOOT					0x33		/* 视频综合平台：6467异常重启 */
#define ANTS_ANDROID_MINOR_MATRIX_STARTBUZZER						0x34		/* 视频综合平台：dm6467异常，启动蜂鸣器 */

//!2010-01-22 增加视频综合平台异常日志次类型
#define ANTS_ANDROID_MINOR_NET_ABNORMAL								0x35		/*网络状态异常*/
#define ANTS_ANDROID_MINOR_MEM_ABNORMAL								0x36		/*内存状态异常*/
#define ANTS_ANDROID_MINOR_FILE_ABNORMAL							0x37		/*文件状态异常*/


//!次类型
#define ANTS_ANDROID_MINOR_START_DVR								0x41		/* 开机 */
#define ANTS_ANDROID_MINOR_STOP_DVR									0x42		/* 关机 */
#define ANTS_ANDROID_MINOR_STOP_ABNORMAL							0x43		/* 异常关机 */
#define ANTS_ANDROID_MINOR_REBOOT_DVR      							0x44	    /* 本地重启设备*/

#define ANTS_ANDROID_MINOR_LOCAL_LOGIN								0x50		/* 本地登陆 */
#define ANTS_ANDROID_MINOR_LOCAL_LOGOUT								0x51		/* 本地注销登陆 */
#define ANTS_ANDROID_MINOR_LOCAL_CFG_PARM							0x52		/* 本地配置参数 */
#define ANTS_ANDROID_MINOR_LOCAL_PLAYBYFILE          				0x53		/* 本地按文件回放或下载 */
#define ANTS_ANDROID_MINOR_LOCAL_PLAYBYTIME          				0x54		/* 本地按时间回放或下载*/
#define ANTS_ANDROID_MINOR_LOCAL_START_REC							0x55		/* 本地开始录像 */
#define ANTS_ANDROID_MINOR_LOCAL_STOP_REC							0x56		/* 本地停止录像 */
#define ANTS_ANDROID_MINOR_LOCAL_PTZCTRL							0x57		/* 本地云台控制 */
#define ANTS_ANDROID_MINOR_LOCAL_PREVIEW							0x58		/* 本地预览 (保留不使用)*/
#define ANTS_ANDROID_MINOR_LOCAL_MODIFY_TIME         				0x59		/* 本地修改时间(保留不使用) */
#define ANTS_ANDROID_MINOR_LOCAL_UPGRADE             				0x5a		/* 本地升级 */
#define ANTS_ANDROID_MINOR_LOCAL_RECFILE_OUTPUT      				0x5b   		/* 本地备份录象文件 */
#define ANTS_ANDROID_MINOR_LOCAL_FORMAT_HDD          				0x5c    	/* 本地初始化硬盘 */
#define ANTS_ANDROID_MINOR_LOCAL_CFGFILE_OUTPUT      				0x5d   	 	/* 导出本地配置文件 */
#define ANTS_ANDROID_MINOR_LOCAL_CFGFILE_INPUT       				0x5e    	/* 导入本地配置文件 */
#define ANTS_ANDROID_MINOR_LOCAL_COPYFILE            				0x5f    	/* 本地备份文件 */
#define ANTS_ANDROID_MINOR_LOCAL_LOCKFILE            				0x60    	/* 本地锁定录像文件 */
#define ANTS_ANDROID_MINOR_LOCAL_UNLOCKFILE          				0x61    	/* 本地解锁录像文件 */
#define ANTS_ANDROID_MINOR_LOCAL_DVR_ALARM           				0x62    	/* 本地手动清除和触发报警*/
#define ANTS_ANDROID_MINOR_IPC_ADD                   				0x63    	/* 本地添加IPC */
#define ANTS_ANDROID_MINOR_IPC_DEL                   				0x64    	/* 本地删除IPC */
#define ANTS_ANDROID_MINOR_IPC_SET                   				0x65    	/* 本地设置IPC */
#define ANTS_ANDROID_MINOR_LOCAL_START_BACKUP						0x66		/* 本地开始备份 */
#define ANTS_ANDROID_MINOR_LOCAL_STOP_BACKUP						0x67		/* 本地停止备份*/
#define ANTS_ANDROID_MINOR_LOCAL_COPYFILE_START_TIME 				0x68		/* 本地备份开始时间*/
#define ANTS_ANDROID_MINOR_LOCAL_COPYFILE_END_TIME					0x69		/* 本地备份结束时间*/
#define ANTS_ANDROID_MINOR_LOCAL_ADD_NAS             				0x6a		/* 本地添加网络硬盘 （nfs、iscsi）*/
#define ANTS_ANDROID_MINOR_LOCAL_DEL_NAS             				0x6b		/* 本地删除nas盘 （nfs、iscsi）*/
#define ANTS_ANDROID_MINOR_LOCAL_SET_NAS             				0x6c		/* 本地设置nas盘 （nfs、iscsi）*/

#define ANTS_ANDROID_MINOR_REMOTE_LOGIN								0x70		/* 远程登录 */
#define ANTS_ANDROID_MINOR_REMOTE_LOGOUT							0x71		/* 远程注销登陆 */
#define ANTS_ANDROID_MINOR_REMOTE_START_REC							0x72		/* 远程开始录像 */
#define ANTS_ANDROID_MINOR_REMOTE_STOP_REC							0x73		/* 远程停止录像 */
#define ANTS_ANDROID_MINOR_START_TRANS_CHAN							0x74		/* 开始透明传输 */
#define ANTS_ANDROID_MINOR_STOP_TRANS_CHAN							0x75		/* 停止透明传输 */
#define ANTS_ANDROID_MINOR_REMOTE_GET_PARM							0x76		/* 远程获取参数 */
#define ANTS_ANDROID_MINOR_REMOTE_CFG_PARM							0x77		/* 远程配置参数 */
#define ANTS_ANDROID_MINOR_REMOTE_GET_STATUS         				0x78		/* 远程获取状态 */
#define ANTS_ANDROID_MINOR_REMOTE_ARM								0x79		/* 远程布防 */
#define ANTS_ANDROID_MINOR_REMOTE_DISARM							0x7a		/* 远程撤防 */
#define ANTS_ANDROID_MINOR_REMOTE_REBOOT							0x7b		/* 远程重启 */
#define ANTS_ANDROID_MINOR_START_VT									0x7c		/* 开始语音对讲 */
#define ANTS_ANDROID_MINOR_STOP_VT									0x7d		/* 停止语音对讲 */
#define ANTS_ANDROID_MINOR_REMOTE_UPGRADE							0x7e		/* 远程升级 */
#define ANTS_ANDROID_MINOR_REMOTE_PLAYBYFILE         				0x7f		/* 远程按文件回放 */
#define ANTS_ANDROID_MINOR_REMOTE_PLAYBYTIME         				0x80		/* 远程按时间回放 */
#define ANTS_ANDROID_MINOR_REMOTE_PTZCTRL							0x81		/* 远程云台控制 */
#define ANTS_ANDROID_MINOR_REMOTE_FORMAT_HDD         				0x82    	/* 远程格式化硬盘 */
#define ANTS_ANDROID_MINOR_REMOTE_STOP               				0x83   		/* 远程关机 */
#define ANTS_ANDROID_MINOR_REMOTE_LOCKFILE							0x84		/* 远程锁定文件 */
#define ANTS_ANDROID_MINOR_REMOTE_UNLOCKFILE         				0x85		/* 远程解锁文件 */
#define ANTS_ANDROID_MINOR_REMOTE_CFGFILE_OUTPUT     				0x86    	/* 远程导出配置文件 */
#define ANTS_ANDROID_MINOR_REMOTE_CFGFILE_INTPUT     				0x87    	/* 远程导入配置文件 */
#define ANTS_ANDROID_MINOR_REMOTE_RECFILE_OUTPUT     				0x88    	/* 远程导出录象文件 */
#define ANTS_ANDROID_MINOR_REMOTE_DVR_ALARM          				0x89	  	/* 远程手动清除和触发报警*/
#define ANTS_ANDROID_MINOR_REMOTE_IPC_ADD							0x8a		/* 远程添加IPC */
#define ANTS_ANDROID_MINOR_REMOTE_IPC_DEL							0x8b		/* 远程删除IPC */
#define ANTS_ANDROID_MINOR_REMOTE_IPC_SET							0x8c		/* 远程设置IPC */
#define ANTS_ANDROID_MINOR_REBOOT_VCA_LIB            				0x8d    	/*重启智能库*/
#define ANTS_ANDROID_MINOR_REMOTE_ADD_NAS           	 			0x8e   		/* 远程添加nas盘 （nfs、iscsi）*/
#define ANTS_ANDROID_MINOR_REMOTE_DEL_NAS            				0x8f   		/* 远程删除nas盘 （nfs、iscsi）*/
#define ANTS_ANDROID_MINOR_REMOTE_SET_NAS            				0x90   		/* 远程设置nas盘 （nfs、iscsi）*/

//!审讯DVR日志类型
#define ANTS_ANDROID_MINOR_LOCAL_START_REC_CDRW      				0x91   		/* 本地开始刻录 */
#define ANTS_ANDROID_MINOR_LOCAL_STOP_REC_CDRW       				0x92   		/* 本地停止刻录 */
#define ANTS_ANDROID_MINOR_REMOTE_START_REC_CDRW     				0x93   		/* 远程开始刻录 */
#define ANTS_ANDROID_MINOR_REMOTE_STOP_REC_CDRW      				0x94   		/* 远程停止刻录 */

//!视频综合平台日志类型
#define ANTS_ANDROID_MINOR_SUBSYSTEMREBOOT           				0xa0		/*视频综合平台：dm6467 正常重启*/
#define ANTS_ANDROID_MINOR_MATRIX_STARTTRANSFERVIDEO 				0xa1		/*视频综合平台：矩阵切换开始传输图像*/
#define ANTS_ANDROID_MINOR_MATRIX_STOPTRANSFERVIDEO					0xa2		/*视频综合平台：矩阵切换停止传输图像*/
#define ANTS_ANDROID_MINOR_REMOTE_SET_ALLSUBSYSTEM   				0xa3		/*视频综合平台：设置所有6467子系统信息*/
#define ANTS_ANDROID_MINOR_REMOTE_GET_ALLSUBSYSTEM   				0xa4		/*视频综合平台：获取所有6467子系统信息*/
#define ANTS_ANDROID_MINOR_REMOTE_SET_PLANARRAY      				0xa5		/*视频综合平台：设置计划轮询组*/
#define ANTS_ANDROID_MINOR_REMOTE_GET_PLANARRAY      				0xa6		/*视频综合平台：获取计划轮询组*/
#define ANTS_ANDROID_MINOR_MATRIX_STARTTRANSFERAUDIO 				0xa7		/*视频综合平台：矩阵切换开始传输音频*/
#define ANTS_ANDROID_MINOR_MATRIX_STOPRANSFERAUDIO   				0xa8		/*视频综合平台：矩阵切换停止传输音频*/
#define ANTS_ANDROID_MINOR_LOGON_CODESPITTER         				0xa9		/*视频综合平台：登陆码分器*/
#define ANTS_ANDROID_MINOR_LOGOFF_CODESPITTER        				0xaa		/*视频综合平台：退出码分器*/

//!综合平台中解码器操作日志
#define ANTS_ANDROID_MINOR_START_DYNAMIC_DECODE 					0xb0		/*开始动态解码*/
#define ANTS_ANDROID_MINOR_STOP_DYNAMIC_DECODE						0xb1		/*停止动态解码*/
#define ANTS_ANDROID_MINOR_GET_CYC_CFG								0xb2		/*获取解码器通道轮询配置*/
#define ANTS_ANDROID_MINOR_SET_CYC_CFG								0xb3		/*设置解码通道轮询配置*/
#define ANTS_ANDROID_MINOR_START_CYC_DECODE							0xb4		/*开始轮询解码*/
#define ANTS_ANDROID_MINOR_STOP_CYC_DECODE							0xb5		/*停止轮询解码*/
#define ANTS_ANDROID_MINOR_GET_DECCHAN_STATUS						0xb6		/*获取解码通道状态*/
#define ANTS_ANDROID_MINOR_GET_DECCHAN_INFO							0xb7		/*获取解码通道当前信息*/
#define ANTS_ANDROID_MINOR_START_PASSIVE_DEC						0xb8		/*开始被动解码*/
#define ANTS_ANDROID_MINOR_STOP_PASSIVE_DEC							0xb9		/*停止被动解码*/
#define ANTS_ANDROID_MINOR_CTRL_PASSIVE_DEC							0xba		/*控制被动解码*/
#define ANTS_ANDROID_MINOR_RECON_PASSIVE_DEC						0xbb		/*被动解码重连*/
#define ANTS_ANDROID_MINOR_GET_DEC_CHAN_SW							0xbc		/*获取解码通道总开关*/
#define ANTS_ANDROID_MINOR_SET_DEC_CHAN_SW							0xbd		/*设置解码通道总开关*/
#define ANTS_ANDROID_MINOR_CTRL_DEC_CHAN_SCALE						0xbe		/*解码通道缩放控制*/
#define ANTS_ANDROID_MINOR_SET_REMOTE_REPLAY						0xbf		/*设置远程回放*/
#define ANTS_ANDROID_MINOR_GET_REMOTE_REPLAY						0xc0		/*获取远程回放状态*/
#define ANTS_ANDROID_MINOR_CTRL_REMOTE_REPLAY						0xc1		/*远程回放控制*/
#define ANTS_ANDROID_MINOR_SET_DISP_CFG								0xc2		/*设置显示通道*/
#define ANTS_ANDROID_MINOR_GET_DISP_CFG								0xc3		/*获取显示通道设置*/
#define ANTS_ANDROID_MINOR_SET_PLANTABLE							0xc4		/*设置计划轮询表*/
#define ANTS_ANDROID_MINOR_GET_PLANTABLE							0xc5		/*获取计划轮询表*/
#define ANTS_ANDROID_MINOR_START_PPPPOE								0xc6		/*开始PPPoE连接*/
#define ANTS_ANDROID_MINOR_STOP_PPPPOE								0xc7		/*结束PPPoE连接*/
#define ANTS_ANDROID_MINOR_UPLOAD_LOGO								0xc8		/*上传LOGO*/

#define ANTS_ANDROID_MINOR_LOCAL_CONF_REB_RAID       				0x101   	/*本地配置自动重建*/
#define ANTS_ANDROID_MINOR_LOCAL_CONF_SPARE          				0x102   	/*本地配置热备*/
#define ANTS_ANDROID_MINOR_LOCAL_ADD_RAID            				0x103   	/*本地创建阵列*/
#define ANTS_ANDROID_MINOR_LOCAL_DEL_RAID            				0x104   	/*本地删除阵列*/
#define ANTS_ANDROID_MINOR_LOCAL_MIG_RAID            				0x105   	/*本地迁移阵列*/
#define ANTS_ANDROID_MINOR_LOCAL_REB_RAID            				0x106   	/* 本地手动重建阵列*/
#define ANTS_ANDROID_MINOR_LOCAL_QUICK_CONF_RAID     				0x107   	/*本地一键配置*/
#define ANTS_ANDROID_MINOR_LOCAL_ADD_VD              				0x108   	/*本地创建虚拟磁盘*/
#define ANTS_ANDROID_MINOR_LOCAL_DEL_VD              				0x109   	/*本地删除虚拟磁盘*/
#define ANTS_ANDROID_MINOR_LOCAL_RP_VD               				0x10a   	/*本地修复虚拟磁盘*/
#define ANTS_ANDROID_MINOR_LOCAL_FORMAT_EXPANDVD	     			0x10b   	/*本地扩展虚拟磁盘扩容*/
#define ANTS_ANDROID_MINOR_LOCAL_RAID_UPGRADE       	 			0x10c   	/*本地raid卡升级*/    
#define ANTS_ANDROID_MINOR_REMOTE_CONF_REB_RAID      				0x111   	/*远程配置自动重建*/
#define ANTS_ANDROID_MINOR_REMOTE_CONF_SPARE         				0x112   	/*远程配置热备*/
#define ANTS_ANDROID_MINOR_REMOTE_ADD_RAID           				0x113   	/*远程创建阵列*/
#define ANTS_ANDROID_MINOR_REMOTE_DEL_RAID           				0x114   	/*远程删除阵列*/
#define ANTS_ANDROID_MINOR_REMOTE_MIG_RAID           				0x115   	/*远程迁移阵列*/
#define ANTS_ANDROID_MINOR_REMOTE_REB_RAID           				0x116   	/* 远程手动重建阵列*/
#define ANTS_ANDROID_MINOR_REMOTE_QUICK_CONF_RAID    				0x117   	/*远程一键配置*/
#define ANTS_ANDROID_MINOR_REMOTE_ADD_VD            	 			0x118   	/*远程创建虚拟磁盘*/
#define ANTS_ANDROID_MINOR_REMOTE_DEL_VD             				0x119   	/*远程删除虚拟磁盘*/
#define ANTS_ANDROID_MINOR_REMOTE_RP_VD              				0x11a   	/*远程修复虚拟磁盘*/
#define ANTS_ANDROID_MINOR_REMOTE_FORMAT_EXPANDVD	    			0x11b   	/*远程虚拟磁盘扩容*/
#define ANTS_ANDROID_MINOR_REMOTE_RAID_UPGRADE       				0x11c   	/*远程raid卡升级*/    

//!日志附加信息
//!主类型
#define ANTS_ANDROID_MAJOR_INFORMATION               				0x4     	/*附加信息*/
//!次类型
#define ANTS_ANDROID_MINOR_HDD_INFO                  				0xa1 		/*硬盘信息*/
#define ANTS_ANDROID_MINOR_SMART_INFO                				0xa2 		/*SMART信息*/
#define ANTS_ANDROID_MINOR_REC_START                 				0xa3 		/*开始录像*/
#define ANTS_ANDROID_MINOR_REC_STOP                  				0xa4 		/*停止录像*/
#define ANTS_ANDROID_MINOR_REC_OVERDUE								0xa5 		/*过期录像删除*/
#define ANTS_ANDROID_MINOR_LINK_START								0xa6 		/*连接前端设备*/
#define ANTS_ANDROID_MINOR_LINK_STOP								0xa7 		/*断开前端设备*/
#define ANTS_ANDROID_MINOR_NET_DISK_INFO							0xa8 		/*网络硬盘信息*/
#define ANTS_ANDROID_MINOR_RAID_INFO                 				0xa9 		/*raid相关信息*/

//当日志的主类型为ANTS_ANDROIMAJOR_OPERATION=03，次类型为ANTS_ANDROIMINOR_LOCAL_CFG_PARM=0x52或者ANTS_ANDROIMINOR_REMOTE_GET_PARM=0x76或者ANTS_ANDROIMINOR_REMOTE_CFG_PARM=0x77时，dwParaType:参数类型有效，其含义如下：
#define ANTS_ANDROID_PARA_VIDEOOUT									0x1
#define ANTS_ANDROID_PARA_IMAGE										0x2
#define ANTS_ANDROID_PARA_ENCODE									0x4
#define ANTS_ANDROID_PARA_NETWORK									0x8
#define ANTS_ANDROID_PARA_ALARM										0x10
#define ANTS_ANDROID_PARA_EXCEPTION									0x20
#define ANTS_ANDROID_PARA_DECODER									0x40    	/*解码器*/
#define ANTS_ANDROID_PARA_RS232										0x80
#define ANTS_ANDROID_PARA_PREVIEW									0x100
#define ANTS_ANDROID_PARA_SECURITY									0x200
#define ANTS_ANDROID_PARA_DATETIME									0x400
#define ANTS_ANDROID_PARA_FRAMETYPE									0x800   	/*帧格式*/
#define ANTS_ANDROID_PARA_VCA_RULE   								0x1001 	 	/*行为规则*/ 
#define ANTS_ANDROID_PARA_VCA_CTRL   								0x1002		/*配置智能控制信息*/
#define ANTS_ANDROID_PARA_VCA_PLATE  								0x1003 		/*车牌识别*/

#define ANTS_ANDROID_PARA_CODESPLITTER 								0x2000 		/*码分器参数*/
//!视频综合平台日志信息次类型
#define ANTS_ANDROID_PARA_RS485		  								0x2001		/*RS485配置信息*/
#define ANTS_ANDROID_PARA_DEVICE		  							0x2002		/*设备配置信息*/
#define ANTS_ANDROID_PARA_HARDDISK	  								0x2003		/*硬盘配置信息 */
#define ANTS_ANDROID_PARA_AUTOBOOT	  								0x2004		/*自动重启配置信息*/
#define ANTS_ANDROID_PARA_HOLIDAY	  								0x2005		/*节假日配置信息*/			
#define ANTS_ANDROID_PARA_IPC		  								0x2006		/*IP通道配置 */	

//!ATM专用
#define ANTS_ANDROID_NCR						0
#define ANTS_ANDROID_DIEBOLD					1
#define ANTS_ANDROID_WINCOR_NIXDORF	2
#define ANTS_ANDROID_SIEMENS					3
#define ANTS_ANDROID_OLIVETTI					4
#define ANTS_ANDROID_FUJITSU					5
#define ANTS_ANDROID_HITACHI					6
#define ANTS_ANDROID_SMI						7
#define ANTS_ANDROID_IBM						8
#define ANTS_ANDROID_BULL						9
#define ANTS_ANDROID_YiHua						10
#define ANTS_ANDROID_LiDe						11
#define ANTS_ANDROID_GDYT						12
#define ANTS_ANDROID_Mini_Banl					13
#define ANTS_ANDROID_GuangLi					14
#define ANTS_ANDROID_DongXin					15
#define ANTS_ANDROID_ChenTong					16
#define ANTS_ANDROID_NanTian					17
#define ANTS_ANDROID_XiaoXing					18
#define ANTS_ANDROID_GZYY						19
#define ANTS_ANDROID_QHTLT						20
#define ANTS_ANDROID_DRS918						21
#define ANTS_ANDROID_KALATEL					22
#define ANTS_ANDROID_NCR_2						23	
#define ANTS_ANDROID_NXS						24

//!解码设备控制码定义
#define ANTS_ANDROID_NET_DEC_STARTDEC			1
#define ANTS_ANDROID_NET_DEC_STOPDEC			2
#define ANTS_ANDROID_NET_DEC_STOPCYCLE			3
#define ANTS_ANDROID_NET_DEC_CONTINUECYCLE		4

//! 文件播放命令 
#define ANTS_ANDROID_NET_DVR_PLAYSTART					1//!开始播放
#define ANTS_ANDROID_NET_DVR_PLAYSTOP					2//!停止播放
#define ANTS_ANDROID_NET_DVR_PLAYPAUSE					3//!暂停播放
#define ANTS_ANDROID_NET_DVR_PLAYRESTART				4//!恢复播放
#define ANTS_ANDROID_NET_DVR_PLAYFAST					5//!快放
#define ANTS_ANDROID_NET_DVR_PLAYSLOW					6//!慢放
#define ANTS_ANDROID_NET_DVR_PLAYNORMAL					7//!正常速度
#define ANTS_ANDROID_NET_DVR_PLAYSTARTAUDIO				9//!打开声音
#define ANTS_ANDROID_NET_DVR_PLAYSTOPAUDIO				10//!关闭声音
#define ANTS_ANDROID_NET_DVR_PLAYSETPOS					12//!改变文件回放的进度

//!编码类型
#define ANTS_ANDROID_NET_DVR_ENCODER_UNKOWN 			0 /*未知编码格式*/
#define ANTS_ANDROID_NET_DVR_ENCODER_H264   			1 /*私有 264*/
#define ANTS_ANDROID_NET_DVR_ENCODER_S264  				2 /*Standard H264*/
#define ANTS_ANDROID_NET_DVR_ENCODER_MPEG4  			3 /*MPEG4*/
#define ANTS_ANDROID_NET_DVR_ORIGINALSTREAM    			4 //原始流(视频综合平台解码子系统用)

//! 打包格式 
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_UNKOWN   		0  /*未知打包格式*/
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_PRIVT   		1  /*私有格式*/
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_TS    			7  /* TS打包 */
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_PS   			8  /* PS打包 */
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_RTP  			9  /* RTP打包 */
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_ORIGIN   		10 //未打包(视频综合平台解码子系统用)

//!显示通道状态
#define ANTS_ANDROID_NET_DVR_MAX_DISPREGION 16/*每个显示通道最多可以显示的窗口*/

//!低帧率定义
#define ANTS_ANDROID_LOW_DEC_FPS_1_2		51
#define ANTS_ANDROID_LOW_DEC_FPS_1_4 		52
#define ANTS_ANDROID_LOW_DEC_FPS_1_8 		53
#define ANTS_ANDROID_LOW_DEC_FPS_1_16 		54

#define ANTS_ANDROID_MAX_DECODECHANNUM   	64	//!多路解码器最大解码通道数
#define ANTS_ANDROID_MAX_DISPCHANNUM  		64	//!多路解码器最大显示通道数

#define ANTS_ANDROID_PASSIVE_DEC_PAUSE							1/*被动解码暂停(仅文件流有效)*/
#define ANTS_ANDROID_PASSIVE_DEC_RESUME							2/*恢复被动解码(仅文件流有效)*/
#define ANTS_ANDROID_PASSIVE_DEC_FAST          					3/*快速被动解码(仅文件流有效)*/
#define ANTS_ANDROID_PASSIVE_DEC_SLOW							4/*慢速被动解码(仅文件流有效)*/
#define ANTS_ANDROID_PASSIVE_DEC_NORMAL      					5/*正常被动解码(仅文件流有效)*/
#define ANTS_ANDROID_PASSIVE_DEC_ONEBYONE      					6/*被动解码单帧播放(保留)*/
#define ANTS_ANDROID_PASSIVE_DEC_AUDIO_ON 						7/*音频开启*/
#define ANTS_ANDROID_PASSIVE_DEC_AUDIO_OFF						8/*音频关闭*/
#define ANTS_ANDROID_PASSIVE_DEC_RESETBUFFER    				9/*清空缓冲区(仅文件流有效)*/

//!综合平台接口函数
#define ANTS_ANDROID_MAX_SUBSYSTEM_NUM			80					//!一个矩阵系统中最多子系统数量
#define ANTS_ANDROID_MAX_SERIALLEN				36					//!最大序列号长度
#define ANTS_ANDROID_MAX_LOOPPLANNUM			16					//!最大计划切换组
#define ANTS_ANDROID_DECODE_TIMESEGMENT 		4					//!计划解码每天时间段数

//!LinkMode取值范围
#define ANTS_ANDROID_TCP_MAINSTREAM 					(0x00000000|0)//!TCP主码流方式
#define ANTS_ANDROID_TCP_SUBSTREAM						(0x80000000|0)//!TCP子码流方式
#define ANTS_ANDROID_TCP_THIRDSTREAM					(0x40000000|0)//!TCP第三码流方式

#define ANTS_ANDROID_TCP_MAINSTREAM_AUTO				(0x10000000|0)//!TCP主码流自动切换方式
#define ANTS_ANDROID_TCP_SUBSTREAM_AUTO					(0x90000000|0)//!TCP子码流自动切换方式
#define ANTS_ANDROID_TCP_THIRDSTREAM_AUTO    			(0x50000000|0)//!TCP第三码自动切换方式

#define ANTS_ANDROID_UDP_MAINSTREAM						(0x00000000|1)//!UDP主码流方式
#define ANTS_ANDROID_UDP_SUBSTREAM						(0x80000000|1)//!UDP子码流方式
#define ANTS_ANDROID_UDP_THIRDSTREAM					(0x40000000|1)//!UDP第三码流方式

#define ANTS_ANDROID_UDP_MAINSTREAM_AUTO				(0x10000000|1)//!UDP主码流方式自动切换方式
#define ANTS_ANDROID_UDP_SUBSTREAM_AUTO					(0x90000000|1)//!UDP子码流方式自动切换方式
#define ANTS_ANDROID_UDP_THIRDSTREAM_AUTO				(0x50000000|1)//!UDP第三码流方式自动切换方式

#define ANTS_ANDROID_MULTI_MAINSTREAM					(0x00000000|2)//!多播主码流方式
#define ANTS_ANDROID_MULTI_SUBSTREAM					(0x80000000|2)//!多播子码流方式
#define ANTS_ANDROID_MULTI_THIRDSTREAM					(0x40000000|2)//!多播第三码流方式

#define ANTS_ANDROID_MULTI_MAINSTREAM_AUTO				(0x10000000|2)//!多播主码流方式自动切换方式
#define ANTS_ANDROID_MULTI_SUBSTREAM_AUTO				(0x90000000|2)//!多播子码流方式自动切换方式
#define ANTS_ANDROID_MULTI_THIRDSTREAM_AUTO				(0x50000000|2)//!多播第三码流方式自动切换方式

#define ANTS_ANDROID_RTP_MAINSTREAM						(0x00000000|3)//!RTP主码流方式
#define ANTS_ANDROID_RTP_SUBSTREAM						(0x80000000|3)//!RTP子码流方式
#define ANTS_ANDROID_RTP_THIRDSTREAM					(0x40000000|3)//!RTP第三码流方式

#define ANTS_ANDROID_RTP_MAINSTREAM_AUTO				(0x10000000|3)//!RTP主码流方式自动切换方式
#define ANTS_ANDROID_RTP_SUBSTREAM_AUTO					(0x90000000|3)//!RTP子码流方式自动切换方式
#define ANTS_ANDROID_RTP_THIRDSTREAM_AUTO				(0x50000000|3)//!RTP第三码流方式自动切换方式

#define ANTS_ANDROID_IW_ESSID_MAX_SIZE					32
#define ANTS_ANDROID_WIFI_WEP_MAX_KEY_COUNT				4
#define ANTS_ANDROID_WIFI_WEP_MAX_KEY_LENGTH			33
#define ANTS_ANDROID_WIFI_WPA_PSK_MAX_KEY_LENGTH		63
#define ANTS_ANDROID_WIFI_WPA_PSK_MIN_KEY_LENGTH		8
#define ANTS_ANDROID_WIFI_MAX_AP_COUNT					20

//!能力获取命令
#define ANTS_ANDROID_DEVICE_ALL_ABILITY            			0x000	//!设备全部能力
#define ANTS_ANDROID_DEVICE_SOFTHARDWARE_ABILITY   			0x001	//!设备软硬件能力
#define ANTS_ANDROID_DEVICE_NETWORK_ABILITY        			0x002	//!设备网络能力
#define ANTS_ANDROID_DEVICE_ENCODE_ALL_ABILITY     			0x003	//!设备所有编码能力
#define ANTS_ANDROID_DEVICE_ENCONE_CURRENT         			0x004	//!设备当前编码能力
#define ANTS_ANDROID_IPC_FRONT_PARAMETER					0x005	//!ipc前端参数
#define ANTS_ANDROID_IPC_UPGRADE_DESCRIPTION				0x006	//!ipc升级信息
#define ANTS_ANDROID_VCA_DEV_ABILITY 	 					0x100	//!设备智能分析的总能力
#define ANTS_ANDROID_VCA_CHAN_ABILITY     					0x110	//!行为分析能力
#define ANTS_ANDROID_MATRIXDECODER_ABILITY 					0x200	//!多路解码器显示、解码能力
#define ANTS_ANDROID_SNAPCAMERA_ABILITY         			0x300 	//!抓拍机能力集
#define ANTS_ANDROID_COMPRESSIONCFG_ABILITY  				0x400	//!获取压缩参数能力获取
#define ANTS_ANDROID_COMPRESSIONCFG_ABILITYEX				0x500	//!获取所有压缩参数能力
#define ANTS_ANDROID_COMPRESSIONCFG_ABILITYEX_V2			0x600	//!获取所有压缩参数能力(扩展命令,针对36-DVR/NVR)

//!报警回调命令
//!对应ANTS_ANDROID_NET_DVR_PLATE_RESULT
#define ANTS_ANDROID_COMM_ALARM_PLATE						0x1101 //!车牌识别报警信息
//!对应ANTS_ANDROID_NET_VCA_RULE_ALARM
#define ANTS_ANDROID_COMM_ALARM_RULE						0x1102 //!行为分析报警信息
#define ANTS_ANDROID_COMM_ALARM_PDC                 		0x1103 //!人数统计报警信息
#define ANTS_ANDROID_COMM_ALARM_VIDEOPLATFORM        		0x1104 //!视频综合平台报警
#define ANTS_ANDROID_COMM_ALARM_AID                  		0x1110 //!交通事件报警信息
#define ANTS_ANDROID_COMM_ALARM_TPS                  		0x1111 //!交通参数统计报警信息

//!结构参数宏定义 
#define ANTS_ANDROID_VCA_MAX_POLYGON_POINT_NUM				10	//!检测区域最多支持10个点的多边形
#define ANTS_ANDROID_MAX_RULE_NUM							8	//!最多规则条数
#define ANTS_ANDROID_MAX_TARGET_NUM    						30	//!最多目标个数
#define ANTS_ANDROID_MAX_CALIB_PT 							6	//!最大标定点个数
#define ANTS_ANDROID_MIN_CALIB_PT 							4	//!最小标定点个数
#define ANTS_ANDROID_MAX_TIMESEGMENT_2	    				2	//!最大时间段数
#define ANTS_ANDROID_MAX_LICENSE_LEN						16	//!车牌号最大长度
#define ANTS_ANDROID_MAX_PLATE_NUM							3	//!车牌个数
#define ANTS_ANDROID_MAX_MASK_REGION_NUM					4	//!最多四个屏蔽区域
#define ANTS_ANDROID_MAX_SEGMENT_NUM						6	//!摄像机标定最大样本线数目
#define ANTS_ANDROID_MIN_SEGMENT_NUM						3	//!摄像机标定最小样本线数目

#define ANTS_ANDROID_MAX_VCA_CHAN  							16	//!最大智能通道数

//!行为分析能力类型
#define ANTS_ANDROID_TRAVERSE_PLANE_ABILITY			0x01						//!穿越警戒面
#define ANTS_ANDROID_ENTER_AREA_ABILITY				0x02						//!进入区域
#define ANTS_ANDROID_EXIT_AREA_ABILITY				0x04						//!离开区域
#define ANTS_ANDROID_INTRUSION_ABILITY				0x08						//!入侵
#define ANTS_ANDROID_LOITER_ABILITY					0x10						//!徘徊
#define ANTS_ANDROID_LEFT_TAKE_ABILITY				0x20						//!丢包捡包
#define ANTS_ANDROID_PARKING_ABILITY				0x40						//!停车
#define ANTS_ANDROID_RUN_ABILITY					0x80						//!奔跑
#define ANTS_ANDROID_HIGH_DENSITY_ABILITY			0x100						//!内人员密度
#define ANTS_ANDROID_LF_TRACK_ABILITY				0x200						//!球机跟踪
#define ANTS_ANDROID_VIOLENT_MOTION_ABILITY			0x400						//!剧烈运动检测
#define ANTS_ANDROID_REACH_HIGHT_ABILITY			0x800						//!攀高检测
#define ANTS_ANDROID_GET_UP_ABILITY					0x1000						//!起身检测
#define ANTS_ANDROID_TARRY_ABILITY					0x2000						//!人员滞留
#define ANTS_ANDROID_STICK_UP_ABILITY				0x40000000					//!贴纸条
#define ANTS_ANDROID_INSTALL_SCANNER_ABILITY		0x80000000					//!安装读卡器

//!行为分析事件类型
#define ANTS_ANDROID_VCA_TRAVERSE_PLANE				0x1							//!穿越警戒面
#define ANTS_ANDROID_VCA_ENTER_AREA					0x2							//!目标进入区域,支持区域规则
#define ANTS_ANDROID_VCA_EXIT_AREA					0x4							//!目标离开区域,支持区域规则
#define ANTS_ANDROID_VCA_INTRUSION					0x8							//!周界入侵,支持区域规则
#define ANTS_ANDROID_VCA_LOITER						0x10						//!徘徊,支持区域规则
#define ANTS_ANDROID_VCA_LEFT_TAKE					0x20						//!丢包捡包,支持区域规则
#define ANTS_ANDROID_VCA_PARKING					0x40						//!停车,支持区域规则
#define ANTS_ANDROID_VCA_RUN						0x80						//!奔跑,支持区域规则
#define ANTS_ANDROID_VCA_HIGH_DENSITY				0x100						//!区域内人员密度,支持区域规则
#define ANTS_ANDROID_VCA_VIOLENT_MOTION				0x200						//!剧烈运动检测
#define ANTS_ANDROID_VCA_REACH_HIGHT				0x400						//!攀高检测
#define ANTS_ANDROID_VCA_GET_UP						0x800						//!起身检测
#define ANTS_ANDROID_VCA_TARRY						0x1000						//!人员滞留
#define ANTS_ANDROID_VCA_STICK_UP					0x40000000					//!贴纸条,支持区域规则
#define ANTS_ANDROID_VCA_INSTALL_SCANNER			0x80000000					//!安装读卡器,支持区域规则

//!警戒面穿越方向类型
#define ANTS_ANDROID_VCA_BOTH_DIRECTION				0x00						//!双向 
#define ANTS_ANDROID_VCA_LEFT_GO_RIGHT				0x01						//!由左至右 
#define ANTS_ANDROID_VCA_RIGHT_GO_LEFT				0x02						//!由右至左
 
#define ANTS_ANDROID_MAX_NET_DISK 					16							//!最大网络硬盘个数

//!事件类型
//!主类型
#define ANTS_ANDROID_EVENT_MOT_DET 					0							//!移动侦测
#define ANTS_ANDROID_EVENT_ALARM_IN					1							//!报警输入
#define ANTS_ANDROID_EVENT_VCA_BEHAVIOR				2							//! 行为分析
#define ANTS_ANDROID_EVENT_VCA_ITS					3							//!交通事件     

//!行为分析主类型对应的此类型， 0xffff表示全部
#define ANTS_ANDROID_EVENT_TRAVERSE_PLANE			0							//!穿越警戒面
#define ANTS_ANDROID_EVENT_ENTER_AREA				1							//!目标进入区域,支持区域规则
#define ANTS_ANDROID_EVENT_EXIT_AREA				2							//!目标离开区域,支持区域规则
#define ANTS_ANDROID_EVENT_INTRUSION				3							//!周界入侵,支持区域规则
#define ANTS_ANDROID_EVENT_LOITER					4							//!徘徊,支持区域规则
#define ANTS_ANDROID_EVENT_LEFT_TAKE				5							//!丢包捡包,支持区域规则
#define ANTS_ANDROID_EVENT_PARKING					6							//!停车,支持区域规则
#define ANTS_ANDROID_EVENT_RUN						7							//!奔跑,支持区域规则
#define ANTS_ANDROID_EVENT_HIGH_DENSITY				8
#define ANTS_ANDROID_EVENT_VIOLENT_MOTION			9							//!剧烈运动
#define ANTS_ANDROID_EVENT_REACH_HIGH				10							//!攀高
#define ANTS_ANDROID_EVENT_GET_UP					11							//!起身
#define ANTS_ANDROID_EVENT_STICK_UP					12							//!贴纸条,支持区域规则
#define ANTS_ANDROID_EVENT_INSTALL_SCANNER			13							//!安装读卡器,支持区域规则
#define ANTS_ANDROID_EVENT_OBJECT_PASTE				20							//!异物粘贴区域

#define ANTS_ANDROID_SEARCH_EVENT_INFO_LEN 300									//事件信息长度


//!异物监测规则配置
#define ANTS_ANDROID_DETECTION_AREA					0							//!检测区域
#define ANTS_ANDROID_ENTER_AREA						1							//!进入区域
#define ANTS_ANDROID_MAX_DETECT_RECT 				8							//!最大检测区域个数

//!设置人脸识别内部参数关键字
#define ANTS_ANDROID_MAX_FACE_SIZE 					20							//!最大人脸大小
#define ANTS_ANDROID_MINI_FACE_SIZE 				21							//!最小人脸大小

//!标定配置类型
#define ANTS_ANDROID_PDC_CALIBRATE					0x01						//!PDC 标定
#define ANTS_ANDROID_BEHAVIOR_OUT_CALIBRATE			0x02						//!行为室外场景标定  
#define ANTS_ANDROID_BEHAVIOR_IN_CALIBRATE			0x03						//!行为室内场景标定 
#define ANTS_ANDROID_ITS_CALBIRETE					0x04						//!交通事件标定

#define ANTS_ANDROID_MAX_RECT_NUM  					6
#define ANTS_ANDROID_CALIB_PT_NUM 					4

#define ANTS_ANDROID_HUMAN_GENERATE_RATE			50							//!目标生成速度 从50开始
#define ANTS_ANDROID_DETECT_SENSITIVE				51							//!检测灵敏度

#define ANTS_ANDROID_MAX_POSITION_NUM 				10
#define ANTS_ANDROID_MAX_REGION_NUM					8							//!区域列表最大数目
#define ANTS_ANDROID_MAX_TPS_RULE					8							//!最大参数规则数目
#define ANTS_ANDROID_MAX_AID_RULE					8							//!最大事件规则数目
#define ANTS_ANDROID_MAX_LANE_NUM					8							//!最大车道数目

//!交通事件类型
#define ANTS_ANDROID_CONGESTION						0x01						//!拥堵
#define ANTS_ANDROID_PARKING						0x02						//!停车  
#define ANTS_ANDROID_INVERSE						0x04						//!逆行
#define ANTS_ANDROID_PEDESTRIAN						0x08						//!行人                      
#define ANTS_ANDROID_DEBRIS							0x10						//!遗留物 抛洒物碎片 

#define ANTS_ANDROID_FREEWAY 						0							//!普通高速路段 

#define ANTS_ANDROID_ITS_CONGESTION_ABILITY				0x01					//!拥堵
#define ANTS_ANDROID_ITS_PARKING_ABILITY				0x02					//!停车  
#define ANTS_ANDROID_ITS_INVERSE_ABILITY				0x04					//!逆行
#define ANTS_ANDROID_ITS_PEDESTRIAN_ABILITY				0x08					//!行人                      
#define ANTS_ANDROID_ITS_DEBRIS_ABILITY					0x10					//!遗留物 抛洒物碎片
#define ANTS_ANDROID_ITS_LANE_VOLUME_ABILITY			0x010000				//!车道流量
#define ANTS_ANDROID_ITS_LANE_VELOCITY_ABILITY			0x020000				//!车道平均速度
#define ANTS_ANDROID_ITS_TIME_HEADWAY_ABILITY			0x040000				//!车头时距
#define ANTS_ANDROID_ITS_SPACE_HEADWAY_ABILITY			0x080000				//!车头间距
#define ANTS_ANDROID_ITS_TIME_OCCUPANCY_RATIO_ABILITY	0x100000				//!车道占有率，（时间上)
#define ANTS_ANDROID_ITS_SPACE_OCCUPANCY_RATIO_ABILITY	0x200000				//!车道占有率，百分比计算（空间上)
#define ANTS_ANDROID_ITS_LANE_QUEUE_ABILITY				0x400000				//!排队长度

//! 交通统计参数
#define ANTS_ANDROID_LANE_VOLUME						0x01					//!车道流量
#define ANTS_ANDROID_LANE_VELOCITY						0x02					//!车道速度
#define ANTS_ANDROID_TIME_HEADWAY						0x04					//!车头时距
#define ANTS_ANDROID_SPACE_HEADWAY						0x08					//!车头间距
#define ANTS_ANDROID_TIME_OCCUPANCY_RATIO				0x10					//!车道占有率 (时间上)
#define ANTS_ANDROID_SPACE_OCCUPANCY_RATIO				0x20					//!车道占有率，百分比计算(空间上)
#define ANTS_ANDROID_QUEUE								0x40					//!排队长度

#define ANTS_ANDROID_XXX_MAJOR_VERSION      			2

//! 子版本号，性能优化、局部结构调整、模块内集成其他库的主版本提升时递增，最大31 
#define ANTS_ANDROID_XXX_SUB_VERSION        			3

//! 修正版本号，修正bug后递增，最大31 
#define ANTS_ANDROID_XXX_REVISION_VERSION   			4

#define ANTS_VIDEOPLATFORM_SBUCODESYSTEM_ABILITY        0x211 					//!视频综合平台编码子系统能力集

//!获取能力集接口
#define ANTS_ANDROID_VIDEOPLATFORM_ABILITY          	0x210 					//!视频综合平台能力集

//!车牌颜色
#define ANTS_ANDROID_VCA_BLUE_PLATE						0						//!蓝色车牌
#define ANTS_ANDROID_VCA_YELLOW_PLATE					1						//!黄色车牌
#define ANTS_ANDROID_VCA_WHITE_PLATE					2						//!白色车牌
#define ANTS_ANDROID_VCA_BLACK_PLATE					3						//!黑色车牌

//!车牌类型
#define ANTS_ANDROID_VCA_STANDARD92_PLATE				0						//!标准民用车与军车
#define ANTS_ANDROID_VCA_STANDARD02_PLATE				1						//!02式民用车牌 
#define ANTS_ANDROID_VCA_WJPOLICE_PLATE					2						//!武警车 
#define ANTS_ANDROID_VCA_JINGCHE_PLATE					3						//!警车
#define ANTS_ANDROID_STANDARD92_BACK_PLATE				4						//!民用车双行尾牌

//!后面紧跟图片数据和录像数据，只传一种，图片数据为场景图片+车牌小图片
//!车牌报警ANTS_ANDROID_NET_DVR_PLATE_RESULT
#define ANTS_ANDROID_COMM_UPLOAD_PLATE_RESULT			0x2800					//!上传车牌信息

//!可用来命名图片的相关元素 
#define ANTS_ANDROID_PICNAME_ITEM_DEV_NAME 				1/*设备名*/
#define ANTS_ANDROID_PICNAME_ITEM_DEV_NO 				2/*设备号*/
#define ANTS_ANDROID_PICNAME_ITEM_DEV_IP 				3/*设备IP*/
#define ANTS_ANDROID_PICNAME_ITEM_CHAN_NAME 			4/*通道名*/
#define ANTS_ANDROID_PICNAME_ITEM_CHAN_NO 				5/*通道号*/
#define ANTS_ANDROID_PICNAME_ITEM_TIME 					6/*时间*/
#define ANTS_ANDROID_PICNAME_ITEM_CARDNO				7/*卡号*/
#define ANTS_ANDROID_PICNAME_ITEM_PLATE_NO      		8/*车牌号码*/
#define ANTS_ANDROID_PICNAME_ITEM_PLATE_COLOR   		9/*车牌颜色*/
#define ANTS_ANDROID_PICNAME_ITEM_CAR_CHAN      		10/*车道号*/
#define ANTS_ANDROID_PICNAME_ITEM_CAR_SPEED     		11/*车辆速度*/
#define ANTS_ANDROID_PICNAME_ITEM_CARCHAN       		12/*监测点*/
#define ANTS_ANDROID_PICNAME_MAXITEM 					15

#define ANTS_ANDROID_IPC_PROTOCOL_NUM 					128						//!ipc 协议最大个数

#define ANTS_ANDROID_MAX_ZEROCHAN_NUM    				16
#define ANTS_ANDROID_DESC_LEN_64 						64
#define ANTS_ANDROID_PROCESSING          				0						//!正在处理
#define ANTS_ANDROID_PROCESS_SUCCESS     				100						//!过程完成
#define ANTS_ANDROID_PROCESS_EXCEPTION   				400						//!过程异常
#define ANTS_ANDROID_PROCESS_FAILED      				500						//!过程失败
#define ANTS_ANDROID_SOFTWARE_VERSION_LEN 				48
#define ANTS_ANDROID_MAX_SADP_NUM   					256 					//!搜索到设备最大数目

//!备份进度列表
#define ANTS_ANDROID_BACKUP_SUCCESS                		100  //!备份完成
#define ANTS_ANDROID_BACKUP_SEARCH_DEVICE          		300  //!正在搜索备份设备
#define ANTS_ANDROID_BACKUP_SEARCH_FILE            		301  //!正在搜索录像文件
#define ANTS_ANDROID_BACKUP_EXCEPTION  					400  //!备份异常
#define ANTS_ANDROID_BACKUP_FAIL						500  //!备份失败
#define ANTS_ANDROID_BACKUP_TIME_SEG_NO_FILE       		501  //!时间段内无录像文件
#define ANTS_ANDROID_BACKUP_NO_RESOURCE            		502  //!申请不到资源
#define ANTS_ANDROID_BACKUP_DEVICE_LOW_SPACE       		503  //!备份设备容量不足
#define ANTS_ANDROID_BACKUP_DISK_FINALIZED         		504  //!刻录光盘封盘
#define ANTS_ANDROID_BACKUP_DISK_EXCEPTION         		505  //!刻录光盘异常
#define ANTS_ANDROID_BACKUP_DEVICE_NOT_EXIST       		506  //!备份设备不存在
#define ANTS_ANDROID_BACKUP_OTHER_BACKUP_WORK      		507  //!有其他备份操作在进行
#define ANTS_ANDROID_BACKUP_USER_NO_RIGHT          		508  //!用户没有操作权限
#define ANTS_ANDROID_BACKUP_OPERATE_FAIL           		509  //!操作失败

#define ANTS_ANDROID_MAX_ABILITYTYPE_NUM  				12	 //!最大能力项

#define ANTS_ANDROID_SUPPORT_PD_NUM						16
#define ANTS_ANDROID_SUPPORT_ARRAY_NUM					8
#define ANTS_ANDROID_SUPPORT_VD_NUM						128

#define ANTS_ANDROID_RAID0  							1
#define ANTS_ANDROID_RAID1								2
#define ANTS_ANDROID_RAID10								3
#define ANTS_ANDROID_RAID1E								4
#define ANTS_ANDROID_RAID5								5
#define ANTS_ANDROID_RAID6								6
#define ANTS_ANDROID_RAID50								7
#define ANTS_ANDROID_JBOD								8 
#define ANTS_ANDROID_RAID60								9

#define ANTS_ANDROID_HD_TYPE_SATA						0x01
#define ANTS_ANDROID_HD_TYPE_PATA						0x02
#define ANTS_ANDROID_HD_TYPE_SAS						0x04
#define ANTS_ANDROID_HD_TYPE_ATAPI						0x08
#define ANTS_ANDROID_HD_TYPE_TAPE						0x10
#define ANTS_ANDROID_HD_TYPE_SES						0x20

//!按位表示 位为0表示不支持  1表示支持
#define ANTS_ANDROID_RAID0_ABILITY						0x0001
#define ANTS_ANDROID_RAID1_ABILITY						0x0002
#define ANTS_ANDROID_RAID10_ABILITY						0x0004
#define ANTS_ANDROID_RAID1E_ABILITY						0x0008
#define ANTS_ANDROID_RAID5_ABILITY						0x0010
#define ANTS_ANDROID_RAID6_ABILITY						0x0020
#define ANTS_ANDROID_RAID50_ABILITY						0x0040
#define ANTS_ANDROID_JBOD_ABILITY						0x0080
#define ANTS_ANDROID_RAID60_ABILITY						0x0100

#define ANTS_ANDROID_BGA_REBUILD						0x01	//!重建
#define ANTS_ANDROID_BGA_CONSISTENCY_FIX				0x02	//!一致性检查并修复
#define ANTS_ANDROID_BGA_CONSISTENCY_CHECK				0x04	//!一致性检查
#define ANTS_ANDROID_BGA_INIT_QUICK						0x08	//!初始化(快)
#define ANTS_ANDROID_BGA_INIT_BACK						0x10	//!初始化(完全)
#define ANTS_ANDROID_BGA_MIGRATION						0x20	//!迁移
#define ANTS_ANDROID_BGA_INIT_FORE						0x40	//!初始化
#define ANTS_ANDROID_BGA_COPYBACK						0x80	//!回迁

#define ANTS_ANDROID_BGA_STATE_NONE						0		//!无后台任务
#define ANTS_ANDROID_BGA_STATE_RUNNING					1		//!后台任务正在运行
#define ANTS_ANDROID_BGA_STATE_ABORTED					2		//!后台任务取消
#define ANTS_ANDROID_BGA_STATE_PAUSED					3		//!后台任务暂停

#define ANTS_ANDROID_MAX_INQUEST_PIP_NUM   				3	    //!单通道显示的画中画数目
#define ANTS_ANDROID_MAX_INQUEST_CDRW_NUM  				4   	//!最大刻录机数目

#define ANTS_ANDROID_NET_DVR_SHOWLOGO					1/*显示LOGO*/
#define ANTS_ANDROID_NET_DVR_HIDELOGO					2/*隐藏LOGO*/ 
#define ANTS_ANDROID_DISP_CMD_ENLARGE_WINDOW			1/*显示通道放大某个窗口*/
#define ANTS_ANDROID_DISP_CMD_RENEW_WINDOW				2/*显示通道窗口还原*/

//!标识校验 
#define ANTS_ANDROID_NET_DVR_PDC_VERIFY_CALIBRATION				1//!当值为1是为PDC标定校验 pdc传入值为NET_VCA_POINT   传出值为 NET_VCA_RECT结构
#define ANTS_ANDROID_NET_DVR_VERIFY_BEHAVIOR_CALIBRATION    	2//!行为分析标定线校验 
#define ANTS_ANDROID_NET_DVR_VERIFY_ITS_CALIBRATION				3//!智能交通标定校验 

//!设备主动注册宏定义
#define ANTS_ANDROID_NET_DVR_REGISTER							1
#define ANTS_ANDROID_NET_DVR_UNREGISTER							2

#define ANTS_ANDROID_NET_DVR_ONLINE								1
#define ANTS_ANDROID_NET_DVR_OFFLINE							2

//!Added by ItmanLee for Search Device at 2012-12-15
#define ANTS_ANDROID_NET_DVR_SUPPORT_ONVIF					(0x0001)
#define ANTS_ANDROID_NET_DVR_SUPPORT_PRIVATENET				(0x0002)
#define ANTS_ANDROID_MAX_SUPPORTPROTOCOLNUM 				(64)

#define ANTS_ANDROID_NET_DVR_MANAGERHOST_TYPE_AGENT_SH      1
#define ANTS_ANDROID_NET_DVR_MANAGERHOST_TYPE_TIANST_UC     2
#define ANTS_ANDROID_NET_DVR_MANAGERHOST_TYPE_TIANST_IPVS   3
#define ANTS_ANDROID_NET_DVR_MANAGERHOST_TYPE_MINGSOFT      4

//!Added by ItmanLee at 2013-01-25 远程设备搜索查询状态
#define ANTS_ANDROID_NET_DVR_QUERY_SUCCESS 					0x0000 	//!远程设备查询成功 
#define ANTS_ANDROID_NET_DVR_QUERY_BUSY 					0x0001	//!远程设备查询忙
#define ANTS_ANDROID_NET_DVR_QUERY_FAILED					0x0002	//!远程设备查询失败

//!Added by ItmanLee at 2013-08-08 远程控制
#define ANTS_ANDROID_NET_DVR_CONTROL_AGENT_REPAIRMAIN         	10100 //维保
#define ANTS_ANDROID_NET_DVR_CONTROL_AGENT_FAULTREPAIR        	10101 //故障报修
#define ANTS_ANDROID_NET_DVR_CONTROL_AGENT_MANUALPICTURE      	10102 //手动图像上传
#define ANTS_ANDROID_NET_DVR_CONTROL_MANAGERHOSTS_MAX         	19999 
#define ANTS_ANDROID_NET_DVR_CONTROL_REMOTE_ADJUSTTIME       	110
#define ANTS_ANDROID_NET_DVR_CONTROL_REMOTE_REBOOT           	111

//=========================================仅供恩智手机搜索模块使用 Begin======================================================
//!SDK接口函数声明
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_Cleanup(JNIEnv* env,jobject thiz);

//!搜索模块
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_Start(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_Stop(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_Discovery_GetCount(JNIEnv* env,jobject thiz);
JNIEXPORT jstring JNICALL Java_com_Activity_Discovery_GetDeviceByIndex(JNIEnv* env,jobject thiz,jint Index);
JNIEXPORT jstring JNICALL Java_com_Activity_Discovery_GetAllDevices(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_ModifyDevice(JNIEnv* env,jobject thiz,jstring ModfiyString);
//=========================================仅供恩智手机搜索模块使用 End  ======================================================

//!RemoteCtrlActivity
//=========================================仅供恩智手机控制模块使用 Begin=====================================================
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_Cleanup(JNIEnv* env,jobject thiz);
JNIEXPORT jstring JNICALL Java_com_Activity_RemoteControl_Login(JNIEnv* env,jobject thiz,jstring HostIPString,jint CtrlPort,jstring UserNameString,jstring PasswordString);
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_Logout(JNIEnv* env,jobject thiz,jint UserId);
JNIEXPORT jint JNICALL Java_com_Activity_RemoteControl_GetLastError(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_Send(JNIEnv* env,jobject thiz,jint UserId,jint Command,jbyteArray Array,jint Size);
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_SendV2(JNIEnv* env,jobject thiz,jint UserId,jint Command,jint Param);
//=========================================仅供恩智手机控制模块使用 End  ======================================================

//!Real Stream
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview_Cleanup(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_Preview_Login(JNIEnv* env,jobject thiz,jstring HostIPString,jint CtrlPort,jstring UserNameString,jstring PasswordString);
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview_Logout(JNIEnv* env,jobject thiz,jint UserId);
JNIEXPORT jint JNICALL Java_com_Activity_Preview_GetLastError(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_Preview_Start(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint LinkMode,jint x,jint y,jint Width,jint Height);
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview_Stop(JNIEnv* env,jobject thiz,jint RealPlayId);
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview_SetClientVideoEffect(JNIEnv* env,jobject thiz,jint RealPlayId,jint Bright,jint Contrast,jint Saturation,jint Hue);
JNIEXPORT jstring JNICALL Java_com_Activity_Preview_GetClientVideoEffect(JNIEnv* env,jobject thiz,jint RealPlayId);

JNIEXPORT jboolean JNICALL Java_com_Activity_Preview4LowVersion_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview4LowVersion_Cleanup(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_Preview4LowVersion_Login(JNIEnv* env,jobject thiz,jstring HostIPString,jint CtrlPort,jstring UserNameString,jstring PasswordString);
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview4LowVersion_Logout(JNIEnv* env,jobject thiz,jint UserId);
JNIEXPORT jint JNICALL Java_com_Activity_Preview4LowVersion_GetLastError(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_Preview4LowVersion_Start(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint LinkMode,jint x,jint y,jint Width,jint Height);
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview4LowVersion_Stop(JNIEnv* env,jobject thiz,jint RealPlayId);
JNIEXPORT jboolean JNICALL Java_com_Activity_Preview4LowVersion_SetClientVideoEffect(JNIEnv* env,jobject thiz,jint RealPlayId,jint Bright,jint Contrast,jint Saturation,jint Hue);
JNIEXPORT jstring JNICALL Java_com_Activity_Preview4LowVersion_GetClientVideoEffect(JNIEnv* env,jobject thiz,jint RealPlayId);

//!PTZ Control
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_Cleanup(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_PTZControl_Login(JNIEnv* env,jobject thiz,jstring HostIPString,jint CtrlPort,jstring UserNameString,jstring PasswordString);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_Logout(JNIEnv* env,jobject thiz,jint UserId);
JNIEXPORT jint JNICALL Java_com_Activity_PTZControl_GetLastError(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_PTZControl(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint Command,jint Stop,jint Speed);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_PTZPreset(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint Command,jint Index);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_PTZCruise(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint Command,jint Route,jint Point,jint Input);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_PTZTrack(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint Command);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_PTZSet3D(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint PosX,jint PosY,jint Scale);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_PTZTrans(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jbyteArray Array,jint Size);
JNIEXPORT jstring JNICALL Java_com_Activity_PTZControl_GetPTZCruise(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint CruiseRoute);
JNIEXPORT jboolean JNICALL Java_com_Activity_PTZControl_SetVideoEffect(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jint Bright,jint Contrast,jint Saturation,jint Hue);
JNIEXPORT jstring JNICALL Java_com_Activity_PTZControl_GetVideoEffect(JNIEnv* env,jobject thiz,jint UserId,jint Channel);

//!Query Remote File
JNIEXPORT jboolean JNICALL Java_com_Activity_QueryRemoteFile_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_QueryRemoteFile_Cleanup(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_QueryRemoteFile_Login(JNIEnv* env,jobject thiz,jstring HostIPString,jint CtrlPort,jstring UserNameString,jstring PasswordString);
JNIEXPORT jboolean JNICALL Java_com_Activity_QueryRemoteFile_Logout(JNIEnv* env,jobject thiz,jint UserId);
JNIEXPORT jint JNICALL Java_com_Activity_QueryRemoteFile_GetLastError(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_QueryRemoteFile_Start(JNIEnv* env,jobject thiz,jint UserId,jstring FindCondString);
JNIEXPORT jstring JNICALL Java_com_Activity_QueryRemoteFile_GetFile(JNIEnv* env,jobject thiz,jint FindFileId);
JNIEXPORT jboolean JNICALL Java_com_Activity_QueryRemoteFile_Stop(JNIEnv* env,jobject thiz,jint FindFileId);
//!Added by ItmanLee at 2014-04-15 for Query File Record On Month
JNIEXPORT jint JNICALL Java_com_Activity_QueryRemoteFile_FindFile4Monthly(JNIEnv* env,jobject thiz,jint UserId,jint StartYear, jint StartMonth,jint DayNumOfMonth) ; 

//!History Stream
JNIEXPORT jboolean JNICALL Java_com_Activity_HistoryStream_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_HistoryStream_Cleanup(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_HistoryStream_Login(JNIEnv* env,jobject thiz,jstring HostIPString,jint CtrlPort,jstring UserNameString,jstring PasswordString);
JNIEXPORT jboolean JNICALL Java_com_Activity_HistoryStream_Logout(JNIEnv* env,jobject thiz,jint UserId);
JNIEXPORT jint JNICALL Java_com_Activity_HistoryStream_GetLastError(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_HistoryStream_Start(JNIEnv* env,jobject thiz,jint UserId,jint Channel,jstring BeginTime,jstring EndTime);//!BeginTime YYYYMMDDHHMMSS EndTime YYYYMMDDHHMMSS
JNIEXPORT jboolean JNICALL Java_com_Activity_HistoryStream_Stop(JNIEnv* env,jobject thiz,jint PlayHandle);
JNIEXPORT jint JNICALL Java_com_Activity_HistoryStream_Control(JNIEnv* env,jobject thiz,jint PlayHandleId,jint ControlCode, jint Param);
/*
{	
	"SetTime":[{
		"Year":2014,
		"Month":05,
		"Day":13,
		"Hour":17,
		"Minute":29,
		"Second":0,}]
}
*/
JNIEXPORT jboolean JNICALL Java_com_Activity_HistoryStream_SetTime(JNIEnv* env,jobject thiz,jint PlayHandleId,jstring Param);
/*
{	
	"CurTime":[{
		"Year":2014,
		"Month":05,
		"Day":13,
		"Hour":17,
		"Minute":29,
		"Second":0,}]
}
*/
JNIEXPORT jstring JNICALL Java_com_Activity_HistoryStream_GetTime(JNIEnv* env,jobject thiz,jint PlayHandleId);

#ifdef __cplusplus
}
#endif

#endif 

