package com.example.e318.a180411;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageView;

/**
 * Created by E318 on 2018-04-11.
 */

public class VolumeControlView extends ImageView implements View.OnTouchListener {
    private double angle = 0.0, initAngle = 0.0, prevAngle = 0.0;
    private KnobListener listener;
    float x, mx, y, my;

    public interface KnobListener {
        public void onChanged(double angle);
    }

    public void setKnobListener(KnobListener lis) {
        listener = lis;
    }

    public VolumeControlView(Context context) {
        super(context);
        this.setImageResource(R.drawable.knob);
        this.setOnTouchListener(this);
    }

    public VolumeControlView(Context context, AttributeSet attrs) {
        super(context, attrs);
        this.setImageResource(R.drawable.knob);
        this.setOnTouchListener(this);
    }

    private double getAngle(float x, float y) {
        mx = x - (getWidth() / 2.0f);
        my = (getHeight() / 2.0f) - y;

        double degree = Math.atan2(mx, my) * 180.0 / 3.141592;
        return degree;
    }

    @Override
    public boolean onTouch(View view, MotionEvent event) {
        x = event.getX(0);
        y = event.getY(0);
        angle = getAngle(x, y);
        if (event.getAction() == MotionEvent.ACTION_DOWN) {
            initAngle = angle - prevAngle;
            angle = prevAngle;
        } else {
            angle -=initAngle;
            prevAngle = angle;
        }
        listener.onChanged(angle);
        invalidate();

        return true;
    }

    protected void onDraw(Canvas canvas) {
        Paint paint = new Paint();
        canvas.save();
        canvas.rotate((float) angle, getWidth() / 2, getHeight() / 2);
        super.onDraw(canvas);
        canvas.restore();
    }


}
