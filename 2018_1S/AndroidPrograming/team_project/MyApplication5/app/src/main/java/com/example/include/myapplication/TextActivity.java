package com.example.include.myapplication;

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
        super(context, "Mydb.db", null, 7);
    }

    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table data(idx int, memo text);");
    }

    public void onUpgrade(SQLiteDatabase db, int a, int b) {
        db.execSQL("drop table if exists data;");
        onCreate(db);
    }
}
public class TextActivity extends AppCompatActivity {

    Button insertBtn, deleteBtn;
    EditText idx, memo;
    MyDB Helper;
    SQLiteDatabase db;
    TextView result;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_text);

        Helper = new MyDB(this);
        db = Helper.getWritableDatabase();
        result = (TextView) findViewById(R.id.result);
        idx = (EditText) findViewById(R.id.idx);
        memo = (EditText) findViewById(R.id.memo);
        Cursor cursor = db.rawQuery("select idx, memo from data order by idx asc;", null);

        String resultString = null;
        while (cursor.moveToNext()) {
            if (resultString == null)
                resultString = cursor.getInt(0) + ":" + cursor.getString(1) + "\n";
            else
                resultString += cursor.getInt(0) + ":" + cursor.getString(1) + "\n";
        }
        if (resultString != null)
            result.setText(resultString);



        insertBtn = (Button) findViewById(R.id.insert);
        insertBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                db.execSQL("insert into data(idx, memo)" + "values(" + idx.getText() + ", '" + memo.getText() + "');");
                Toast.makeText(getApplicationContext(), "삽입 완료", Toast.LENGTH_SHORT).show();

                idx.setText("");
                memo.setText("");

                Cursor cursor = db.rawQuery("select idx, memo from data order by idx asc;", null);

                String resultString = null;
                while (cursor.moveToNext()) {
                    if (resultString == null)
                        resultString = cursor.getInt(0) + ": " + cursor.getString(1) + "\n";
                    else
                        resultString += cursor.getInt(0) + ": " + cursor.getString(1) + "\n";
                }
                if (resultString != null)
                    result.setText(resultString);
            }
        });

        deleteBtn = (Button) findViewById(R.id.delete);
        deleteBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                db.execSQL("delete from data where idx == " + idx.getText() + ";");
                Toast.makeText(getApplicationContext(), "삭제 완료", Toast.LENGTH_SHORT).show();

                idx.setText("");
                memo.setText("");

                Cursor cursor = db.rawQuery("select idx, memo from data order by idx asc;", null);

                String resultString = null;
                while (cursor.moveToNext()) {
                    if (resultString == null)
                        resultString = cursor.getInt(0) + ":" + cursor.getString(1) + "\n";
                    else
                        resultString += cursor.getInt(0) + ":" + cursor.getString(1) + "\n";
                }
                if (resultString != null)
                    result.setText(resultString);
            }
        });
    }
}
