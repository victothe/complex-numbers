/*
PIC 10B 1A, Homework 4
Purpose: complex function
Author: Victor He
Date: 5/18/2022
*/

#include "Complex.h"

Complex::Complex()
{
	real = 1;
	i = 1;
}

Complex::Complex(double a, double b)
{
	real = a;
	i = b;
}

std::string Complex::get_number() const
{
	std::ostringstream o;
	o << std::right << std::setw(3) << std::fixed << std::setprecision(1) << real;
	if (i < 0)
	{
		o << std::right << std::setw(3) << " - " << std::right << std::setw(3) << abs(i) << std::right << std::setw(3) << "i ";
		std::string output = o.str();
		return output;
	}
	o << std::right << std::setw(3) << " + " << std::right << std::setw(3) << i << std::right << std::setw(3) << "i ";
	std::string output = o.str();
	return output;
}

std::string Complex::get_rnumber() const
{
	std::ostringstream o;
	o << std::right << std::setw(3) << std::setprecision(6) << real;
	if (i < 0)
	{
		o << std::right << std::setw(3) << " - " << std::right << std::setw(3) << abs(i) << std::right << std::setw(3) << "i ";
		std::string output = o.str();
		return output;
	}
	o << std::right << std::setw(3) << " + " << std::right << std::setw(3) << i << std::right << std::setw(3) << "i ";
	std::string output = o.str();
	return output;
}

double Complex::get_i() const
{
	return i;
}

double Complex::get_real() const
{
	return real;
}

void Complex::add(const Complex& c)
{
	real += c.get_real();
	i += c.get_i();
}

void Complex::sub(const Complex& c)
{
	real -= c.get_real();
	i -= c.get_i();
}

void Complex::multiply(const Complex& c)
{
	double r = (real * c.get_real()) - (i * c.get_i());
	double im = (i * c.get_real()) + (real * c.get_i());
	real = r;
	i = im;
}

void Complex::divide(const Complex& c)
{
	double r = ((real * c.get_real()) + (i * c.get_i())) / (c.get_real() * c.get_real() + c.get_i() * c.get_i());
	double im = ((i * c.get_real()) - (real * c.get_i())) / (c.get_real() * c.get_real() + c.get_i() * c.get_i());
	real = r;
	i = im;
}