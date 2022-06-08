package oop.labs.lab02;

import java.awt.*;
import java.awt.event.*;

class CoordinatesCanvas extends Canvas implements MouseListener, MouseMotionListener {
    private Point m;

    public CoordinatesCanvas() {
        m = new Point();
        setBackground(Color.pink);
        addMouseListener(this);
        addMouseMotionListener(this);
    }

    public void paint(Graphics p) {
        p.drawString(m.x + " , " + m.y, m.x, m.y);
    }

    public void mouseMoved(MouseEvent e) {
        m = e.getPoint();
        repaint();
    }

    public void mousePressed(MouseEvent e) {}
    public void mouseDragged(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseClicked(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
}

public class Coordinates implements WindowListener {
    private Frame a;
    private CoordinatesCanvas k;

    public Coordinates() {
        a = new Frame();
        k = new CoordinatesCanvas();
        a.addWindowListener(this);
        a.add(k);
        a.setSize(800, 600);
        a.setResizable(false);
        a.setVisible(true);
    }

    public static void main(String args[]) {
        Coordinates application = new Coordinates();
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
