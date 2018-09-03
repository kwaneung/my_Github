package com.example.kimkwaneung.practice14;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

class MyDB extends SQLiteOpenHelper {
    public MyDB(Context context) {
        super(context, "mydb.db", null, 5);
    }

    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table data(name text, point int);");
        for (int i = 1; i <= 100; i++)
            db.execSQL("insert into data(name, point)" + "values('" + "홍길동" + i + "'," + i + "); ");
    }

    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("drop table if exists data;");
        onCreate(db);
    }
}

public class MainActivity extends AppCompatActivity {
    Button searchBTN, insertBtn, endBtn;
    TextView result;
    EditText name, point;
    MyDB dbHelper;
    SQLiteDatabase db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dbHelper = new MyDB(this);
        db = dbHelper.getWritableDatabase();

        result = (TextView) findViewById(R.id.result);
        name = (EditText) findViewById(R.id.name);
        point = (EditText) findViewById(R.id.point);

        searchBTN = (Button) findViewById(R.id.btn1);
        searchBTN.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (point.getText() == null) return;
                Cursor cursor = db.rawQuery("select name, point from data where point>=" + point.getText() + " order by point asc;", null);
                Toast.makeText(getApplicationContext(), "검색 완료", Toast.LENGTH_SHORT).show();

                String resultString = null;
                while (cursor.moveToNext()) {
                    if (resultString == null)
                        resultString = cursor.getString(0) + ":" + cursor.getInt(1) + "\n";
                    else
                        resultString += cursor.getString(0) + ":" + cursor.getInt(1) + "\n";
                }
                if (resultString != null)
                    result.setText(resultString);
            }
        });

        insertBtn = (Button) findViewById(R.id.btn2);
        insertBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                db.execSQL("insert into data(name, point)" + "values('" + name.getText() + "', " + point.getText() + ");");
                Toast.makeText(getApplicationContext(), "삽입 완료", Toast.LENGTH_SHORT).show();

                name.setText("");
                point.setText("");
            }
        });
        endBtn = (Button) findViewById(R.id.btn3);
        endBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
    }
}
