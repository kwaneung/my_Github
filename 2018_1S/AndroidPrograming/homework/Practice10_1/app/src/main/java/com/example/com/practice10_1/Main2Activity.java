package com.example.com.practice10_1;

import android.app.DatePickerDialog;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CalendarView;
import android.widget.DatePicker;

import java.util.Calendar;

public class Main2Activity extends AppCompatActivity {
    CalendarView cal;
    Button btn;

    private int mYear, mMonth, mDay;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        cal = (CalendarView) findViewById(R.id.calender);
        btn = (Button) findViewById(R.id.btn);

        Intent intent = getIntent();
        String name = intent.getStringExtra("INPUT_NAME");
        btn.setText(name + " 생일을 설정");
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent();
                intent.putExtra("INPUT_TEXT", mYear + "년" + mMonth + "월" + mDay);
                setResult(RESULT_OK, intent);
                finish();
            }
        });

        cal.setOnDateChangeListener(new CalendarView.OnDateChangeListener() {
            @Override
            public void onSelectedDayChange(@NonNull CalendarView calendarView, int i, int i1, int i2) {
                mYear = i;
                mMonth = i1 + 1;
                mDay = i2;
            }
        });
    }


}
