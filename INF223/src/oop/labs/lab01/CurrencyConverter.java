package oop.labs.lab01;

import java.awt.*;
import java.awt.event.*;

public class CurrencyConverter implements WindowListener, ActionListener {
    Frame f;
    Panel p1, p2, p3, p4, p5, p6;
    TextField t1, t2;
    Label l1, l2;
    Button b1, b2;

    public CurrencyConverter() {
        f = new Frame();
        p1 = new Panel();
        p2 = new Panel();
        p3 = new Panel();
        p4 = new Panel();
        p5 = new Panel();
        p6 = new Panel();
        t1 = new TextField(20);
        t2 = new TextField(20);
        l1 = new Label("$ : ");
        l2 = new Label("€ : ");
        b1 = new Button("Euro'ya cevir.");
        b2 = new Button("Dolar'a cevir.");

        p1.add(l1);
        p2.add(t1);
        p4.add(l2);
        p5.add(t2);
        p3.add(b1);
        p6.add(b2);
        f.setLayout(new GridLayout(2, 3));
        f.add(p1);
        f.add(p2);
        f.add(p3);
        f.add(p4);
        f.add(p5);
        f.add(p6);

        f.addWindowListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        f.pack();
        f.setSize(500, 300);
        f.setResizable(false);
        f.setVisible(true);
    }

    public static void main(String[] args)
    {
        CurrencyConverter app = new CurrencyConverter();
    }

    public void actionPerformed(ActionEvent e) {
        String s;
        float n;

        if(e.getSource() == b1) {
            s = t1.getText();
            try {
                n = Float.valueOf(s);
            }catch(Exception e1) {return;}
            t2.setText(String.valueOf(n / 1.10));
        }
        if(e.getSource() == b2) {
            s = t2.getText();
            try {
                n = Float.valueOf(s);
            }catch(Exception e1) {return;}
            t1.setText(String.valueOf(n * 1.10));
        }
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
