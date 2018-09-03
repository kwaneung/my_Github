package com.example.e318.a180411;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class Main3Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);

        VolumeControlView view = (VolumeControlView) findViewById(R.id.vol);
        view.setKnobListener(new VolumeControlView.KnobListener() {
            @Override
            public void onChanged(double angle) {
                if (angle > 0)
                    ;
                else
                    ;
            }
        });
    }
}
