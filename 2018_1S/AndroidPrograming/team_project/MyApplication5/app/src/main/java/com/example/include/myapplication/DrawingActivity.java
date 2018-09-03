package com.example.include.myapplication;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.Environment;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.SubMenu;
import android.view.View;
import android.widget.Toast;

import java.io.File;
import java.io.FileOutputStream;
import java.io.Serializable;
import java.util.ArrayList;

public class DrawingActivity extends AppCompatActivity {

    private DrawView mDrawView;
    public static float mStrokeWidth = 1;
    public static int mStrokeColor = Color.BLACK;
    public static int mBackColor = Color.WHITE;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mDrawView = new DrawView(this);
        if (savedInstanceState != null) {
            mDrawView.pointList =
                    (ArrayList<DrawView.Point>) savedInstanceState.getSerializable("list");

        }
        ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},1);


        setContentView(mDrawView);
    }

    // 방향이 바뀔때 호출되는 메소드(자원 저장용 메소드)
    // Activity가 죽기전에 호출되는 메서드
    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putSerializable("list", mDrawView.pointList);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        //선굵기,색깔,바탕색 변경 메뉴 추가
        SubMenu subMenu = menu.addSubMenu(0, 0, 0, "선굵기");
        subMenu.add(1, 1, 0, "얇은 선");
        subMenu.add(1, 2, 1, "중간 선");
        subMenu.add(1, 3, 2, "굵은 선");
        subMenu.setGroupCheckable(1, true, true);

        getMenuInflater().inflate(R.menu.phoroshop_menu, menu);

        // 화면 회전에 따른 저장
        menu.add(2, 4, 5, "그림저장");



        return true;
    }

    // 메뉴버튼을 누를때마다 호출(특정값이 선택되어 있게 할 때 사용)
    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        switch ((int) mStrokeWidth) {
            case 1:
                menu.findItem(1).setChecked(true);
                break;
            case 3:
                menu.findItem(2).setChecked(true);
                break;
            case 5:
                menu.findItem(3).setChecked(true);
                break;
        }

        switch (mStrokeColor) {
            case Color.BLACK:
                menu.findItem(R.id.item_black).setChecked(true);
                break;
            case Color.BLUE:
                menu.findItem(R.id.item_blue).setChecked(true);
                break;
            case Color.RED:
                menu.findItem(R.id.item_red).setChecked(true);
                break;
        }

        switch (mBackColor) {
            case Color.YELLOW:
                menu.findItem(R.id.item_back_yellow).setChecked(true);
                break;
            case Color.WHITE:
                menu.findItem(R.id.item_back_white).setChecked(true);
                break;
            case Color.GREEN:
                menu.findItem(R.id.item_back_green).setChecked(true);
                break;
        }
        return super.onPrepareOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        switch (item.getItemId()) {
            case 1:
                mStrokeWidth = 1;
                mDrawView.invalidate();
                break;
            case 2:
                mStrokeWidth = 3;
                mDrawView.invalidate();
                break;
            case 3:
                mStrokeWidth = 5;
                mDrawView.invalidate();
                break;

            case 4:
                // 그림을 저장한다.
                savePicture();
                break;


            case R.id.item_black:
                mStrokeColor = Color.BLACK;
                mDrawView.invalidate();
                break;
            case R.id.item_blue:
                mStrokeColor = Color.BLUE;
                mDrawView.invalidate();
                break;
            case R.id.item_red:
                mStrokeColor = Color.RED;
                mDrawView.invalidate();
                break;
            case R.id.item_back_white:
                mBackColor = Color.WHITE;
                mDrawView.invalidate();
                break;
            case R.id.item_back_yellow:
                mBackColor = Color.GRAY;
                mDrawView.invalidate();
                break;
            case R.id.item_back_green:
                mBackColor = Color.rgb(2, 199, 62);
                mDrawView.invalidate();
                break;
            case R.id.item_clear:
                mDrawView.pointList.clear();
                mDrawView.invalidate();

        }
        return super.onOptionsItemSelected(item);
    }



    private void savePicture() {
        // 1. 캐쉬(Cache)를 허용시킨다.
        // 2. 그림을 Bitmap 으로 저장.
        // 3. 캐쉬를 막는다.
        mDrawView.setDrawingCacheEnabled(true);    // 캐쉬허용
        // 캐쉬에서 가져온 비트맵을 복사해서 새로운 비트맵(스크린샷) 생성
        Bitmap screenshot = Bitmap.createBitmap(mDrawView.getDrawingCache());
        mDrawView.setDrawingCacheEnabled(false);   // 캐쉬닫기

        // SDCard(ExternalStorage) : 외부저장공간
        // 접근하려면 반드시 AndroidManifest.xml에 권한 설정을 한다.
        File dir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
        // 폴더가 있는지 확인 후 없으면 새로 만들어준다.
        if (!dir.exists())
            dir.mkdirs();
        FileOutputStream fos;

        int permissionCheck = ContextCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE);

        if(permissionCheck== PackageManager.PERMISSION_DENIED){
            // 권한 없음
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},1);
        }else{
            try {
                fos = new FileOutputStream(new File(dir, "my.png"));
                screenshot.compress(Bitmap.CompressFormat.PNG, 100, fos);
                fos.close();
                Toast.makeText(this, "저장 성공", 0).show();

            } catch (Exception e) {
                Log.e("phoro", "그림저장오류", e);
                Toast.makeText(this, "저장 실패", 0).show();
            }
        }

    }

    private static class DrawView extends View implements View.OnTouchListener {

        float x;
        float y;
        public ArrayList<Point> pointList = new ArrayList<DrawingActivity.DrawView.Point>();

        public DrawView(Context context) {
            super(context);
            setOnTouchListener(this);
            setFocusableInTouchMode(true);  // 이벤트가 계속해서 발생하기 위해
        }

        @Override
        protected void onDraw(Canvas canvas) {
            super.onDraw(canvas);

            canvas.drawColor(mBackColor);

            Paint paint = new Paint();

            if (pointList.size() < 2) return;
            for (int i = 1; i < pointList.size(); i++) {

                if (pointList.get(i).draw) {
                    paint.setColor(pointList.get(i).mStrokeColor);
                    paint.setStrokeWidth(pointList.get(i).mStrokeWidth);
                    canvas.drawLine(pointList.get(i - 1).x,
                            pointList.get(i - 1).y, pointList.get(i).x,
                            pointList.get(i).y, paint);
                }
            }


        }

        @Override
        public boolean onTouch(View v, MotionEvent event) {

            x = event.getX();
            y = event.getY();

            switch (event.getAction()) {
                case MotionEvent.ACTION_DOWN:
                    Log.d("phoro", "손가락으로 터치했음");
                    pointList.add(new Point(x, y, false, mStrokeWidth, mStrokeColor));
                    invalidate();         // 그림 다시 그리기
                    return true;                // 이벤트가 여기에서 끝난다.

                case MotionEvent.ACTION_MOVE:
                    Log.d("phoro", "손가락으로 움직이는 중");
                    pointList.add(new Point(x, y, true, mStrokeWidth, mStrokeColor));
                    invalidate();         // 그림 다시 그리기
                    return true;

                case MotionEvent.ACTION_UP:
                    Log.d("phoro", "손가락 땠음");
                default:

            }


            return false;
        }//end class DrawView

        static class Point implements Serializable {
            float x, y;
            boolean draw;
            float mStrokeWidth;
            int mStrokeColor;

            public Point(float x, float y, boolean draw, float mStrokeWidth, int mStrokeColor) {
                this.x = x;
                this.y = y;
                this.draw = draw;
                this.mStrokeColor = mStrokeColor;
                this.mStrokeWidth = mStrokeWidth;
            }

        }//end class Point
    }
}