package com.company;

import java.io.*;
import java.util.Vector;


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

            bufReader = new BufferedReader(new FileReader("Source.txt"));
            String line;
            System.out.println("Original text:\n");
            while ((line = bufReader.readLine()) != null)
            {
                System.out.println(line);
            }

            CutWord(file, bufReader);

            bufReader = new BufferedReader(new FileReader("Result.txt"));

            System.out.println("\nResult text:\n");
            while ((line = bufReader.readLine()) != null)
            {
                System.out.println(line);
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

    public static void CutWord(File file, BufferedReader bufReader) throws IOException
    {
        PrintWriter printwr = new PrintWriter(file);

        bufReader = new BufferedReader(new FileReader("Source.txt"));

        String line;
        while ((line = bufReader.readLine()) != null)
        {
            String[] words = line.split(" ");
            Vector<String> Words = new Vector<String>();
            for(String word: words)
            {
                Words.add(word);
            }

            Vector<String> suitableWords = new Vector<String>();
            for (String word: words)
            {

                if(word.length() >= 3 && word.length() <= 5)
                {
                    suitableWords.add(word);
                }
            }

            if(suitableWords.size() % 2 != 0)
            {
                suitableWords.remove(suitableWords.size() - 1);
            }

            for (int i = 0; i < suitableWords.size(); i++)
            {
                    Words.remove(suitableWords.get(i));
            }
            String[] resultLine = Words.toArray(new String[Words.size()]);
            printwr.println(String.join(" ", resultLine));
        }
        printwr.close();
    }
}
