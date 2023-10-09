/*
PIC 10B 1A, Homework 4
Purpose: complex function
Author: Victor He
Date: 5/18/2022
*/
#ifndef COMPLEXVECTOR_H
#define COMPLEXVECTOR_H
#include "Complex.h"
#include <vector>
#include <iomanip>
#include <fstream>

class ComplexVector
{
public:
	// Constructs ComplexVector with name n
	ComplexVector(std::string n);

	// adds this ComplexVector to ComplexVector c
	void add(Complex c);

	// runs the recursive function n times
	Complex rfunct(int n);

	// returns string containing Complex number format
	std::string print() const;

	// returns string containing recursive Complex number format
	std::string printr() const;

	// returns Complex number at at list[a]
	Complex get_complex(int a) const;

	// overloader for stream output
	friend std::ostream& operator << (std::ostream& out, const ComplexVector& c);
	
	// overloader for ComplexVector addition
	friend ComplexVector operator + (ComplexVector const& a, ComplexVector const& b);

	// overloader for ComplexVector subtraction
	friend ComplexVector operator - (ComplexVector const& a, ComplexVector const& b);

	// overloader for ComplexVector multiplication
	friend ComplexVector operator * (ComplexVector const& a, ComplexVector const& b);

	// overloader for ComplexVector division
	friend ComplexVector operator / (ComplexVector const& a, ComplexVector const& b);

private:
	std::vector<Complex> list;
	std::string name;
};


#endif
