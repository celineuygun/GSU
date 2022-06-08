package oop.labs.lab05;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.util.regex.*;

public class RomanNumeralsConverter implements WindowListener, ActionListener {
    GridBagLayout a = new GridBagLayout();
    GridBagConstraints b = new GridBagConstraints();
    Frame f;
    Panel p;
    TextField t1, t2;
    Label headerLabel, errorLabel;
    Button toRoman, toInteger;

    int errorIndex;
    String[] errorMessages = {
            "",
            "ERROR: Enter a valid number",
            "ERROR: Enter a number between 0 and 4000",
            "ERROR: Enter a valid Roman numeral"
            };

    /*
     * X? finds no or exactly one letter X
     * X{1,4} means X must occur at least once and at a maximum of four
     * X|Z finds X or Z
     * XZ Finds X directly followed by Z
     * regex$ Finds regex that must match at the end of the line
     * ^regex Finds regex that must match at the beginning of the line
     * () Allows you to assign a repetition operator to a complete group.
     */
    private final Pattern RomanPattern = Pattern.compile("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");

    private final static TreeMap<Integer, String> intToRomanMap = new TreeMap<>();
    static {
        intToRomanMap.put(1000, "M");
        intToRomanMap.put(900, "CM");
        intToRomanMap.put(500, "D");
        intToRomanMap.put(400, "CD");
        intToRomanMap.put(100, "C");
        intToRomanMap.put(90, "XC");
        intToRomanMap.put(50, "L");
        intToRomanMap.put(40, "XL");
        intToRomanMap.put(10, "X");
        intToRomanMap.put(9, "IX");
        intToRomanMap.put(5, "V");
        intToRomanMap.put(4, "IV");
        intToRomanMap.put(1, "I");
    }

    private final static Map<Character, Integer> romanToIntMap = new HashMap<>();
    static {
        romanToIntMap.put('I', 1);
        romanToIntMap.put('V', 5);
        romanToIntMap.put('X', 10);
        romanToIntMap.put('L', 50);
        romanToIntMap.put('C', 100);
        romanToIntMap.put('D', 500);
        romanToIntMap.put('M', 1000);
    }

    public RomanNumeralsConverter() {
        f = new Frame();
        p = new Panel();

        p.setLayout(a);
        b.fill = GridBagConstraints.BOTH;
        b.insets = new Insets(5, 8, 5, 8);

        b.gridx = 0;
        b.gridy = 0;
        b.gridwidth = 6;
        b.gridheight = 1;
        headerLabel = new Label("Roman Numerals Converter");
        headerLabel.setAlignment(Label.CENTER);
        headerLabel.setFont(new Font("Poppins", Font.BOLD, 20));
        headerLabel.setBackground(Color.lightGray);
        headerLabel.setForeground(Color.darkGray);
        a.setConstraints(headerLabel, b);
        p.add(headerLabel);

        b.gridx = 0;
        b.gridy = 1;
        b.gridwidth = 3;
        b.gridheight = 1;
        t1 = new TextField(20);
        a.setConstraints(t1, b);
        p.add(t1);

        b.gridx = 3;
        b.gridy = 1;
        b.gridwidth = 3;
        b.gridheight = 1;
        toRoman = new Button(" Convert to Roman ");
        a.setConstraints(toRoman, b);
        p.add(toRoman);

        b.gridx = 0;
        b.gridy = 2;
        b.gridwidth = 3;
        b.gridheight = 1;
        t2 = new TextField(20);
        a.setConstraints(t2, b);
        p.add(t2);

        b.gridx = 3;
        b.gridy = 2;
        b.gridwidth = 3;
        b.gridheight = 1;
        toInteger = new Button("Convert to Integer");
        a.setConstraints(toInteger, b);
        p.add(toInteger);

        b.gridx = 0;
        b.gridy = 4;
        b.gridwidth = 6;
        b.gridheight = 1;
        errorLabel = new Label("            ");
        errorLabel.setAlignment(Label.CENTER);
        errorLabel.setFont(new Font("Poppins", Font.PLAIN, 12));
        errorLabel.setForeground(Color.white);
        a.setConstraints(errorLabel, b);
        p.add(errorLabel);

        p.setBackground(Color.DARK_GRAY);
        f.add(p);
        toRoman.addActionListener(this);
        toInteger.addActionListener(this);

        f.addWindowListener(this);
        f.pack();
        f.setSize(600, 400);
        f.setResizable(true);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        RomanNumeralsConverter app = new RomanNumeralsConverter();
    }

    public int romanToInteger(String roman) {
        int result = 0;

        for (int i = 0; i < roman.length(); i++) {
            char ch = roman.charAt(i);

            // we subtract twice the Previous Character value because we might have
            // already added the value while processing it, so we subtract twice the value.
            if (i > 0 && romanToIntMap.get(ch) > romanToIntMap.get(roman.charAt(i - 1))) {
                result += romanToIntMap.get(ch) - 2 * romanToIntMap.get(roman.charAt(i - 1));
            }
            // just add the corresponding number to result.
            else
                result += romanToIntMap.get(ch);
        }

        return result;
    }

    public static String integerToRoman(int number) {
        int l = intToRomanMap.floorKey(number);
        if (number == l) {
            return intToRomanMap.get(number);
        }
        return intToRomanMap.get(l) + integerToRoman(number - l);

    }

    public void actionPerformed(ActionEvent e) {
        try {
            errorIndex = 0;
            if (e.getSource() == toRoman) {
                int number = Integer.parseInt(t1.getText());
                if(number > 0 && number < 4000)
                    t2.setText(integerToRoman(number));
                else
                    errorIndex = 2;
            } else if (e.getSource() == toInteger) {
                String str = t2.getText().toUpperCase();
                Matcher matcher = RomanPattern.matcher(str);
                boolean matches = matcher.matches();
                if(!matches)
                    errorIndex = 3;
                else {
                    t1.setText(String.valueOf(romanToInteger(str)));
                }
            }
        } catch (Exception e1) {
            errorIndex = 1;
        }
        errorLabel.setText(errorMessages[errorIndex]);
    }

    public void windowOpened(WindowEvent e) {}
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }
    public void windowClosed(WindowEvent e) { }
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
}
