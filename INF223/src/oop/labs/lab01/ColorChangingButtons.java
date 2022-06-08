package oop.labs.lab01;

import java.awt.*;
import java.awt.event.*;

public class ColorChangingButtons implements WindowListener, ActionListener {
    Frame f;
    Panel p1, p2, p3;
    Button b1, b2, b3;

    public ColorChangingButtons() {
        f = new Frame();
        p1 = new Panel();
        p2 = new Panel();
        p3 = new Panel();

        b1 = new Button("Kirmizi");
        b2 = new Button("Sari");
        b3 = new Button("Beyaz");

        p1.add(b1);
        p2.add(b2);
        p3.add(b3);
        f.setLayout(new GridLayout(1, 3));
        f.add(p1);
        f.add(p2);
        f.add(p3);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        f.addWindowListener(this);
        f.pack();
        f.setSize(300, 200);
        f.setResizable(true);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        ColorChangingButtons app = new ColorChangingButtons();
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == b1) f.setBackground(Color.red);
        if(e.getSource() == b2) f.setBackground(Color.yellow);
        if(e.getSource() == b3) f.setBackground(Color.white);
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
