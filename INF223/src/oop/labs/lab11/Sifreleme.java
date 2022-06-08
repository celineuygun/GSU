package oop.labs.lab11;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Random;
import java.lang.*;

public class Sifreleme implements WindowListener, ActionListener {
    Frame f;
    Panel p;
    TextField klasor, dosya, bilgi;
    Button sifrele, sifreyiCoz;
    Label klasorIsmi, dosyaIsmi;
    ArrayList<Integer> matrix;
    int matrixEdge = 26; // Only english letters
    boolean isInit = false;
    ArrayList<Integer> sifreListesi = new ArrayList<>();

    public Sifreleme() {
        f = new Frame();
        p = new Panel();

        klasorIsmi = new Label("Klasor: ");
        dosyaIsmi = new Label("Dosya: ");
        klasor = new TextField(50);
        dosya = new TextField(50);
        sifrele = new Button("Sifrele");
        sifreyiCoz = new Button("Sifreyi Coz");
        bilgi = new TextField(50);
        bilgi.setEditable(false);

        p.add(klasorIsmi);
        p.add(klasor);
        p.add(dosyaIsmi);
        p.add(dosya);
        p.add(sifrele);
        p.add(sifreyiCoz);
        p.add(bilgi);

        p.setBackground(Color.LIGHT_GRAY);
        f.add(p);
        sifrele.addActionListener(this);
        sifreyiCoz.addActionListener(this);
        f.addWindowListener(this);
        f.pack();
        f.setSize(500, 300);
        f.setResizable(false);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        Sifreleme app = new Sifreleme();
    }

    ArrayList<Integer> uniqueRandomGenerator(int n) {
        Random random = new Random();
        ArrayList<Integer> arrayList = new ArrayList<>();

        while (arrayList.size() < n) {
            int a = random.nextInt(899) + 100;
            if (!arrayList.contains(a))
                arrayList.add(a);
        }
        return arrayList;
    }

    void initMatrix() {
        if (!isInit) {
            matrix = new ArrayList<>(matrixEdge * matrixEdge);
            ArrayList<Integer> randomNumbers = uniqueRandomGenerator(matrixEdge * matrixEdge);
            int n = 0;
            for (int i = 0; i < matrixEdge * matrixEdge; i++)
                matrix.add(randomNumbers.get(n++));
            isInit = true;
        }
    }

    public void actionPerformed(ActionEvent e) {
        initMatrix();
        String path = klasor.getText();
        String fileName = dosya.getText();
        int prev, curr = 0;
        int n = 0;
        int res = 0;
        StringBuilder sifre = new StringBuilder();

        if (e.getSource() == sifrele) {
            File f = new File(path + fileName);
            FileReader fr;
            try {
                fr = new FileReader(f);
            } catch (FileNotFoundException ex) {
                throw new RuntimeException(ex);
            }
            BufferedReader br = new BufferedReader(fr);
            int c;
            while (true) {
                try {
                    if ((c = br.read()) == -1) break;
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }

                char character = (char) c;
                if(!Character.isLetter(character))
                    continue;
                prev = curr;
                curr = Character.toLowerCase(character);
                if (n % 2 == 1) {
                    res = matrix.get((prev - 'a') * matrixEdge + (curr - 'a'));
                    sifre.append(res);
                }
                n++;
            }

            FileOutputStream fos;
            try {
                fos = new FileOutputStream(path + "sifreli_" + fileName);
            } catch (FileNotFoundException ex) {
                throw new RuntimeException(ex);
            }
            PrintWriter pw = new PrintWriter(fos);
            pw.println(sifre);
            pw.close();
            bilgi.setText("sifreli_" + fileName + " isimli dosya olusturuldu.");

//            if(f.delete())
//                System.out.println(f.getName() + " silindi");
//            else
//                System.out.println("Dosya silinirken hata olustu.");
        } else if (e.getSource() == sifreyiCoz) {
            File f = new File(path + "sifreli_" + fileName);
            FileReader fr;
            try {
                fr = new FileReader(f);
            } catch (FileNotFoundException ex) {
                throw new RuntimeException(ex);
            }
            BufferedReader br = new BufferedReader(fr);
            try {
                sifre = new StringBuilder(br.readLine());
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }

            for (int i = 0; i < sifre.length(); i++)
                if (i % 3 == 0) {
                    int x = Integer.parseInt(sifre.substring(i, i + 3));
                    sifreListesi.add(x);
                }

            StringBuilder cozum = new StringBuilder();
            int m = 0;
            while (m < sifreListesi.size() && matrix.contains(sifreListesi.get(m))) {
                int index = matrix.indexOf(sifreListesi.get(m));
                int row = index / matrixEdge;
                int col = index % matrixEdge;
                cozum.append((char) (row + 'a'));
                cozum.append((char) (col + 'a'));
                m++;
            }

            FileOutputStream fos;
            try {
                fos = new FileOutputStream(path + "sifresiz_" + fileName);
            } catch (FileNotFoundException ex) {
                throw new RuntimeException(ex);
            }
            PrintWriter pw = new PrintWriter(fos);
            pw.println(cozum);
            pw.close();
            bilgi.setText("sifresiz_" + fileName + " isimli dosya olusturuldu.");
        }
    }

    public void windowOpened(WindowEvent e) {}
    public void windowClosing(WindowEvent e) {System.exit(0);}
    public void windowClosed(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
}
