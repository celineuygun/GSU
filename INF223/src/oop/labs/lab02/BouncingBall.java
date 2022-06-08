package oop.labs.lab02;

import java.awt.*;
import java.awt.event.*;
import java.util.*;

class BouncingBallCanvas extends Canvas {
    Random random = new Random();
    int xRect = random.nextInt(590), yRect = random.nextInt(390);
    int x = random.nextInt(790), y = random.nextInt(570);
    int xVelocity = 10 * (random.nextInt(3) + 1), yVelocity = 10 * (random.nextInt(3) + 1);

    public BouncingBallCanvas() {
        setBackground(Color.blue);
    }
    public void paint(Graphics p) {
        p.setColor(Color.white);
        p.fillRect(xRect, yRect, 200, 200);
        p.setColor(Color.red);
        p.fillOval(x, y, 10, 10);

        if(x >= xRect && x <= xRect + 200 && y >= yRect && y <= yRect + 200) {
            x += xVelocity / 2;
            y += yVelocity / 2;
        } else {
            x += xVelocity;
            y += yVelocity;
        }
        if(x >= 775 || x <= 5)
            xVelocity *= -1;
        if(y >= 555 || y <= 5)
            yVelocity *= -1;
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        repaint();
    }
}

public class BouncingBall implements WindowListener {
    private Frame a;
    private BouncingBallCanvas k;
    public BouncingBall() {
        a = new Frame();
        k = new BouncingBallCanvas();
        a.addWindowListener(this);
        a.add(k);
        a.setSize(800,600);
        a.setResizable(true);
        a.setVisible(true);
    }
    public static void main(String[] args) { BouncingBall app = new BouncingBall();}
    public void windowOpened(WindowEvent e) {}
    public void windowClosing(WindowEvent e) {System.exit(0);}
    public void windowClosed(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
}
