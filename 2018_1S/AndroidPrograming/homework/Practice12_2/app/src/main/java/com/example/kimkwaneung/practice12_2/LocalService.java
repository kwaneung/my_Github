package com.example.kimkwaneung.practice12_2;

import android.app.Service;
import android.content.Intent;
import android.os.Binder;
import android.os.IBinder;

import java.util.Random;

public class LocalService extends Service {
    Thread counter;
    int mCount = 0;
    boolean bCount = true;

    private final IBinder mBinder = new LocalBinder();

    public class LocalBinder extends Binder {
        LocalService getService() {
            return LocalService.this;
        }
    }

    @Override
    public IBinder onBind(final Intent intent) {
        counter = new Thread(new Runnable() {
            @Override
            public void run() {
                while (bCount) {
                    try {
                        Thread.sleep(1000);
                        mCount++;
                        if (mCount % 5 == 0) {
                            Intent intent = new Intent();
                            intent.setAction("C");
                            intent.putExtra("COUNT", mCount);
                            sendBroadcast(intent);
                        }
                    } catch (Exception e) {
                    }
                }
            }
        });
        counter.start();

        return mBinder;
    }

    @Override
    public boolean onUnbind(Intent intent) {
        bCount = false;
        return super.onUnbind(intent);
    }

    public int getCount() {
        return mCount;
    }
}
