package oop.labs.lab10;
import java.io.File;
import java.util.*;

public class SortFiles {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.println("Enter the path: ");
            File dir = new File(sc.next());
            if (!dir.exists()) {
                System.out.println("Folder can not be found");
                return;
            }
            File[] files = dir.listFiles();
            if (files == null) {
                System.out.println("There are no files in this folder.");
                return;
            }
            ArrayList<Long> lastModifiedTimes = new ArrayList<>(files.length);
            ArrayList<Long> sortedByLastModifiedTime = new ArrayList<>(files.length);
            ArrayList<String> fileNames = new ArrayList<>(files.length);
            ArrayList<String> sortedFileNames = new ArrayList<>(files.length);
            ArrayList<Integer> indexes = new ArrayList<>(files.length);

            System.out.println("\nBEFORE SORTING");
            for (File file : files) {
                System.out.println(new Date(file.lastModified()) + " " + file.getName());
                lastModifiedTimes.add(file.lastModified());
                sortedByLastModifiedTime.add(0L);
                sortedFileNames.add("");
                fileNames.add(file.getName());
                indexes.add(0);
            }
            System.out.println("Number of files: " + files.length);

            System.out.println("\nAFTER SORTING");
            for (int i = 0; i < files.length; i++) {
                for (int j = i + 1; j < files.length; j++) {
                    if (lastModifiedTimes.get(i) >= lastModifiedTimes.get(j))
                        indexes.set(i, indexes.get(i) + 1);
                    else if (lastModifiedTimes.get(i) < lastModifiedTimes.get(j))
                        indexes.set(j, indexes.get(j) + 1);
                }
            }

            for (int i = 0; i < files.length; i++) {
                sortedByLastModifiedTime.set(indexes.get(i), lastModifiedTimes.get(i));
                sortedFileNames.set(indexes.get(i), fileNames.get(i));
            }

            for (int i = 0; i < files.length; i++)
                System.out.printf("[%2d] %s %s\n", i + 1, new Date(sortedByLastModifiedTime.get(i)), sortedFileNames.get(i));
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
