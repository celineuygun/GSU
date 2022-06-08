package oop.labs.lab02;
import java.awt.*;
import java.awt.event.*;

class BombGameCanvas extends Canvas implements KeyListener {
    static final int lineX1 = 0, lineX2 = 800, lineY = 500;
    static final int rectangleSize = 100, rectangleX = 245, rectangleY = 400;
    int playerX = 0, playerY = 80;
    double bombX, bombY;
    boolean bombLaunched = false;
    double t = 1, g = 9.8;
    int velocity = 10;
    public BombGameCanvas() {
        setBackground(Color.BLUE);
        addKeyListener(this);
    }
    public void paint(Graphics p) {
        p.drawLine(lineX1, lineY, lineX2, lineY);
        p.fillRect(rectangleX, rectangleY, rectangleSize, rectangleSize);
        p.fillRect(playerX, playerY, 50, 50);
        p.fillOval((int)bombX, (int)bombY, 20, 20);
        playerX += 10;
        if(!bombLaunched) {
            t = 0;
            bombX = playerX + 25;
            bombY = playerY + 25;
        } else {
            t += 0.5;
            bombY = 0.5 * g * Math.pow(t, 2) + playerY + 25;
            bombX = bombX + velocity;
            if(bombY > 425 || bombX > 725) {
                bombLaunched = false;
                p.setColor(Color.BLUE);
            }
        }
        if(bombX >= rectangleX && bombX <= rectangleX + rectangleSize
                && bombY >= rectangleY && bombY <= rectangleY + rectangleSize) {
            p.setColor(Color.white);
            p.drawString("Congrats!", rectangleX + rectangleSize / 2 - 30, rectangleY + rectangleSize / 2);
        }
        if(playerX == 800)
            playerX = 0;
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        repaint();
    }
    public void keyTyped(KeyEvent e) {}
    public void keyPressed(KeyEvent e) {
        int tus = e.getKeyCode();
        if(tus == KeyEvent.VK_DOWN) {
            bombLaunched = true;
        }
    }
    public void keyReleased(KeyEvent e) {}
}

public class BombGame implements WindowListener{
    private final Frame a;
    private final BombGameCanvas k;
    public BombGame() {
        a = new Frame();
        k = new BombGameCanvas();
        a.addWindowListener(this);
        a.add(k);
        a.setSize(800,600);
        a.setResizable(false);
        a.setVisible(true);
    }
    public static void main(String[] args) {
        BombGame app = new BombGame();
    }
    public void windowOpened(WindowEvent e) {}
    public void windowClosing(WindowEvent e) {System.exit(0);}
    public void windowClosed(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
}