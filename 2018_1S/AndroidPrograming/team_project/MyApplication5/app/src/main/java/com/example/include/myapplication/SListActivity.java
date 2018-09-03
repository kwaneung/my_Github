package com.example.include.myapplication;

        import android.database.Cursor;
        import android.database.sqlite.SQLiteDatabase;
        import android.support.v7.app.AppCompatActivity;
        import android.os.Bundle;
        import android.view.View;
        import android.widget.EditText;
        import android.widget.ListView;
        import android.widget.SimpleCursorAdapter;
        import android.widget.TextView;

        import org.w3c.dom.Text;

        import java.util.List;

public class SListActivity extends AppCompatActivity {
    DBHelper helper;
    SQLiteDatabase db;
    EditText num;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_slist);


        ListView list = (ListView) findViewById(R.id.list);

        num = (EditText) findViewById(R.id.num);
        helper = new DBHelper(this);
        db = helper.getWritableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM contacts", null);
        cursor.moveToFirst();

        startManagingCursor(cursor);

        String[] from = new String[]{"_id","date","time" , "memo"};
        int[] to = new int[] {R.id.id,R.id.sdate, R.id.stime, R.id.smemo};
        SimpleCursorAdapter adapter = new SimpleCursorAdapter(list.getContext(),R.layout.memolist, cursor, from, to);

        list.setAdapter(adapter);
    }

    public void onDel(View view) {
        db.execSQL("delete from contacts where _id == " + num.getText() + ";");

        Cursor cursor = db.rawQuery("SELECT * FROM contacts", null);

        ListView list = (ListView) findViewById(R.id.list);
        startManagingCursor(cursor);

        String[] from = new String[]{"_id","date","time" , "memo"};
        int[] to = new int[] {R.id.id,R.id.sdate, R.id.stime, R.id.smemo};
        SimpleCursorAdapter adapter = new SimpleCursorAdapter(list.getContext(),R.layout.memolist, cursor, from, to);

        list.setAdapter(adapter);
        num.setText("");
    }
}
