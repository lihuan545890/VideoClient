package com.Utility;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Serializable;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.List;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.CookieStore;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.cookie.Cookie;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;
import android.util.Log;

public class HttpUtil {

	private static final String TAG = null;

	public static CookieStore mCookieStore;

	/*
	 * Anthor xujun function
	 * 
	 * HttpGet 鏂规硶
	 */

	public static String getDataByHttpGet(String httpUrl) {

		String result = null;

		HttpGet httpGet = new HttpGet(httpUrl);

		HttpClient httpClient = new DefaultHttpClient();

		try {

			HttpResponse httpResponse = httpClient.execute(httpGet);

			if (httpResponse.getStatusLine().getStatusCode() == HttpStatus.SC_OK)

			{

				result = EntityUtils.toString(httpResponse.getEntity());

				Log.v("HttpGet", result);

			}

			else

			{

				Log.v("HttpGet", "HttpGet has exception.");

			}

		} catch (ClientProtocolException e) {

			// TODO Auto-generated cat7ch block

			e.printStackTrace();

		} catch (IOException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();

		}

		return result;

	}

	/**
	 * HttpGet
	 * 
	 * @author xj
	 * 
	 */
	public static String HttpGetHandle(String httpUrl) {

		String result = "";

		DefaultHttpClient httpclient = new DefaultHttpClient();
		HttpGet httpget = new HttpGet(httpUrl);

		try {
			System.out.println("寮�鎵ц");

			HttpResponse response = httpclient.execute(httpget);
			HttpEntity entity = response.getEntity();
			System.out.println("鎵ц瀹屾瘯");
//			System.out.println("HTTP 杩斿洖鐘舵�锛�
//					+ response.getStatusLine().getStatusCode());
			if (response.getStatusLine().getStatusCode() == HttpStatus.SC_OK) {
				result = EntityUtils.toString(response.getEntity());
				if (entity != null) {
					entity.consumeContent();
					// com.BLL.HandleHttpBLL.mCookieStore=httpclient.getCookieStore();
					mCookieStore = httpclient.getCookieStore();
					List<Cookie> cookies = httpclient.getCookieStore()
							.getCookies();
					if (entity != null) {
						entity.consumeContent();
					}
					if (cookies.isEmpty()) {
						Log.i(TAG, "NONE");
					} else {
						System.out.println(cookies.size());

						for (int i = 0; i < cookies.size(); i++) {
							System.out
									.println("- " + cookies.get(i).toString());
						}
					}
				}

				httpclient.getConnectionManager().shutdown();

				Log.v("HttpGet", result);

			} else {
				Log.v("HttpGet", "HttpGet has exception.");
			}

		} catch (ClientProtocolException e) {

			// TODO Auto-generated cat7ch block

			e.printStackTrace();

		} catch (IOException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();

		}

		return result;

	}

	public static String getDataByHttpPostTest(String httpUrl, String base64) {
		String result = null;
		DefaultHttpClient httpclient = new DefaultHttpClient();
		HttpPost httpPost = new HttpPost(httpUrl);
		httpclient.setCookieStore(mCookieStore);
		httpPost.setHeader("Content-Type", "text/xml");
		try {
			StringEntity httpPostEntity = new StringEntity(base64, "UTF-8");
			httpPost.setEntity(httpPostEntity);
			HttpResponse response = httpclient.execute(httpPost);
			System.out.println("鎴愬姛鍙戦�");

			int code = response.getStatusLine().getStatusCode();
			System.out.println(" httpPost杩斿洖鍊�" + code);
			if (code == HttpStatus.SC_OK) {
				result = EntityUtils.toString(response.getEntity());

				Log.v("HttpPost 鎴愬姛杈撳嚭", result);
			} else {
				result = "1";
				Log.v("HttpPost", "HttpPost has exception.");
			}

		} catch (UnsupportedEncodingException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();
			System.out.println(e.toString());

		} catch (ClientProtocolException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();
			System.out.println(e.toString());

		} catch (IOException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();
			System.out.println(e.toString());

		}

		return result;

	}

	/**
	 * HttpPost 鏂规硶
	 * 
	 * @author xj
	 * 
	 */
	public static String getDataByHttpPost(String httpUrl,
			List<NameValuePair> params, String base64) {
		String result = null;

		HttpPost httpPost = new HttpPost(httpUrl);
		httpPost.setHeader("Content-Type", "text/xml");

		try {
			StringEntity httpPostEntity = new StringEntity(base64, "UTF-8");
			httpPost.setEntity(httpPostEntity);
			HttpClient httpClient = new DefaultHttpClient();
			HttpResponse response;
			response = httpClient.execute(httpPost);
			System.out.println("鎴愬姛鍙戦�");

			int code = response.getStatusLine().getStatusCode();
			System.out.println(" httpPost杩斿洖鍊�" + code);
			if (code == HttpStatus.SC_OK) {
				result = EntityUtils.toString(response.getEntity());

				Log.v("HttpPost 鎴愬姛杈撳嚭", result);
			} else {
				Log.v("HttpPost", "HttpPost has exception.");
			}

		} catch (UnsupportedEncodingException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();
			System.out.println(e.toString());

		} catch (ClientProtocolException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();
			System.out.println(e.toString());

		} catch (IOException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();
			System.out.println(e.toString());

		}

		return result;

	}

	public String Refesh(String httpUrl) {

		String result = null;

		try {

			URL url = new URL(httpUrl);

			HttpURLConnection urlConn = (HttpURLConnection) url
					.openConnection();

			urlConn.connect();

			InputStream input = urlConn.getInputStream();

			InputStreamReader inputReader = new InputStreamReader(input);

			BufferedReader reader = new BufferedReader(inputReader);

			String str = null;

			StringBuffer sb = new StringBuffer();

			while ((str = reader.readLine()) != null)

			{

				sb.append(str).append("/n");

			}

			result = sb.toString();

		} catch (MalformedURLException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();

		} catch (IOException e) {

			// TODO Auto-generated catch block

			e.printStackTrace();

		}

		return result;

	}

	public class SerializedCookie implements Serializable {

		private static final long serialVersionUID = 5327445113190674523L; // arbitrary

		private String name;
		private String value;
		private String domain;

		public SerializedCookie(Cookie cookie) {
			this.name = cookie.getName();
			this.value = cookie.getValue();
			this.domain = cookie.getDomain();
		}

		public String getName() {
			return name;
		}

		public String getValue() {
			return value;
		}

		public String getDomain() {
			return domain;
		}
	}

}
