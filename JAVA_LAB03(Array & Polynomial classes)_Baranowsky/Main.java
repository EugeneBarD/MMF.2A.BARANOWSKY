package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of coefficients: ");
        int size = in.nextInt();

        double[] numbers = new double[size];

        for (int i = 0; i < size; i++)
        {
            System.out.print((i + 1) + "# number: ");
            numbers[i] = in.nextInt();
        }

        Array coefficients = new Array(size);
        coefficients.setNumbers(numbers);

        System.out.println("\nYour coefficients: ");
        for (int i = 0; i < size; i++)
        {
            System.out.print(coefficients.getNumbers()[i] + " ");
        }

        Polynomial polynomial = new Polynomial(coefficients);
        System.out.println("\nYour polynomial: ");
        polynomial.show();
    }
}
