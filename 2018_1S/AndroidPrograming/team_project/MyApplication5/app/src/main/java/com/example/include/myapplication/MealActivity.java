package com.example.include.myapplication;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.Gallery;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.PopupMenu;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.include.myapplication.R;

public class MealActivity extends AppCompatActivity {

    private static final int MENU_ID_MODIFY = Menu.FIRST;
    ListView list;
    int a = 1;

    String[] titles = {
            "BBQ 정왕점",
            "836바베큐 치킨",
            "처갓집 치킨 정왕점",
            "페리카나 정왕점",
            "계동 치킨",
            "멕시카나 치킨 정왕점",
            "노랑통닭 시흥점"
    };
    Integer[] images1 = {
            R.drawable.bbq,
            R.drawable.babeqq,
            R.drawable.ccugazip,
            R.drawable.fericana,
            R.drawable.ggadong,
            R.drawable.mexicana,
            R.drawable.yellow

    };
    String[] numbers = {
            "48245907",
            "49945412",
            "48821575",
            "48154447",
            "41887415",
            "47550567",
            "48245785"

    };
    String[] titles2 = {
            "박가부대",
            "만나고 쪽갈비가",
            "죽사랑",
            "설렁탕",
            "소공동 직화구이",
            "소꼼닭",
            "수상한 순대국 곱창볶음"
    };
    Integer[] images2 = {
            R.drawable.bbudae,
            R.drawable.ggalbi,
            R.drawable.jjuk,
            R.drawable.ssulrrungtang,
            R.drawable.ssogokdong,
            R.drawable.sogomddack,
            R.drawable.ggobchang

    };
    String[] titles3 = {
            "대박짬뽕",
            "녹색반점",
            "깐짬뽕",
            "홍짬뽕",
            "산동성",
            "영빈관",
            "귀빈관"

    };
    Integer[] images3 = {
            R.drawable.ddajjam,
            R.drawable.green,
            R.drawable.gganjjam,
            R.drawable.redjjam,
            R.drawable.sandong,
            R.drawable.youngbing,
            R.drawable.guibin
        };
    String[] titles4 = {
            "코바코",
            "돈우동",
            "장산도 횟집",
            "더 스시",
            "와르바시",
            "후지돈까스",
            "압구정돈까스"

    };
    Integer[] images4 = {
            R.drawable.cobaco,
            R.drawable.donudong,
            R.drawable.jangsando,
            R.drawable.thesusi,
            R.drawable.warubasi,
            R.drawable.huzi,
            R.drawable.apguzung
    };

    String[] numbers2 = {
            "48941245",
            "48795444",
            "15749784",
            "48774887",
            "47841534",
            "46791145",
            "48774415"

    };
    String[] numbers3 = {
            "48774547",
            "47781674",
            "48767841",
            "56781147",
            "48751267",
            "49771242",
            "16537114"

    };
    String[] numbers4 = {
            "15447841",
            "95771574",
            "44781541",
            "59871154",
            "74555151",
            "15771457",
            "41547844"

    };

    String[] workingtime1 = {
            "15:00~00:00",
            "16:00~01:00",
            "12:00~23:00",
            "12:00~21:00",
            "12:30~22:30",
            "17:00~03:00",
            "11:00~22:00"
    };
    String[] workingtime2 = {
            "10:00~20:00",
            "10:30~21:00",
            "09:00~22:00",
            "11:30~20:00",
            "11:30~22:30",
            "10:00~20:00",
            "10:00~20:00"
    };
    String[] workingtime3 = {
            "10:00~20:00",
            "10:30~21:00",
            "11:00~22:00",
            "11:30~20:00",
            "10:00~20:00",
            "10:00~20:00",
            "10:00~20:00"

    };
    String[] workingtime4 = {
            "10:30~21:00",
            "11:00~22:00",
            "11:30~20:00",
            "10:00~20:00",
            "10:00~20:00",
            "11:00~22:00",
            "11:30~20:00"

    };



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_meal);


        CustomList adapter = new CustomList(MealActivity.this);

        list = (ListView) findViewById(R.id.list);

        registerForContextMenu(list);

        findViewById(R.id.food1).setOnClickListener(mClickListener);
        findViewById(R.id.food2).setOnClickListener(mClickListener);
        findViewById(R.id.food3).setOnClickListener(mClickListener);
        findViewById(R.id.food4).setOnClickListener(mClickListener);


        list.setAdapter(adapter);

        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view,
                                    int position, long id) {

            }
        });
    }


    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        getMenuInflater().inflate(R.menu.mymenu, menu);
    }

    @Override

    public boolean onContextItemSelected(MenuItem item) {

        super.onContextItemSelected(item);
        AdapterView.AdapterContextMenuInfo menuInfo;

        int index;
        Intent intent = null;
        switch (item.getItemId()) {
            case R.id.call:
                menuInfo = (AdapterView.AdapterContextMenuInfo) item.getMenuInfo();
                index = menuInfo.position;
                if (a == 1)
                    intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:(050)" + numbers[index]));
                if (a == 2)
                    intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:(050)" + numbers2[index]));
                if (a == 3)
                    intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:(050)" + numbers3[index]));
                if (a == 4)
                    intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:(050)" + numbers4[index]));
                break;

        }
        if (intent != null) {
            startActivity(intent);
        }

        return false;
    }


    Button.OnClickListener mClickListener = new View.OnClickListener() {
        public void onClick(View v) {
            CustomList adapter = new CustomList(MealActivity.this);
            switch (v.getId()) {
                case R.id.food1:
                    a = 1;
                    break;
                case R.id.food2:
                    a = 2;
                    break;
                case R.id.food3:
                    a = 3;
                    break;
                case R.id.food4:
                    a = 4;
                    break;
                default:
                    a = 1;
            }
            list.setAdapter(adapter);
        }
    };

    public class CustomList extends ArrayAdapter<String> {
        private final Activity context;

        public CustomList(Activity context) {
            super(context, R.layout.listitem, titles);
            this.context = context;
        }

        @Override
        public View getView(int position, View view, ViewGroup parent) {
            LayoutInflater inflater = context.getLayoutInflater();
            View rowView = inflater.inflate(R.layout.listitem, null, true);
            ImageView imageView = (ImageView) rowView.findViewById(R.id.image);
            TextView title = (TextView) rowView.findViewById(R.id.title);
            TextView rating = (TextView) rowView.findViewById(R.id.rating);
            TextView genre = (TextView) rowView.findViewById(R.id.genre);
            title.setText(titles[position]);

            if (a == 1) {
                title.setText(titles[position]);
                imageView.setImageResource(images1[position]);
                rating.setText("전화번호 : " + numbers[position]);
                genre.setText(workingtime1[position]);
            }
            if (a == 2) {
                title.setText(titles2[position]);
                imageView.setImageResource(images2[position]);
                rating.setText("전화번호 : " + numbers2[position]);
                genre.setText(workingtime2[position]);
            }
            if (a == 3) {
                title.setText(titles3[position]);
                imageView.setImageResource(images3[position]);
                rating.setText("전화번호 : " + numbers3[position]);
                genre.setText(workingtime3[position]);
            }
            if (a == 4) {
                title.setText(titles4[position]);
                imageView.setImageResource(images4[position]);
                rating.setText("전화번호 : " + numbers4[position]);
                genre.setText(workingtime4[position]);
            }

            return rowView;
        }

    }


}
