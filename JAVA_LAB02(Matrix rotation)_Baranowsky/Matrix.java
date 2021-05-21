package com.company;

import java.util.Arrays;

public class Matrix
{
    Matrix(int size)
    {
        this.size = size;
        numbers = new int[size][size];
    }

    Matrix(Matrix matrix)
    {
        this.size = matrix.GetSize();
        this.numbers = new int[size][size];

        for (int i = 0; i < this.size; i++)
        {
            for (int j = 0; j < this.size; j++)
            {
                this.numbers[i][j] = matrix.GetNumbers()[i][j];
            }
        }
    }

    int GetSize()
    {
        return this.size;
    }

    int[][] GetNumbers()
    {
        return this.numbers;
    }

    void SetSize(int size)
    {
        if (size <= 0)
        {
            throw new IllegalArgumentException("Size must be positive number!");
        }

        this.size = size;
    }

    void SetNumbers(int [][] numbers)
    {
        if(numbers.length != this.numbers.length)
        {
            throw new IllegalArgumentException("Matrix size must be the same as original matrix!");
        }

        for (int i = 0; i < numbers.length; i++)
        {
            this.numbers[i] = Arrays.copyOf(numbers[i], numbers.length);
        }
    }

    void SetRandomNumbers()
    {
        for (int i = 0; i < this.size; i++)
        {
            for (int j = 0; j < this.size; j++)
            {
                this.numbers[i][j] = (int)(Math.random() * 2 * this.size) - this.size;
            }
        }
    }

    void Show()
    {
        for (int i = 0; i < this.size; i++)
        {
            System.out.println(Arrays.toString(numbers[i]));
        }
        System.out.println();
    }

    void ReverseOrthogonalRotate()
    {
        int[][] result = new int[this.size][this.size];
        for (int i = 0; i < this.size; i++)
        {
            for (int j = 0; j < this.size; j++)
            {
                result[this.size - j - 1][i] = this.numbers[i][j];
            }
        }

        for (int i = 0; i < this.size; i++)
        {
            for (int j = 0; j < this.size; j++)
            {
                this.numbers[i][j] = result[i][j];
            }
        }
    }

    private int [][] numbers;
    private int size;
}

