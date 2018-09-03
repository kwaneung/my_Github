package com.example.kimkwaneung.a12_1;

import android.app.Activity;
import android.app.IntentService;
import android.app.Service;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.IBinder;
import android.os.Message;
import android.os.Messenger;
import android.widget.Button;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;

public class DownloadService extends IntentService {

    private int result = Activity.RESULT_CANCELED;

    public DownloadService() {
        super("DownloadService");
    }

    @Override
    protected void onHandleIntent(Intent intent) {
        String urlPath = intent.getStringExtra("urlpath");
        Bitmap bitmap = null;

        InputStream stream = null;

        try {
            URL url= new URL(urlPath);
            stream = url.openConnection().getInputStream();
            bitmap= BitmapFactory.decodeStream(stream);

            result = Activity.RESULT_OK;
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            if (stream != null) {
                try {
                    stream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        Bundle extras = intent.getExtras();
        if (extras != null) {
            Messenger messenger = (Messenger) extras.get("MESSENGER");
            Message msg = Message.obtain();
            msg.arg1 = result;
            msg.obj = bitmap;
            try {
                messenger.send(msg);
            } catch (android.os.RemoteException e1) {

            }
        }
    }


}
