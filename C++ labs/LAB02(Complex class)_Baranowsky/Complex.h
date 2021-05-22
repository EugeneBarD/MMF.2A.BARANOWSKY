#pragma once
class Complex
{
public:
	Complex() {};
	Complex(const Complex&);
	Complex(double, double);
	~Complex() {};

	void SetRealPart(double);
	void SetImaginaryPart(double);
	void SetComplex(double, double);
	double GetRealPart();
	double GetImaginaryPart();
	void Display();
	void EnterComplex();

	const Complex operator+ (const Complex&);
	const Complex operator- (const Complex&);
	const Complex operator* (const Complex&);
	const Complex operator/ (const Complex&);
	const Complex& operator= (const Complex&);
private:
	double real = 0, imaginary = 0;
};
