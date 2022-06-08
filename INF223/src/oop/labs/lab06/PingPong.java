package oop.labs.lab06;

import java.awt.*;
import java.awt.event.*;
import java.util.Random;

class PingPongCanvas extends Canvas implements KeyListener{
    Font tt = new Font("Times New Roman", Font.PLAIN,50);
    Random random = new Random();
    int height = 800, width = 1000;
    int lineX1 = 40, lineY1 = 0, lineX2 = width - lineX1, lineY2 = height;
    int x = random.nextInt(400) + 300, y = random.nextInt(400) + 200;
    int playerWidth = 10, playerHeight = 100;
    int player1X = 50, player1Y = 350;
    int player2X = 950 - playerWidth, player2Y = 350;
    int player1Score = 0, player2Score = 0;
    int ballR = 10;
    int xVel = 12, yVel = 12;

    public PingPongCanvas(){
        setBackground(Color.white);
        addKeyListener(this);
    }

    public void paint(Graphics p) {
        p.drawString(player1Score + " : " + player2Score, 480, 20);
        p.drawLine(lineX1, lineY1, lineX1, lineY2);
        p.drawLine(lineX2, lineY1, lineX2, lineY2);
        p.setColor(Color.pink);
        p.fillRect(player1X, player1Y, playerWidth, playerHeight);
        p.fillRect(player2X, player2Y, playerWidth, playerHeight);
        p.setColor(Color.red);
        p.fillOval(x, y, ballR, ballR);
        x += xVel;
        y += yVel;

        if(player1Score == 3 || player2Score == 3) {
            p.setFont(tt);
            p.setColor(Color.pink);
            p.fillOval(300, 200, 400, 400);
            p.setColor(Color.red);
            p.drawString("Game Over", 380, 380);
            //p.drawString(player1Score + " : " + player2Score, 445, 450);
            if(player1Score == 3) p.drawString("Player1 Wins!", 360, 440);
            else p.drawString("Player2 Wins!", 360, 440);
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {}
            System.exit(0);
        } else if((x <= lineX1 || x >= lineX2) && y > 15 && y < 760) {
            if(x >= lineX2) player1Score++;
            else player2Score++;
            x = random.nextInt(400) + 300;
            y = random.nextInt(400) + 200;
        } else if(x >= player1X && x <= player1X + playerWidth && y + (ballR / 2) >= player1Y && y + (ballR / 2) <= player1Y + playerHeight) {
            x = player1X + playerWidth;
            xVel *= -1;
        } else if(x + ballR >= player2X && x + ballR <= player2X + playerWidth && y + (ballR / 2) >= player2Y && y + (ballR / 2) <= player2Y + playerHeight) {
            x = player2X - ballR;
            xVel *= -1;
        } else if(y >= 760 || y <= 5) {
            if(y >= 760) y = 760;
            else y = 5;
            yVel *= -1;
        }

        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        repaint();
    }

    @Override
    public void keyTyped(KeyEvent e) {}

    @Override
    public void keyPressed(KeyEvent e) {
        int tus = e.getKeyCode();
        switch(tus) {
            case (KeyEvent.VK_A):
                if(player1Y - 40 >= lineY1)
                    player1Y -= 40;
                else player1Y = lineY1;
                break;
            case (KeyEvent.VK_Z):
                if(player1Y + playerHeight + 40 <= lineY2)
                    player1Y += 40;
                else player1Y = lineY2 - 28 - playerHeight;
                break;
            case (KeyEvent.VK_UP):
                if(player2Y - 40 >= lineY1)
                    player2Y -= 40;
                else player2Y = lineY1;
                break;
            case (KeyEvent.VK_DOWN):
                if(player2Y + playerHeight + 40 <= lineY2)
                    player2Y += 40;
                else player2Y = lineY2 - 28 - playerHeight;
                break;
        }
        repaint();
    }
    @Override
    public void keyReleased(KeyEvent e) {}
}

public class PingPong implements WindowListener{
    final Frame a;
    final PingPongCanvas k;

    public PingPong() {
        a = new Frame();
        k = new PingPongCanvas();
        a.addWindowListener(this);
        a.add(k);
        a.setSize(1000,800);
        a.setResizable(false);
        a.setVisible(true);
    }

    public static void main(String[] args) {
        PingPong app = new PingPong();
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
