package oop.labs.lab07;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

public class Calculator implements WindowListener, ActionListener {
    Frame f;
    Panel p;
    GridBagLayout a = new GridBagLayout();
    GridBagConstraints gbc = new GridBagConstraints();

    TextField display;
    Label errorMessage;
    Button backspace, clean, plus_minus, square_root, fraction, dot;
    Button plus, minus, divide, multiply, percent, equals;
    Button zero, one, two, three, four, five, six, seven, eight, nine;

    char oldOpt = '?', opt = '?';
    String text;
    ArrayList<Double> numbers = new ArrayList<>();

    public Calculator(String title) {
        f = new Frame(title);
        p = new Panel();

        p.setLayout(a);
        gbc.fill = GridBagConstraints.BOTH;
        gbc.insets = new Insets(3, 3, 3, 3);

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        gbc.gridheight = 1;
        errorMessage = new Label("");
        errorMessage.setForeground(Color.white);
        errorMessage.setAlignment(Label.CENTER);
        a.setConstraints(errorMessage, gbc);
        p.add(errorMessage);

        gbc.gridx = 2;
        gbc.gridy = 0;
        gbc.gridwidth = 4;
        gbc.gridheight = 1;
        display = new TextField("");
        display.setBackground(Color.pink);
        display.setEditable(false);
        a.setConstraints(display, gbc);
        p.add(display);

        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        backspace = new Button("<--");
        a.setConstraints(backspace, gbc);
        p.add(backspace);
        backspace.addActionListener(this);

        gbc.gridx = 2;
        gbc.gridy = 1;
        gbc.gridwidth = 2;
        gbc.gridheight = 1;
        clean = new Button("C");
        gbc.fill = GridBagConstraints.HORIZONTAL;
        p.add(clean, gbc);
        clean.addActionListener(this);

        gbc.gridx = 4;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        plus_minus = new Button("+/-");
        p.add(plus_minus, gbc);
        plus_minus.addActionListener(this);

        gbc.gridx = 5;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        square_root = new Button("\u221A");
        p.add(square_root, gbc);
        square_root.addActionListener(this);

        gbc.gridx = 1;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        seven = new Button("7");
        p.add(seven, gbc);
        seven.addActionListener(this);

        gbc.gridx = 2;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        eight = new Button("8");
        p.add(eight, gbc);
        eight.addActionListener(this);

        gbc.gridx = 3;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        nine = new Button("9");
        p.add(nine, gbc);
        nine.addActionListener(this);

        gbc.gridx = 4;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        divide = new Button("/");
        p.add(divide, gbc);
        divide.addActionListener(this);

        gbc.gridx = 5;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        percent = new Button("%");
        p.add(percent, gbc);
        percent.addActionListener(this);

        gbc.gridx = 1;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        four = new Button("4");
        p.add(four, gbc);
        four.addActionListener(this);

        gbc.gridx = 2;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        five = new Button("5");
        p.add(five, gbc);
        five.addActionListener(this);

        gbc.gridx = 3;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        six = new Button("6");
        p.add(six, gbc);
        six.addActionListener(this);

        gbc.gridx = 4;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        multiply = new Button("*");
        p.add(multiply, gbc);
        multiply.addActionListener(this);

        gbc.gridx = 5;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        fraction = new Button("1/x");
        p.add(fraction, gbc);
        fraction.addActionListener(this);

        gbc.gridx = 1;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        one = new Button("1");
        p.add(one, gbc);
        one.addActionListener(this);

        gbc.gridx = 2;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        two = new Button("2");
        p.add(two, gbc);
        two.addActionListener(this);

        gbc.gridx = 3;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        three = new Button("3");
        p.add(three, gbc);
        three.addActionListener(this);

        gbc.gridx = 4;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        minus = new Button("-");
        p.add(minus, gbc);
        minus.addActionListener(this);

        gbc.gridx = 5;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.gridheight = 2;
        equals = new Button("=");
        gbc.fill = GridBagConstraints.VERTICAL;
        p.add(equals, gbc);
        equals.addActionListener(this);

        gbc.gridx = 1;
        gbc.gridy = 5;
        gbc.gridwidth = 2;
        gbc.gridheight = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        zero = new Button("0");
        p.add(zero, gbc);
        zero.addActionListener(this);

        gbc.gridx = 3;
        gbc.gridy = 5;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        dot = new Button(".");
        p.add(dot, gbc);
        dot.addActionListener(this);

        gbc.gridx = 4;
        gbc.gridy = 5;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        plus = new Button("+");
        p.add(plus, gbc);
        plus.addActionListener(this);

        p.setBackground(Color.darkGray);
        f.add(p);

        f.addWindowListener(this);
        f.pack();
        f.setSize(500, 300);
        f.setResizable(false);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        Calculator app = new Calculator("Calculator");
    }

    public void actionPerformed(ActionEvent e) {
        errorMessage.setText("");
        text = display.getText();
        if (e.getSource() == zero) {
            display.setText(text + "0");
        } else if (e.getSource() == one) {
            display.setText(text + "1");
        } else if (e.getSource() == two) {
            display.setText(text + "2");
        } else if (e.getSource() == three) {
            display.setText(text + "3");
        } else if (e.getSource() == four) {
            display.setText(text + "4");
        } else if (e.getSource() == five) {
            display.setText(text + "5");
        } else if (e.getSource() == six) {
            display.setText(text + "6");
        } else if (e.getSource() == seven) {
            display.setText(text + "7");
        } else if (e.getSource() == eight) {
            display.setText(text + "8");
        } else if (e.getSource() == nine) {
            display.setText(text + "9");
        } else if (e.getSource() == dot) {
            if(!text.contains(".")) {
                display.setText(text + ".");
            }
        } else if (e.getSource() == clean) {
            display.setText("");
        } else if (e.getSource() == backspace) {
            text = text.substring(0, text.length() - 1);
            display.setText(text);
        } else if (e.getSource() == plus_minus) {
            if(text.contains("-")) {
                text = text.substring(1);
                display.setText(text);
            } else {
                display.setText("-" + text);
            }
        } else if (e.getSource() == square_root) {
            double n = Double.parseDouble(text);
            if(n >= 0.0) display.setText(String.valueOf(Math.sqrt(n)));
            else errorMessage.setText("ERROR");
        } else if (e.getSource() == fraction) {
            double n = Double.parseDouble(text);
            if(n != 0.0) {
                display.setText(String.valueOf(1 / n));
            } else errorMessage.setText("ERROR");
        } else if (e.getSource() == plus) {
            if(!text.isBlank()) {
                if (opt != '?') oldOpt = opt;
                opt = '+';
                numbers.add(Double.valueOf(text));
                display.setText("");
            } else opt = '+';
        } else if (e.getSource() == minus) {
            if(!text.isBlank()) {
                if (opt != '?') oldOpt = opt;
                opt = '-';
                numbers.add(Double.valueOf(text));
                display.setText("");
            } else opt = '-';
        } else if (e.getSource() == divide) {
            if(!text.isBlank()) {
                if (opt != '?') oldOpt = opt;
                opt = '/';
                numbers.add(Double.valueOf(text));
                display.setText("");
            } else opt = '/';
        } else if (e.getSource() == multiply) {
            if(!text.isBlank()) {
                if (opt != '?') oldOpt = opt;
                opt = '*';
                numbers.add(Double.valueOf(text));
                display.setText("");
            } else opt = '*';
        } else if (e.getSource() == percent) {
            if(!text.isBlank()) {
                if (opt != '?') oldOpt = opt;
                opt = '%';
                numbers.add(Double.valueOf(text));
                display.setText("");
            } else opt = '%';
        } else if (e.getSource() == equals) {
            if(!text.isBlank()) {
                if (opt != '?') oldOpt = opt;
                else oldOpt = '=';
                opt = '=';
                numbers.add(Double.valueOf(text));
                display.setText("");
            } else {
                opt = '=';
                oldOpt = '=';
            }
        }

        if (oldOpt != '?') {
            double oldNum = 0, newNum = 0;
            if (numbers.size() == 2) {
                newNum = numbers.remove(1);
                oldNum = numbers.remove(0);
            }

            switch (oldOpt) {
                case '+':
                    numbers.add(oldNum + newNum);
                    break;
                case '-':
                    numbers.add(oldNum - newNum);
                    break;
                case '/':
                    if (newNum != 0.0) numbers.add(oldNum / newNum);
                    else {
                        numbers.add(oldNum);
                        errorMessage.setText("ERROR");
                    }
                    break;
                case '*':
                    numbers.add(oldNum * newNum);
                    break;
                case '%':
                    numbers.add(oldNum % newNum);
                    break;
            }

            if (opt == '=' && !numbers.isEmpty()) {
                oldNum = numbers.remove(0);
                display.setText(String.valueOf(oldNum));
            }
            oldOpt = '?';
        }
    }

    public void windowOpened(WindowEvent e) {}
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }
    public void windowClosed(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
}
