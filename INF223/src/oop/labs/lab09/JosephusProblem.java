package oop.labs.lab09;
import java.util.*;

public class JosephusProblem {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Toplam asker sayisi:");
        int n = sc.nextInt();

        System.out.println("Ilk hangi askere kilic verilsin:");
        int f = sc.nextInt();

        ArrayList<Integer> a = new ArrayList(n);

        for(int i = 1; i <= n; i++)
            a.add(i);

        for(int i = f - 1; a.size() != 1; i++) {
            if(a.size() < i + 1)
                i = 0;
            if(a.size() == i + 1)
                i = -1;

            for(int j = 0; j < a.size(); j++) {
                System.out.printf("%d ",a.get(j));
            } System.out.println();
            a.remove(i + 1);
        }
        System.out.print("Hayatta kalan asker: "+ a.get(0));
    }
}
