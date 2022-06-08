package oop.labs.lab03;

import java.awt.*;
import java.awt.event.*;
import java.util.*;

class ShootingGameCanvas extends Canvas implements KeyListener {
    static final int lineX1 = 0, lineX2 = 800, lineY = 575;
    int playerX = (new Random()).nextInt(750), playerY = 525, playerHeight = 50, playerWidth = 50;
    int airplaneX = 0, airplaneY = 20, airplaneHeight = 50, airplaneWidth = 100;
    int bombX = playerX + 25, bombY = playerY - 25, bombR = 10, x, y;
    int stockX = playerX + 25, stockY = playerY - 25;
    int theta = 90, theta2, range = 50, bombVelocity = 20;
    boolean bombLaunched = false;

    public ShootingGameCanvas() {
        setBackground(Color.black);
        addKeyListener(this);
    }

    public void paint(Graphics p) {
        p.setColor(Color.orange);
        p.drawLine(lineX1, lineY, lineX2, lineY);
        p.fillRect(playerX, playerY, playerWidth, playerHeight);
        p.fillRect(airplaneX, airplaneY, airplaneWidth, airplaneHeight);

        stockX = (int) (playerX + 30 + range * Math.cos(2 * Math.PI * theta / 360));
        stockY = (int) (playerY - range * Math.sin(2 * Math.PI * theta / 360));
        p.drawLine(playerX + 25, playerY, stockX, stockY);

        airplaneX += 10;
        if(airplaneX == 800) airplaneX = airplaneWidth * -1;

        if(bombLaunched) {
            p.setColor(Color.red);
            p.fillOval(x, y, bombR * 2, bombR * 2);

            x = (int) (x + bombVelocity * Math.cos(2 * Math.PI * theta2 / 360));
            y = (int) (y - bombVelocity * Math.sin(2 * Math.PI * theta2 / 360));

            if(x >= airplaneX && x <= airplaneX + airplaneWidth
                    && y >= airplaneY && y <= airplaneY + airplaneHeight) {
                p.setColor(Color.green);
                Font tt = new Font("Times New Roman", Font.PLAIN,60);
                p.setFont(tt);
                p.drawString("CONGRATS",200,300);
            }

            if(x <= 0 || x >= 800 || y <= 0)
                bombLaunched = false;
        }

        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        } repaint();
    }

    @Override
    public void keyTyped(KeyEvent e) {}
    @Override
    public void keyPressed(KeyEvent e) {
        int tus = e.getKeyCode();
        switch(tus) {
            case(KeyEvent.VK_UP):
                if(!bombLaunched) {
                    bombLaunched = true;
                    theta2 = theta;
                    x = bombX;
                    y = bombY;
                }
                break;
            case(KeyEvent.VK_LEFT):
                theta += 10;
                if(theta > 180)
                    theta = 180;
                break;
            case(KeyEvent.VK_RIGHT):
                theta -= 10;
                if(theta < 0)
                    theta = 0;
                break;
        }
        repaint();
    }
    @Override
    public void keyReleased(KeyEvent e) {}
}

public class ShootingGame implements WindowListener {
    private Frame a;
    private ShootingGameCanvas k;

    public ShootingGame() {
        a = new Frame();
        k = new ShootingGameCanvas();
        a.addWindowListener(this);
        a.add(k);
        a.setSize(800, 700);
        a.setResizable(false);
        a.setVisible(true);
    }

    public static void main(String args[]) {
        ShootingGame application = new ShootingGame();
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
