package com.Data;

/**
 * @Description Initia video info by video filename
 * @ClassName video
 * @author By 徐军
 * @Created 2013 2013-11-15 上午11:23:45
 */
public class ResultVideo {
	private int Channel; // 通道
	private String StartTime;  //开始时间
	private String StopTime; //结束时间
	private int FileSize; // 文件大小
	private String FileName; // 文件名
	private String ShowFileFile;//列表显示时间
	 

	public int getChannel() {
		return Channel;
	}

	public void setChannel(int channel) {
		this.Channel = channel;
	}
	
	public String getStartTime() {
		return StartTime;
	}

	public void setStartTime(String  starttime) {
		this.StartTime = starttime;
	}

	public String getStopTime() {
		return StopTime;
	}

	public void setStopTime(String stoptime) {
		this.StopTime = stoptime;
	}
	
	public int getFileSize() {
		return FileSize;
	}

	public void setFileSize(int filesize) {
		this.FileSize = filesize;
	}
	
	public String getFileName() {
		return FileName;
	}

	public void setFileName(String fileName) {
		this.FileName = fileName;
	}
	
	public String getShowFileFile() {
		return ShowFileFile;
	}

	public void setShowFileName(String showfilename) {
		this.ShowFileFile = showfilename;
	}
 	
}
