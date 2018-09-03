package com.example.e318.pingpong;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Display;

class Ball {
    int x, y, xInc = 1, yInc = 1;
    int radius;
    static int WIDTH = 1080, HEIGHT = 1920;

    public Ball() {
        radius = WIDTH / 40;

        x = (int) (Math.random() * (WIDTH - radius));
        y = (int) (Math.random() * (HEIGHT - radius));
        x = x < radius ? radius : x;
        y = y < radius ? radius : y;

        xInc = (int) (Math.random() * 30 + 1);
        yInc = (int) (Math.random() * 30 + 1);
    }

    public void paint(Canvas canvas) {
        Paint paint = new Paint();

        if (x < radius || x > (WIDTH - radius))
            xInc = -xInc;
        if (y < radius || y > (HEIGHT - radius))
            yInc = -yInc;

        x += xInc;
        y += yInc;

        paint.setColor(Color.RED);
        canvas.drawCircle(x, y, radius, paint);
    }
}

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Display display = getWindowManager().getDefaultDisplay();
        Point size = new Point();
        display.getSize(size);
        Ball.WIDTH = size.x;
        Ball.HEIGHT = size.y;

        setContentView(new MySurfaceView(this));
    }
}
