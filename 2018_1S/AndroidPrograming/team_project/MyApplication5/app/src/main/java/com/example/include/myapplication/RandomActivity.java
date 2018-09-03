package com.example.include.myapplication;

import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

public class RandomActivity extends AppCompatActivity {

    String[] korearice={
            "소고기비빔밥 set",
            "안동찜닭",
            "두부김치정식",
            "철판불고기쌈밥",
            "연탄불고기",
            "청양불고기",
            "뚝불고기",
            "철판참치김치덮밥",
            "돌솣닭갈비",
            "돌솣제육덮밥",
            "닭갈비덮밥",
            "철판쭈꾸미삼겹살",
            "치즈베이컨김치볶은밥",
            "목살스테이크 덮밥",
            "치즈불고기볶은밥",
            "돼지주물럭",
            "참치비빔밥",
            "삼겹살강된장비빔밥"
            ,"우삼겹숙주덮밥"
            ,"매운참치비빔밥"
    };

    String[] koreanoodle={
            "물냉면",
            "비빔냉면",
            "냉쫄면",
            "콩국수",
            "초계막국수",
            "초계 비빔국수",
            "고기국수"

    };
    String[] koreasoup={
            "갈비탕",
            "부대찌개",
            "김치찌개",
            "차돌된장찌개",
            "순대국",
            "뼈해장국",
            "참치김치만두찌개",
            "모둠수제비",
            "김치찌개돈까스"
    };
    String[] japanrice={
            "매콤치킨커리",
            "카레 제육덮밥"
            ,"양념감자오믈렛"
            ,"갈릭함박스테이크 오믈렛",
            "치킨볼오믈렛",
            "불닭 오믈렛"
            ,"돈도리 볶은밥"
            ,"소고기 필라프 ",
            "소금구이 덮밥",
            "치즈오븐치킨라이스",
            "불닭치즈도리아",
            "등심돈까스",
            "갈릭양파돈까스",
            "다꼬야끼치킨덮밥",
            "커리미야자키치킨덮밥",
            "부타동",
            "참치회덮밥",
            "돈카츠벤또"


    };

    String[] japannoodle={
            "해물미트스파게티",
            "우동",
            "냉모밀",
            "비빔모밀",
            "해물야끼우동"

    };
    String[] japansoup={
            "우동",
            "냉모밀"
    };
    String[] chinarice={
            "목살스테이크 덮밥",
            "대패 삼겹덮밥",
            "쉐프치킨 덮밥",
            "철판 낚지덮밥",
            "뚝 날치알밥"
            ,"궁보찜닭"
            ,"탕수육 세트"
            ,"쉐프치킨 세트"
            ,"왕난자완스덮밥"
            ,"쮸~덮밥"
            ,"우쮸~덮밥"

    };

    String[] chinanoodle={
            "짜장면",
            "소고기 쌀국수"
            ,"크림 짬뽕"
            ,"짬뽕"
            ,"짬 짜 면"
            ,"짜장면"
            ,"빨간당면"


    };
    String[] chinasoup={
            "짬뽕",
            "짬짜면",
            "크림 짬뽕",


    };

    String a ="";
    String b ="";

    RadioGroup koreadGroup;
    Button randombt;
    TextView recommend;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_random);



    }

    public void onRadioButtonClicked(View view) {
        boolean checked = ((RadioButton)view).isChecked();
        koreadGroup = (RadioGroup)findViewById(R.id.korea);
        koreadGroup.setVisibility(View.VISIBLE);
        switch (view.getId()) {
            case R.id.foodkorea :
                if (checked)
                    a="korea";
                break;
            case R.id.foodchina :
                if (checked)
                    a="china";
                break;
            case R.id.foodjapan :
                if (checked)
                    a="japan";
                break;
        }




    }
    public void onRadioButtonClicked2(View view) {
        boolean checked = ((RadioButton)view).isChecked();
        randombt = (Button) findViewById(R.id.random);
        randombt.setVisibility(View.VISIBLE);
        switch (view.getId()) {
            case R.id.rice :
                if (checked)
                    b="rice";
                break;
            case R.id.noodle :
                if (checked)
                    b="noodle";
                break;
            case R.id.soup :
                if (checked)
                    b="soup";
                break;
        }
    }

    public void onClick(View view) {
        Intent intent = new Intent(Intent.ACTION_VIEW,
                Uri.parse("http://ibook.kpu.ac.kr/Viewer/1SG81F7PEI5Z"));
        startActivity(intent);
    }
    public void onClick2(View view) {
        Intent intent = new Intent(Intent.ACTION_VIEW,
                Uri.parse("http://ibook.kpu.ac.kr/Viewer/YP7504RLX8E6"));
        startActivity(intent);
    }
    public void onClick3(View view) {
        recommend = (TextView) findViewById(R.id.recommend);
        int randomNum;
        String c;
        c = a+b;


        if(c.equals("korearice")){
            randomNum = (int) (Math.random() * korearice.length);
            recommend.setText(korearice[randomNum]);
            return;
        }
        if(c.equals("koreanoodle")){
            randomNum = (int) (Math.random() * koreanoodle.length);
            recommend.setText(koreanoodle[randomNum]);
            return;
        }
        if(c.equals("koreasoup")){
            randomNum = (int) (Math.random() * koreasoup.length);
            recommend.setText(koreasoup[randomNum]);
            return;
        }
        if(c.equals("chinarice")){
            randomNum = (int) (Math.random() * chinarice.length);
            recommend.setText(chinarice[randomNum]);
            return;
        }
        if(c.equals("japannoodle")){
            randomNum = (int) (Math.random() * japannoodle.length);
            recommend.setText(japannoodle[randomNum]);
            return;
        }
        if(c.equals("japansoup")){
            randomNum = (int) (Math.random() * japansoup.length);
            recommend.setText(japansoup[randomNum]);
            return;
        }
        if(c.equals("japanrice")){
            randomNum = (int) (Math.random() * japanrice.length);
            recommend.setText(japanrice[randomNum]);
            return;
        }
        if(c.equals("chinanoodle")){
            randomNum = (int) (Math.random() * chinanoodle.length);
            recommend.setText(chinanoodle[randomNum]);
            return;
        }
        if(c.equals("chinasoup")){
            randomNum = (int) (Math.random() * chinasoup.length);
            recommend.setText(chinasoup[randomNum]);
            return;
        }


    }


}