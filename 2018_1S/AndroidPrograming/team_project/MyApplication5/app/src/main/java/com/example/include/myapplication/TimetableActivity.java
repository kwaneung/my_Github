package com.example.include.myapplication;

import android.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class TimetableActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_timetable);

        getFragmentManager().beginTransaction().add(R.id.fragment_container, new TimeFragment()).commit();
    }

    public void onClick(View view) {
        Fragment fr = null;

        switch (view.getId()) {
            case R.id.btn1:
                fr = new TimeFragment();
                break;
            case R.id.btn2:
                fr = new CourseFragment();
                break;
        }

        getFragmentManager().beginTransaction().replace(R.id.fragment_container, fr).commit();
    }
}
