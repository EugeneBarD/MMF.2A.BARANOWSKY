import java.util.Scanner;
import java.util.Vector;

public class Task_1_JavaBaranovskii
{ 
    public static void main (String args[])
    {      
        Vector strings = new Vector<String>(0,1);
        Scanner input = new Scanner(System.in);

        while (true)
        {
            System.out.print("Input a string: ");
            String word = input.next();
            strings.addElement(word);
            
            System.out.print("Do you want to enter new word?\nFalse or True\n>> ");
            Boolean flag = input.nextBoolean();

            if(!flag) break;
        }

        int capacity = strings.capacity();
        int sumLength = 0;

        for (int i = 0; i < capacity; i++) 
        {
            System.out.print(strings.elementAt(i) + "length: " + strings.elementAt(i).toString().length() + "\n");
            sumLength += strings.elementAt(i).toString().length();
        }

        double averageLength = sumLength / capacity;
        System.out.print("Average length of all the words is: " + averageLength + "\n");
        System.out.print("Words whose length is less than the average length:\n");

        for (int i = 0; i < capacity; i++) 
        {
            String word = strings.elementAt(i).toString();
            if (word.length() < averageLength) System.out.print("Word #" + (i + 1) + ": " + word);
        }

        input.close();
    }
}