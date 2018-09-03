package com.example.kimkwaneung.processbartest;

import android.app.ProgressDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private ProgressDialog progress;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        progress = new ProgressDialog(this);
    }

    public void start(View view) {
        progress.setCancelable(true);
        progress.setMessage("네트워크에서 다운로드 중입니다. ");
        progress.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
        progress.setProgress(0);
        progress.setMax(100);
        progress.show();

        final Thread t = new Thread(){
            @Override
            public void run() {
                int time = 0;
                while (time < 100) {
                    try {
                        sleep(40);
                        time += 1;
                        progress.setProgress(time);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                progress.cancel();
            }
        };
        t.start();
    }
}
