package com.example.include.myapplication;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.drawable.Drawable;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.View;

public class MyImageView extends View {
    private Drawable image;
    private ScaleGestureDetector gestureDetector;
    private float scale = 1.0f;

    public MyImageView(Context context) {
        super(context);
        image = context.getResources().getDrawable(R.drawable.subway);
        setFocusable(true);
        image.setBounds(0, 0, image.getIntrinsicWidth(), image.getIntrinsicHeight());
        gestureDetector = new ScaleGestureDetector(context, new ScaleListener());
    }

    private int x = 0, y = 0;

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        canvas.save();
        canvas.translate(x - image.getIntrinsicWidth() / 2 * scale, y - image.getIntrinsicHeight() / 2 * scale);
        canvas.scale(scale, scale);
        image.draw(canvas);
        canvas.restore();
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        switch (event.getAction()) {
            case MotionEvent.ACTION_DOWN:
            case MotionEvent.ACTION_MOVE:
                x = (int) event.getX(0);
                y = (int) event.getY(0);
        }

        gestureDetector.onTouchEvent(event);
        invalidate();
        return true;
    }

    public class ScaleListener extends ScaleGestureDetector.SimpleOnScaleGestureListener {
        @Override
        public boolean onScale(ScaleGestureDetector detector) {
            scale *= detector.getScaleFactor();

            if (scale < 0.1f)
                scale = 0.1f;
            if (scale > 10.0f)
                scale = 10.0f;
            invalidate();
            return true;
        }
    }

}
