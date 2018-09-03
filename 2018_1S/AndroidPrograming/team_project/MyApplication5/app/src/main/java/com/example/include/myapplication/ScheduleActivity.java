package com.example.include.myapplication;

import android.app.Dialog;
import android.app.TimePickerDialog;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CalendarView;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

class DBHelper extends SQLiteOpenHelper {
    public DBHelper(Context context) {
        super(context, "Mydb2.db", null, 8);
    }

    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table contacts( _id INTEGER PRIMARY KEY AUTOINCREMENT," +
                "date text, time text, memo text);");
    }

    public void onUpgrade(SQLiteDatabase db, int a, int b) {
        db.execSQL("drop table if exists contacts;");
        onCreate(db);
    }
}

public class ScheduleActivity extends AppCompatActivity {
    final static int TIME_DIALOG_ID = 2;
    private CalendarView calendarView;
    private EditText dateText, timeText, memoText;
    Dialog timeDialog;
    TimePicker timePicker;
    DBHelper helper;
    SQLiteDatabase db;
    TextView result;
    Button btn, btn2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_schedule);
        helper = new DBHelper(this);
        result = (TextView) findViewById(R.id.result);
        db = helper.getWritableDatabase();


        calendarView = (CalendarView) findViewById(R.id.calendarView);
        dateText = (EditText) findViewById(R.id.date);
        timeText = (EditText) findViewById(R.id.time);
        memoText = (EditText) findViewById(R.id.memotext);
        btn = (Button) findViewById(R.id.btn);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                db.execSQL("INSERT INTO contacts VALUES(null, '" + dateText.getText() + "', '" + timeText.getText() + "', '" + memoText.getText() + "');");
                Toast.makeText(ScheduleActivity.this, "예약이 완료되었습니다.", Toast.LENGTH_SHORT).show();
                dateText.setText("");
                timeText.setText("");
                memoText.setText("");

            }
        });
        btn2 = (Button) findViewById(R.id.btn2);
        btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ScheduleActivity.this, SListActivity.class);
                startActivity(intent);
            }
        });

        calendarView.setOnDateChangeListener(new CalendarView.OnDateChangeListener() {
            @Override
            public void onSelectedDayChange(@NonNull CalendarView view, int year, int month, int dayOfMonth) {
                dateText.setText("" + year + "년" + (month + 1) + "월" + dayOfMonth + "일");
            }
        });
    }

    public void onClick(View view) {
        showDialog(TIME_DIALOG_ID);
    }

    private TimePickerDialog.OnTimeSetListener mTimeSetListener = new TimePickerDialog.OnTimeSetListener() {
        @Override
        public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
            timeText.setText("" + hourOfDay + "시" + minute + "분");
        }
    };

    @Override
    protected Dialog onCreateDialog(int id) {
        switch (id) {
            case TIME_DIALOG_ID:
                return new TimePickerDialog(this, mTimeSetListener, 0, 0, false);
        }
        return null;
    }
}
