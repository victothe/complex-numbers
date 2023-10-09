/*
PIC 10B 1A, Homework 4
Purpose: complex function
Author: Victor He
Date: 5/18/2022
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Complex.h"
#include "ComplexVector.h"
using namespace std;

int main()
{
	// initializing the Complex numbers to be in the ComplexVector
	Complex a1(2.0, 4.0), a2(3.0, 5.0), a3(-1.0, -3.0), a4(8.0, 10.0);
	Complex b1(-10.0, 3.5), b2(4.0, 7.3), b3(2.0, -8.0), b4(10.0, -142.0);

	// initializes ComplexVectors and adds Complex numbers to their respective
	ComplexVector a("v1");
	a.add(a1);
	a.add(a2);
	a.add(a3);
	a.add(a4);
	ComplexVector b("v2");
	b.add(b1);
	b.add(b2);
	b.add(b3);
	b.add(b4);

	// outputs ComplexVector v1 and v2 using operator overloaded "<<"
	cout << a << endl;
	cout << b << endl;

	// adds ComplexVector v1 and v2 using operator overloaded "+"
	ComplexVector addition = a + b;
	cout << addition << endl;

	// subtracts ComplexVector v1 and v2 using operator overloaded "-"
	ComplexVector subtraction = a - b;
	cout << subtraction << endl;

	// multiplies ComplexVector v1 and v2 using operator overloaded "*"
	ComplexVector multiplication = a * b;
	cout << multiplication << endl;

	// divides ComplexVector v1 and v2 using operator overloaded "/"
	ComplexVector division = a / b;
	cout << division << endl << endl;

	// opens textfile, initializes a ComplexVector to run the recursive function, and prints the ComplexVector to the text file
	ofstream fout;
	fout.open("ComplexSequence.txt");
	ComplexVector recursive("funct");
	recursive.rfunct(6);
	fout << recursive.printr();
	cout << "Writing Complex Sequence to File ... Done" << endl;
	fout.close();

	return 0;
}