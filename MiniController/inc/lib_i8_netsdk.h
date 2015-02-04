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
*	ע:V2 ��ʾ���36·DVR/NVR���������ݽṹ
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

//!�궨��
#define ANTS_ANDROID_MAX_NAMELEN			    		16			//!DVR���ص�½��
#define ANTS_ANDROID_MAX_RIGHT			    			32			//!�豸֧�ֵ�Ȩ�ޣ�1-12��ʾ����Ȩ�ޣ�13-32��ʾԶ��Ȩ�ޣ�
#define ANTS_ANDROID_NAME_LEN			    			32      	//!�û�������
#define ANTS_ANDROID_PASSWD_LEN			    			16      	//!���볤��
#define ANTS_ANDROID_SERIALNO_LEN		    			48      	//!���кų���
#define ANTS_ANDROID_MACADDR_LEN			    		6       	//!mac��ַ����
#define ANTS_ANDROID_MAX_ETHERNET		    			2       	//!�豸������̫����
#define ANTS_ANDROID_MAX_NETWORK_CARD        			4       	//!�豸�������������Ŀ
#define ANTS_ANDROID_PATHNAME_LEN		    			128    		//!·������

#define ANTS_ANDROID_MAX_TIMESEGMENT	    			8       	//!�豸���ʱ�����

#define ANTS_ANDROID_MAX_SHELTERNUM						4       	//!�豸����ڵ�������
#define ANTS_ANDROID_MAX_DAYS							7       	//!ÿ������
#define ANTS_ANDROID_PHONENUMBER_LEN					32      	//!pppoe���ź�����󳤶�

#define ANTS_ANDROID_MAX_DISKNUM						8			//!�豸���Ӳ����/* ���33��Ӳ��(����16������SATAӲ�̡�1��eSATAӲ�̺�16��NFS��) */
#define ANTS_ANDROID_MAX_DISKNUM_V2						24

#define ANTS_ANDROID_MAX_WINDOW							32      	//!�豸������ʾ��󲥷Ŵ�����
#define ANTS_ANDROID_MAX_VGA							4       	//!�豸���ɽ�VGA��

#define ANTS_ANDROID_MAX_USERNUM						8      		//!�豸����û���
#define ANTS_ANDROID_MAX_EXCEPTIONNUM					32      	//!�豸����쳣������
#define ANTS_ANDROID_MAX_LINK							6       	//!�豸��ͨ�������Ƶ��������
#define ANTS_ANDROID_MAX_NETDECNUM						32
#define ANTS_ANDROID_MAX_NETDECNUM_V2					64

#define ANTS_ANDROID_MAX_DECPOOLNUM						4       	//!��·������ÿ������ͨ������ѭ��������
#define ANTS_ANDROID_MAX_DECNUM							4       	//!��·��������������ͨ������ʵ��ֻ��һ������������������
#define ANTS_ANDROID_MAX_TRANSPARENTNUM					2       	//!��·���������������͸��ͨ����
#define ANTS_ANDROID_MAX_CYCLE_CHAN      				64      	//!��·�����������ѭͨ����
#define ANTS_ANDROID_MAX_DIRNAME_LENGTH					80      	//!���Ŀ¼����
#define ANTS_ANDROID_MAX_WINDOWS						16      	//!��󴰿���

#define ANTS_ANDROID_MAX_STRINGNUM						1			//!�豸���OSD�ַ�������
#define ANTS_ANDROID_MAX_AUXOUT							16      	//!�豸����������
#define ANTS_ANDROID_MAX_HD_GROUP						16      	//!�豸���Ӳ������
#define ANTS_ANDROID_MAX_NFS_DISK						8      		//!�豸���NFSӲ����

#define ANTS_ANDROID_IW_ESSID_MAX_SIZE	    			32	      	//!WIFI��SSID�ų���
#define ANTS_ANDROID_IW_ENCODING_TOKEN_MAX				32     		//!WIFI��������ֽ���
#define ANTS_ANDROID_MAX_SERIAL_NUM						64	    	//!���֧�ֵ�͸��ͨ��·��
#define ANTS_ANDROID_MAX_DDNS_NUMS	        			10      	//!�豸������ddns��
#define ANTS_ANDROID_MAX_DOMAIN_NAME		    		64			//!����������� 
#define ANTS_ANDROID_MAX_EMAIL_ADDR_LEN	    			48      	//!���email��ַ����
#define ANTS_ANDROID_MAX_EMAIL_PWD_LEN					32      	//!���email���볤��

#define ANTS_ANDROID_MAXPROGRESS		        		100     	//!�ط�ʱ�����ٷ���
#define ANTS_ANDROID_MAX_SERIALNUM	        			2       	//!�豸֧�ֵĴ����� 1-232�� 2-485
#define ANTS_ANDROID_CARDNUM_LEN		        		20      	//!���ų���
#define ANTS_ANDROID_MAX_VIDEOOUT		        		4	       	//!�豸����Ƶ�����

#define ANTS_ANDROID_MAX_PRESET							256			//!�豸֧�ֵ���̨Ԥ�õ��� 
#define ANTS_ANDROID_MAX_TRACK							256			//!�豸֧�ֵ���̨�켣�� 
#define ANTS_ANDROID_MAX_CRUISE							256			//!�豸֧�ֵ���̨Ѳ���� 

#define ANTS_ANDROID_CRUISE_MAX_PRESET_NUMS				32 	    	//!һ��Ѳ������Ѳ���� 

#define ANTS_ANDROID_MAX_SERIAL_PORT             		8       	//!�豸֧��232������
#define ANTS_ANDROID_MAX_PREVIEW_MODE            		8       	//!�豸֧�����Ԥ��ģʽ��Ŀ 1����,4����,9����,16����.... 
#define ANTS_ANDROID_MAX_MATRIXOUT               		16      	//!���ģ������������ 
#define ANTS_ANDROID_LOG_INFO_LEN                		11840   	//!��־������Ϣ 
#define ANTS_ANDROID_DESC_LEN                    		16      	//!��̨�����ַ������� 
#define ANTS_ANDROID_DESC_LEN_32	           			32			//!�����ֳ���
#define ANTS_ANDROID_PTZ_PROTOCOL_NUM            		200     	//!���֧�ֵ���̨Э���� 
#define ANTS_ANDROID_MAX_NODE_NUM         				256			//!�ڵ����
#define ANTS_ANDROID_MAX_AUDIO							2      		//!�����Խ�ͨ����
#define ANTS_ANDROID_MAX_CHANNUM			        	16      	//!�豸���ͨ����
#define ANTS_ANDROID_MAX_CHANNUM_V2						64			//!36·DVR
#define ANTS_ANDROID_MAX_ALARMIN			        	16      	//!�豸��󱨾�������
#define ANTS_ANDROID_MAX_ALARMIN_V2						64			//!36·DVR
#define ANTS_ANDROID_MAX_ALARMOUT		        		4      		//!�豸��󱨾������

#define ANTS_ANDROID_MAX_ANALOG_CHANNUM          		32      	//!���32��ģ��ͨ��
#define ANTS_ANDROID_MAX_ANALOG_ALARMOUT         		32      	//!���32·ģ�ⱨ����� 
#define ANTS_ANDROID_MAX_ANALOG_ALARMIN          		32      	//!���32·ģ�ⱨ������

#define ANTS_ANDROID_MAX_IP_DEVICE               		32      	//!�����������IP�豸��
#define ANTS_ANDROID_MAX_IP_CHANNEL              		32      	//!�����������IPͨ����
#define ANTS_ANDROID_MAX_IP_ALARMIN              		128     	//!����������౨��������
#define ANTS_ANDROID_MAX_IP_ALARMOUT             		64      	//!����������౨�������

#define ANTS_ANDROID_MAX_RECORD_FILE_NUM         		20      	//!ÿ��ɾ�����߿�¼������ļ���

#define ANTS_ANDROID_MAX_ACTION_TYPE	        				12	    	//!�Զ���Э����ӽ�����Ϊ�����Ϊ���� 
#define ANTS_ANDROID_MAX_ATM_PROTOCOL_NUM    					256  		//!ÿ�����뷽ʽ��Ӧ��ATM���Э����
#define ANTS_ANDROID_ATM_CUSTOM_PROTO       					1025   		//!�Զ���Э�� ֵΪ1025
#define ANTS_ANDROID_ATM_PROTOCOL_SORT       					4      		//!ATMЭ����� 
#define ANTS_ANDROID_ATM_DESC_LEN            					32      	//!ATM�����ַ�������

#define ANTS_ANDROID_MAX_LANERECT_NUM        					5    		//!�����ʶ��������
#define ANTS_ANDROID_MAX_FORTIFY_NUM     						10	   		//!��󲼷�����
#define ANTS_ANDROID_MAX_INTERVAL_NUM    						4    		//!���ʱ��������
#define ANTS_ANDROID_MAX_CHJC_NUM        						3    		//!�����ʡ�ݼ���ַ�����
#define ANTS_ANDROID_MAX_VL_NUM          						5    		//!���������Ȧ����

#define ANTS_ANDROID_MAX_MANAGERHOST_NUM						2

//!ȫ�ִ����� 
#define ANTS_ANDROID_NET_DVR_NOERROR 											0	//!û�д���
#define ANTS_ANDROID_NET_DVR_PASSWORD_ERROR 									1	//!�û����������
#define ANTS_ANDROID_NET_DVR_NOENOUGHPRI 										2	//!Ȩ�޲���
#define ANTS_ANDROID_NET_DVR_NOINIT 											3	//!û�г�ʼ��
#define ANTS_ANDROID_NET_DVR_CHANNEL_ERROR 										4	//!ͨ���Ŵ���
#define ANTS_ANDROID_NET_DVR_OVER_MAXLINK 										5	//!���ӵ�DVR�Ŀͻ��˸����������
#define ANTS_ANDROID_NET_DVR_VERSIONNOMATCH										6	//!�汾��ƥ��
#define ANTS_ANDROID_NET_DVR_NETWORK_FAIL_CONNECT								7	//!���ӷ�����ʧ��
#define ANTS_ANDROID_NET_DVR_NETWORK_SEND_ERROR									8	//!�����������ʧ��
#define ANTS_ANDROID_NET_DVR_NETWORK_RECV_ERROR									9	//!�ӷ�������������ʧ��
#define ANTS_ANDROID_NET_DVR_NETWORK_RECV_TIMEOUT								10	//!�ӷ������������ݳ�ʱ
#define ANTS_ANDROID_NET_DVR_NETWORK_ERRORDATA									11	//!���͵���������
#define ANTS_ANDROID_NET_DVR_ORDER_ERROR										12	//!���ô������
#define ANTS_ANDROID_NET_DVR_OPERNOPERMIT										13	//!�޴�Ȩ��
#define ANTS_ANDROID_NET_DVR_COMMANDTIMEOUT										14	//!DVR����ִ�г�ʱ
#define ANTS_ANDROID_NET_DVR_ERRORSERIALPORT									15	//!���ںŴ���
#define ANTS_ANDROID_NET_DVR_ERRORALARMPORT										16	//!�����˿ڴ���
#define ANTS_ANDROID_NET_DVR_PARAMETER_ERROR 									17  //!��������
#define ANTS_ANDROID_NET_DVR_CHAN_EXCEPTION										18	//!������ͨ�����ڴ���״̬
#define ANTS_ANDROID_NET_DVR_NODISK												19	//!û��Ӳ��
#define ANTS_ANDROID_NET_DVR_ERRORDISKNUM										20	//!Ӳ�̺Ŵ���
#define ANTS_ANDROID_NET_DVR_DISK_FULL											21	//!������Ӳ����
#define ANTS_ANDROID_NET_DVR_DISK_ERROR											22	//!������Ӳ�̳���
#define ANTS_ANDROID_NET_DVR_NOSUPPORT											23	//!��������֧��
#define ANTS_ANDROID_NET_DVR_BUSY												24	//!������æ
#define ANTS_ANDROID_NET_DVR_MODIFY_FAIL										25	//!�������޸Ĳ��ɹ�
#define ANTS_ANDROID_NET_DVR_PASSWORD_FORMAT_ERROR								26	//!���������ʽ����ȷ
#define ANTS_ANDROID_NET_DVR_DISK_FORMATING										27	//!Ӳ�����ڸ�ʽ����������������
#define ANTS_ANDROID_NET_DVR_DVRNORESOURCE										28	//!DVR��Դ����
#define ANTS_ANDROID_NET_DVR_DVROPRATEFAILED									29  //!DVR����ʧ��
#define ANTS_ANDROID_NET_DVR_OPENHOSTSOUND_FAIL 								30  //!��PC����ʧ��
#define ANTS_ANDROID_NET_DVR_DVRVOICEOPENED 									31  //!�����������Խ���ռ��
#define ANTS_ANDROID_NET_DVR_TIMEINPUTERROR										32  //!ʱ�����벻��ȷ
#define ANTS_ANDROID_NET_DVR_NOSPECFILE											33  //!�ط�ʱ������û��ָ�����ļ�
#define ANTS_ANDROID_NET_DVR_CREATEFILE_ERROR									34	//!�����ļ�����
#define ANTS_ANDROID_NET_DVR_FILEOPENFAIL										35  //!���ļ�����
#define ANTS_ANDROID_NET_DVR_OPERNOTFINISH										36  //!�ϴεĲ�����û�����
#define ANTS_ANDROID_NET_DVR_GETPLAYTIMEFAIL									37  //!��ȡ��ǰ���ŵ�ʱ�����
#define ANTS_ANDROID_NET_DVR_PLAYFAIL											38  //!���ų���
#define ANTS_ANDROID_NET_DVR_FILEFORMAT_ERROR									39  //!�ļ���ʽ����ȷ
#define ANTS_ANDROID_NET_DVR_DIR_ERROR											40	//!·������
#define ANTS_ANDROID_NET_DVR_ALLOC_RESOURCE_ERROR								41  //!��Դ�������
#define ANTS_ANDROID_NET_DVR_AUDIO_MODE_ERROR									42	//!����ģʽ����
#define ANTS_ANDROID_NET_DVR_NOENOUGH_BUF										43	//!������̫С
#define ANTS_ANDROID_NET_DVR_CREATESOCKET_ERROR									44	//!����SOCKET����
#define ANTS_ANDROID_NET_DVR_SETSOCKET_ERROR									45	//!����SOCKET����
#define ANTS_ANDROID_NET_DVR_MAX_NUM											46	//!�����ﵽ���
#define ANTS_ANDROID_NET_DVR_USERNOTEXIST										47	//!�û�������
#define ANTS_ANDROID_NET_DVR_WRITEFLASHERROR									48  //!дFLASH����
#define ANTS_ANDROID_NET_DVR_UPGRADEFAIL										49  //!DVR����ʧ��
#define ANTS_ANDROID_NET_DVR_CARDHAVEINIT										50  //!���뿨�Ѿ���ʼ����
#define ANTS_ANDROID_NET_DVR_PLAYERFAILED										51	//!���ò��ſ���ĳ������ʧ��
#define ANTS_ANDROID_NET_DVR_MAX_USERNUM										52  //!�豸���û����ﵽ���
#define ANTS_ANDROID_NET_DVR_GETLOCALIPANDMACFAIL								53  //!��ÿͻ��˵�IP��ַ�������ַʧ��
#define ANTS_ANDROID_NET_DVR_NOENCODEING										54	//!��ͨ��û�б���
#define ANTS_ANDROID_NET_DVR_IPMISMATCH											55	//!IP��ַ��ƥ��
#define ANTS_ANDROID_NET_DVR_MACMISMATCH										56	//!MAC��ַ��ƥ��
#define ANTS_ANDROID_NET_DVR_UPGRADELANGMISMATCH								57	//!�����ļ����Բ�ƥ��
#define ANTS_ANDROID_NET_DVR_MAX_PLAYERPORT										58	//!������·���ﵽ���
#define ANTS_ANDROID_NET_DVR_NOSPACEBACKUP										59	//!�����豸��û���㹻�ռ���б���
#define ANTS_ANDROID_NET_DVR_NODEVICEBACKUP										60	//!û���ҵ�ָ���ı����豸
#define ANTS_ANDROID_NET_DVR_PICTURE_BITS_ERROR									61	//!ͼ����λ����������24ɫ
#define ANTS_ANDROID_NET_DVR_PICTURE_DIMENSION_ERROR							62	//!ͼƬ��*���ޣ� ��128*256
#define ANTS_ANDROID_NET_DVR_PICTURE_SIZ_ERROR									63	//!ͼƬ��С���ޣ���100K
#define ANTS_ANDROID_NET_DVR_LOADPLAYERSDKFAILED								64	//!���뵱ǰĿ¼��Player Sdk����
#define ANTS_ANDROID_NET_DVR_LOADPLAYERSDKPROC_ERROR							65	//!�Ҳ���Player Sdk��ĳ���������
#define ANTS_ANDROID_NET_DVR_LOADDSSDKFAILED									66	//!���뵱ǰĿ¼��DSsdk����
#define ANTS_ANDROID_NET_DVR_LOADDSSDKPROC_ERROR								67	//!�Ҳ���DsSdk��ĳ���������
#define ANTS_ANDROID_NET_DVR_DSSDK_ERROR										68	//!����Ӳ�����DsSdk��ĳ������ʧ��
#define ANTS_ANDROID_NET_DVR_VOICEMONOPOLIZE									69	//!��������ռ
#define ANTS_ANDROID_NET_DVR_JOINMULTICASTFAILED								70	//!����ಥ��ʧ��
#define ANTS_ANDROID_NET_DVR_CREATEDIR_ERROR									71	//!������־�ļ�Ŀ¼ʧ��
#define ANTS_ANDROID_NET_DVR_BINDSOCKET_ERROR									72	//!���׽���ʧ��
#define ANTS_ANDROID_NET_DVR_SOCKETCLOSE_ERROR									73	//!socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ�
#define ANTS_ANDROID_NET_DVR_USERID_ISUSING										74	//!ע��ʱ�û�ID���ڽ���ĳ����
#define ANTS_ANDROID_NET_DVR_SOCKETLISTEN_ERROR									75	//!����ʧ��
#define ANTS_ANDROID_NET_DVR_PROGRAM_EXCEPTION									76	//!�����쳣
#define ANTS_ANDROID_NET_DVR_WRITEFILE_FAILED									77	//!д�ļ�ʧ��
#define ANTS_ANDROID_NET_DVR_FORMAT_READONLY									78  //!��ֹ��ʽ��ֻ��Ӳ��
#define ANTS_ANDROID_NET_DVR_WITHSAMEUSERNAME									79  //!�û����ýṹ�д�����ͬ���û���
#define ANTS_ANDROID_NET_DVR_DEVICETYPE_ERROR            						80  //!�������ʱ�豸�ͺŲ�ƥ��
#define ANTS_ANDROID_NET_DVR_LANGUAGE_ERROR              						81  //!�������ʱ���Բ�ƥ��
#define ANTS_ANDROID_NET_DVR_PARAVERSION_ERROR           						82  //!�������ʱ����汾��ƥ��
#define ANTS_ANDROID_NET_DVR_IPCHAN_NOTALIVE             						83  //!Ԥ��ʱ���IPͨ��������
#define ANTS_ANDROID_NET_DVR_RTSP_SDK_ERROR										84	//!���ظ���IPCͨѶ��StreamTransClient.dllʧ��
#define ANTS_ANDROID_NET_DVR_CONVERT_SDK_ERROR									85	//!����ת���ʧ��
#define ANTS_ANDROID_NET_DVR_IPC_COUNT_OVERFLOW									86  //!��������ip����ͨ����
#define ANTS_ANDROID_NET_DVR_PARAMMODE_ERROR             						88 	//!ͼ����ǿ�ǣ�����ģʽ��������Ӳ������ʱ���ͻ��˽����������ʱ����ֵ��
#define ANTS_ANDROID_NET_DVR_CODESPITTER_OFFLINE								89 	//!��Ƶ�ۺ�ƽ̨�������������
#define ANTS_ANDROID_NET_DVR_BACKUP_COPYING										90  //!�豸���ڱ���
#define ANTS_ANDROID_NET_DVR_CHAN_NOTSUPPORT             						91 	//!ͨ����֧�ָò���
#define ANTS_ANDROID_NET_DVR_CALLINEINVALID              						92  //!�߶���λ��̫���л򳤶��߲�����б 
#define ANTS_ANDROID_NET_DVR_CALCANCELCONFLICT           						93  //!ȡ���궨��ͻ����������˹���ȫ�ֵ�ʵ�ʴ�С�ߴ����
#define ANTS_ANDROID_NET_DVR_CALPOINTOUTRANGE            						94 	//!�궨�㳬����Χ 
#define ANTS_ANDROID_NET_DVR_FILTERRECTINVALID            						95  //!�ߴ������������Ҫ��
#define ANTS_ANDROID_NET_DVR_CREATEXMLFILE_ERROR 	   							96
#define ANTS_ANDROID_NET_DVR_ACCEPTXMLFILE_ERROR    							97

//! ���д�����
#define ANTS_ANDROID_RAID_ERROR_INDEX								200
#define ANTS_ANDROID_NET_DVR_NAME_NOT_ONLY               			(ANTS_RAID_ERROR_INDEX + 0)  //! �û�����Ψһ
#define ANTS_ANDROID_NET_DVR_OVER_MAX_ARRAY              			(ANTS_RAID_ERROR_INDEX + 1 ) //! ���дﵽ����
#define ANTS_ANDROID_NET_DVR_OVER_MAX_VD                 			(ANTS_RAID_ERROR_INDEX + 2 ) //! ������̴ﵽ����
#define ANTS_ANDROID_NET_DVR_VD_SLOT_EXCEED              			(ANTS_RAID_ERROR_INDEX + 3 ) //! ����Ӳ�̲�λ����
#define ANTS_ANDROID_NET_DVR_PD_STATUS_INVALID           			(ANTS_RAID_ERROR_INDEX + 4 ) //! �ؽ�������������Ӳ��״̬����
#define ANTS_ANDROID_NET_DVR_PD_BE_DEDICATE_SPARE        			(ANTS_RAID_ERROR_INDEX + 5 ) //! �ؽ�������������Ӳ��Ϊָ���ȱ�
#define ANTS_ANDROID_NET_DVR_PD_NOT_FREE                 			(ANTS_RAID_ERROR_INDEX + 6 ) //! �ؽ�������������Ӳ�̷ǿ���
#define ANTS_ANDROID_NET_DVR_CANNOT_MIG2NEWMODE          			(ANTS_RAID_ERROR_INDEX + 7 ) //! ���ܴӵ�ǰ��raid����Ǩ�Ƶ��µ�RAid����
#define ANTS_ANDROID_NET_DVR_MIG_PAUSE                   			(ANTS_RAID_ERROR_INDEX + 8 ) //! Ǩ�Ʋ�������ͣ
#define ANTS_ANDROID_NET_DVR_MIG_ABOUTED                 			(ANTS_RAID_ERROR_INDEX + 9 ) //! Ǩ�Ʋ�����ȡ��
#define ANTS_ANDROID_NET_DVR_EXIST_VD                    			(ANTS_RAID_ERROR_INDEX + 10) //! �����������ϴ���������̣��޷�ɾ������
#define ANTS_ANDROID_NET_DVR_TARGET_IN_LD_FUNCTIONAL     			(ANTS_RAID_ERROR_INDEX + 11) //! Target physical disk is part of the virtual disk and is functional
#define ANTS_ANDROID_NET_DVR_HD_IS_ASSIGNED_ALREADY      			(ANTS_RAID_ERROR_INDEX + 12) //! Specified physical disk is assigned to a virtual disk
#define ANTS_ANDROID_NET_DVR_INVALID_HD_COUNT            			(ANTS_RAID_ERROR_INDEX + 13) //! Number of physical disks doesn't fit the specified RAID level
#define ANTS_ANDROID_NET_DVR_LD_IS_FUNCTIONAL            			(ANTS_RAID_ERROR_INDEX + 14) //! Specified virtual disk is functional���������������ؽ�
#define ANTS_ANDROID_NET_DVR_BGA_RUNNING                 			(ANTS_RAID_ERROR_INDEX + 15) //! BGA is running
#define ANTS_ANDROID_NET_DVR_LD_NO_ATAPI                	 		(ANTS_RAID_ERROR_INDEX + 16) //! Can not create virtual disk with ATAPI drive
#define ANTS_ANDROID_NET_DVR_MIGRATION_NOT_NEED          			(ANTS_RAID_ERROR_INDEX + 17) //! Migration is not necessary
#define ANTS_ANDROID_NET_DVR_HD_TYPE_MISMATCH            			(ANTS_RAID_ERROR_INDEX + 18) //! Physical disks are not of the same type
#define ANTS_ANDROID_NET_DVR_NO_LD_IN_DG                 			(ANTS_RAID_ERROR_INDEX + 19) //! No virtual disk exist on the specified array
#define ANTS_ANDROID_NET_DVR_NO_ROOM_FOR_SPARE           			(ANTS_RAID_ERROR_INDEX + 20) //! Disk space is too small to be assigned as spare drive
#define ANTS_ANDROID_NET_DVR_SPARE_IS_IN_MULTI_DG        			(ANTS_RAID_ERROR_INDEX + 21) //! Disk is already assigned as a spare drive for an array
#define ANTS_ANDROID_NET_DVR_DG_HAS_MISSING_PD           			(ANTS_RAID_ERROR_INDEX + 22) //! Disk is missing from an array

//!���Ŵ�����
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
ANTS_NET_DVR_IsSupport()����ֵ
1��9λ�ֱ��ʾ������Ϣ��λ����TRUE)��ʾ֧��
**************************************************/
#define ANTS_ANDROID_NET_DVR_SUPPORT_DDRAW									0x01//!֧��DIRECTDRAW�������֧�֣��򲥷������ܹ�����
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLT									0x02//!�Կ�֧��BLT�����������֧�֣��򲥷������ܹ�����
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTFOURCC								0x04//!�Կ�BLT֧����ɫת���������֧�֣��������������������RGBת����
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTSHRINKX								0x08//!�Կ�BLT֧��X����С�������֧�֣�ϵͳ�����������ת����
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTSHRINKY								0x10//!�Կ�BLT֧��Y����С�������֧�֣�ϵͳ�����������ת����
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTSTRETCHX							0x20//!�Կ�BLT֧��X��Ŵ������֧�֣�ϵͳ�����������ת����
#define ANTS_ANDROID_NET_DVR_SUPPORT_BLTSTRETCHY							0x40//!�Կ�BLT֧��Y��Ŵ������֧�֣�ϵͳ�����������ת����
#define ANTS_ANDROID_NET_DVR_SUPPORT_SSE									0x80//!CPU֧��SSEָ�Intel Pentium3����֧��SSEָ�
#define ANTS_ANDROID_NET_DVR_SUPPORT_MMX									0x100//!CPU֧��MMXָ���Intel Pentium3����֧��SSEָ�

//!��̨�������� 	
#define ANTS_ANDROID_LIGHT_PWRON															2	//! ��ͨ�ƹ��Դ 
#define ANTS_ANDROID_WIPER_PWRON															3	//! ��ͨ��ˢ���� 
#define ANTS_ANDROID_FAN_PWRON																4	//! ��ͨ���ȿ��� 
#define ANTS_ANDROID_HEATER_PWRON															5	//! ��ͨ���������� 
#define ANTS_ANDROID_AUX_PWRON1																6	//! ��ͨ�����豸���� 
#define ANTS_ANDROID_AUX_PWRON2																7	//! ��ͨ�����豸���� 
#define ANTS_ANDROID_SET_PRESET																8	//! ����Ԥ�õ� 
#define ANTS_ANDROID_CLE_PRESET																9	//! ���Ԥ�õ� 

#define ANTS_ANDROID_ZOOM_IN																11	//! �������ٶ�SS���(���ʱ��) 
#define ANTS_ANDROID_ZOOM_OUT																12	//! �������ٶ�SS��С(���ʱ�С) 
#define ANTS_ANDROID_FOCUS_NEAR      														13  //! �������ٶ�SSǰ�� 
#define ANTS_ANDROID_FOCUS_FAR       														14  //! �������ٶ�SS��� 
#define ANTS_ANDROID_IRIS_OPEN       														15  //! ��Ȧ���ٶ�SS���� 
#define ANTS_ANDROID_IRIS_CLOSE      														16  //! ��Ȧ���ٶ�SS��С 

#define ANTS_ANDROID_TILT_UP																21	//! ��̨��SS���ٶ����� 
#define ANTS_ANDROID_TILT_DOWN																22	//! ��̨��SS���ٶ��¸� 
#define ANTS_ANDROID_PAN_LEFT																23	//! ��̨��SS���ٶ���ת 
#define ANTS_ANDROID_PAN_RIGHT																24	//! ��̨��SS���ٶ���ת 
#define ANTS_ANDROID_UP_LEFT																25	//! ��̨��SS���ٶ���������ת 
#define ANTS_ANDROID_UP_RIGHT																26	//! ��̨��SS���ٶ���������ת 
#define ANTS_ANDROID_DOWN_LEFT																27	//! ��̨��SS���ٶ��¸�����ת 
#define ANTS_ANDROID_DOWN_RIGHT																28	//! ��̨��SS���ٶ��¸�����ת 
#define ANTS_ANDROID_PAN_AUTO																29	//! ��̨��SS���ٶ������Զ�ɨ�� 

#define ANTS_ANDROID_FILL_PRE_SEQ															30	//! ��Ԥ�õ����Ѳ������ 
#define ANTS_ANDROID_SET_SEQ_DWELL															31	//! ����Ѳ����ͣ��ʱ�� 
#define ANTS_ANDROID_SET_SEQ_SPEED															32	//! ����Ѳ���ٶ� 
#define ANTS_ANDROID_CLE_PRE_SEQ															33	//! ��Ԥ�õ��Ѳ��������ɾ�� 
#define ANTS_ANDROID_STA_MEM_CRUISE															34	//! ��ʼ��¼�켣 
#define ANTS_ANDROID_STO_MEM_CRUISE															35	//! ֹͣ��¼�켣 
#define ANTS_ANDROID_RUN_CRUISE																36	//! ��ʼ�켣 
#define ANTS_ANDROID_RUN_SEQ																37	//! ��ʼѲ�� 
#define ANTS_ANDROID_STOP_SEQ																38	//! ֹͣѲ�� 
#define ANTS_ANDROID_GOTO_PRESET															39	//! ����ת��Ԥ�õ� 
#define ANTS_ANDROID_FILL_SEQ_CRUISE														40	//! ��Ѳ���������õ���̨�� 
/*************************************************
�ط�ʱ���ſ�������궨�� 
ANTS_ANDROID_NET_DVR_PlayBackControl
ANTS_ANDROID_NET_DVR_PlayControlLocDisplay
ANTS_ANDROID_NET_DVR_DecPlayBackCtrl�ĺ궨��
����֧�ֲ鿴����˵���ʹ���
**************************************************/	
#define ANTS_ANDROID_NET_DVR_PLAYSTART													1	//!��ʼ����
#define ANTS_ANDROID_NET_DVR_PLAYSTOP													2	//!ֹͣ����
#define ANTS_ANDROID_NET_DVR_PLAYPAUSE													3	//!��ͣ����
#define ANTS_ANDROID_NET_DVR_PLAYRESTART												4	//!�ָ�����
#define ANTS_ANDROID_NET_DVR_PLAYFAST													5	//!���
#define ANTS_ANDROID_NET_DVR_PLAYSLOW													6	//!����
#define ANTS_ANDROID_NET_DVR_PLAYNORMAL													7	//!�����ٶ�
#define ANTS_ANDROID_NET_DVR_PLAYFRAME													8	//!��֡��
#define ANTS_ANDROID_NET_DVR_PLAYSTARTAUDIO												9	//!������
#define ANTS_ANDROID_NET_DVR_PLAYSTOPAUDIO												10	//!�ر�����
#define ANTS_ANDROID_NET_DVR_PLAYAUDIOVOLUME											11	//!��������
#define ANTS_ANDROID_NET_DVR_PLAYSETPOS													12	//!�ı��ļ��طŵĽ���
#define ANTS_ANDROID_NET_DVR_PLAYGETPOS													13	//!��ȡ�ļ��طŵĽ���
#define ANTS_ANDROID_NET_DVR_PLAYGETTIME												14	//!��ȡ��ǰ�Ѿ����ŵ�ʱ��(���ļ��طŵ�ʱ����Ч)
#define ANTS_ANDROID_NET_DVR_PLAYGETFRAME												15	//!��ȡ��ǰ�Ѿ����ŵ�֡��(���ļ��طŵ�ʱ����Ч)
#define ANTS_ANDROID_NET_DVR_GETTOTALFRAMES  											16	//!��ȡ��ǰ�����ļ��ܵ�֡��(���ļ��طŵ�ʱ����Ч)
#define ANTS_ANDROID_NET_DVR_GETTOTALTIME    											17	//!��ȡ��ǰ�����ļ��ܵ�ʱ��(���ļ��طŵ�ʱ����Ч)
#define ANTS_ANDROID_NET_DVR_THROWBFRAME												20	//!��B֡
#define ANTS_ANDROID_NET_DVR_SETSPEED													24	//!���������ٶ�
#define ANTS_ANDROID_NET_DVR_KEEPALIVE													25	//!�������豸������(����ص�����������2�뷢��һ��)
#define ANTS_ANDROID_NET_DVR_PLAYSETTIME												26	//!������ʱ�䶨λ
#define ANTS_ANDROID_NET_DVR_PLAYGETTOTALLEN											27	//!��ȡ��ʱ��طŶ�Ӧʱ����ڵ������ļ����ܳ���

//!Զ�̰����������£�
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

#define ANTS_ANDROID_KEY_PTZ_AP1_START						ANTS_ANDROID_KEY_CODE_EDIT /* ��Ȧ+ */
#define ANTS_ANDROID_KEY_PTZ_AP1_STOP 						36

#define ANTS_ANDROID_KEY_PTZ_AP2_START						ANTS_ANDROID_KEY_CODE_PAN /* ��Ȧ- */
#define ANTS_ANDROID_KEY_PTZ_AP2_STOP						37

#define ANTS_ANDROID_KEY_PTZ_FOCUS1_START 					ANTS_ANDROID_KEY_CODE_A /* �۽�+ */
#define ANTS_ANDROID_KEY_PTZ_FOCUS1_STOP 					38

#define ANTS_ANDROID_KEY_PTZ_FOCUS2_START 					ANTS_ANDROID_KEY_CODE_M /* �۽�- */
#define ANTS_ANDROID_KEY_PTZ_FOCUS2_STOP 					39

#define ANTS_ANDROID_KEY_PTZ_B1_START 						40 /* �䱶+ */
#define ANTS_ANDROID_KEY_PTZ_B1_STOP 						41

#define ANTS_ANDROID_KEY_PTZ_B2_START 						42 /* �䱶- */
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
#define ANTS_ANDROID_NET_DVR_GET_DEVICECFG									(ANTS_ANDROID_NET_DVR_GETCFG+1) 	//!��ȡ�豸����
#define ANTS_ANDROID_NET_DVR_GET_NETCFG										(ANTS_ANDROID_NET_DVR_GETCFG+2) 	//!��ȡ�������
#define ANTS_ANDROID_NET_DVR_GET_PICCFG										(ANTS_ANDROID_NET_DVR_GETCFG+3) 	//!��ȡͼ�����
#define ANTS_ANDROID_NET_DVR_GET_COMPRESSCFG								(ANTS_ANDROID_NET_DVR_GETCFG+4) 	//!��ȡѹ������
#define ANTS_ANDROID_NET_DVR_GET_RECORDCFG									(ANTS_ANDROID_NET_DVR_GETCFG+5) 	//!��ȡ¼��ʱ�����
#define ANTS_ANDROID_NET_DVR_GET_DECODERCFG									(ANTS_ANDROID_NET_DVR_GETCFG+6) 	//!��ȡ����������
#define ANTS_ANDROID_NET_DVR_GET_RS232CFG									(ANTS_ANDROID_NET_DVR_GETCFG+7) 	//!��ȡ232���ڲ���
#define ANTS_ANDROID_NET_DVR_GET_ALARMINCFG									(ANTS_ANDROID_NET_DVR_GETCFG+8) 	//!��ȡ�����������
#define ANTS_ANDROID_NET_DVR_GET_ALARMOUTCFG								(ANTS_ANDROID_NET_DVR_GETCFG+9) 	//!��ȡ�����������
#define ANTS_ANDROID_NET_DVR_GET_TIMECFG									(ANTS_ANDROID_NET_DVR_GETCFG+10)	//!��ȡDVRʱ��
#define ANTS_ANDROID_NET_DVR_GET_PREVIEWCFG									(ANTS_ANDROID_NET_DVR_GETCFG+11)	//!��ȡԤ������
#define ANTS_ANDROID_NET_DVR_GET_VIDEOOUTCFG								(ANTS_ANDROID_NET_DVR_GETCFG+12)	//!��ȡ��Ƶ�������
#define ANTS_ANDROID_NET_DVR_GET_USERCFG									(ANTS_ANDROID_NET_DVR_GETCFG+13)	//!��ȡ�û�����
#define ANTS_ANDROID_NET_DVR_GET_EXCEPTIONCFG								(ANTS_ANDROID_NET_DVR_GETCFG+14)	//!��ȡ�쳣����
#define ANTS_ANDROID_NET_DVR_GET_ZONEANDDST									(ANTS_ANDROID_NET_DVR_GETCFG+15)	//!��ȡʱ������ʱ�Ʋ���
#define ANTS_ANDROID_NET_DVR_GET_SHOWSTRING									(ANTS_ANDROID_NET_DVR_GETCFG+16)	//!��ȡ�����ַ�����
#define ANTS_ANDROID_NET_DVR_GET_EVENTCOMPCFG								(ANTS_ANDROID_NET_DVR_GETCFG+17)	//!��ȡ�¼�����¼�����
#define ANTS_ANDROID_NET_DVR_GET_FTPCFG										(ANTS_ANDROID_NET_DVR_GETCFG+18)	//!��ȡץͼ��FTP����(����)
#define ANTS_ANDROID_NET_DVR_GET_AUXOUTCFG									(ANTS_ANDROID_NET_DVR_GETCFG+19)	//!��ȡ�������������������(HS�豸�������)
#define ANTS_ANDROID_NET_DVR_GET_PREVIEWCFG_AUX								(ANTS_ANDROID_NET_DVR_GETCFG+20)	//!��ȡ-sϵ��˫���Ԥ������(-sϵ��˫���)
#define ANTS_ANDROID_NET_DVR_GET_RULECFG									(ANTS_ANDROID_NET_DVR_GETCFG+21)	//!��ȡ��Ϊ��������
#define ANTS_ANDROID_NET_DVR_GET_TRACK_CFG									(ANTS_ANDROID_NET_DVR_GETCFG+22)	//!��ȡ��������ò���
#define ANTS_ANDROID_NET_DVR_GET_IVMS_STREAMCFG								(ANTS_ANDROID_NET_DVR_GETCFG+23)	//!��ȡ���ܷ�����ȡ������
#define ANTS_ANDROID_NET_DVR_GET_VCA_CTRLCFG								(ANTS_ANDROID_NET_DVR_GETCFG+24)	//!��ȡ���ܿ��Ʋ���
#define ANTS_ANDROID_NET_DVR_GET_VCA_MASK_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+25)	//!��ȡ�����������
#define ANTS_ANDROID_NET_DVR_GET_VCA_ENTER_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+26)	//!��ȡ�����������
#define ANTS_ANDROID_NET_DVR_GET_VCA_LINE_SEGMENT							(ANTS_ANDROID_NET_DVR_GETCFG+27)	//!��ȡ�궨��
#define ANTS_ANDROID_NET_DVR_GET_IVMS_MASK_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+28)	//!��ȡIVMS�����������
#define ANTS_ANDROID_NET_DVR_GET_IVMS_ENTER_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+29)	//!��ȡIVMS�����������
#define ANTS_ANDROID_NET_DVR_GET_IVMS_BEHAVIORCFG							(ANTS_ANDROID_NET_DVR_GETCFG+30)	//!��ȡ���ܷ�������Ϊ�������
#define ANTS_ANDROID_NET_DVR_GET_IVMS_SEARCHCFG								(ANTS_ANDROID_NET_DVR_GETCFG+31)	//!��ȡIVMS�طż�������
#define ANTS_ANDROID_NET_DVR_GET_POSITION_TRACK								(ANTS_ANDROID_NET_DVR_GETCFG+32)	//!��ȡ��������������Ϣ
#define ANTS_ANDROID_NET_DVR_GET_CALIBRATION								(ANTS_ANDROID_NET_DVR_GETCFG+33)	//!��ȡ�궨��Ϣ
#define ANTS_ANDROID_NET_DVR_GET_PDC_RULECFG								(ANTS_ANDROID_NET_DVR_GETCFG+34)	//!��ȡ������ͳ�ƹ���
#define ANTS_ANDROID_NET_DVR_GET_PU_STREAMCFG								(ANTS_ANDROID_NET_DVR_GETCFG+35)	//!��ȡǰ��ȡ���豸��Ϣ
#define ANTS_ANDROID_NET_DVR_GET_DETECT_RULECFG								(ANTS_ANDROID_NET_DVR_GETCFG+36)	//!��ȡATM���������
#define ANTS_ANDROID_NET_DVR_GET_VCA_SIZE_FILTER							(ANTS_ANDROID_NET_DVR_GETCFG+37)	//!��ȡȫ�ֳߴ������
#define ANTS_ANDROID_NET_DVR_GET_TRACK_PARAMCFG								(ANTS_ANDROID_NET_DVR_GETCFG+38)	//!��ȡ������ز˵�����
#define ANTS_ANDROID_NET_DVR_GET_DOME_MOVEMENT_PARAM						(ANTS_ANDROID_NET_DVR_GETCFG+39)	//!��ȡ�����о����
#define ANTS_ANDROID_NET_DVR_GET_NETAPPCFG									(ANTS_ANDROID_NET_DVR_GETCFG+40)	//!��ȡ����Ӧ�ò��� NTP/DDNS/EMAIL
#define ANTS_ANDROID_NET_DVR_GET_NTPCFG										(ANTS_ANDROID_NET_DVR_GETCFG+41)	//!��ȡ����Ӧ�ò��� NTP
#define ANTS_ANDROID_NET_DVR_GET_DDNSCFG									(ANTS_ANDROID_NET_DVR_GETCFG+42)	//!��ȡ����Ӧ�ò��� DDNS
#define ANTS_ANDROID_NET_DVR_GET_EMAILCFG									(ANTS_ANDROID_NET_DVR_GETCFG+43)	//!��ȡ����Ӧ�ò��� EMAIL
#define ANTS_ANDROID_NET_DVR_GET_NFSCFG										(ANTS_ANDROID_NET_DVR_GETCFG+44)	//!NFS disk config
#define ANTS_ANDROID_NET_DVR_GET_NETCFG_OTHER								(ANTS_ANDROID_NET_DVR_GETCFG+45)	//!��ȡ�������
#define ANTS_ANDROID_NET_DVR_GET_EMAILPARACFG								(ANTS_ANDROID_NET_DVR_GETCFG+46)	//!Get EMAIL parameters
#define ANTS_ANDROID_NET_DVR_GET_PTZPOS										(ANTS_ANDROID_NET_DVR_GETCFG+47)	//!��̨��ȡPTZλ��
#define ANTS_ANDROID_NET_DVR_GET_PTZSCOPE									(ANTS_ANDROID_NET_DVR_GETCFG+48)	//!��̨��ȡPTZ��Χ
#define ANTS_ANDROID_NET_DVR_GET_REFERENCE_REGION							(ANTS_ANDROID_NET_DVR_GETCFG+49)	//!��ȡ�ο�����
#define ANTS_ANDROID_NET_DVR_GET_TARFFIC_MASK_REGION						(ANTS_ANDROID_NET_DVR_GETCFG+50)	//!��ȡ��ͨ�¼���������
#define ANTS_ANDROID_NET_DVR_GET_SCENE_MODE									(ANTS_ANDROID_NET_DVR_GETCFG+51)	//!��ȡ����ģʽ
#define ANTS_ANDROID_NET_DVR_GET_AID_RULECFG								(ANTS_ANDROID_NET_DVR_GETCFG+52)	//!��ȡ��ͨ�¼��������
#define ANTS_ANDROID_NET_DVR_GET_TPS_RULECFG								(ANTS_ANDROID_NET_DVR_GETCFG+53)	//!���ý�ͨͳ�ƹ������
#define ANTS_ANDROID_NET_DVR_GET_LANECFG									(ANTS_ANDROID_NET_DVR_GETCFG+54)	//!��ȡ��������
#define ANTS_ANDROID_NET_DVR_GET_PLATECFG									(ANTS_ANDROID_NET_DVR_GETCFG+55)	//!��ȡ����ʶ�����
#define ANTS_ANDROID_NET_DVR_GET_CRUISE										(ANTS_ANDROID_NET_DVR_GETCFG+56)	
#define ANTS_ANDROID_NET_DVR_GET_NET_DISKCFG								(ANTS_ANDROID_NET_DVR_GETCFG+57)	//!����Ӳ�̽����ȡ
#define ANTS_ANDROID_NET_DVR_GET_HDCFG										(ANTS_ANDROID_NET_DVR_GETCFG+58)	//!��ȡӲ�̹������ò���
#define ANTS_ANDROID_NET_DVR_GET_HDGROUP_CFG								(ANTS_ANDROID_NET_DVR_GETCFG+59)	//!��ȡ����������ò���
#define ANTS_ANDROID_NET_DVR_GET_COMPRESSCFG_AUD							(ANTS_ANDROID_NET_DVR_GETCFG+60)	//!��ȡ�豸�����Խ��������	
#define ANTS_ANDROID_NET_DVR_GET_IOINCFG									(ANTS_ANDROID_NET_DVR_GETCFG+61)	//!��ȡץ�Ļ�IO�������
#define ANTS_ANDROID_NET_DVR_GET_IOOUTCFG									(ANTS_ANDROID_NET_DVR_GETCFG+62)	//!��ȡץ�Ļ�IO�������
#define ANTS_ANDROID_NET_DVR_GET_FLASHCFG									(ANTS_ANDROID_NET_DVR_GETCFG+63)	//!��ȡIO������������
#define ANTS_ANDROID_NET_DVR_GET_LIGHTSNAPCFG								(ANTS_ANDROID_NET_DVR_GETCFG+64)	//!��ȡץ�Ļ����̵Ʋ���
#define ANTS_ANDROID_NET_DVR_GET_MEASURESPEEDCFG							(ANTS_ANDROID_NET_DVR_GETCFG+65)	//!��ȡץ�Ļ����ٲ���
#define ANTS_ANDROID_NET_DVR_GET_IMAGEOVERLAYCFG							(ANTS_ANDROID_NET_DVR_GETCFG+66)	//!��ȡץ�Ļ�ͼ�������Ϣ����
#define ANTS_ANDROID_NET_DVR_GET_SNAPCFG									(ANTS_ANDROID_NET_DVR_GETCFG+67)	//!��ȡ��IO����ץ�Ĺ�������
#define ANTS_ANDROID_NET_DVR_GET_VTPPARAM									(ANTS_ANDROID_NET_DVR_GETCFG+68)	//!��ȡ������Ȧ����
#define ANTS_ANDROID_NET_DVR_GET_SNAPENABLECFG								(ANTS_ANDROID_NET_DVR_GETCFG+69)	//!��ȡץ�Ļ�ʹ�ܲ���
#define ANTS_ANDROID_NET_DVR_GET_JPEGCFG									(ANTS_ANDROID_NET_DVR_GETCFG+70)	//!��ȡץͼ��JPEG����(����)
#define ANTS_ANDROID_NET_DVR_GET_SPRCFG										(ANTS_ANDROID_NET_DVR_GETCFG+71)	//!��ȡ����ʶ�����
#define ANTS_ANDROID_NET_DVR_GET_PLCCFG										(ANTS_ANDROID_NET_DVR_GETCFG+72)	//!��ȡ�������Ȳ�������
#define ANTS_ANDROID_NET_DVR_GET_DEVICESTATECFG								(ANTS_ANDROID_NET_DVR_GETCFG+73)	//!��ȡ�豸��ǰ״̬����
#define ANTS_ANDROID_NET_DVR_GET_ZEROCHANCFG								(ANTS_ANDROID_NET_DVR_GETCFG+74)	//!��ȡ��ͨ��ѹ������ 
#define ANTS_ANDROID_NET_DVR_GET_ZERO_ZOOM									(ANTS_ANDROID_NET_DVR_GETCFG+75)	//!��ȡ��ͨ������������
#define ANTS_ANDROID_NET_DVR_GET_NATASSOCIATECFG							(ANTS_ANDROID_NET_DVR_GETCFG+76)	//!��ȡNAT���������Ϣ
#define ANTS_ANDROID_NET_DVR_GET_SNMPCFG									(ANTS_ANDROID_NET_DVR_GETCFG+77)	//!��ȡSNMP���� 
#define ANTS_ANDROID_NET_DVR_GET_VIDEOPLATFORMALARMCFG						(ANTS_ANDROID_NET_DVR_GETCFG+78)	//!��ȡ��Ƶ�ۺ�ƽ̨��������
#define ANTS_ANDROID_NET_DVR_GET_RAID_ADAPTER_INFO							(ANTS_ANDROID_NET_DVR_GETCFG+79)	//!��ȡ��������Ϣ
#define ANTS_ANDROID_NET_DVR_GET_NETCFG_MULTI								(ANTS_ANDROID_NET_DVR_GETCFG+80)	//!��ȡ����������
#define ANTS_ANDROID_NET_DVR_GET_IPPARACFG									(ANTS_ANDROID_NET_DVR_GETCFG+81)	//!��ȡIP����������Ϣ 
#define ANTS_ANDROID_NET_DVR_GET_CCDPARAMCFG								(ANTS_ANDROID_NET_DVR_GETCFG+82)	//!IPC��ȡCCD��������
#define ANTS_ANDROID_NET_DVR_GET_IPALARMINCFG								(ANTS_ANDROID_NET_DVR_GETCFG+83)	//!��ȡIP�����������������Ϣ 
#define ANTS_ANDROID_NET_DVR_GET_IPALARMOUTCFG								(ANTS_ANDROID_NET_DVR_GETCFG+84)	//!��ȡIP�����������������Ϣ 
#define ANTS_ANDROID_NET_DVR_GET_AUTOREBOOT									(ANTS_ANDROID_NET_DVR_GETCFG+85) 	//!��ȡ�Զ�ά������ 
#define ANTS_ANDROID_NET_DVR_GET_PICCFGEX									(ANTS_ANDROID_NET_DVR_GETCFG+86)	//!��ȡͼ�����(��չ)
#define ANTS_ANDROID_NET_DVR_GET_COMPRESSCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+87)	//!��ȡѹ������(��չ)
#define ANTS_ANDROID_NET_DVR_GET_RECORDCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+88)	//!��ȡ¼��ʱ�����(��չ)
#define ANTS_ANDROID_NET_DVR_GET_DECODERCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+89)	//!��ȡ����������(��չ)
#define ANTS_ANDROID_NET_DVR_GET_ALARMINCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+90)	//!��ȡ�����������(��չ)
#define ANTS_ANDROID_NET_DVR_GET_ALARMOUTCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+91)	//!��ȡ�����������(��չ)
#define ANTS_ANDROID_NET_DVR_GET_SHOWSTRINGEX								(ANTS_ANDROID_NET_DVR_GETCFG+92)	//!��ȡ�����ַ�����(��չ)
#define ANTS_ANDROID_NET_DVR_GET_EVENTCOMPCFGEX								(ANTS_ANDROID_NET_DVR_GETCFG+93)	//!��ȡ�¼�����¼�����(��չ)
#define ANTS_ANDROID_NET_DVR_GET_AP_INFO_LIST								(ANTS_ANDROID_NET_DVR_GETCFG+94)	//!��ȡ����������Դ����
#define ANTS_ANDROID_NET_DVR_GET_WIFI_CFG									(ANTS_ANDROID_NET_DVR_GETCFG+95)	//!��ȡIP����豸���߲���
#define ANTS_ANDROID_NET_DVR_GET_WIFI_WORKMODE								(ANTS_ANDROID_NET_DVR_GETCFG+96)	//!��ȡIP����豸���ڹ���ģʽ����
#define ANTS_ANDROID_NET_DVR_GET_3G_CFG										(ANTS_ANDROID_NET_DVR_GETCFG+97)	//!��ȡ3G���ò���
#define ANTS_ANDROID_NET_DVR_GET_MANAGERHOST_CFG							(ANTS_ANDROID_NET_DVR_GETCFG+98)	//!��ȡý����������ò���
#define ANTS_ANDROID_NET_DVR_GET_3GDEVICE_CFG								(ANTS_ANDROID_NET_DVR_GETCFG+99)	//!��ȡ3G�豸����
#define ANTS_ANDROID_NET_DVR_GET_NETDEV_CFG									(ANTS_ANDROID_NET_DVR_GETCFG+100)	//!��ȡԶ��NVR��IPC�豸��Ϣ

#define ANTS_ANDROID_NET_DVR_SETCFG											200
#define ANTS_ANDROID_NET_DVR_SET_DEVICECFG									(ANTS_ANDROID_NET_DVR_SETCFG+1)		//!�����豸����
#define ANTS_ANDROID_NET_DVR_SET_NETCFG										(ANTS_ANDROID_NET_DVR_SETCFG+2)		//!�����������
#define ANTS_ANDROID_NET_DVR_SET_PICCFG										(ANTS_ANDROID_NET_DVR_SETCFG+3)		//!����ͼ�����
#define ANTS_ANDROID_NET_DVR_SET_COMPRESSCFG								(ANTS_ANDROID_NET_DVR_SETCFG+4)		//!����ѹ������
#define ANTS_ANDROID_NET_DVR_SET_RECORDCFG									(ANTS_ANDROID_NET_DVR_SETCFG+5)		//!����¼��ʱ�����
#define ANTS_ANDROID_NET_DVR_SET_DECODERCFG									(ANTS_ANDROID_NET_DVR_SETCFG+6)		//!���ý���������
#define ANTS_ANDROID_NET_DVR_SET_RS232CFG									(ANTS_ANDROID_NET_DVR_SETCFG+7)		//!����232���ڲ���
#define ANTS_ANDROID_NET_DVR_SET_ALARMINCFG									(ANTS_ANDROID_NET_DVR_SETCFG+8)		//!���ñ����������
#define ANTS_ANDROID_NET_DVR_SET_ALARMOUTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+9)		//!���ñ����������
#define ANTS_ANDROID_NET_DVR_SET_TIMECFG									(ANTS_ANDROID_NET_DVR_SETCFG+10)	//!����DVRʱ��
#define ANTS_ANDROID_NET_DVR_SET_PREVIEWCFG									(ANTS_ANDROID_NET_DVR_SETCFG+11)	//!����Ԥ������
#define ANTS_ANDROID_NET_DVR_SET_VIDEOOUTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+12)	//!������Ƶ�������
#define ANTS_ANDROID_NET_DVR_SET_USERCFG									(ANTS_ANDROID_NET_DVR_SETCFG+13)	//!�����û�����
#define ANTS_ANDROID_NET_DVR_SET_EXCEPTIONCFG								(ANTS_ANDROID_NET_DVR_SETCFG+14)	//!�����쳣����
#define ANTS_ANDROID_NET_DVR_SET_ZONEANDDST									(ANTS_ANDROID_NET_DVR_SETCFG+15)	//!����ʱ������ʱ�Ʋ���
#define ANTS_ANDROID_NET_DVR_SET_SHOWSTRING									(ANTS_ANDROID_NET_DVR_SETCFG+16)	//!���õ����ַ�����
#define ANTS_ANDROID_NET_DVR_SET_EVENTCOMPCFG								(ANTS_ANDROID_NET_DVR_SETCFG+17)	//!�����¼�����¼�����
#define ANTS_ANDROID_NET_DVR_SET_FTPCFG										(ANTS_ANDROID_NET_DVR_SETCFG+18)	//!����ץͼ��FTP����(����)
#define ANTS_ANDROID_NET_DVR_SET_AUXOUTCFG									(ANTS_ANDROID_NET_DVR_SETCFG+19)	//!���ñ������������������(HS�豸�������)
#define ANTS_ANDROID_NET_DVR_SET_PREVIEWCFG_AUX								(ANTS_ANDROID_NET_DVR_SETCFG+20)	//!����-sϵ��˫���Ԥ������(-sϵ��˫���)
#define ANTS_ANDROID_NET_DVR_SET_RULECFG									(ANTS_ANDROID_NET_DVR_SETCFG+21)	//!������Ϊ��������
#define ANTS_ANDROID_NET_DVR_SET_TRACK_CFG									(ANTS_ANDROID_NET_DVR_SETCFG+22)	//!������������ò��� 
#define ANTS_ANDROID_NET_DVR_SET_IVMS_STREAMCFG								(ANTS_ANDROID_NET_DVR_SETCFG+23)	//!�������ܷ�����ȡ������
#define ANTS_ANDROID_NET_DVR_SET_VCA_CTRLCFG								(ANTS_ANDROID_NET_DVR_SETCFG+24)	//!�������ܿ��Ʋ���
#define ANTS_ANDROID_NET_DVR_SET_VCA_MASK_REGION							(ANTS_ANDROID_NET_DVR_SETCFG+25) 	//!���������������
#define ANTS_ANDROID_NET_DVR_SET_VCA_ENTER_REGION							(ANTS_ANDROID_NET_DVR_SETCFG+26)	//!���ý����������
#define ANTS_ANDROID_NET_DVR_SET_VCA_LINE_SEGMENT							(ANTS_ANDROID_NET_DVR_SETCFG+27)	//!���ñ궨��
#define ANTS_ANDROID_NET_DVR_SET_IVMS_MASK_REGION							(ANTS_ANDROID_NET_DVR_SETCFG+28)	//!����IVMS�����������
#define ANTS_ANDROID_NET_DVR_SET_IVMS_ENTER_REGION							(ANTS_ANDROID_NET_DVR_SETCFG+29)	//!����IVMS�����������
#define ANTS_ANDROID_NET_DVR_SET_IVMS_BEHAVIORCFG  							(ANTS_ANDROID_NET_DVR_SETCFG+30)	//!�������ܷ�������Ϊ�������
#define ANTS_ANDROID_NET_DVR_SET_IVMS_SEARCHCFG								(ANTS_ANDROID_NET_DVR_SETCFG+31)	//!����IVMS�طż�������
#define ANTS_ANDROID_NET_DVR_SET_POSITION_TRACK     						(ANTS_ANDROID_NET_DVR_SETCFG+32) 	//!���ó�������������Ϣ
#define ANTS_ANDROID_NET_DVR_SET_CALIBRATION       							(ANTS_ANDROID_NET_DVR_SETCFG+33) 	//!���ñ궨��Ϣ
#define ANTS_ANDROID_NET_DVR_SET_PDC_RULECFG       							(ANTS_ANDROID_NET_DVR_SETCFG+34) 	//!����������ͳ�ƹ���
#define ANTS_ANDROID_NET_DVR_SET_PU_STREAMCFG      							(ANTS_ANDROID_NET_DVR_SETCFG+35) 	//!����ǰ��ȡ���豸��Ϣ
#define ANTS_ANDROID_NET_DVR_SET_DETECT_RULECFG      						(ANTS_ANDROID_NET_DVR_SETCFG+36) 	//!����ATM���������
#define ANTS_ANDROID_NET_DVR_SET_VCA_SIZE_FILTER         					(ANTS_ANDROID_NET_DVR_SETCFG+37)	//!����ȫ�ֳߴ������
#define ANTS_ANDROID_NET_DVR_SET_TRACK_PARAMCFG      						(ANTS_ANDROID_NET_DVR_SETCFG+38) 	//!����������ز˵�����	
#define ANTS_ANDROID_NET_DVR_SET_DOME_MOVEMENT_PARAM						(ANTS_ANDROID_NET_DVR_SETCFG+39) 	//!���������о����
#define ANTS_ANDROID_NET_DVR_SET_NETAPPCFG									(ANTS_ANDROID_NET_DVR_SETCFG+40)	//!��������Ӧ�ò��� NTP/DDNS/EMAIL
#define ANTS_ANDROID_NET_DVR_SET_NTPCFG										(ANTS_ANDROID_NET_DVR_SETCFG+41)	//!��������Ӧ�ò��� NTP
#define ANTS_ANDROID_NET_DVR_SET_DDNSCFG									(ANTS_ANDROID_NET_DVR_SETCFG+42)	//!��������Ӧ�ò��� DDNS
#define ANTS_ANDROID_NET_DVR_SET_EMAILCFG									(ANTS_ANDROID_NET_DVR_SETCFG+43)	//!��������Ӧ�ò��� EMAIL
#define ANTS_ANDROID_NET_DVR_SET_NFSCFG										(ANTS_ANDROID_NET_DVR_SETCFG+44)	//!NFS disk config
#define ANTS_ANDROID_NET_DVR_SET_NETCFG_OTHER								(ANTS_ANDROID_NET_DVR_SETCFG+45)	//!�����������
#define ANTS_ANDROID_NET_DVR_SET_EMAILPARACFG								(ANTS_ANDROID_NET_DVR_SETCFG+46)	//!Setup EMAIL parameters
#define ANTS_ANDROID_NET_DVR_SET_PTZPOS										(ANTS_ANDROID_NET_DVR_SETCFG+47)	//!��̨����PTZλ��
#define ANTS_ANDROID_NET_DVR_SET_REFERENCE_REGION   						(ANTS_ANDROID_NET_DVR_SETCFG+48) 	//!���òο�����
#define ANTS_ANDROID_NET_DVR_SET_TARFFIC_MASK_REGION   						(ANTS_ANDROID_NET_DVR_SETCFG+49)	//!���ý�ͨ�¼���������
#define ANTS_ANDROID_NET_DVR_SET_SCENE_MODE          						(ANTS_ANDROID_NET_DVR_SETCFG+50) 	//!���ó���ģʽ 
#define ANTS_ANDROID_NET_DVR_SET_AID_RULECFG         						(ANTS_ANDROID_NET_DVR_SETCFG+51)	         
#define ANTS_ANDROID_NET_DVR_SET_TPS_RULECFG         						(ANTS_ANDROID_NET_DVR_SETCFG+52)        	
#define ANTS_ANDROID_NET_DVR_SET_LANECFG									(ANTS_ANDROID_NET_DVR_SETCFG+53)	//!���ó�������
#define ANTS_ANDROID_NET_DVR_SET_PLATECFG            						(ANTS_ANDROID_NET_DVR_SETCFG+54)	//!���ó���ʶ�����
#define ANTS_ANDROID_NET_DVR_SET_CRUISE										(ANTS_ANDROID_NET_DVR_SETCFG+55)		
#define ANTS_ANDROID_NET_DVR_SET_NET_DISKCFG								(ANTS_ANDROID_NET_DVR_SETCFG+56)	//!����Ӳ�̽�������
#define ANTS_ANDROID_NET_DVR_SET_HDCFG										(ANTS_ANDROID_NET_DVR_SETCFG+57)	//!����Ӳ�̹������ò���
#define ANTS_ANDROID_NET_DVR_SET_HDGROUP_CFG								(ANTS_ANDROID_NET_DVR_SETCFG+58)	//!��������������ò���
#define ANTS_ANDROID_NET_DVR_SET_COMPRESSCFG_AUD							(ANTS_ANDROID_NET_DVR_SETCFG+60) 	//!�����豸�����Խ��������
#define ANTS_ANDROID_NET_DVR_SET_IOINCFG		        					(ANTS_ANDROID_NET_DVR_SETCFG+61)	//!����ץ�Ļ�IO�������
#define ANTS_ANDROID_NET_DVR_SET_IOOUTCFG		        					(ANTS_ANDROID_NET_DVR_SETCFG+62)	//!����ץ�Ļ�IO�������
#define ANTS_ANDROID_NET_DVR_SET_FLASHCFG		        					(ANTS_ANDROID_NET_DVR_SETCFG+63)	//!����IO������������
#define ANTS_ANDROID_NET_DVR_SET_LIGHTSNAPCFG	        					(ANTS_ANDROID_NET_DVR_SETCFG+64)	//!����ץ�Ļ����̵Ʋ���
#define ANTS_ANDROID_NET_DVR_SET_MEASURESPEEDCFG							(ANTS_ANDROID_NET_DVR_SETCFG+65)	//!���ý�ͨ�¼��������
#define ANTS_ANDROID_NET_DVR_SET_IMAGEOVERLAYCFG							(ANTS_ANDROID_NET_DVR_SETCFG+66)	//!���ý�ͨͳ�ƹ������
#define ANTS_ANDROID_NET_DVR_SET_SNAPCFG                					(ANTS_ANDROID_NET_DVR_SETCFG+67)	//!���õ�IO����ץ�Ĺ�������
#define ANTS_ANDROID_NET_DVR_SET_VTPPARAM	        						(ANTS_ANDROID_NET_DVR_SETCFG+68)	//!����������Ȧ����
#define ANTS_ANDROID_NET_DVR_SET_SNAPENABLECFG								(ANTS_ANDROID_NET_DVR_SETCFG+69)	//!����ץ�Ļ�ʹ�ܲ���
#define ANTS_ANDROID_NET_DVR_SET_JPEGCFG									(ANTS_ANDROID_NET_DVR_SETCFG+70)	//!����ץͼ��JPEG����(����)
#define ANTS_ANDROID_NET_DVR_SET_SPRCFG	                 					(ANTS_ANDROID_NET_DVR_SETCFG+71) 	//!���ó���ʶ�����
#define ANTS_ANDROID_NET_DVR_SET_PLCCFG  									(ANTS_ANDROID_NET_DVR_SETCFG+72) 	//!���ó������Ȳ�������
#define ANTS_ANDROID_NET_DVR_SET_ZEROCHANCFG 								(ANTS_ANDROID_NET_DVR_SETCFG+73)	//!������ͨ��ѹ������
#define ANTS_ANDROID_NET_DVR_SET_ZERO_ZOOM									(ANTS_ANDROID_NET_DVR_SETCFG+74) 	//!������ͨ������������ 
#define ANTS_ANDROID_NET_DVR_SET_NATASSOCIATECFG							(ANTS_ANDROID_NET_DVR_SETCFG+75) 	//!����NAT���������Ϣ
#define ANTS_ANDROID_NET_DVR_SET_SNMPCFG	               					(ANTS_ANDROID_NET_DVR_SETCFG+76) 	//!����SNMP����
#define ANTS_ANDROID_NET_DVR_SET_VIDEOPLATFORMALARMCFG						(ANTS_ANDROID_NET_DVR_SETCFG+77)	//!������Ƶ�ۺ�ƽ̨��������
#define ANTS_ANDROID_NET_DVR_SET_RAID_ADAPTER_INFO  						(ANTS_ANDROID_NET_DVR_SETCFG+78) 	//!������������Ϣ   
#define ANTS_ANDROID_NET_DVR_SET_NETCFG_MULTI         						(ANTS_ANDROID_NET_DVR_SETCFG+79) 	//!���ö���������	
#define ANTS_ANDROID_NET_DVR_SET_IPPARACFG									(ANTS_ANDROID_NET_DVR_SETCFG+80)	//!����IP����������Ϣ
#define ANTS_ANDROID_NET_DVR_SET_CCDPARAMCFG								(ANTS_ANDROID_NET_DVR_SETCFG+81)	//!IPC����CCD��������
#define ANTS_ANDROID_NET_DVR_SET_IPALARMINCFG								(ANTS_ANDROID_NET_DVR_SETCFG+82)	//!����IP�����������������Ϣ
#define ANTS_ANDROID_NET_DVR_SET_IPALARMOUTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+83)	//!����IP�����������������Ϣ
#define ANTS_ANDROID_NET_DVR_SET_AUTOREBOOT               					(ANTS_ANDROID_NET_DVR_SETCFG+84)	//!�����Զ�ά������
#define ANTS_ANDROID_NET_DVR_SET_PICCFGEX									(ANTS_ANDROID_NET_DVR_SETCFG+85)	//!����ͼ�����(��չ)
#define ANTS_ANDROID_NET_DVR_SET_COMPRESSCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+86)	//!����ѹ������(��չ)
#define ANTS_ANDROID_NET_DVR_SET_RECORDCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+87)	//!����¼��ʱ�����(��չ)
#define ANTS_ANDROID_NET_DVR_SET_DECODERCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+88)	//!���ý���������(��չ)
#define ANTS_ANDROID_NET_DVR_SET_ALARMINCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+89)	//!���ñ����������(��չ)
#define ANTS_ANDROID_NET_DVR_SET_ALARMOUTCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+90)	//!���ñ����������(��չ)
#define ANTS_ANDROID_NET_DVR_SET_SHOWSTRINGEX								(ANTS_ANDROID_NET_DVR_SETCFG+91)	//!���õ����ַ�����(��չ)
#define ANTS_ANDROID_NET_DVR_SET_EVENTCOMPCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+92)	//!�����¼�����¼�����(��չ)
#define ANTS_ANDROID_NET_DVR_SET_WIFI_CFG									(ANTS_ANDROID_NET_DVR_SETCFG+93)	//!����IP����豸���߲���
#define ANTS_ANDROID_NET_DVR_SET_WIFI_WORKMODE								(ANTS_ANDROID_NET_DVR_SETCFG+94)	//!����IP����豸���ڹ���ģʽ����
#define ANTS_ANDROID_NET_DVR_SET_3G_CFG										(ANTS_ANDROID_NET_DVR_SETCFG+95)	//!����3G���ò���
#define ANTS_ANDROID_NET_DVR_SET_MANAGERHOST_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+96)	//!����ý����������ò���
#define ANTS_ANDROID_NET_DVR_SET_NETDEV_CFG									(ANTS_ANDROID_NET_DVR_SETCFG+97)	//!����NVR�ϵ�IPC���ò���

//!Modify by ItmanLee at 2012-11-22
#define ANTS_ANDROID_NET_DVR_GET_NETDEV_CFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+100)	//!��ȡԶ��NVR��IPC�豸��Ϣ,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_PICCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+101)	//!��ȡͼ�����,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_USERCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+102)	//!��ȡ�û�����,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_ALARMINCFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+103)	//!��ȡ�����������,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_HDGROUP_CFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+104)	//!��ȡ����������ò���,���36-DVR/NVR

//!Added by ItmanLee at 2012-11-22
#define ANTS_ANDROID_NET_DVR_GET_VIDEOEFFECTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+105)	//!��ȡ���ȶԱȶ�ɫ�Ȳ���
#define ANTS_ANDROID_NET_DVR_GET_MOTIONCFG									(ANTS_ANDROID_NET_DVR_SETCFG+106)	//!��ȡ�ƶ�������
#define ANTS_ANDROID_NET_DVR_GET_MOTIONCFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+107)	//!��ȡ�ƶ�������
#define ANTS_ANDROID_NET_DVR_GET_SHELTERCFG									(ANTS_ANDROID_NET_DVR_SETCFG+108)	//!��ȡ��Ƶ�ڵ�����
#define ANTS_ANDROID_NET_DVR_GET_HIDEALARMCFG								(ANTS_ANDROID_NET_DVR_SETCFG+109)	//!��ȡ��Ƶ�ڵ���������
#define ANTS_ANDROID_NET_DVR_GET_VIDEOLOSTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+110)	//!��ȡ��Ƶ��ʧ����
#define ANTS_ANDROID_NET_DVR_GET_OSDCFG										(ANTS_ANDROID_NET_DVR_SETCFG+111)	//!��ȡ��ƵOSD����
#define ANTS_ANDROID_NET_DVR_GET_VIDEOFORMAT								(ANTS_ANDROID_NET_DVR_SETCFG+112)	//!��ȡ��Ƶ��ʽ����

#define ANTS_ANDROID_NET_DVR_GET_PICCFGEX_V2								(ANTS_ANDROID_NET_DVR_SETCFG+113)	//!��ȡͼ�����(��չ),���36-DVR/NVR	
#define ANTS_ANDROID_NET_DVR_GET_ALARMINCFGEX_V2							(ANTS_ANDROID_NET_DVR_SETCFG+114)	//!��ȡ�����������,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_VIDEOEFFECTCFGEX							(ANTS_ANDROID_NET_DVR_SETCFG+115)	//!��ȡ���ȶԱȶ�ɫ�Ȳ���
#define ANTS_ANDROID_NET_DVR_GET_MOTIONCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+116)	//!��ȡ�ƶ�������
#define ANTS_ANDROID_NET_DVR_GET_MOTIONCFGEX_V2								(ANTS_ANDROID_NET_DVR_SETCFG+117)
#define ANTS_ANDROID_NET_DVR_GET_SHELTERCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+118)	//!��ȡ��Ƶ�ڵ�����
#define ANTS_ANDROID_NET_DVR_GET_HIDEALARMCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+119)	//!��ȡ��Ƶ�ڵ���������
#define ANTS_ANDROID_NET_DVR_GET_VIDEOLOSTCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+120)	//!��ȡ��Ƶ��ʧ����
#define ANTS_ANDROID_NET_DVR_GET_OSDCFGEX									(ANTS_ANDROID_NET_DVR_SETCFG+121)	//!��ȡ��ƵOSD����
#define ANTS_ANDROID_NET_DVR_GET_VIDEOFORMATEX								(ANTS_ANDROID_NET_DVR_SETCFG+122)
#define ANTS_ANDROID_NET_DVR_GET_AUTOSWITCH_CFG								(ANTS_ANDROID_NET_DVR_SETCFG+123)	//!��ȡԶ��NVR�Զ��л�ģʽ
#define ANTS_ANDROID_NET_DVR_GET_NETDEVCONNETCTCFG							(ANTS_ANDROID_NET_DVR_SETCFG+124)	//!��ȡԶ��NVRͨ���Ƿ�����		

//!Added by ItmanLee at 2012-01-08
#define ANTS_ANDROID_NET_DVR_GET_DEVCHANNAME_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+125)	//!��ȡԶ���豸ͨ������,��ͨ����ȡ��ʽ
#define ANTS_ANDROID_NET_DVR_GET_DEVCHANNAME_CFG_V2							(ANTS_ANDROID_NET_DVR_SETCFG+126)	//!��ȡԶ���豸ͨ������,��ͨ����ȡ��ʽ
#define ANTS_ANDROID_NET_DVR_GET_HDCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+127)	//!��ȡԶ���豸Ӳ����չ�ṹ
#define ANTS_ANDROID_NET_DVR_GET_SENSORCFG									(ANTS_ANDROID_NET_DVR_SETCFG+128)	//!��ȡIPC Sensor�ṹ
#define ANTS_ANDROID_NET_DVR_GET_NETDEV_CFG_V3								(ANTS_ANDROID_NET_DVR_SETCFG+129)	//!��ȡԶ��NVR��IPC�豸��Ϣ,���64-DVR/NVR
#define ANTS_ANDROID_NET_DVR_GET_MANAGERHOSTV2_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+130)	//!��ȡԶ���豸����ƽ̨���ò���

#define ANTS_ANDROID_NET_DVR_GET_NETDEVCONNETCTCFG_V2						(ANTS_ANDROID_NET_DVR_SETCFG+131)	//!��ȡԶ��NVR����IPͨ������״̬,���4/8/16/32/64-NVR	
#define ANTS_ANDROID_NET_DVR_GET_DEVCHANNAME_CFGV2							(ANTS_ANDROID_NET_DVR_SETCFG+132)	//!��ȡԶ��NVR����ͨ�����ƽṹ,���4/8/16/32/64-NVR	
 
#define ANTS_ANDROID_NET_DVR_SET_NETDEV_CFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+300)	//!����Զ��NVR��IPC�豸��Ϣ,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_PICCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+301)	//!����ͼ�����,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_USERCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+302)	//!�����û�����,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_ALARMINCFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+303)	//!���ñ����������,���36-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_HDGROUP_CFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+304)	//!��������������ò���,���36-DVR/NVR

#define ANTS_ANDROID_NET_DVR_SET_VIDEOEFFECTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+305)
#define ANTS_ANDROID_NET_DVR_SET_MOTIONCFG									(ANTS_ANDROID_NET_DVR_SETCFG+306)	//!�����ƶ�������
#define ANTS_ANDROID_NET_DVR_SET_MOTIONCFG_V2								(ANTS_ANDROID_NET_DVR_SETCFG+307)	//!�����ƶ�������(���36-DVR/NVR)
#define ANTS_ANDROID_NET_DVR_SET_SHELTERCFG									(ANTS_ANDROID_NET_DVR_SETCFG+308)	//!������Ƶ�ڵ�����
#define ANTS_ANDROID_NET_DVR_SET_HIDEALARMCFG								(ANTS_ANDROID_NET_DVR_SETCFG+309)	//!������Ƶ�ڵ���������
#define ANTS_ANDROID_NET_DVR_SET_VIDEOLOSTCFG								(ANTS_ANDROID_NET_DVR_SETCFG+310)	//!������Ƶ��ʧ����
#define ANTS_ANDROID_NET_DVR_SET_OSDCFG										(ANTS_ANDROID_NET_DVR_SETCFG+311)	//!������ƵOSD����
#define ANTS_ANDROID_NET_DVR_SET_VIDEOFORMAT								(ANTS_ANDROID_NET_DVR_SETCFG+312)

#define ANTS_ANDROID_NET_DVR_SET_PICCFGEX_V2								(ANTS_ANDROID_NET_DVR_SETCFG+313)	//!����ͼ�����(��չ),���64-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_ALARMINCFGEX_V2							(ANTS_ANDROID_NET_DVR_SETCFG+314)	//!���ñ����������,���64-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_VIDEOEFFECTCFGEX							(ANTS_ANDROID_NET_DVR_SETCFG+315)	//!�������ȶԱȶ�ɫ�Ȳ���
#define ANTS_ANDROID_NET_DVR_SET_MOTIONCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+316)	//!�����ƶ�������
#define ANTS_ANDROID_NET_DVR_SET_MOTIONCFGEX_V2								(ANTS_ANDROID_NET_DVR_SETCFG+317) 	//!�����ƶ�������(���64-DVR/NVR)	
#define ANTS_ANDROID_NET_DVR_SET_SHELTERCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+318)	//!������Ƶ�ڵ�����
#define ANTS_ANDROID_NET_DVR_SET_HIDEALARMCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+319)	//!������Ƶ�ڵ���������
#define ANTS_ANDROID_NET_DVR_SET_VIDEOLOSTCFGEX								(ANTS_ANDROID_NET_DVR_SETCFG+320)	//!������Ƶ��ʧ����
#define ANTS_ANDROID_NET_DVR_SET_OSDCFGEX									(ANTS_ANDROID_NET_DVR_SETCFG+321)	//!������ƵOSD����
#define ANTS_ANDROID_NET_DVR_SET_VIDEOFORMATEX								(ANTS_ANDROID_NET_DVR_SETCFG+322)	//!����Զ���豸��Ƶ��ʽ
#define ANTS_ANDROID_NET_DVR_SET_AUTOSWITCH_CFG								(ANTS_ANDROID_NET_DVR_SETCFG+323)	//!����Զ��NVR�Զ��л�ģʽ
#define ANTS_ANDROID_NET_DVR_SET_NETDEVCONNETCTCFG							(ANTS_ANDROID_NET_DVR_GETCFG+324)	//!����Զ��NVRͨ���Ƿ�����	

//!Added by ItmanLee at 2012-01-08
#define ANTS_ANDROID_NET_DVR_SET_DEVCHANNAME_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+325)	//!����Զ���豸ͨ������,��ͨ����ȡ
#define ANTS_ANDROID_NET_DVR_SET_DEVCHANNAME_CFG_V2							(ANTS_ANDROID_NET_DVR_SETCFG+326)	//!����Զ���豸ͨ������,��ͨ����ȡ
#define ANTS_ANDROID_NET_DVR_SET_HDCFG_V2									(ANTS_ANDROID_NET_DVR_SETCFG+327)	//!����Զ���豸Ӳ����չ�ṹ
#define ANTS_ANDROID_NET_DVR_SET_SENSORCFG									(ANTS_ANDROID_NET_DVR_SETCFG+328)	//!����IPC Sensor�ṹ
#define ANTS_ANDROID_NET_DVR_SET_NETDEV_CFG_V3								(ANTS_ANDROID_NET_DVR_SETCFG+329)	//!����Զ��NVR��IPC�豸��Ϣ,���64-DVR/NVR
#define ANTS_ANDROID_NET_DVR_SET_MANAGERHOSTV2_CFG							(ANTS_ANDROID_NET_DVR_SETCFG+330)	//!��ȡԶ���豸����ƽ̨���ò���

#define ANTS_ANDROID_NET_DVR_SET_NETDEVCONNETCTCFG_V2						(ANTS_ANDROID_NET_DVR_SETCFG+331)	//!����Զ��NVR����IPͨ������״̬,���4/8/16/32/64-NVR	
#define ANTS_ANDROID_NET_DVR_SET_DEVCHANNAME_CFGV2							(ANTS_ANDROID_NET_DVR_SETCFG+332)	//!����Զ��NVR����ͨ�����ƽṹ,���4/8/16/32/64-NVR	

//!Added by ItmanLee at 2013-09-02
#define ANTS_ANDROID_NET_DVR_GET_FACTORY_INFO								(ANTS_ANDROID_NET_DVR_SETCFG+333)

#define ANTS_ANDROID_STATIC_ALLOC_MEMORY 							0x0000 	//!��̬�����ڴ�
#define ANTS_ANDROID_DYNAMIC_ALLOC_MEMORY 							0x0001	//!��̬�����ڴ�,ֻ���䲻���ڴ��ͷ�	

//!�����ļ�����־��������ֵ
#define ANTS_ANDROID_NET_DVR_FILE_SUCCESS							1000		//!����ļ���Ϣ
#define ANTS_ANDROID_NET_DVR_FILE_NOFIND							1001		//!û���ļ�
#define ANTS_ANDROID_NET_DVR_ISFINDING								1002		//!���ڲ����ļ�
#define ANTS_ANDROID_NET_DVR_NOMOREFILE								1003		//!�����ļ�ʱû�и�����ļ�
#define ANTS_ANDROID_NET_DVR_FILE_EXCEPTION							1004		//!�����ļ�ʱ�쳣

//!�ص��������� 
#define ANTS_ANDROID_COMM_ALARM										0x1100	//!������Ϣ�����ϴ�
#define ANTS_ANDROID_COMM_TRADEINFO									0x1500 	//!ATMDVR�����ϴ�������Ϣ
#define ANTS_ANDROID_COMM_IPCCFG			        				0x4001	//!�豸IPC�������øı䱨����Ϣ�����ϴ�

//!�����쳣����(��Ϣ��ʽ, �ص���ʽ(����))
#define ANTS_ANDROID_EXCEPTION_EXCHANGE								0x8000	//!�û�����ʱ�쳣
#define ANTS_ANDROID_EXCEPTION_AUDIOEXCHANGE						0x8001	//!�����Խ��쳣
#define ANTS_ANDROID_EXCEPTION_ALARM								0x8002	//!�����쳣
#define ANTS_ANDROID_EXCEPTION_PREVIEW								0x8003	//!����Ԥ���쳣
#define ANTS_ANDROID_EXCEPTION_SERIAL								0x8004	//!͸��ͨ���쳣
#define ANTS_ANDROID_EXCEPTION_RECONNECT							0x8005	//!Ԥ��ʱ����
#define ANTS_ANDROID_EXCEPTION_ALARMRECONNECT						0x8006	//!����ʱ����
#define ANTS_ANDROID_EXCEPTION_SERIALRECONNECT						0x8007	//!͸��ͨ������
#define ANTS_ANDROID_SERIAL_RECONNECTSUCCESS 						0x8008	//!͸��ͨ�������ɹ�
#define ANTS_ANDROID_EXCEPTION_PLAYBACK	        					0x8010	//!�ط��쳣
#define ANTS_ANDROID_EXCEPTION_DISKFMT	        					0x8011	//!Ӳ�̸�ʽ��
#define ANTS_ANDROID_EXCEPTION_PASSIVEDECODE     					0x8012 	//!���������쳣
#define ANTS_ANDROID_EXCEPTION_EMAILTEST           					0x8013 	//!�ʼ������쳣    
#define ANTS_ANDROID_EXCEPTION_BACKUP               				0x8014 	//!�����쳣
#define ANTS_ANDROID_PREVIEW_RECONNECTSUCCESS      					0x8015 	//!Ԥ��ʱ�����ɹ�
#define ANTS_ANDROID_ALARM_RECONNECTSUCCESS     					0x8016 	//!����ʱ�����ɹ�

#define ANTS_ANDROID_EXCEPTION_OFFLINE								0x9000 //!�豸����״̬
#define ANTS_ANDROID_EXCEPTION_ONLINE								0x9001 //!�豸����״̬	

//!Ԥ���ص�����
#define ANTS_ANDROID_NET_DVR_SYSHEAD								1		//!ϵͳͷ����
#define ANTS_ANDROID_NET_DVR_STREAMDATA								2		//!��Ƶ�����ݣ�����������������Ƶ�ֿ�����Ƶ�����ݣ�
#define ANTS_ANDROID_NET_DVR_AUDIOSTREAMDATA						3		//!��Ƶ������
#define ANTS_ANDROID_NET_DVR_STD_VIDEODATA							4		//!��׼��Ƶ������
#define ANTS_ANDROID_NET_DVR_STD_AUDIODATA							5		//!��׼��Ƶ������
#define ANTS_ANDROID_NET_DVR_MOTIONDETECTIONDATA					6		//!�ƶ����֡����

//!�豸�������쳣����ʽ
#define ANTS_ANDROID_NOACTION										0x00	//!����Ӧ
#define ANTS_ANDROID_WARNONMONITOR									0x01	//!�������Ͼ���
#define ANTS_ANDROID_WARNONAUDIOOUT									0x02	//!��������
#define ANTS_ANDROID_UPTOCENTER										0x04	//!�ϴ�����
#define ANTS_ANDROID_TRIGGERALARMOUT								0x08	//!�����������
#define ANTS_ANDROID_SENDJPG2EMAIL									0x10	//!JPEGץͼ���ϴ���e-mail


//!����
//!������
#define ANTS_ANDROID_MAJOR_ALARM									0x1

//!������
#define ANTS_ANDROID_MINOR_ALARM_IN									0x1			/*�������� */
#define ANTS_ANDROID_MINOR_ALARM_OUT								0x2			/*������� */
#define ANTS_ANDROID_MINOR_MOTDET_START								0x3			/*�ƶ���ⱨ����ʼ */
#define ANTS_ANDROID_MINOR_MOTDET_STOP								0x4			/*�ƶ���ⱨ������ */
#define ANTS_ANDROID_MINOR_HIDE_ALARM_START							0x5			/*�ڵ�������ʼ */
#define ANTS_ANDROID_MINOR_HIDE_ALARM_STOP							0x6			/*�ڵ��������� */
#define ANTS_ANDROID_MINOR_VCA_ALARM_START							0x7			/*���ܱ�����ʼ*/
#define ANTS_ANDROID_MINOR_VCA_ALARM_STOP							0x8			/*���ܱ���ֹͣ*/
#define ANTS_ANDROID_MINOR_ITS_ALARM_START    						0x09  		/*��ͨ�¼�������ʼ*/
#define ANTS_ANDROID_MINOR_ITS_ALARM_STOP     						0x0A   		/*��ͨ�¼���������*/

//!�쳣
//!������
#define ANTS_ANDROID_MAJOR_EXCEPTION								0x2

//!������
#define ANTS_ANDROID_MINOR_VI_LOST									0x21		/* ��Ƶ�źŶ�ʧ */
#define ANTS_ANDROID_MINOR_ILLEGAL_ACCESS							0x22		/* �Ƿ����� */
#define ANTS_ANDROID_MINOR_HD_FULL									0x23		/* Ӳ���� */
#define ANTS_ANDROID_MINOR_HD_ERROR									0x24		/* Ӳ�̴��� */
#define ANTS_ANDROID_MINOR_DCD_LOST									0x25		/* MODEM ����(������ʹ��) */
#define ANTS_ANDROID_MINOR_IP_CONFLICT								0x26		/* IP��ַ��ͻ */
#define ANTS_ANDROID_MINOR_NET_BROKEN								0x27		/* ����Ͽ�*/
#define ANTS_ANDROID_MINOR_REC_ERROR          						0x28   		/* ¼����� */
#define ANTS_ANDROID_MINOR_IPC_NO_LINK        						0x29   		/* IPC�����쳣 */
#define ANTS_ANDROID_MINOR_VI_EXCEPTION       						0x2a   		/* ��Ƶ�����쳣(ֻ���ģ��ͨ��) */
#define ANTS_ANDROID_MINOR_IPC_IP_CONFLICT    						0x2b   		/*ipc ip ��ַ ��ͻ*/

//!����
//!������
#define ANTS_ANDROID_MAJOR_OPERATION								0x3

//!������
//!2009-12-16 ������Ƶ�ۺ�ƽ̨��־����
#define ANTS_ANDROID_MINOR_FANABNORMAL								0x31		/* ��Ƶ�ۺ�ƽ̨������״̬�쳣 */
#define ANTS_ANDROID_MINOR_FANRESUME								0x32		/* ��Ƶ�ۺ�ƽ̨������״̬�ָ����� */
#define ANTS_ANDROID_MINOR_SUBSYSTEM_ABNORMALREBOOT					0x33		/* ��Ƶ�ۺ�ƽ̨��6467�쳣���� */
#define ANTS_ANDROID_MINOR_MATRIX_STARTBUZZER						0x34		/* ��Ƶ�ۺ�ƽ̨��dm6467�쳣������������ */

//!2010-01-22 ������Ƶ�ۺ�ƽ̨�쳣��־������
#define ANTS_ANDROID_MINOR_NET_ABNORMAL								0x35		/*����״̬�쳣*/
#define ANTS_ANDROID_MINOR_MEM_ABNORMAL								0x36		/*�ڴ�״̬�쳣*/
#define ANTS_ANDROID_MINOR_FILE_ABNORMAL							0x37		/*�ļ�״̬�쳣*/


//!������
#define ANTS_ANDROID_MINOR_START_DVR								0x41		/* ���� */
#define ANTS_ANDROID_MINOR_STOP_DVR									0x42		/* �ػ� */
#define ANTS_ANDROID_MINOR_STOP_ABNORMAL							0x43		/* �쳣�ػ� */
#define ANTS_ANDROID_MINOR_REBOOT_DVR      							0x44	    /* ���������豸*/

#define ANTS_ANDROID_MINOR_LOCAL_LOGIN								0x50		/* ���ص�½ */
#define ANTS_ANDROID_MINOR_LOCAL_LOGOUT								0x51		/* ����ע����½ */
#define ANTS_ANDROID_MINOR_LOCAL_CFG_PARM							0x52		/* �������ò��� */
#define ANTS_ANDROID_MINOR_LOCAL_PLAYBYFILE          				0x53		/* ���ذ��ļ��طŻ����� */
#define ANTS_ANDROID_MINOR_LOCAL_PLAYBYTIME          				0x54		/* ���ذ�ʱ��طŻ�����*/
#define ANTS_ANDROID_MINOR_LOCAL_START_REC							0x55		/* ���ؿ�ʼ¼�� */
#define ANTS_ANDROID_MINOR_LOCAL_STOP_REC							0x56		/* ����ֹͣ¼�� */
#define ANTS_ANDROID_MINOR_LOCAL_PTZCTRL							0x57		/* ������̨���� */
#define ANTS_ANDROID_MINOR_LOCAL_PREVIEW							0x58		/* ����Ԥ�� (������ʹ��)*/
#define ANTS_ANDROID_MINOR_LOCAL_MODIFY_TIME         				0x59		/* �����޸�ʱ��(������ʹ��) */
#define ANTS_ANDROID_MINOR_LOCAL_UPGRADE             				0x5a		/* �������� */
#define ANTS_ANDROID_MINOR_LOCAL_RECFILE_OUTPUT      				0x5b   		/* ���ر���¼���ļ� */
#define ANTS_ANDROID_MINOR_LOCAL_FORMAT_HDD          				0x5c    	/* ���س�ʼ��Ӳ�� */
#define ANTS_ANDROID_MINOR_LOCAL_CFGFILE_OUTPUT      				0x5d   	 	/* �������������ļ� */
#define ANTS_ANDROID_MINOR_LOCAL_CFGFILE_INPUT       				0x5e    	/* ���뱾�������ļ� */
#define ANTS_ANDROID_MINOR_LOCAL_COPYFILE            				0x5f    	/* ���ر����ļ� */
#define ANTS_ANDROID_MINOR_LOCAL_LOCKFILE            				0x60    	/* ��������¼���ļ� */
#define ANTS_ANDROID_MINOR_LOCAL_UNLOCKFILE          				0x61    	/* ���ؽ���¼���ļ� */
#define ANTS_ANDROID_MINOR_LOCAL_DVR_ALARM           				0x62    	/* �����ֶ�����ʹ�������*/
#define ANTS_ANDROID_MINOR_IPC_ADD                   				0x63    	/* �������IPC */
#define ANTS_ANDROID_MINOR_IPC_DEL                   				0x64    	/* ����ɾ��IPC */
#define ANTS_ANDROID_MINOR_IPC_SET                   				0x65    	/* ��������IPC */
#define ANTS_ANDROID_MINOR_LOCAL_START_BACKUP						0x66		/* ���ؿ�ʼ���� */
#define ANTS_ANDROID_MINOR_LOCAL_STOP_BACKUP						0x67		/* ����ֹͣ����*/
#define ANTS_ANDROID_MINOR_LOCAL_COPYFILE_START_TIME 				0x68		/* ���ر��ݿ�ʼʱ��*/
#define ANTS_ANDROID_MINOR_LOCAL_COPYFILE_END_TIME					0x69		/* ���ر��ݽ���ʱ��*/
#define ANTS_ANDROID_MINOR_LOCAL_ADD_NAS             				0x6a		/* �����������Ӳ�� ��nfs��iscsi��*/
#define ANTS_ANDROID_MINOR_LOCAL_DEL_NAS             				0x6b		/* ����ɾ��nas�� ��nfs��iscsi��*/
#define ANTS_ANDROID_MINOR_LOCAL_SET_NAS             				0x6c		/* ��������nas�� ��nfs��iscsi��*/

#define ANTS_ANDROID_MINOR_REMOTE_LOGIN								0x70		/* Զ�̵�¼ */
#define ANTS_ANDROID_MINOR_REMOTE_LOGOUT							0x71		/* Զ��ע����½ */
#define ANTS_ANDROID_MINOR_REMOTE_START_REC							0x72		/* Զ�̿�ʼ¼�� */
#define ANTS_ANDROID_MINOR_REMOTE_STOP_REC							0x73		/* Զ��ֹͣ¼�� */
#define ANTS_ANDROID_MINOR_START_TRANS_CHAN							0x74		/* ��ʼ͸������ */
#define ANTS_ANDROID_MINOR_STOP_TRANS_CHAN							0x75		/* ֹͣ͸������ */
#define ANTS_ANDROID_MINOR_REMOTE_GET_PARM							0x76		/* Զ�̻�ȡ���� */
#define ANTS_ANDROID_MINOR_REMOTE_CFG_PARM							0x77		/* Զ�����ò��� */
#define ANTS_ANDROID_MINOR_REMOTE_GET_STATUS         				0x78		/* Զ�̻�ȡ״̬ */
#define ANTS_ANDROID_MINOR_REMOTE_ARM								0x79		/* Զ�̲��� */
#define ANTS_ANDROID_MINOR_REMOTE_DISARM							0x7a		/* Զ�̳��� */
#define ANTS_ANDROID_MINOR_REMOTE_REBOOT							0x7b		/* Զ������ */
#define ANTS_ANDROID_MINOR_START_VT									0x7c		/* ��ʼ�����Խ� */
#define ANTS_ANDROID_MINOR_STOP_VT									0x7d		/* ֹͣ�����Խ� */
#define ANTS_ANDROID_MINOR_REMOTE_UPGRADE							0x7e		/* Զ������ */
#define ANTS_ANDROID_MINOR_REMOTE_PLAYBYFILE         				0x7f		/* Զ�̰��ļ��ط� */
#define ANTS_ANDROID_MINOR_REMOTE_PLAYBYTIME         				0x80		/* Զ�̰�ʱ��ط� */
#define ANTS_ANDROID_MINOR_REMOTE_PTZCTRL							0x81		/* Զ����̨���� */
#define ANTS_ANDROID_MINOR_REMOTE_FORMAT_HDD         				0x82    	/* Զ�̸�ʽ��Ӳ�� */
#define ANTS_ANDROID_MINOR_REMOTE_STOP               				0x83   		/* Զ�̹ػ� */
#define ANTS_ANDROID_MINOR_REMOTE_LOCKFILE							0x84		/* Զ�������ļ� */
#define ANTS_ANDROID_MINOR_REMOTE_UNLOCKFILE         				0x85		/* Զ�̽����ļ� */
#define ANTS_ANDROID_MINOR_REMOTE_CFGFILE_OUTPUT     				0x86    	/* Զ�̵��������ļ� */
#define ANTS_ANDROID_MINOR_REMOTE_CFGFILE_INTPUT     				0x87    	/* Զ�̵��������ļ� */
#define ANTS_ANDROID_MINOR_REMOTE_RECFILE_OUTPUT     				0x88    	/* Զ�̵���¼���ļ� */
#define ANTS_ANDROID_MINOR_REMOTE_DVR_ALARM          				0x89	  	/* Զ���ֶ�����ʹ�������*/
#define ANTS_ANDROID_MINOR_REMOTE_IPC_ADD							0x8a		/* Զ�����IPC */
#define ANTS_ANDROID_MINOR_REMOTE_IPC_DEL							0x8b		/* Զ��ɾ��IPC */
#define ANTS_ANDROID_MINOR_REMOTE_IPC_SET							0x8c		/* Զ������IPC */
#define ANTS_ANDROID_MINOR_REBOOT_VCA_LIB            				0x8d    	/*�������ܿ�*/
#define ANTS_ANDROID_MINOR_REMOTE_ADD_NAS           	 			0x8e   		/* Զ�����nas�� ��nfs��iscsi��*/
#define ANTS_ANDROID_MINOR_REMOTE_DEL_NAS            				0x8f   		/* Զ��ɾ��nas�� ��nfs��iscsi��*/
#define ANTS_ANDROID_MINOR_REMOTE_SET_NAS            				0x90   		/* Զ������nas�� ��nfs��iscsi��*/

//!��ѶDVR��־����
#define ANTS_ANDROID_MINOR_LOCAL_START_REC_CDRW      				0x91   		/* ���ؿ�ʼ��¼ */
#define ANTS_ANDROID_MINOR_LOCAL_STOP_REC_CDRW       				0x92   		/* ����ֹͣ��¼ */
#define ANTS_ANDROID_MINOR_REMOTE_START_REC_CDRW     				0x93   		/* Զ�̿�ʼ��¼ */
#define ANTS_ANDROID_MINOR_REMOTE_STOP_REC_CDRW      				0x94   		/* Զ��ֹͣ��¼ */

//!��Ƶ�ۺ�ƽ̨��־����
#define ANTS_ANDROID_MINOR_SUBSYSTEMREBOOT           				0xa0		/*��Ƶ�ۺ�ƽ̨��dm6467 ��������*/
#define ANTS_ANDROID_MINOR_MATRIX_STARTTRANSFERVIDEO 				0xa1		/*��Ƶ�ۺ�ƽ̨�������л���ʼ����ͼ��*/
#define ANTS_ANDROID_MINOR_MATRIX_STOPTRANSFERVIDEO					0xa2		/*��Ƶ�ۺ�ƽ̨�������л�ֹͣ����ͼ��*/
#define ANTS_ANDROID_MINOR_REMOTE_SET_ALLSUBSYSTEM   				0xa3		/*��Ƶ�ۺ�ƽ̨����������6467��ϵͳ��Ϣ*/
#define ANTS_ANDROID_MINOR_REMOTE_GET_ALLSUBSYSTEM   				0xa4		/*��Ƶ�ۺ�ƽ̨����ȡ����6467��ϵͳ��Ϣ*/
#define ANTS_ANDROID_MINOR_REMOTE_SET_PLANARRAY      				0xa5		/*��Ƶ�ۺ�ƽ̨�����üƻ���ѯ��*/
#define ANTS_ANDROID_MINOR_REMOTE_GET_PLANARRAY      				0xa6		/*��Ƶ�ۺ�ƽ̨����ȡ�ƻ���ѯ��*/
#define ANTS_ANDROID_MINOR_MATRIX_STARTTRANSFERAUDIO 				0xa7		/*��Ƶ�ۺ�ƽ̨�������л���ʼ������Ƶ*/
#define ANTS_ANDROID_MINOR_MATRIX_STOPRANSFERAUDIO   				0xa8		/*��Ƶ�ۺ�ƽ̨�������л�ֹͣ������Ƶ*/
#define ANTS_ANDROID_MINOR_LOGON_CODESPITTER         				0xa9		/*��Ƶ�ۺ�ƽ̨����½�����*/
#define ANTS_ANDROID_MINOR_LOGOFF_CODESPITTER        				0xaa		/*��Ƶ�ۺ�ƽ̨���˳������*/

//!�ۺ�ƽ̨�н�����������־
#define ANTS_ANDROID_MINOR_START_DYNAMIC_DECODE 					0xb0		/*��ʼ��̬����*/
#define ANTS_ANDROID_MINOR_STOP_DYNAMIC_DECODE						0xb1		/*ֹͣ��̬����*/
#define ANTS_ANDROID_MINOR_GET_CYC_CFG								0xb2		/*��ȡ������ͨ����ѯ����*/
#define ANTS_ANDROID_MINOR_SET_CYC_CFG								0xb3		/*���ý���ͨ����ѯ����*/
#define ANTS_ANDROID_MINOR_START_CYC_DECODE							0xb4		/*��ʼ��ѯ����*/
#define ANTS_ANDROID_MINOR_STOP_CYC_DECODE							0xb5		/*ֹͣ��ѯ����*/
#define ANTS_ANDROID_MINOR_GET_DECCHAN_STATUS						0xb6		/*��ȡ����ͨ��״̬*/
#define ANTS_ANDROID_MINOR_GET_DECCHAN_INFO							0xb7		/*��ȡ����ͨ����ǰ��Ϣ*/
#define ANTS_ANDROID_MINOR_START_PASSIVE_DEC						0xb8		/*��ʼ��������*/
#define ANTS_ANDROID_MINOR_STOP_PASSIVE_DEC							0xb9		/*ֹͣ��������*/
#define ANTS_ANDROID_MINOR_CTRL_PASSIVE_DEC							0xba		/*���Ʊ�������*/
#define ANTS_ANDROID_MINOR_RECON_PASSIVE_DEC						0xbb		/*������������*/
#define ANTS_ANDROID_MINOR_GET_DEC_CHAN_SW							0xbc		/*��ȡ����ͨ���ܿ���*/
#define ANTS_ANDROID_MINOR_SET_DEC_CHAN_SW							0xbd		/*���ý���ͨ���ܿ���*/
#define ANTS_ANDROID_MINOR_CTRL_DEC_CHAN_SCALE						0xbe		/*����ͨ�����ſ���*/
#define ANTS_ANDROID_MINOR_SET_REMOTE_REPLAY						0xbf		/*����Զ�̻ط�*/
#define ANTS_ANDROID_MINOR_GET_REMOTE_REPLAY						0xc0		/*��ȡԶ�̻ط�״̬*/
#define ANTS_ANDROID_MINOR_CTRL_REMOTE_REPLAY						0xc1		/*Զ�̻طſ���*/
#define ANTS_ANDROID_MINOR_SET_DISP_CFG								0xc2		/*������ʾͨ��*/
#define ANTS_ANDROID_MINOR_GET_DISP_CFG								0xc3		/*��ȡ��ʾͨ������*/
#define ANTS_ANDROID_MINOR_SET_PLANTABLE							0xc4		/*���üƻ���ѯ��*/
#define ANTS_ANDROID_MINOR_GET_PLANTABLE							0xc5		/*��ȡ�ƻ���ѯ��*/
#define ANTS_ANDROID_MINOR_START_PPPPOE								0xc6		/*��ʼPPPoE����*/
#define ANTS_ANDROID_MINOR_STOP_PPPPOE								0xc7		/*����PPPoE����*/
#define ANTS_ANDROID_MINOR_UPLOAD_LOGO								0xc8		/*�ϴ�LOGO*/

#define ANTS_ANDROID_MINOR_LOCAL_CONF_REB_RAID       				0x101   	/*���������Զ��ؽ�*/
#define ANTS_ANDROID_MINOR_LOCAL_CONF_SPARE          				0x102   	/*���������ȱ�*/
#define ANTS_ANDROID_MINOR_LOCAL_ADD_RAID            				0x103   	/*���ش�������*/
#define ANTS_ANDROID_MINOR_LOCAL_DEL_RAID            				0x104   	/*����ɾ������*/
#define ANTS_ANDROID_MINOR_LOCAL_MIG_RAID            				0x105   	/*����Ǩ������*/
#define ANTS_ANDROID_MINOR_LOCAL_REB_RAID            				0x106   	/* �����ֶ��ؽ�����*/
#define ANTS_ANDROID_MINOR_LOCAL_QUICK_CONF_RAID     				0x107   	/*����һ������*/
#define ANTS_ANDROID_MINOR_LOCAL_ADD_VD              				0x108   	/*���ش����������*/
#define ANTS_ANDROID_MINOR_LOCAL_DEL_VD              				0x109   	/*����ɾ���������*/
#define ANTS_ANDROID_MINOR_LOCAL_RP_VD               				0x10a   	/*�����޸��������*/
#define ANTS_ANDROID_MINOR_LOCAL_FORMAT_EXPANDVD	     			0x10b   	/*������չ�����������*/
#define ANTS_ANDROID_MINOR_LOCAL_RAID_UPGRADE       	 			0x10c   	/*����raid������*/    
#define ANTS_ANDROID_MINOR_REMOTE_CONF_REB_RAID      				0x111   	/*Զ�������Զ��ؽ�*/
#define ANTS_ANDROID_MINOR_REMOTE_CONF_SPARE         				0x112   	/*Զ�������ȱ�*/
#define ANTS_ANDROID_MINOR_REMOTE_ADD_RAID           				0x113   	/*Զ�̴�������*/
#define ANTS_ANDROID_MINOR_REMOTE_DEL_RAID           				0x114   	/*Զ��ɾ������*/
#define ANTS_ANDROID_MINOR_REMOTE_MIG_RAID           				0x115   	/*Զ��Ǩ������*/
#define ANTS_ANDROID_MINOR_REMOTE_REB_RAID           				0x116   	/* Զ���ֶ��ؽ�����*/
#define ANTS_ANDROID_MINOR_REMOTE_QUICK_CONF_RAID    				0x117   	/*Զ��һ������*/
#define ANTS_ANDROID_MINOR_REMOTE_ADD_VD            	 			0x118   	/*Զ�̴����������*/
#define ANTS_ANDROID_MINOR_REMOTE_DEL_VD             				0x119   	/*Զ��ɾ���������*/
#define ANTS_ANDROID_MINOR_REMOTE_RP_VD              				0x11a   	/*Զ���޸��������*/
#define ANTS_ANDROID_MINOR_REMOTE_FORMAT_EXPANDVD	    			0x11b   	/*Զ�������������*/
#define ANTS_ANDROID_MINOR_REMOTE_RAID_UPGRADE       				0x11c   	/*Զ��raid������*/    

//!��־������Ϣ
//!������
#define ANTS_ANDROID_MAJOR_INFORMATION               				0x4     	/*������Ϣ*/
//!������
#define ANTS_ANDROID_MINOR_HDD_INFO                  				0xa1 		/*Ӳ����Ϣ*/
#define ANTS_ANDROID_MINOR_SMART_INFO                				0xa2 		/*SMART��Ϣ*/
#define ANTS_ANDROID_MINOR_REC_START                 				0xa3 		/*��ʼ¼��*/
#define ANTS_ANDROID_MINOR_REC_STOP                  				0xa4 		/*ֹͣ¼��*/
#define ANTS_ANDROID_MINOR_REC_OVERDUE								0xa5 		/*����¼��ɾ��*/
#define ANTS_ANDROID_MINOR_LINK_START								0xa6 		/*����ǰ���豸*/
#define ANTS_ANDROID_MINOR_LINK_STOP								0xa7 		/*�Ͽ�ǰ���豸*/
#define ANTS_ANDROID_MINOR_NET_DISK_INFO							0xa8 		/*����Ӳ����Ϣ*/
#define ANTS_ANDROID_MINOR_RAID_INFO                 				0xa9 		/*raid�����Ϣ*/

//����־��������ΪANTS_ANDROIMAJOR_OPERATION=03��������ΪANTS_ANDROIMINOR_LOCAL_CFG_PARM=0x52����ANTS_ANDROIMINOR_REMOTE_GET_PARM=0x76����ANTS_ANDROIMINOR_REMOTE_CFG_PARM=0x77ʱ��dwParaType:����������Ч���京�����£�
#define ANTS_ANDROID_PARA_VIDEOOUT									0x1
#define ANTS_ANDROID_PARA_IMAGE										0x2
#define ANTS_ANDROID_PARA_ENCODE									0x4
#define ANTS_ANDROID_PARA_NETWORK									0x8
#define ANTS_ANDROID_PARA_ALARM										0x10
#define ANTS_ANDROID_PARA_EXCEPTION									0x20
#define ANTS_ANDROID_PARA_DECODER									0x40    	/*������*/
#define ANTS_ANDROID_PARA_RS232										0x80
#define ANTS_ANDROID_PARA_PREVIEW									0x100
#define ANTS_ANDROID_PARA_SECURITY									0x200
#define ANTS_ANDROID_PARA_DATETIME									0x400
#define ANTS_ANDROID_PARA_FRAMETYPE									0x800   	/*֡��ʽ*/
#define ANTS_ANDROID_PARA_VCA_RULE   								0x1001 	 	/*��Ϊ����*/ 
#define ANTS_ANDROID_PARA_VCA_CTRL   								0x1002		/*�������ܿ�����Ϣ*/
#define ANTS_ANDROID_PARA_VCA_PLATE  								0x1003 		/*����ʶ��*/

#define ANTS_ANDROID_PARA_CODESPLITTER 								0x2000 		/*���������*/
//!��Ƶ�ۺ�ƽ̨��־��Ϣ������
#define ANTS_ANDROID_PARA_RS485		  								0x2001		/*RS485������Ϣ*/
#define ANTS_ANDROID_PARA_DEVICE		  							0x2002		/*�豸������Ϣ*/
#define ANTS_ANDROID_PARA_HARDDISK	  								0x2003		/*Ӳ��������Ϣ */
#define ANTS_ANDROID_PARA_AUTOBOOT	  								0x2004		/*�Զ�����������Ϣ*/
#define ANTS_ANDROID_PARA_HOLIDAY	  								0x2005		/*�ڼ���������Ϣ*/			
#define ANTS_ANDROID_PARA_IPC		  								0x2006		/*IPͨ������ */	

//!ATMר��
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

//!�����豸�����붨��
#define ANTS_ANDROID_NET_DEC_STARTDEC			1
#define ANTS_ANDROID_NET_DEC_STOPDEC			2
#define ANTS_ANDROID_NET_DEC_STOPCYCLE			3
#define ANTS_ANDROID_NET_DEC_CONTINUECYCLE		4

//! �ļ��������� 
#define ANTS_ANDROID_NET_DVR_PLAYSTART					1//!��ʼ����
#define ANTS_ANDROID_NET_DVR_PLAYSTOP					2//!ֹͣ����
#define ANTS_ANDROID_NET_DVR_PLAYPAUSE					3//!��ͣ����
#define ANTS_ANDROID_NET_DVR_PLAYRESTART				4//!�ָ�����
#define ANTS_ANDROID_NET_DVR_PLAYFAST					5//!���
#define ANTS_ANDROID_NET_DVR_PLAYSLOW					6//!����
#define ANTS_ANDROID_NET_DVR_PLAYNORMAL					7//!�����ٶ�
#define ANTS_ANDROID_NET_DVR_PLAYSTARTAUDIO				9//!������
#define ANTS_ANDROID_NET_DVR_PLAYSTOPAUDIO				10//!�ر�����
#define ANTS_ANDROID_NET_DVR_PLAYSETPOS					12//!�ı��ļ��طŵĽ���

//!��������
#define ANTS_ANDROID_NET_DVR_ENCODER_UNKOWN 			0 /*δ֪�����ʽ*/
#define ANTS_ANDROID_NET_DVR_ENCODER_H264   			1 /*˽�� 264*/
#define ANTS_ANDROID_NET_DVR_ENCODER_S264  				2 /*Standard H264*/
#define ANTS_ANDROID_NET_DVR_ENCODER_MPEG4  			3 /*MPEG4*/
#define ANTS_ANDROID_NET_DVR_ORIGINALSTREAM    			4 //ԭʼ��(��Ƶ�ۺ�ƽ̨������ϵͳ��)

//! �����ʽ 
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_UNKOWN   		0  /*δ֪�����ʽ*/
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_PRIVT   		1  /*˽�и�ʽ*/
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_TS    			7  /* TS��� */
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_PS   			8  /* PS��� */
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_RTP  			9  /* RTP��� */
#define ANTS_ANDROID_NET_DVR_STREAM_TYPE_ORIGIN   		10 //δ���(��Ƶ�ۺ�ƽ̨������ϵͳ��)

//!��ʾͨ��״̬
#define ANTS_ANDROID_NET_DVR_MAX_DISPREGION 16/*ÿ����ʾͨ����������ʾ�Ĵ���*/

//!��֡�ʶ���
#define ANTS_ANDROID_LOW_DEC_FPS_1_2		51
#define ANTS_ANDROID_LOW_DEC_FPS_1_4 		52
#define ANTS_ANDROID_LOW_DEC_FPS_1_8 		53
#define ANTS_ANDROID_LOW_DEC_FPS_1_16 		54

#define ANTS_ANDROID_MAX_DECODECHANNUM   	64	//!��·������������ͨ����
#define ANTS_ANDROID_MAX_DISPCHANNUM  		64	//!��·�����������ʾͨ����

#define ANTS_ANDROID_PASSIVE_DEC_PAUSE							1/*����������ͣ(���ļ�����Ч)*/
#define ANTS_ANDROID_PASSIVE_DEC_RESUME							2/*�ָ���������(���ļ�����Ч)*/
#define ANTS_ANDROID_PASSIVE_DEC_FAST          					3/*���ٱ�������(���ļ�����Ч)*/
#define ANTS_ANDROID_PASSIVE_DEC_SLOW							4/*���ٱ�������(���ļ�����Ч)*/
#define ANTS_ANDROID_PASSIVE_DEC_NORMAL      					5/*������������(���ļ�����Ч)*/
#define ANTS_ANDROID_PASSIVE_DEC_ONEBYONE      					6/*�������뵥֡����(����)*/
#define ANTS_ANDROID_PASSIVE_DEC_AUDIO_ON 						7/*��Ƶ����*/
#define ANTS_ANDROID_PASSIVE_DEC_AUDIO_OFF						8/*��Ƶ�ر�*/
#define ANTS_ANDROID_PASSIVE_DEC_RESETBUFFER    				9/*��ջ�����(���ļ�����Ч)*/

//!�ۺ�ƽ̨�ӿں���
#define ANTS_ANDROID_MAX_SUBSYSTEM_NUM			80					//!һ������ϵͳ�������ϵͳ����
#define ANTS_ANDROID_MAX_SERIALLEN				36					//!������кų���
#define ANTS_ANDROID_MAX_LOOPPLANNUM			16					//!���ƻ��л���
#define ANTS_ANDROID_DECODE_TIMESEGMENT 		4					//!�ƻ�����ÿ��ʱ�����

//!LinkModeȡֵ��Χ
#define ANTS_ANDROID_TCP_MAINSTREAM 					(0x00000000|0)//!TCP��������ʽ
#define ANTS_ANDROID_TCP_SUBSTREAM						(0x80000000|0)//!TCP��������ʽ
#define ANTS_ANDROID_TCP_THIRDSTREAM					(0x40000000|0)//!TCP����������ʽ

#define ANTS_ANDROID_TCP_MAINSTREAM_AUTO				(0x10000000|0)//!TCP�������Զ��л���ʽ
#define ANTS_ANDROID_TCP_SUBSTREAM_AUTO					(0x90000000|0)//!TCP�������Զ��л���ʽ
#define ANTS_ANDROID_TCP_THIRDSTREAM_AUTO    			(0x50000000|0)//!TCP�������Զ��л���ʽ

#define ANTS_ANDROID_UDP_MAINSTREAM						(0x00000000|1)//!UDP��������ʽ
#define ANTS_ANDROID_UDP_SUBSTREAM						(0x80000000|1)//!UDP��������ʽ
#define ANTS_ANDROID_UDP_THIRDSTREAM					(0x40000000|1)//!UDP����������ʽ

#define ANTS_ANDROID_UDP_MAINSTREAM_AUTO				(0x10000000|1)//!UDP��������ʽ�Զ��л���ʽ
#define ANTS_ANDROID_UDP_SUBSTREAM_AUTO					(0x90000000|1)//!UDP��������ʽ�Զ��л���ʽ
#define ANTS_ANDROID_UDP_THIRDSTREAM_AUTO				(0x50000000|1)//!UDP����������ʽ�Զ��л���ʽ

#define ANTS_ANDROID_MULTI_MAINSTREAM					(0x00000000|2)//!�ಥ��������ʽ
#define ANTS_ANDROID_MULTI_SUBSTREAM					(0x80000000|2)//!�ಥ��������ʽ
#define ANTS_ANDROID_MULTI_THIRDSTREAM					(0x40000000|2)//!�ಥ����������ʽ

#define ANTS_ANDROID_MULTI_MAINSTREAM_AUTO				(0x10000000|2)//!�ಥ��������ʽ�Զ��л���ʽ
#define ANTS_ANDROID_MULTI_SUBSTREAM_AUTO				(0x90000000|2)//!�ಥ��������ʽ�Զ��л���ʽ
#define ANTS_ANDROID_MULTI_THIRDSTREAM_AUTO				(0x50000000|2)//!�ಥ����������ʽ�Զ��л���ʽ

#define ANTS_ANDROID_RTP_MAINSTREAM						(0x00000000|3)//!RTP��������ʽ
#define ANTS_ANDROID_RTP_SUBSTREAM						(0x80000000|3)//!RTP��������ʽ
#define ANTS_ANDROID_RTP_THIRDSTREAM					(0x40000000|3)//!RTP����������ʽ

#define ANTS_ANDROID_RTP_MAINSTREAM_AUTO				(0x10000000|3)//!RTP��������ʽ�Զ��л���ʽ
#define ANTS_ANDROID_RTP_SUBSTREAM_AUTO					(0x90000000|3)//!RTP��������ʽ�Զ��л���ʽ
#define ANTS_ANDROID_RTP_THIRDSTREAM_AUTO				(0x50000000|3)//!RTP����������ʽ�Զ��л���ʽ

#define ANTS_ANDROID_IW_ESSID_MAX_SIZE					32
#define ANTS_ANDROID_WIFI_WEP_MAX_KEY_COUNT				4
#define ANTS_ANDROID_WIFI_WEP_MAX_KEY_LENGTH			33
#define ANTS_ANDROID_WIFI_WPA_PSK_MAX_KEY_LENGTH		63
#define ANTS_ANDROID_WIFI_WPA_PSK_MIN_KEY_LENGTH		8
#define ANTS_ANDROID_WIFI_MAX_AP_COUNT					20

//!������ȡ����
#define ANTS_ANDROID_DEVICE_ALL_ABILITY            			0x000	//!�豸ȫ������
#define ANTS_ANDROID_DEVICE_SOFTHARDWARE_ABILITY   			0x001	//!�豸��Ӳ������
#define ANTS_ANDROID_DEVICE_NETWORK_ABILITY        			0x002	//!�豸��������
#define ANTS_ANDROID_DEVICE_ENCODE_ALL_ABILITY     			0x003	//!�豸���б�������
#define ANTS_ANDROID_DEVICE_ENCONE_CURRENT         			0x004	//!�豸��ǰ��������
#define ANTS_ANDROID_IPC_FRONT_PARAMETER					0x005	//!ipcǰ�˲���
#define ANTS_ANDROID_IPC_UPGRADE_DESCRIPTION				0x006	//!ipc������Ϣ
#define ANTS_ANDROID_VCA_DEV_ABILITY 	 					0x100	//!�豸���ܷ�����������
#define ANTS_ANDROID_VCA_CHAN_ABILITY     					0x110	//!��Ϊ��������
#define ANTS_ANDROID_MATRIXDECODER_ABILITY 					0x200	//!��·��������ʾ����������
#define ANTS_ANDROID_SNAPCAMERA_ABILITY         			0x300 	//!ץ�Ļ�������
#define ANTS_ANDROID_COMPRESSIONCFG_ABILITY  				0x400	//!��ȡѹ������������ȡ
#define ANTS_ANDROID_COMPRESSIONCFG_ABILITYEX				0x500	//!��ȡ����ѹ����������
#define ANTS_ANDROID_COMPRESSIONCFG_ABILITYEX_V2			0x600	//!��ȡ����ѹ����������(��չ����,���36-DVR/NVR)

//!�����ص�����
//!��ӦANTS_ANDROID_NET_DVR_PLATE_RESULT
#define ANTS_ANDROID_COMM_ALARM_PLATE						0x1101 //!����ʶ�𱨾���Ϣ
//!��ӦANTS_ANDROID_NET_VCA_RULE_ALARM
#define ANTS_ANDROID_COMM_ALARM_RULE						0x1102 //!��Ϊ����������Ϣ
#define ANTS_ANDROID_COMM_ALARM_PDC                 		0x1103 //!����ͳ�Ʊ�����Ϣ
#define ANTS_ANDROID_COMM_ALARM_VIDEOPLATFORM        		0x1104 //!��Ƶ�ۺ�ƽ̨����
#define ANTS_ANDROID_COMM_ALARM_AID                  		0x1110 //!��ͨ�¼�������Ϣ
#define ANTS_ANDROID_COMM_ALARM_TPS                  		0x1111 //!��ͨ����ͳ�Ʊ�����Ϣ

//!�ṹ�����궨�� 
#define ANTS_ANDROID_VCA_MAX_POLYGON_POINT_NUM				10	//!����������֧��10����Ķ����
#define ANTS_ANDROID_MAX_RULE_NUM							8	//!����������
#define ANTS_ANDROID_MAX_TARGET_NUM    						30	//!���Ŀ�����
#define ANTS_ANDROID_MAX_CALIB_PT 							6	//!���궨�����
#define ANTS_ANDROID_MIN_CALIB_PT 							4	//!��С�궨�����
#define ANTS_ANDROID_MAX_TIMESEGMENT_2	    				2	//!���ʱ�����
#define ANTS_ANDROID_MAX_LICENSE_LEN						16	//!���ƺ���󳤶�
#define ANTS_ANDROID_MAX_PLATE_NUM							3	//!���Ƹ���
#define ANTS_ANDROID_MAX_MASK_REGION_NUM					4	//!����ĸ���������
#define ANTS_ANDROID_MAX_SEGMENT_NUM						6	//!������궨�����������Ŀ
#define ANTS_ANDROID_MIN_SEGMENT_NUM						3	//!������궨��С��������Ŀ

#define ANTS_ANDROID_MAX_VCA_CHAN  							16	//!�������ͨ����

//!��Ϊ������������
#define ANTS_ANDROID_TRAVERSE_PLANE_ABILITY			0x01						//!��Խ������
#define ANTS_ANDROID_ENTER_AREA_ABILITY				0x02						//!��������
#define ANTS_ANDROID_EXIT_AREA_ABILITY				0x04						//!�뿪����
#define ANTS_ANDROID_INTRUSION_ABILITY				0x08						//!����
#define ANTS_ANDROID_LOITER_ABILITY					0x10						//!�ǻ�
#define ANTS_ANDROID_LEFT_TAKE_ABILITY				0x20						//!�������
#define ANTS_ANDROID_PARKING_ABILITY				0x40						//!ͣ��
#define ANTS_ANDROID_RUN_ABILITY					0x80						//!����
#define ANTS_ANDROID_HIGH_DENSITY_ABILITY			0x100						//!����Ա�ܶ�
#define ANTS_ANDROID_LF_TRACK_ABILITY				0x200						//!�������
#define ANTS_ANDROID_VIOLENT_MOTION_ABILITY			0x400						//!�����˶����
#define ANTS_ANDROID_REACH_HIGHT_ABILITY			0x800						//!�ʸ߼��
#define ANTS_ANDROID_GET_UP_ABILITY					0x1000						//!������
#define ANTS_ANDROID_TARRY_ABILITY					0x2000						//!��Ա����
#define ANTS_ANDROID_STICK_UP_ABILITY				0x40000000					//!��ֽ��
#define ANTS_ANDROID_INSTALL_SCANNER_ABILITY		0x80000000					//!��װ������

//!��Ϊ�����¼�����
#define ANTS_ANDROID_VCA_TRAVERSE_PLANE				0x1							//!��Խ������
#define ANTS_ANDROID_VCA_ENTER_AREA					0x2							//!Ŀ���������,֧���������
#define ANTS_ANDROID_VCA_EXIT_AREA					0x4							//!Ŀ���뿪����,֧���������
#define ANTS_ANDROID_VCA_INTRUSION					0x8							//!�ܽ�����,֧���������
#define ANTS_ANDROID_VCA_LOITER						0x10						//!�ǻ�,֧���������
#define ANTS_ANDROID_VCA_LEFT_TAKE					0x20						//!�������,֧���������
#define ANTS_ANDROID_VCA_PARKING					0x40						//!ͣ��,֧���������
#define ANTS_ANDROID_VCA_RUN						0x80						//!����,֧���������
#define ANTS_ANDROID_VCA_HIGH_DENSITY				0x100						//!��������Ա�ܶ�,֧���������
#define ANTS_ANDROID_VCA_VIOLENT_MOTION				0x200						//!�����˶����
#define ANTS_ANDROID_VCA_REACH_HIGHT				0x400						//!�ʸ߼��
#define ANTS_ANDROID_VCA_GET_UP						0x800						//!������
#define ANTS_ANDROID_VCA_TARRY						0x1000						//!��Ա����
#define ANTS_ANDROID_VCA_STICK_UP					0x40000000					//!��ֽ��,֧���������
#define ANTS_ANDROID_VCA_INSTALL_SCANNER			0x80000000					//!��װ������,֧���������

//!�����洩Խ��������
#define ANTS_ANDROID_VCA_BOTH_DIRECTION				0x00						//!˫�� 
#define ANTS_ANDROID_VCA_LEFT_GO_RIGHT				0x01						//!�������� 
#define ANTS_ANDROID_VCA_RIGHT_GO_LEFT				0x02						//!��������
 
#define ANTS_ANDROID_MAX_NET_DISK 					16							//!�������Ӳ�̸���

//!�¼�����
//!������
#define ANTS_ANDROID_EVENT_MOT_DET 					0							//!�ƶ����
#define ANTS_ANDROID_EVENT_ALARM_IN					1							//!��������
#define ANTS_ANDROID_EVENT_VCA_BEHAVIOR				2							//! ��Ϊ����
#define ANTS_ANDROID_EVENT_VCA_ITS					3							//!��ͨ�¼�     

//!��Ϊ���������Ͷ�Ӧ�Ĵ����ͣ� 0xffff��ʾȫ��
#define ANTS_ANDROID_EVENT_TRAVERSE_PLANE			0							//!��Խ������
#define ANTS_ANDROID_EVENT_ENTER_AREA				1							//!Ŀ���������,֧���������
#define ANTS_ANDROID_EVENT_EXIT_AREA				2							//!Ŀ���뿪����,֧���������
#define ANTS_ANDROID_EVENT_INTRUSION				3							//!�ܽ�����,֧���������
#define ANTS_ANDROID_EVENT_LOITER					4							//!�ǻ�,֧���������
#define ANTS_ANDROID_EVENT_LEFT_TAKE				5							//!�������,֧���������
#define ANTS_ANDROID_EVENT_PARKING					6							//!ͣ��,֧���������
#define ANTS_ANDROID_EVENT_RUN						7							//!����,֧���������
#define ANTS_ANDROID_EVENT_HIGH_DENSITY				8
#define ANTS_ANDROID_EVENT_VIOLENT_MOTION			9							//!�����˶�
#define ANTS_ANDROID_EVENT_REACH_HIGH				10							//!�ʸ�
#define ANTS_ANDROID_EVENT_GET_UP					11							//!����
#define ANTS_ANDROID_EVENT_STICK_UP					12							//!��ֽ��,֧���������
#define ANTS_ANDROID_EVENT_INSTALL_SCANNER			13							//!��װ������,֧���������
#define ANTS_ANDROID_EVENT_OBJECT_PASTE				20							//!����ճ������

#define ANTS_ANDROID_SEARCH_EVENT_INFO_LEN 300									//�¼���Ϣ����


//!�������������
#define ANTS_ANDROID_DETECTION_AREA					0							//!�������
#define ANTS_ANDROID_ENTER_AREA						1							//!��������
#define ANTS_ANDROID_MAX_DETECT_RECT 				8							//!������������

//!��������ʶ���ڲ������ؼ���
#define ANTS_ANDROID_MAX_FACE_SIZE 					20							//!���������С
#define ANTS_ANDROID_MINI_FACE_SIZE 				21							//!��С������С

//!�궨��������
#define ANTS_ANDROID_PDC_CALIBRATE					0x01						//!PDC �궨
#define ANTS_ANDROID_BEHAVIOR_OUT_CALIBRATE			0x02						//!��Ϊ���ⳡ���궨  
#define ANTS_ANDROID_BEHAVIOR_IN_CALIBRATE			0x03						//!��Ϊ���ڳ����궨 
#define ANTS_ANDROID_ITS_CALBIRETE					0x04						//!��ͨ�¼��궨

#define ANTS_ANDROID_MAX_RECT_NUM  					6
#define ANTS_ANDROID_CALIB_PT_NUM 					4

#define ANTS_ANDROID_HUMAN_GENERATE_RATE			50							//!Ŀ�������ٶ� ��50��ʼ
#define ANTS_ANDROID_DETECT_SENSITIVE				51							//!���������

#define ANTS_ANDROID_MAX_POSITION_NUM 				10
#define ANTS_ANDROID_MAX_REGION_NUM					8							//!�����б������Ŀ
#define ANTS_ANDROID_MAX_TPS_RULE					8							//!������������Ŀ
#define ANTS_ANDROID_MAX_AID_RULE					8							//!����¼�������Ŀ
#define ANTS_ANDROID_MAX_LANE_NUM					8							//!��󳵵���Ŀ

//!��ͨ�¼�����
#define ANTS_ANDROID_CONGESTION						0x01						//!ӵ��
#define ANTS_ANDROID_PARKING						0x02						//!ͣ��  
#define ANTS_ANDROID_INVERSE						0x04						//!����
#define ANTS_ANDROID_PEDESTRIAN						0x08						//!����                      
#define ANTS_ANDROID_DEBRIS							0x10						//!������ ��������Ƭ 

#define ANTS_ANDROID_FREEWAY 						0							//!��ͨ����·�� 

#define ANTS_ANDROID_ITS_CONGESTION_ABILITY				0x01					//!ӵ��
#define ANTS_ANDROID_ITS_PARKING_ABILITY				0x02					//!ͣ��  
#define ANTS_ANDROID_ITS_INVERSE_ABILITY				0x04					//!����
#define ANTS_ANDROID_ITS_PEDESTRIAN_ABILITY				0x08					//!����                      
#define ANTS_ANDROID_ITS_DEBRIS_ABILITY					0x10					//!������ ��������Ƭ
#define ANTS_ANDROID_ITS_LANE_VOLUME_ABILITY			0x010000				//!��������
#define ANTS_ANDROID_ITS_LANE_VELOCITY_ABILITY			0x020000				//!����ƽ���ٶ�
#define ANTS_ANDROID_ITS_TIME_HEADWAY_ABILITY			0x040000				//!��ͷʱ��
#define ANTS_ANDROID_ITS_SPACE_HEADWAY_ABILITY			0x080000				//!��ͷ���
#define ANTS_ANDROID_ITS_TIME_OCCUPANCY_RATIO_ABILITY	0x100000				//!����ռ���ʣ���ʱ����)
#define ANTS_ANDROID_ITS_SPACE_OCCUPANCY_RATIO_ABILITY	0x200000				//!����ռ���ʣ��ٷֱȼ��㣨�ռ���)
#define ANTS_ANDROID_ITS_LANE_QUEUE_ABILITY				0x400000				//!�Ŷӳ���

//! ��ͨͳ�Ʋ���
#define ANTS_ANDROID_LANE_VOLUME						0x01					//!��������
#define ANTS_ANDROID_LANE_VELOCITY						0x02					//!�����ٶ�
#define ANTS_ANDROID_TIME_HEADWAY						0x04					//!��ͷʱ��
#define ANTS_ANDROID_SPACE_HEADWAY						0x08					//!��ͷ���
#define ANTS_ANDROID_TIME_OCCUPANCY_RATIO				0x10					//!����ռ���� (ʱ����)
#define ANTS_ANDROID_SPACE_OCCUPANCY_RATIO				0x20					//!����ռ���ʣ��ٷֱȼ���(�ռ���)
#define ANTS_ANDROID_QUEUE								0x40					//!�Ŷӳ���

#define ANTS_ANDROID_XXX_MAJOR_VERSION      			2

//! �Ӱ汾�ţ������Ż����ֲ��ṹ������ģ���ڼ�������������汾����ʱ���������31 
#define ANTS_ANDROID_XXX_SUB_VERSION        			3

//! �����汾�ţ�����bug����������31 
#define ANTS_ANDROID_XXX_REVISION_VERSION   			4

#define ANTS_VIDEOPLATFORM_SBUCODESYSTEM_ABILITY        0x211 					//!��Ƶ�ۺ�ƽ̨������ϵͳ������

//!��ȡ�������ӿ�
#define ANTS_ANDROID_VIDEOPLATFORM_ABILITY          	0x210 					//!��Ƶ�ۺ�ƽ̨������

//!������ɫ
#define ANTS_ANDROID_VCA_BLUE_PLATE						0						//!��ɫ����
#define ANTS_ANDROID_VCA_YELLOW_PLATE					1						//!��ɫ����
#define ANTS_ANDROID_VCA_WHITE_PLATE					2						//!��ɫ����
#define ANTS_ANDROID_VCA_BLACK_PLATE					3						//!��ɫ����

//!��������
#define ANTS_ANDROID_VCA_STANDARD92_PLATE				0						//!��׼���ó������
#define ANTS_ANDROID_VCA_STANDARD02_PLATE				1						//!02ʽ���ó��� 
#define ANTS_ANDROID_VCA_WJPOLICE_PLATE					2						//!�侯�� 
#define ANTS_ANDROID_VCA_JINGCHE_PLATE					3						//!����
#define ANTS_ANDROID_STANDARD92_BACK_PLATE				4						//!���ó�˫��β��

//!�������ͼƬ���ݺ�¼�����ݣ�ֻ��һ�֣�ͼƬ����Ϊ����ͼƬ+����СͼƬ
//!���Ʊ���ANTS_ANDROID_NET_DVR_PLATE_RESULT
#define ANTS_ANDROID_COMM_UPLOAD_PLATE_RESULT			0x2800					//!�ϴ�������Ϣ

//!����������ͼƬ�����Ԫ�� 
#define ANTS_ANDROID_PICNAME_ITEM_DEV_NAME 				1/*�豸��*/
#define ANTS_ANDROID_PICNAME_ITEM_DEV_NO 				2/*�豸��*/
#define ANTS_ANDROID_PICNAME_ITEM_DEV_IP 				3/*�豸IP*/
#define ANTS_ANDROID_PICNAME_ITEM_CHAN_NAME 			4/*ͨ����*/
#define ANTS_ANDROID_PICNAME_ITEM_CHAN_NO 				5/*ͨ����*/
#define ANTS_ANDROID_PICNAME_ITEM_TIME 					6/*ʱ��*/
#define ANTS_ANDROID_PICNAME_ITEM_CARDNO				7/*����*/
#define ANTS_ANDROID_PICNAME_ITEM_PLATE_NO      		8/*���ƺ���*/
#define ANTS_ANDROID_PICNAME_ITEM_PLATE_COLOR   		9/*������ɫ*/
#define ANTS_ANDROID_PICNAME_ITEM_CAR_CHAN      		10/*������*/
#define ANTS_ANDROID_PICNAME_ITEM_CAR_SPEED     		11/*�����ٶ�*/
#define ANTS_ANDROID_PICNAME_ITEM_CARCHAN       		12/*����*/
#define ANTS_ANDROID_PICNAME_MAXITEM 					15

#define ANTS_ANDROID_IPC_PROTOCOL_NUM 					128						//!ipc Э��������

#define ANTS_ANDROID_MAX_ZEROCHAN_NUM    				16
#define ANTS_ANDROID_DESC_LEN_64 						64
#define ANTS_ANDROID_PROCESSING          				0						//!���ڴ���
#define ANTS_ANDROID_PROCESS_SUCCESS     				100						//!�������
#define ANTS_ANDROID_PROCESS_EXCEPTION   				400						//!�����쳣
#define ANTS_ANDROID_PROCESS_FAILED      				500						//!����ʧ��
#define ANTS_ANDROID_SOFTWARE_VERSION_LEN 				48
#define ANTS_ANDROID_MAX_SADP_NUM   					256 					//!�������豸�����Ŀ

//!���ݽ����б�
#define ANTS_ANDROID_BACKUP_SUCCESS                		100  //!�������
#define ANTS_ANDROID_BACKUP_SEARCH_DEVICE          		300  //!�������������豸
#define ANTS_ANDROID_BACKUP_SEARCH_FILE            		301  //!��������¼���ļ�
#define ANTS_ANDROID_BACKUP_EXCEPTION  					400  //!�����쳣
#define ANTS_ANDROID_BACKUP_FAIL						500  //!����ʧ��
#define ANTS_ANDROID_BACKUP_TIME_SEG_NO_FILE       		501  //!ʱ�������¼���ļ�
#define ANTS_ANDROID_BACKUP_NO_RESOURCE            		502  //!���벻����Դ
#define ANTS_ANDROID_BACKUP_DEVICE_LOW_SPACE       		503  //!�����豸��������
#define ANTS_ANDROID_BACKUP_DISK_FINALIZED         		504  //!��¼���̷���
#define ANTS_ANDROID_BACKUP_DISK_EXCEPTION         		505  //!��¼�����쳣
#define ANTS_ANDROID_BACKUP_DEVICE_NOT_EXIST       		506  //!�����豸������
#define ANTS_ANDROID_BACKUP_OTHER_BACKUP_WORK      		507  //!���������ݲ����ڽ���
#define ANTS_ANDROID_BACKUP_USER_NO_RIGHT          		508  //!�û�û�в���Ȩ��
#define ANTS_ANDROID_BACKUP_OPERATE_FAIL           		509  //!����ʧ��

#define ANTS_ANDROID_MAX_ABILITYTYPE_NUM  				12	 //!���������

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

//!��λ��ʾ λΪ0��ʾ��֧��  1��ʾ֧��
#define ANTS_ANDROID_RAID0_ABILITY						0x0001
#define ANTS_ANDROID_RAID1_ABILITY						0x0002
#define ANTS_ANDROID_RAID10_ABILITY						0x0004
#define ANTS_ANDROID_RAID1E_ABILITY						0x0008
#define ANTS_ANDROID_RAID5_ABILITY						0x0010
#define ANTS_ANDROID_RAID6_ABILITY						0x0020
#define ANTS_ANDROID_RAID50_ABILITY						0x0040
#define ANTS_ANDROID_JBOD_ABILITY						0x0080
#define ANTS_ANDROID_RAID60_ABILITY						0x0100

#define ANTS_ANDROID_BGA_REBUILD						0x01	//!�ؽ�
#define ANTS_ANDROID_BGA_CONSISTENCY_FIX				0x02	//!һ���Լ�鲢�޸�
#define ANTS_ANDROID_BGA_CONSISTENCY_CHECK				0x04	//!һ���Լ��
#define ANTS_ANDROID_BGA_INIT_QUICK						0x08	//!��ʼ��(��)
#define ANTS_ANDROID_BGA_INIT_BACK						0x10	//!��ʼ��(��ȫ)
#define ANTS_ANDROID_BGA_MIGRATION						0x20	//!Ǩ��
#define ANTS_ANDROID_BGA_INIT_FORE						0x40	//!��ʼ��
#define ANTS_ANDROID_BGA_COPYBACK						0x80	//!��Ǩ

#define ANTS_ANDROID_BGA_STATE_NONE						0		//!�޺�̨����
#define ANTS_ANDROID_BGA_STATE_RUNNING					1		//!��̨������������
#define ANTS_ANDROID_BGA_STATE_ABORTED					2		//!��̨����ȡ��
#define ANTS_ANDROID_BGA_STATE_PAUSED					3		//!��̨������ͣ

#define ANTS_ANDROID_MAX_INQUEST_PIP_NUM   				3	    //!��ͨ����ʾ�Ļ��л���Ŀ
#define ANTS_ANDROID_MAX_INQUEST_CDRW_NUM  				4   	//!����¼����Ŀ

#define ANTS_ANDROID_NET_DVR_SHOWLOGO					1/*��ʾLOGO*/
#define ANTS_ANDROID_NET_DVR_HIDELOGO					2/*����LOGO*/ 
#define ANTS_ANDROID_DISP_CMD_ENLARGE_WINDOW			1/*��ʾͨ���Ŵ�ĳ������*/
#define ANTS_ANDROID_DISP_CMD_RENEW_WINDOW				2/*��ʾͨ�����ڻ�ԭ*/

//!��ʶУ�� 
#define ANTS_ANDROID_NET_DVR_PDC_VERIFY_CALIBRATION				1//!��ֵΪ1��ΪPDC�궨У�� pdc����ֵΪNET_VCA_POINT   ����ֵΪ NET_VCA_RECT�ṹ
#define ANTS_ANDROID_NET_DVR_VERIFY_BEHAVIOR_CALIBRATION    	2//!��Ϊ�����궨��У�� 
#define ANTS_ANDROID_NET_DVR_VERIFY_ITS_CALIBRATION				3//!���ܽ�ͨ�궨У�� 

//!�豸����ע��궨��
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

//!Added by ItmanLee at 2013-01-25 Զ���豸������ѯ״̬
#define ANTS_ANDROID_NET_DVR_QUERY_SUCCESS 					0x0000 	//!Զ���豸��ѯ�ɹ� 
#define ANTS_ANDROID_NET_DVR_QUERY_BUSY 					0x0001	//!Զ���豸��ѯæ
#define ANTS_ANDROID_NET_DVR_QUERY_FAILED					0x0002	//!Զ���豸��ѯʧ��

//!Added by ItmanLee at 2013-08-08 Զ�̿���
#define ANTS_ANDROID_NET_DVR_CONTROL_AGENT_REPAIRMAIN         	10100 //ά��
#define ANTS_ANDROID_NET_DVR_CONTROL_AGENT_FAULTREPAIR        	10101 //���ϱ���
#define ANTS_ANDROID_NET_DVR_CONTROL_AGENT_MANUALPICTURE      	10102 //�ֶ�ͼ���ϴ�
#define ANTS_ANDROID_NET_DVR_CONTROL_MANAGERHOSTS_MAX         	19999 
#define ANTS_ANDROID_NET_DVR_CONTROL_REMOTE_ADJUSTTIME       	110
#define ANTS_ANDROID_NET_DVR_CONTROL_REMOTE_REBOOT           	111

//=========================================���������ֻ�����ģ��ʹ�� Begin======================================================
//!SDK�ӿں�������
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_Cleanup(JNIEnv* env,jobject thiz);

//!����ģ��
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_Start(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_Stop(JNIEnv* env,jobject thiz);
JNIEXPORT jint JNICALL Java_com_Activity_Discovery_GetCount(JNIEnv* env,jobject thiz);
JNIEXPORT jstring JNICALL Java_com_Activity_Discovery_GetDeviceByIndex(JNIEnv* env,jobject thiz,jint Index);
JNIEXPORT jstring JNICALL Java_com_Activity_Discovery_GetAllDevices(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_Discovery_ModifyDevice(JNIEnv* env,jobject thiz,jstring ModfiyString);
//=========================================���������ֻ�����ģ��ʹ�� End  ======================================================

//!RemoteCtrlActivity
//=========================================���������ֻ�����ģ��ʹ�� Begin=====================================================
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_Init(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_Cleanup(JNIEnv* env,jobject thiz);
JNIEXPORT jstring JNICALL Java_com_Activity_RemoteControl_Login(JNIEnv* env,jobject thiz,jstring HostIPString,jint CtrlPort,jstring UserNameString,jstring PasswordString);
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_Logout(JNIEnv* env,jobject thiz,jint UserId);
JNIEXPORT jint JNICALL Java_com_Activity_RemoteControl_GetLastError(JNIEnv* env,jobject thiz);
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_Send(JNIEnv* env,jobject thiz,jint UserId,jint Command,jbyteArray Array,jint Size);
JNIEXPORT jboolean JNICALL Java_com_Activity_RemoteControl_SendV2(JNIEnv* env,jobject thiz,jint UserId,jint Command,jint Param);
//=========================================���������ֻ�����ģ��ʹ�� End  ======================================================

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

