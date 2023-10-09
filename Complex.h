/*
PIC 10B 1A, Homework 4
Purpose: complex function
Author: Victor He
Date: 5/18/2022
*/
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

class Complex
{
public:
	/*
		Constructs a Complex with real, a and i, b
	*/
	Complex(double a, double b);

	/*
		Default constructor sets both real and i to 1
	*/
	Complex();

	/*
		retruns a string containing Complex number format
	*/
	std::string get_number() const;

	/*
		retruns a string containing the recursive Complex number format
	*/
	std::string get_rnumber() const;

	/*
		retruns a double containing the real number
	*/
	double get_real() const;

	/*
		retruns a double containing the i number
	*/
	double get_i() const;

	/*
		adds this Complex number to Complex c
	*/
	void add(const Complex& c);

	/*
		subtracts this Complex number to Complex c
	*/
	void sub(const Complex& c);

	/*
		multiplies this Complex number to Complex c
	*/
	void multiply(const Complex& c);

	/*
		divides this Complex number to Complex c
	*/
	void divide(const Complex& c);

private:
	std::string number;
	double real, i;
};


#endif

