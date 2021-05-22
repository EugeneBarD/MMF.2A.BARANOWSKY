package com.company;

import java.util.concurrent.atomic.AtomicReferenceArray;

public class Polynomial
{
    private Array coefficients;
    private int polynomialPower;

    Polynomial()
    {
        coefficients = new Array(1);
        polynomialPower = 1;
    }

    Polynomial(int size)
    {
        coefficients = new Array(size);
        polynomialPower = size;
    }

    Polynomial(Array coefficients)
    {
        this.coefficients = new Array(coefficients);
        polynomialPower = coefficients.getSize();
    }

    Polynomial(Polynomial polynomial)
    {
        this.coefficients = new Array(polynomial.getCoefficients());
        this.polynomialPower = polynomial.getPolynomialPower();
    }

    public Array getCoefficients()
    {
        return coefficients;
    }

    public int getPolynomialPower()
    {
        return polynomialPower;
    }

    public void setCoefficients(Array coefficients)
    {
        this.coefficients = new Array(coefficients);
    }

    public void setPolynomialPower(int polynomialPower)
    {
        this.polynomialPower = polynomialPower;
    }

    public void show()
    {
        int size = coefficients.getSize();
        for (int i = 0; i < size; i++)
        {
            if (coefficients.getNumbers()[i] > 0 && i != 0)
            {
                System.out.print("+");
            }
            if (coefficients.getNumbers()[i] < 0)
            {
                System.out.print("-");
            }
            if ((this.polynomialPower - i) == 1 && coefficients.getNumbers()[i] == 1)
            {
                System.out.print("x");
                continue;
            }
            if((this.polynomialPower - i) == 1 && coefficients.getNumbers()[i] != 1)
            {
                System.out.print(Math.abs(coefficients.getNumbers()[i]) + "x");
                continue;
            }
            if((this.polynomialPower - i) != 1 && Math.abs(coefficients.getNumbers()[i]) == 1)
            {
                System.out.print("x^" + (this.polynomialPower - i));
                continue;
            }
            if((this.polynomialPower - i) != 1 && coefficients.getNumbers()[i] != 1)
            {
                System.out.print(Math.abs(coefficients.getNumbers()[i]) + "x^" + (this.polynomialPower - i));
            }
        }
    }
}
