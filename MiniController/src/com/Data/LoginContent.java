package com.Data;

import java.io.Serializable;

/**
 * @Description
 * @ClassName QueryAlert
 * @author By 徐军
 * @Created 2011 2011-11-29 上午11:23:45
 */
@SuppressWarnings("serial")
public class LoginContent implements Serializable {

	private int UserId; // HTTP状态 0 表示成功，1 表示失败
	private String SerialNo;  //序列号
	private int AlarmInPortNum; //  
	private int AlarmOutPortNum; // 用户ID
	private int DiskNum; // 用户ID
	private int DVRType; // 用户ID
	private int ChanNum; // 用户ID
	private int StartChan; // 用户ID
	private int AudioChanNum; // 用户ID
	private int IPChanNum; // 用户ID
	private int ZeroChanNum; // 用户ID
	private int MainStreamProtocol; // 用户ID
	private int SubStreamProtocol; // 用户ID
	private int SupportProtocol; // 用户ID

	public int getUserId() {
		return UserId;
	}

	public void setUserId(int userid) {
		UserId = userid;
	}
	
	public String getSerialNo() {
		return SerialNo;
	}

	public void setSerialNo(String  serialno) {
		SerialNo = serialno;
	}

	public int getAlarmInPortNum() {
		return AlarmInPortNum;
	}

	public void setAlarmInPortNum(int alarminportNum) {
		AlarmInPortNum = alarminportNum;
	}
	
	public int getAlarmOutPortNum() {
		return AlarmOutPortNum;
	}

	public void setAlarmOutPortNum(int alarmoutportnum) {
		AlarmOutPortNum = alarmoutportnum;
	}
	
	public int getDiskNum() {
		return DiskNum;
	}

	public void setDiskNum(int disknum) {
		DiskNum = disknum;
	}
	
	public int getDVRType() {
		return DVRType;
	}

	public void setDVRType(int dvrtype) {
		DVRType = dvrtype;
	}
	
	public int getChanNum() {
		return ChanNum;
	}

	public void setChanNum(int channum) {
		ChanNum = channum;
	}
	
	public int getStartChan() {
		return StartChan;
	}

	public void setStartChan(int startchan) {
		StartChan = startchan;
	}
	
	public int getAudioChanNum() {
		return AudioChanNum;
	}

	public void setAudioChanNum(int audiochannum) {
		AudioChanNum = audiochannum;
	}
	
	public int getIPChanNum() {
		return IPChanNum;
	}

	public void setIPChanNum(int ipchannum) {
		IPChanNum = ipchannum;
	}
	
	public int getZeroChanNum() {
		return ZeroChanNum;
	}

	public void setZeroChanNum(int zerochannum) {
		ZeroChanNum = zerochannum;
	}
	
	public int getMainStreamProtocol() {
		return MainStreamProtocol;
	}

	public void setMainStreamProtocol(int mainstreamprotocol) {
		MainStreamProtocol = mainstreamprotocol;
	}
	
	public int getSubStreamProtocol() {
		return SubStreamProtocol;
	}

	public void setSubStreamProtocol(int substreamprotocol) {
		SubStreamProtocol = substreamprotocol;
	}
	
	public int SupportProtocol() {
		return SupportProtocol;
	}

	public void setSupportProtocol(int supportprotocol) {
		SupportProtocol = supportprotocol;
	}
	
}
