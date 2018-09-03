package com.example.kimkwaneung.a12_1;

import android.content.Intent;
import android.graphics.Bitmap;
import android.os.Handler;
import android.os.Message;
import android.os.Messenger;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private Handler handler = new Handler(){
        public void handleMessage(Message message){
            Object path = message.obj;
            if(message.arg1 == RESULT_OK && path != null){
                ImageView imageView = (ImageView)findViewById(R.id.imageView);
                imageView.setImageBitmap((Bitmap)path);
            }else Toast.makeText(getApplicationContext(), "다운로드 실패", Toast.LENGTH_LONG).show();
        }
    };
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClick(View view) {
        Intent intent = new Intent(this, DownloadService.class);
        Messenger messenger = new Messenger(handler);
        intent.putExtra("MESSENGER", messenger);
        intent.putExtra("urlpath", "http://java.kpu.ac.kr/image.png");
        startService(intent);
    }
}
