package com.iceira.iubot;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class MainActivityBot1 extends AppCompatActivity {
    Socket socket;
    InputStream inStr;
    OutputStream outStr;
    Button btnConnect, btnDemo1;
    EditText etIP,etPort;
    TextView tvOut;
    static String str1="0",str2="0";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_activity_bot1);
        btnConnect = (Button)findViewById(R.id.btnConnect);
        btnDemo1 =(Button)findViewById(R.id.btnDemo1);
        etIP = (EditText)findViewById(R.id.etIP);
        etPort = (EditText)findViewById(R.id.etPort);
        tvOut   = (TextView)findViewById(R.id.tvOut);
        btnConnect.setOnClickListener(new Button.OnClickListener(){
            @Override
            public void onClick(View v) {
                Thread t = new thread();
                t.start();
                try {
                    t.sleep(3000);

                } catch (InterruptedException e) {

                    tvOut.setText( str1+str2);
                }
            }
        });

        btnDemo1.setOnClickListener(new Button.OnClickListener(){
            @Override
            public void onClick(View v) {
                tvOut.setText("Down");
                String strTmp = new String();
                byte[] sendstr = new byte[21];
                strTmp = "101";
                try {
                    System.arraycopy(strTmp.getBytes(), 0, sendstr, 0, strTmp.length());
                    outStr.write(sendstr);

                } catch (Exception e) {
                    System.out.println("Error: " + e.getMessage());
                }
            }
        });
    }
    class thread extends Thread{
        public void run() {
            try{
                System.out.println("Waitting to connect......");
                String server=etIP.getText().toString();
                //String server="192.168.1.56";//161
                //int servPort=etPort.getText().
                int servPort= 2000;
                socket=new Socket(server,servPort);
                inStr=socket.getInputStream();
                outStr=socket.getOutputStream();
                System.out.println("Connected!!");
                byte[] rebyte = new byte[18];
                inStr.read(rebyte);

            }catch(Exception e)
            {
                System.out.println("Error: "+e.getMessage());
            }
        }
    }
}
