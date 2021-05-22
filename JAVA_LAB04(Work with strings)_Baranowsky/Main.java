package com.company;

import java.io.*;
import java.util.Scanner;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader bufReader = null;
        try
        {
            File file = new File("Result.txt");
            if(!file.exists())
            {
                file.createNewFile();
            }

            bufReader = new BufferedReader(new FileReader("Poem.txt"));
            String line;
            while ((line = bufReader.readLine()) != null)
            {
                System.out.println(line);
            }

            System.out.println("\nWhat do you want to do?");
            System.out.println("1 >> Cut symbol");
            System.out.println("2 >> Paste symbol");
            System.out.print("  >> ");

            Scanner in = new Scanner(System.in);

            int choose = in.nextInt();
            switch (choose)
            {
                case 1:
                    CutChar(file, bufReader);
                    break;
                case 2:
                    PasteChar(file, bufReader);
                    break;
                default:
                    System.out.println("There is no the same operation. Try again!");
                    break;
            }
        }
        catch (IOException e)
        {
            System.out.print("Error: " + e);
        }
        finally {
            bufReader.close();
        }

    }

    public static void CutChar(File file, BufferedReader bufReader) throws IOException
    {
        PrintWriter printwr = new PrintWriter(file);

        Scanner in = new Scanner(System.in);
        System.out.println("\nWhat symbol do you want to cut?");
        System.out.print("  >> ");
        char Char = in.next().charAt(0);

        bufReader = new BufferedReader(new FileReader("Poem.txt"));

        String line;
        while ((line = bufReader.readLine()) != null)
        {
            String[] subStrings = line.split("" + Char);
            line = String.join("", subStrings);
            printwr.println(line);
        }

        in.close();
        printwr.close();
    }

    public static void PasteChar(File file, BufferedReader bufReader) throws IOException
    {
        PrintWriter printwr = new PrintWriter(file);

        Scanner in = new Scanner(System.in);
        System.out.println("\nWhat symbol do you want to paste?");
        System.out.print("  >> ");
        char Char = in.next().charAt(0);

        System.out.println("\nWhere do you want to paste symbol?");
        System.out.print("  >> ");
        int index = in.nextInt();

        bufReader = new BufferedReader(new FileReader("Poem.txt"));

        String line;
        while ((line = bufReader.readLine()) != null)
        {
            if(index < line.length())
            {
                String leftSubStr = line.substring(0, index);
                String rightSubStr = line.substring(index, line.length() - 1);
                printwr.println(leftSubStr + Char + rightSubStr);
            }
        }

        in.close();
        printwr.close();
    }
}
