package oop.labs.lab01;

import java.awt.*;
import java.awt.event.*;

public class AsalSayiMi implements WindowListener, ActionListener
{
    Frame f;
    Panel p1, p2;
    TextField t1, t2;
    Button b;

    public AsalSayiMi()
    {
        f = new Frame();
        p1 = new Panel();
        p2 = new Panel();
        t1 = new TextField(30);
        t2 = new TextField(50);

        p1.add(t1);
        p2.add(t2);
        b = new Button("OK");
        p1.add(b);

        f.setLayout((new GridLayout(2, 1)));
        f.add(p1);
        f.add(p2);
        b.addActionListener(this);
        f.addWindowListener(this);
        f.setBackground(Color.darkGray);
        f.pack();
        f.setSize(400, 300);
        f.setResizable(false);
        f.setVisible(true);
    }

    public boolean isPrime(int num) {
        boolean flag = true;
        for(int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                flag = false;
                break;
            }
        } return (num != 1) ? flag : !flag;
    }

    public static void main(String[] args)
    {
        AsalSayiMi app = new AsalSayiMi();
    }

    public void actionPerformed(ActionEvent e)
    {
        t2.setText("1'den buyuk bir sayi giriniz.");
        String s = t1.getText();
        int n;
        try {
            n = Integer.valueOf(s);
        } catch(Exception e1) {return;}
        if(n < 1) return;
        if (isPrime(n))
            t2.setText(n + " asal bir sayidir.");
        else
            t2.setText(n + " asal bir sayi degildir.");
    }

    public void windowOpened(WindowEvent e) {}
    public void windowClosing(WindowEvent e)
    {
        System.exit(0);
    }
    public void windowClosed(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
}
