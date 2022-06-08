package oop.labs.lab01;

import java.awt.*;
import java.awt.event.*;

class MerhabaCanvas extends Canvas
{
    int x = 0;
    int flag = 1;

    public MerhabaCanvas()
    {
        setBackground(Color.pink);
    }

    public void paint(Graphics p)
    {
        p.drawString("Merhaba", x, 50);
        if(flag == 1 & x < 342) {
            x = x + 10;
        } else {
            flag = 0;
            x = x - 10;
            if(x == 0) flag = 1;
        }

        try
        {
            Thread.sleep(100);
        }
        catch (Exception e) {}
        repaint();
    }
}

public class Merhaba implements  WindowListener
{
    private Frame a;
    private MerhabaCanvas k;

    public Merhaba()
    {
        a = new Frame();
        k = new MerhabaCanvas();
        a.addWindowListener(this);
        a.add(k);
        a.setSize(400, 120);
        a.setResizable(false);
        a.setVisible(true);
    }

    public static void main(String[] args)
    {
        Merhaba app = new Merhaba();
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
