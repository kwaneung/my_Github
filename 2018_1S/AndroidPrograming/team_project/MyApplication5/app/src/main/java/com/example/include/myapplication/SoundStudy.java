package com.example.include.myapplication;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class SoundStudy extends AppCompatActivity  implements View.OnClickListener{

    Button fire,forest,cafe, rain,countbutton;
    TextView studytime;
    MediaPlayer a1,a2,a3,a4;
    String timer;
    int a= 1;
    int b= 1;
    int c =1;
    int d =1;
    int e =1;
    int myCount=1;
    long myBaseTime;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sound_study);

        countbutton = (Button) findViewById(R.id.countbt);
        fire = (Button) findViewById(R.id.firesound);
        forest = (Button) findViewById(R.id.forestsound);
        cafe = (Button) findViewById(R.id.cafesound);
        rain = (Button) findViewById(R.id.rainsound);
        studytime = (TextView) findViewById(R.id.time_out);

        fire.setOnClickListener(this);
        forest.setOnClickListener(this);
        cafe.setOnClickListener(this);
        rain.setOnClickListener(this);

    }


    @Override
    public void onClick(View v) {

        switch (v.getId()) {
            case R.id.firesound:
                if(a==1) {
                    a=0;

                    //stopService(new Intent(this, Cafe.class));
                    // stopService(new Intent(this, Rain.class));
                    // stopService(new Intent(this, Forest.class));
                    startService(new Intent(this, Fire.class));


                    fire.setText("장작 소리 종료");
                    break;
                }
                if(a==0){
                    a=1;

                    stopService(new Intent(this, Fire.class));
                    fire.setText("장작 소리");
                    break;
                }

            case R.id.forestsound:
                if(b==1) {
                    b=0;

                    // stopService(new Intent(this, Cafe.class));
                    // stopService(new Intent(this, Rain.class));
                    // stopService(new Intent(this, Fire.class));
                    startService(new Intent(this, Forest.class));
                    forest.setText("숲 소리 종료");
                    break;
                }
                if(b==0){
                    b=1;

                    stopService(new Intent(this, Forest.class));
                    forest.setText("숲 소리");
                    break;
                }

            case R.id.cafesound:
                if(c==1) {
                    c=0;

                    // stopService(new Intent(this, Fire.class));
                    // stopService(new Intent(this, Rain.class));
                    // stopService(new Intent(this, Forest.class));
                    startService(new Intent(this, Cafe.class));
                    cafe.setText("카페 소리 종료");
                    break;
                }
                if(c==0){
                    c=1;

                    stopService(new Intent(this, Cafe.class));
                    cafe.setText("카페 소리");
                    break;
                }

            case R.id.rainsound:
                if(d==1) {
                    d=0;

                    //stopService(new Intent(this, Cafe.class));
                    //stopService(new Intent(this, Fire.class));
                    // stopService(new Intent(this, Forest.class));
                    startService(new Intent(this, Rain.class));
                    rain.setText("비오는 소리 종료");
                    break;
                }
                if(d==0){
                    d=1;

                    stopService(new Intent(this, Rain.class));
                    rain.setText("비오는 소리");
                    break;
                }

            default:
                break;

        }

    }

    public void CountDown(View V) {


        if (e==1) {
            myBaseTime = SystemClock.elapsedRealtime();
            System.out.println(myBaseTime);
            //myTimer이라는 핸들러를 빈 메세지를 보내서 호출
            myTimer.sendEmptyMessage(0);
            getTimeOut();

            countbutton.setText("공부 끝");
            e=0;

        }
        else{

            e=1;
            countbutton.setText("공부 시작");
            myTimer.removeMessages(0);
            Toast.makeText(this,"당신이 공부한시간 : "+ timer,Toast.LENGTH_SHORT).show();
            studytime.setText("00:00:00");
            getTimeOut();

        }



    }

    Handler myTimer = new Handler(){
        public void handleMessage(Message msg){
            studytime.setText(getTimeOut());

            //sendEmptyMessage 는 비어있는 메세지를 Handler 에게 전송하는겁니다.
            myTimer.sendEmptyMessage(0);
        }
    };
    //현재시간을 계속 구해서 출력하는 메소드
    String getTimeOut(){
        long now = SystemClock.elapsedRealtime();
        long outTime = now - myBaseTime;
        String easy_outTime = String.format("%02d:%02d:%02d", outTime/1000 / 3600, (outTime/1000)/60,(outTime/1000)%60);
        timer = easy_outTime;
        return easy_outTime;

    }
}


