package com.example.com.practice10_1;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    static final int COMMAND = 1;
    TextView text, name;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        text = (EditText)findViewById(R.id.birth);
        name = (EditText)findViewById(R.id.name);
        Button b = (Button)findViewById(R.id.btn);
        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, Main2Activity.class);
                intent.putExtra("INPUT_NAME", name.getText().toString());
                setResult(RESULT_OK, intent);
                startActivityForResult(intent, COMMAND);
            }
        });
    }
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        if (requestCode == COMMAND) {
            if (resultCode == RESULT_OK) {
                text.setText(data.getStringExtra("INPUT_TEXT"));
            }
        }
    }

}
