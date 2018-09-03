package com.example.include.myapplication;

import android.Manifest;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.media.Image;
import android.net.Uri;
import android.os.AsyncTask;
import android.provider.DocumentsContract;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.GridView;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;

import java.lang.annotation.Inherited;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

public class MainActivity extends AppCompatActivity {

    long mNow;
    Date mDate;
    SimpleDateFormat mFormat = new SimpleDateFormat("MM월 dd일");

    TextView mTextView;
    TextView weather;
    MyLocation location;
    ImageView weatherimage;
    ImageButton btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn = (ImageButton) findViewById(R.id.rebtn);
        mTextView = (TextView) findViewById(R.id.date);
        mTextView.setText(getTime());
        weatherimage = (ImageView) findViewById(R.id.weatherimage);
        weather = (TextView) findViewById(R.id.weather);
        location = new MyLocation(this);
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.ACCESS_FINE_LOCATION}, 1);
        } else {
            GetXMLTask task = new GetXMLTask();
            task.execute("https://www.kma.go.kr/wid/queryDFS.jsp?gridx=" + location.getLatitude(this) + "&gridy=" + location.getLongtitude(this));
        }

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                GetXMLTask task = new GetXMLTask();
                task.execute("https://www.kma.go.kr/wid/queryDFS.jsp?gridx=" + location.getLatitude(MainActivity.this) + "&gridy=" + location.getLongtitude(MainActivity.this));
                Toast.makeText(MainActivity.this, "refresh", Toast.LENGTH_SHORT).show();
            }
        });

        GridView gridView = (GridView) findViewById(R.id.GridView01);
        gridView.setAdapter(new ImageAdapter(this));
        gridView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent = null;

                switch (position) {
                    case 0:
                        Toast.makeText(MainActivity.this, "백색소음", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, SoundStudy.class);
                        startActivity(intent);
                        break;
                    case 1:
                        Toast.makeText(MainActivity.this, "일정 메모", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, ScheduleActivity.class);
                        startActivity(intent);
                        break;
                    case 2:
                        Toast.makeText(MainActivity.this, "메모장", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, TextActivity.class);
                        startActivity(intent);
                        break;
                    case 3:
                        Toast.makeText(MainActivity.this, "산기대 홈페이지", Toast.LENGTH_SHORT).show();
                        intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.kpu.ac.kr"));
                        startActivity(intent);
                        break;
                    case 4:
                        Toast.makeText(MainActivity.this, "QR 코드", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, QRScannerActivity.class);
                        startActivity(intent);
                        break;
                    case 5:
                        Toast.makeText(MainActivity.this, "지하철 노선도", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, SubActivity.class);
                        startActivity(intent);
                        break;
                    case 6:
                        Toast.makeText(MainActivity.this, "학식 추천", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, RandomActivity.class);
                        startActivity(intent);
                        break;
                    case 7:
                        Toast.makeText(MainActivity.this, "정왕 음식점", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, MealActivity.class);
                        startActivity(intent);
                        break;
                    case 8:
                        Toast.makeText(MainActivity.this, "온도 변환기", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, TempActivity.class);
                        startActivity(intent);
                        break;
                    case 9:
                        Toast.makeText(MainActivity.this, "그림판", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, DrawingActivity.class);
                        startActivity(intent);
                        break;
                    /*case 10:
                        Toast.makeText(MainActivity.this, "그림판이 선택되었습니다.", Toast.LENGTH_SHORT).show();
                        intent = new Intent(MainActivity.this, SoundStudy.class);
                        startActivity(intent);
                        break;*/

                }
            }
        });
    }

    private class GetXMLTask extends AsyncTask<String, Void, Document> {
        @Override
        protected Document doInBackground(String... urls) {
            Document doc = null;
            URL url;
            try {
                url = new URL(urls[0]);
                DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
                DocumentBuilder db = dbf.newDocumentBuilder();

                doc = db.parse(new InputSource(url.openStream()));
                doc.getDocumentElement().normalize();
            } catch (Exception e) {
            }
            return doc;
        }

        @Override
        protected void onPostExecute(Document doc) {
            String s = "";
            NodeList nodeList = doc.getElementsByTagName("data");
            Element weatherElmnt = (Element) nodeList.item(0);
            NodeList nameList = weatherElmnt.getElementsByTagName("temp");
            Element tempElement = (Element) nameList.item(0);
            NodeList contentList = tempElement.getChildNodes();

            s += "온도 : " + contentList.item(0).getNodeValue() + "\n";
            nameList = weatherElmnt.getElementsByTagName("wfKor");
            Element statusElement = (Element) nameList.item(0);
            contentList = statusElement.getChildNodes();
            s += "날씨 : " + contentList.item(0).getNodeValue();
            weather.setText(s);

            if (contentList.item(0).getNodeValue().equals("맑음")) {
                weatherimage.setImageResource(R.drawable.sun);
            } else if (contentList.item(0).getNodeValue().equals("구름 조금")) {
                weatherimage.setImageResource(R.drawable.cloud);
            } else if (contentList.item(0).getNodeValue().equals("구름 많음")) {
                weatherimage.setImageResource(R.drawable.cloud);
            } else if (contentList.item(0).getNodeValue().equals("비")) {
                weatherimage.setImageResource(R.drawable.raindrop);
            } else if (contentList.item(0).getNodeValue().equals("흐림")) {
                weatherimage.setImageResource(R.drawable.cloud);
            }
        }
    }


    private String getTime() {
        mNow = System.currentTimeMillis();
        mDate = new Date(mNow);
        return mFormat.format(mDate);
    }
}
