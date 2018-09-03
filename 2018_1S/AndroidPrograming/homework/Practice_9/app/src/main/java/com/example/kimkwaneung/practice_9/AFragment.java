package com.example.kimkwaneung.practice_9;


import android.app.ProgressDialog;
import android.os.Bundle;
import android.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;


/**
 * A simple {@link Fragment} subclass.
 */
public class AFragment extends Fragment {

    private ProgressDialog progress;


    public AFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_a, container, false);
        Button btn = (Button) view.findViewById(R.id.btn);
        progress = new ProgressDialog(getActivity());
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                progress.setCancelable(true);
                progress.setMessage("네트워크에서 다운로드 중입니다. ");
                progress.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
                progress.setProgress(0);
                progress.setMax(100);
                progress.show();

                final Thread t = new Thread(){
                    @Override
                    public void run() {
                        int time = 0;
                        while (time < 100) {
                            try {
                                sleep(40);
                                time += 1;
                                progress.setProgress(time);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                        }
                        progress.dismiss();
                    }
                };
                t.start();
            }
        });
        return view;
    }




}
