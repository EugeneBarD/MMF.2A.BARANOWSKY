package com.company;

import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
		Scanner in = new Scanner(System.in);
	    System.out.println("Enter size of matrix: ");

	    int size = in.nextInt();
	    Matrix matrix = new Matrix(size);
	    matrix.SetRandomNumbers();

		System.out.println("Original matrix: ");
		matrix.Show();

		matrix.ReverseOrthogonalRotate();
	    System.out.println("Matrix rotated 90 degrees counterclockwise: ");
		matrix.Show();
    }
}
