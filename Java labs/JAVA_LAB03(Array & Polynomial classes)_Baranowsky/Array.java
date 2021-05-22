package com.company;

import java.util.Arrays;

public class Array
{
    private int size;
    private double[] numbers;

    Array()
    {
        this.size = 1;
        this.numbers = new double[1];
    }

    Array(int size)
    {
        this.size = size;
        this.numbers = new double[size];
    }

    Array(Array array)
    {
        this.size = array.getSize();
        this.numbers = Arrays.copyOf(array.getNumbers(), array.getSize());
    }

    public double[] getNumbers()
    {
        return Arrays.copyOf(this.numbers, this.size);
    }

    public int getSize()
    {
        return this.size;
    }

    public void setNumbers(double[] numbers) throws Exception
    {
        if(numbers.length != this.numbers.length)
        {
            throw new IllegalArgumentException("Size of entered array must be equal to size of original array!");
        }
        this.numbers = Arrays.copyOf(numbers, numbers.length);
    }

    public void setSize(int size) throws Exception
    {
        if(size <= 0)
        {
            throw new IllegalArgumentException("Size must be positive!");
        }
        this.size = size;
    }
}
