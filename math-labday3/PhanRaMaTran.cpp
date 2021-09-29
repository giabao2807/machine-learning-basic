// PhanRaMaTran.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
#include "Polynomial.h"
#include <vector>

using namespace std;
int main()
{
	//Matrix<double> p(4, 4);
	//p.at(0, 0) = 2;
	//p.at(0, 1) = 1;
	//p.at(0, 2) = 4;
	//p.at(0, 3) = 4;

	//p.at(1, 0) = 1;
	//p.at(1, 1) = 2 ;
	//p.at(1, 2) = 5;
	//p.at(1, 3) = 4;

	//p.at(2, 0) = 8;
	//p.at(2, 1) = 7;
	//p.at(2, 2) = 6;
	//p.at(2, 3) = 3;

	//p.at(3, 0) = 26;
	//p.at(3, 1) = 7;
	//p.at(3, 2) = 5;
	//p.at(3, 3) = 2 ;


	Matrix<double> p(2, 2);
	p.at(0, 0) = 2;
	p.at(1, 1) = 2;
	
	p.at(0, 1) = 1;
	p.at(1, 0) = 1;

	Matrix<double> a,b;
	p.Decomposition(a,b);
	cout << a << endl << b;

}


