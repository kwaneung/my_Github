package com.example.e318.myapplication;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.RectF;
import android.graphics.Typeface;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.util.TimeUtils;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

class MyView extends View {
    int x = 0;
    Bitmap b,mb;
    Matrix m = new Matrix();

    public MyView(Context context) {
        super(context);
        b = BitmapFactory.decodeResource(getResources(), R.drawable.house);    //집 비트맵  mb와 b 만듦
        mb = b;
        m.preScale(1, -1);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        Paint paint = new Paint();
        if (x > 300) {                                      //크기가 300에 도달하면 크기를 0으로 초기화 하고 b를 mb를 다시 그려준다.
            x = 0;
            mb = Bitmap.createBitmap(mb, 0, 0, b.getWidth(), b.getHeight(), m, false);
        }
        x += 3;
        Bitmap kb = Bitmap.createScaledBitmap(mb, x, x, false);//mb의 크기를 키워서 kb로 다시 그려준다
        canvas.drawBitmap(kb, 100, 100, null);
        canvas.drawBitmap(b, 0, 0, null);

        invalidate();
    }
}

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new MyView(this));
    }
}
