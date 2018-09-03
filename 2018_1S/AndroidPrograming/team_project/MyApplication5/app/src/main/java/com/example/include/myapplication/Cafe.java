package com.example.include.myapplication;

import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.IBinder;
import android.util.Log;
import android.widget.Toast;

public class Cafe extends Service {

    private static final String TAG = "Cafe";
    MediaPlayer player;
    public Cafe() {
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
    @Override
    public void onCreate(){
        Log.d(TAG, "onCreate");
        player = MediaPlayer.create(this, R.raw.cafesoundcut);
        player.setLooping(true);
    }
    @Override
    public void onDestroy() {
        Toast.makeText(this, "음악종료", Toast.LENGTH_SHORT).show();
        player.stop();

    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startID) {
        Toast.makeText(this, "음악시작", Toast.LENGTH_SHORT).show();
        player.start();
        return super.onStartCommand(intent, flags, startID);

    }
}
