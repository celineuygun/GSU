package oop.labs.lab04;

import java.awt.*;
import java.awt.event.*;

class IsWithinBoundsCanvas extends Canvas implements MouseListener, MouseMotionListener {
    private Point m;
    int line1X1 = 550, line1X2 = 1000, line1Y1 = 250, line1Y2 = 700;
    int line2X1 = 100, line2X2 = 450, line2Y1 = 600, line2Y2 = 350;
    int line3X1 = 250, line3X2 = 300, line3Y1 = 800, line3Y2 = 680;
    int rectangleHeight = 80, rectangleWidth = 200, rectangleX = 100, rectangleY = 600;
    int ovalX = 350, ovalY = 150, ovalR = 100;

    public IsWithinBoundsCanvas() {
        m = new Point();
        addMouseListener(this);
        addMouseMotionListener(this);
    }

    public void paint(Graphics p) {
        p.drawOval(ovalX, ovalY, ovalR * 2, ovalR * 2);
        p.drawRect(rectangleX, rectangleY, rectangleWidth, rectangleHeight);
        p.drawLine(line1X1, line1Y1, line1X2, line1Y2);
        p.drawLine(line2X1, line2Y1, line2X2, line2Y2);
        p.drawLine(line3X1, line3Y1, line3X2, line3Y2);
        repaint();
    }

    /*
     * Is the point m to the left of or to the right of both the lines AB and AC?
     * If true, it can't be inside. If false, it is at least inside the "cones"
     * that satisfy the condition. Now since we know that a point inside a triangle
     * must be to the same side of AB as BC (and also CA), we check if they differ.
     * If they do, m can't possibly be inside, otherwise m must be inside.
     */
    boolean isPointInTriangle(Point m, Point a, Point b, Point c) {
        int am_x = m.x - a.x, am_y = m.y - a.y;
        int bm_x = m.x - b.x, bm_y = m.y - b.y;
        boolean m_ab = (b.x - a.x) * am_y - (b.y - a.y) * am_x > 0;
        boolean m_ac = (c.x - a.x) * am_y - (c.y - a.y) * am_x > 0;
        boolean m_bc = (c.x - b.x) * bm_y - (c.y - b.y) * bm_x > 0;
        return (m_ac != m_ab) && (m_bc == m_ab);
    }

    public void mouseMoved(MouseEvent e) {
        m = e.getPoint();
        boolean inside = false;
        if(m.x >= 450 && m.y > 150) {
            if((Math.sqrt(Math.pow(m.x - 450, 2) + Math.pow(m.y - 250, 2)) <= 100) || (m.x <= 550 || m.y >= 700))
                inside = true;
            else {
                Point a = new Point(550, 250), b = new Point(550, 700), c = new Point(1000, 700);
                inside = isPointInTriangle(m, a, b, c);
            }
        } else if (m.x <= 450 && m.y > 150) {
            if((Math.sqrt(Math.pow(450 - m.x, 2) + Math.pow(m.y - 250, 2)) <= 100) || (m.x >= 300 && m.y >= 600))
                inside = true;
            else {
                Point a = new Point(450, 350), b = new Point(450, 600), c = new Point(100, 600);
                inside = isPointInTriangle(m, a, b, c);
                if (!inside) {
                    Point x = new Point(300, 680), y = new Point(300, 800), z = new Point(250, 800);
                    inside = isPointInTriangle(m, x, y, z);
                }
            }
        }

        if (!inside)
            setBackground(Color.white);
        else setBackground(Color.red);
        repaint();
    }

    public void mousePressed(MouseEvent e) {}
    public void mouseDragged(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseClicked(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
}

public class IsWithinBounds implements WindowListener {
    private final Frame a;
    private final IsWithinBoundsCanvas k;
    public IsWithinBounds() {
        a = new Frame();
        k = new IsWithinBoundsCanvas();
        a.addWindowListener(this);
        a.add(k);
        a.setSize(1000,800);
        a.setResizable(false);
        a.setVisible(true);

    }
    public static void main(String[] args) {
        IsWithinBounds app = new IsWithinBounds();
    }
    public void windowOpened(WindowEvent e) {}
    @Override
    public void windowClosing(WindowEvent e) {System.exit(0);}
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
