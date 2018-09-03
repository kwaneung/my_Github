package com.example.e318.practice10_2;

import android.content.Intent;
import android.graphics.Canvas;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CalendarView;

import java.util.Calendar;

public class Main2Activity extends AppCompatActivity {
    CalendarView calendarView;
    Button btn;
    private int Y, M, D;

    public Main2Activity() {
        final Calendar c = Calendar.getInstance();
        Y = c.get(Calendar.YEAR);
        M = c.get(Calendar.MONTH);
        D = c.get(Calendar.DAY_OF_MONTH);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        calendarView = (CalendarView) findViewById(R.id.cal);
        btn = (Button) findViewById(R.id.btn);
        calendarView.setOnDateChangeListener(new CalendarView.OnDateChangeListener() {
            @Override
            public void onSelectedDayChange(@NonNull CalendarView calendarView, int i, int i1, int i2) {
                Y = i;
                M = i1 + 1;
                D = i2;
            }
        });

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent();
                intent.putExtra("INPUT_TEXT", Y + "년" + M + "월" + D + "일");
                setResult(RESULT_OK, intent);
                finish();
            }
        });

    }
}
