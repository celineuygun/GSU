package oop.labs.lab05;

import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class MastermindGame implements WindowListener, ActionListener {
    Frame f;
    Panel p;
    TextField t1, t2;
    Button b1;
    Label numberToGuess;
    Random r = new Random();
    int n; // [1000,9999]
    boolean isSet = false;
    int birler = 0, onlar = 0, yuzler = 0, binler = 0;
    int birlerb = 0, onlarb = 0, yuzlerb = 0, binlerb = 0;
    int tahmin = 0;
    int dogruYer = 0, yanlisYer = 0;

    public MastermindGame() {
        f = new Frame();
        p = new Panel();
        numberToGuess = new Label("        ");

        t1 = new TextField(10);
        b1 = new Button("OK");
        t2 = new TextField(45);
        p.add(t1);
        p.add(t2);
        p.add(b1);
        // p.add(numberToGuess); // debug

        p.setBackground(Color.LIGHT_GRAY);
        f.add(p);
        b1.addActionListener(this);
        f.addWindowListener(this);
        f.pack();
        f.setSize(450, 200);
        f.setResizable(false);
        f.setVisible(true);
    }

    void setNumber() {
        if(!isSet) {
            do {
                n = r.nextInt(9000) + 1000;
                binler = (int) n / 1000;
                yuzler = (int) (n % 1000) / 100;
                onlar = (int) (n % 100) / 10;
                birler = n % 10;
            } while(birler == onlar || birler == yuzler || birler == binler || onlar == yuzler || onlar == binler || yuzler == binler);
            isSet = true;
        }
    }

    public static void main(String[] args) {
        MastermindGame mastermind = new MastermindGame();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        setNumber();
        String sayi = String.valueOf(n);
        numberToGuess.setText(sayi);
        String s = t1.getText();
        try {
            tahmin = Integer.valueOf(s);
            if (tahmin == n) {
                t2.setText("TEBRIKLER!!!");
                isSet = false;
            } else {
                binlerb = (int) tahmin / 1000;
                yuzlerb = (int) (tahmin % 1000) / 100;
                onlarb = (int) (tahmin % 100) / 10;
                birlerb = tahmin % 10;

                if (tahmin >= 1000 && tahmin <= 9999 && birlerb != onlarb && birlerb != yuzlerb && birlerb != binlerb && onlarb != yuzlerb && onlarb != binlerb && yuzlerb != binlerb) {
                    if (binler == binlerb) dogruYer++;
                    if (yuzler == yuzlerb) dogruYer++;
                    if (onlar == onlarb) dogruYer++;
                    if (birler == birlerb) dogruYer++;
                    if (birlerb == onlar || birlerb == yuzler || birlerb == binler) yanlisYer++;
                    if (onlarb == birler || onlarb == yuzler || onlarb == binler) yanlisYer++;
                    if (yuzlerb == birler || yuzlerb == onlar || yuzlerb == binler) yanlisYer++;
                    if (binlerb == birler || binlerb == onlar || binlerb == yuzler) yanlisYer++;
                    t2.setText("+" + dogruYer + " -" + yanlisYer);
                    dogruYer = 0; yanlisYer = 0;
                } else {
                    t2.setText("4 basamakli rakamlari birbirinden farkli bir sayi giriniz");
                }
            }
        } catch (Exception e1) {
            t1.setText("Lutfen tam sayi giriniz");
        }
    }

    @Override
    public void windowOpened(WindowEvent e) {}

    @Override
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }

    @Override
    public void windowClosed(WindowEvent e) {}

    @Override
    public void windowIconified(WindowEvent e) {}

    @Override
    public void windowDeiconified(WindowEvent e) {}

    @Override
    public void windowActivated(WindowEvent e) {}

    @Override
    public void windowDeactivated(WindowEvent e) {}
}
