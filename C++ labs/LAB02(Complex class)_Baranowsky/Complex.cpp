#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex(double real, double imaginary)
{
	SetComplex(real, imaginary);
}

Complex::Complex(const Complex& complex)
{
	this->real = complex.real;
	this->imaginary = complex.imaginary;
}

void Complex::SetRealPart(double real)
{
	this->real = real;
}

void Complex::SetImaginaryPart(double imaginary)
{
	this->imaginary = imaginary;
}

void Complex::SetComplex(double real, double imaginary)
{
	SetRealPart(real);
	SetImaginaryPart(imaginary);
}

double Complex::GetRealPart()
{
	return this->real;
}

double Complex::GetImaginaryPart()
{
	return this->imaginary;
}

void Complex::Display()
{
	if (this->imaginary != 0)
	{
		if (this->imaginary > 0) cout << this->real << " + " << this->imaginary << "i";
		else cout << this->real << " + (" << this->imaginary << ")i";
	}
	else cout << this->real;
}

void Complex::EnterComplex()
{
	double real = 0, imaginary = 0;
	cout << "Enter real part of complex number: ";
	cin >> real;
	cout << "Enter imaginary part of complex number: ";
	cin >> imaginary;
	this->SetComplex(real, imaginary);
}

const Complex Complex::operator+ (const Complex& complex)
{
	Complex resultComplex;
	resultComplex.real = this->real + complex.real;
	resultComplex.imaginary = this->imaginary + complex.imaginary;
	return resultComplex;
}

const Complex Complex::operator- (const Complex& complex)
{
	Complex resultComplex;
	resultComplex.real = this->real - complex.real;
	resultComplex.imaginary = this->imaginary - complex.imaginary;
	return resultComplex;
}

const Complex Complex::operator* (const Complex& complex)
{
	double x1 = this->real, y1 = this->imaginary, x2 = complex.real, y2 = complex.imaginary;
	Complex resultComplex;
	resultComplex.real = x1 * x2 - y1 * y2;
	resultComplex.imaginary = x1 * y2 + x2 * y1;
	return resultComplex;
}

const Complex Complex::operator/ (const Complex& complex)
{
	double x1 = this->real, y1 = this->imaginary, x2 = complex.real, y2 = complex.imaginary;
	Complex resultComplex;
	resultComplex.real = round(((x1 * x2 + y1 * y2) / (x2 * x2 + y2 * y2)) * 100)/100;
	resultComplex.imaginary = -round(((x1 * y2 - x2 * y1) / (x2 * x2 + y2 * y2)) * 100) / 100;
	return resultComplex;
}

const Complex& Complex::operator= (const Complex& complex)
{
	this->real = complex.real;
	this->imaginary = complex.imaginary;

	return *this;
}