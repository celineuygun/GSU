package oop.labs.lab02;

import java.awt.*;
import java.awt.event.*;

class MovementCanvas extends Canvas implements MouseListener, MouseMotionListener {
    private Point m;

    public MovementCanvas() {
        m = new Point();
        setBackground(Color.pink);
        addMouseListener(this);
        addMouseMotionListener(this);
    }

    public void paint(Graphics p) {
        if ((m.x > 300 && m.x < 400) && (m.y < 400 && m.y > 300)) {
            setBackground(Color.red);
            p.setColor(Color.WHITE);
        } else {
            setBackground(Color.yellow);
            p.setColor(Color.RED);
        }
        p.fillRect(300, 300, 100, 100);
        repaint();
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

public class Movement implements WindowListener {
    private Frame a;
    private MovementCanvas k;

    public Movement() {
        a = new Frame();
        k = new MovementCanvas();
        a.addWindowListener(this);
        a.add(k);
        a.setSize(800, 600);
        a.setResizable(false);
        a.setVisible(true);
    }

    public static void main(String args[]) {
        Movement application = new Movement();
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
