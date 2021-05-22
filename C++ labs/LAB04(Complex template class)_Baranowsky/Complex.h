#pragma once

template<typename T>

class Complex
{
public:
	Complex() {};
	Complex(const Complex&);
	Complex(T, T);
	~Complex() {};

	void SetRealPart(T);
	void SetImaginaryPart(T);
	void SetComplex(T, T);
	T GetRealPart();
	T GetImaginaryPart();
	void Display();
	void EnterComplex();

	const Complex operator+ (const Complex&);
	const Complex operator- (const Complex&);
	const Complex operator* (const Complex&);
	const Complex operator/ (const Complex&);
	const Complex& operator= (const Complex&);
private:
	T real = 0, imaginary = 0;
};
