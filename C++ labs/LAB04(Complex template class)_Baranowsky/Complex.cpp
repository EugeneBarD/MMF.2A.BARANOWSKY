#include "Complex.h"
#include <iostream>

using namespace std;

template<typename T>
Complex<T>::Complex(T real, T imaginary)
{
	SetComplex(real, imaginary);
}

template<typename T>
Complex<T>::Complex(const Complex& complex)
{
	this->real = complex.real;
	this->imaginary = complex.imaginary;
}

template<typename T>
void Complex<T>::SetRealPart(T real)
{
	this->real = real;
}

template<typename T>
void Complex<T>::SetImaginaryPart(T imaginary)
{
	this->imaginary = imaginary;
}

template<typename T>
void Complex<T>::SetComplex(T real, T imaginary)
{
	SetRealPart(real);
	SetImaginaryPart(imaginary);
}

template<typename T>
T Complex<T>::GetRealPart()
{
	return this->real;
}

template<typename T>
T Complex<T>::GetImaginaryPart()
{
	return this->imaginary;
}

template<typename T>
void Complex<T>::Display()
{
	if (this->imaginary != 0)
	{
		if (this->imaginary > 0) cout << this->real << " + " << this->imaginary << "i";
		else cout << this->real << " + (" << this->imaginary << ")i";
	}
	else cout << this->real;
}

template<typename T>
void Complex<T>::EnterComplex()
{
	T real = 0, imaginary = 0;
	cout << "Enter real part of complex number: ";
	cin >> real;
	cout << "Enter imaginary part of complex number: ";
	cin >> imaginary;
	this->SetComplex(real, imaginary);
}

template<typename T>
const Complex<T> Complex<T>::operator+ (const Complex<T>& complex)
{
	Complex resultComplex;
	resultComplex.real = this->real + complex.real;
	resultComplex.imaginary = this->imaginary + complex.imaginary;
	return resultComplex;
}

template<typename T>
const Complex<T> Complex<T>::operator- (const Complex<T>& complex)
{
	Complex resultComplex;
	resultComplex.real = this->real - complex.real;
	resultComplex.imaginary = this->imaginary - complex.imaginary;
	return resultComplex;
}

template<typename T>
const Complex<T> Complex<T>::operator* (const Complex<T>& complex)
{
	T x1 = this->real, y1 = this->imaginary, x2 = complex.real, y2 = complex.imaginary;
	Complex resultComplex;
	resultComplex.real = x1 * x2 - y1 * y2;
	resultComplex.imaginary = x1 * y2 + x2 * y1;
	return resultComplex;
}

template<typename T>
const Complex<T> Complex<T>::operator/ (const Complex<T>& complex)
{
	T x1 = this->real, y1 = this->imaginary, x2 = complex.real, y2 = complex.imaginary;
	Complex resultComplex;
	resultComplex.real = round(((x1 * x2 + y1 * y2) / (x2 * x2 + y2 * y2)) * 100)/100;
	resultComplex.imaginary = -round(((x1 * y2 - x2 * y1) / (x2 * x2 + y2 * y2)) * 100) / 100;
	return resultComplex;
}

template<typename T>
const Complex<T>& Complex<T>::operator= (const Complex<T>& complex)
{
	this->real = complex.real;
	this->imaginary = complex.imaginary;

	return *this;
}