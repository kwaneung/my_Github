package com.example.kimkwaneung.practice_9;

import android.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        getFragmentManager().beginTransaction().add(R.id.fragment_container, new AFragment()).commit();
    }

    public void selectFragment(View view) {
        Fragment fr = null;

        switch (view.getId()) {
            case R.id.btn1:
                fr = new AFragment();
                break;
            case R.id.btn2:
                fr = new BFragment();
                break;
        }

        getFragmentManager().beginTransaction().replace(R.id.fragment_container, fr).commit();
    }
}
