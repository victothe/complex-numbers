/*
PIC 10B 1A, Homework 4
Purpose: complex function
Author: Victor He
Date: 5/18/2022
*/
#include "ComplexVector.h"
#
ComplexVector::ComplexVector(std::string n)
{
	name = n;
}

void ComplexVector::add(Complex c)
{
	list.push_back(c);
}

Complex ComplexVector::rfunct(int n)
{
	Complex base(1, 1);
	int m = n - 1;
	if (n <= 1) // base case
	{
		list.push_back(base);
		return base;
	}
	else
	{
		Complex num(2 * m, 3 * m);
		Complex dem(7, 5 * m * m);
		num.divide(dem);
		num.multiply(rfunct(n - 1)); // multiplies the Complex number by the previous one in the sequence
		list.push_back(num);
		return num;
	}
}

std::string ComplexVector::print() const
{
	std::string all;
	all += name + " = { ";
	for (int i = 0; i < list.size(); i++)
	{
		all += list[i].get_number();
		if (i == list.size() - 1)
		{
			continue;
		}
		all += " , ";
	}
	all += " } ";
	return all;
}

std::string ComplexVector::printr() const
{
	std::string all;
	all += name + " = { ";
	for (int i = 0; i < list.size(); i++)
	{
		all += list[i].get_rnumber();
		if (i == list.size() - 1)
		{
			continue;
		}
		all += " , ";
	}
	all += " } ";
	return all;
}

Complex ComplexVector::get_complex(int a) const
{
	return list[a];
}

std::ostream& operator << (std::ostream& out, const ComplexVector& c)
{
	if (c.name == "v2" || c.name == "v1")
	{
		out << "     "; 
	}
	out << c.print();
	return out;
}

ComplexVector operator + (ComplexVector const& a, ComplexVector const& b)
{
	ComplexVector add = a;
	add.name = a.name + " + " + b.name;
	for (int i = 0; i < a.list.size(); i++)
	{
		add.list[i].add(b.list[i]);
	}
	
	return add;
}

ComplexVector operator - (ComplexVector const& a, ComplexVector const& b)
{
	ComplexVector minus = a;
	minus.name = a.name + " - " + b.name;
	for (int i = 0; i < a.list.size(); i++)
	{
		minus.list[i].sub(b.list[i]);
	}

	return minus;
}

ComplexVector operator * (ComplexVector const& a, ComplexVector const& b)
{
	ComplexVector mult = a;
	mult.name = a.name + " * " + b.name;
	for (int i = 0; i < a.list.size(); i++)
	{
		mult.list[i].multiply(b.list[i]);
	}

	return mult;
}

ComplexVector operator / (ComplexVector const& a, ComplexVector const& b)
{
	ComplexVector div = a;
	div.name = a.name + " / " + b.name;
	for (int i = 0; i < a.list.size(); i++)
	{
		div.list[i].divide(b.list[i]);
	}

	return div;
}