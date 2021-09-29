#pragma once
#include<iostream>
#include<vector>
using namespace std;
struct Monomial
{
	double coefficient;
	int degree;
	Monomial(double coefficient = 0, int degree = 1)
	{
		this->coefficient = coefficient;
		this->degree = degree;
	}
};
struct  Polynomial
{
	vector<Monomial> arr;

public:
	void addMono(double coefficient, int degree)
	{
		if (coefficient == 0) return;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			if (arr.at(i).degree == degree)
			{
				arr.at(i).coefficient += coefficient;
				if (arr.at(i).coefficient == 0)
				{
					arr.erase(arr.begin() + i);
				}
				return;
			}
			else if (arr.at(i).degree < degree)
			{
				arr.insert(arr.begin() + i, Monomial(coefficient, degree));
				return;
			}
		}
		arr.push_back(Monomial(coefficient, degree));
	}

	Polynomial(double coefficient = 0, int degree = 0)
	{
		addMono(coefficient, degree);
	}

	Polynomial derivative()
	{
		Polynomial rs;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			rs.addMono(arr[i].coefficient * arr[i].degree, arr[i].degree - 1);
		}
		return rs;
	}

	double calc(double a)
	{
		double s = 0;
		for (uint32_t i = 0; i < arr.size(); i++)
		{
			s = s + arr[i].coefficient * pow(a, arr[i].degree);
		}
		return s;
	}
	double get_coefficient(int degree)
	{
		for (uint32_t i = 0; i < arr.size(); i++)
		{
			if (arr[i].degree == degree) return arr[i].coefficient;
		}
		return 0;
	}
#define EPSILON pow(10,-14)
	double newton(double a, double b)
	{
		Polynomial der = this->derivative();
		while (fabs(der.calc(a)) <EPSILON || fabs(der.calc(b))<EPSILON) 
		{
			double x = (a + b) / 2;
			double s = this->calc(x);
			if (s == 0) return s;
			if (s * this->calc(a) > 0) a = x;
			else b = x;
		}
		double x = this->calc(a) * der.calc(a) > 0 ? a : b;
		while (this->calc(x)!=0)
		{
			double y = x - this->calc(x) / der.calc(x);
			if (fabs(x-y)<EPSILON) break;
			x = y;
		}
		
		return x;
	}
#define INF pow(10,10)
	vector<double> solve()
	{
		if (arr.size() == 0 || arr[0].degree == 0) throw "";
		vector<double> rs;
		if (arr[0].degree == 1) 
		{
			rs.push_back(-get_coefficient(0) / get_coefficient(1));
			return rs;
		}
		Polynomial der = this->derivative();
		
		vector<double> s_ser = der.solve();
		
		s_ser.insert(s_ser.begin(), -INF);
		s_ser.push_back(INF);
		for (unsigned int i = 0; i < s_ser.size()-1; i++)
		{

			//nghiệm kép
			if (fabs(this->calc(s_ser[i + 1])) <EPSILON)
			{
				rs.push_back(s_ser[i + 1]);
				i = i + 1;
				continue;
			}
			if (this->calc(s_ser[i]) * this->calc(s_ser[i + 1]) < 0)
			{
				rs.push_back(this->newton(s_ser[i], s_ser[i + 1]));
			}
		}
		return rs;
	}

	

	friend bool operator==(const Polynomial& A, const Polynomial& B)
	{
		if (A.arr.size() != B.arr.size()) return false;
		for (int i = 0; i < A.arr.size(); i++)
		{
			if (A.arr.at(i).coefficient != B.arr.at(i).coefficient)
				return false;
			if (A.arr.at(i).degree != B.arr.at(i).degree)
				return false;
		}
		return true;
	}

	friend Polynomial operator+(const Polynomial& A, const Polynomial& B)
	{
		Polynomial rs = A;
		for (unsigned int i = 0; i < B.arr.size(); i++)
		{
			rs.addMono(B.arr.at(i).coefficient, B.arr.at(i).degree);
		}
		return rs;
	}
	friend Polynomial operator-(const Polynomial& A, const Polynomial& B)
	{
		Polynomial rs = A;
		for (unsigned int i = 0; i < B.arr.size(); i++)
		{
			rs.addMono(-B.arr.at(i).coefficient, B.arr.at(i).degree);
		}
		return rs;
	}
	friend Polynomial operator*(const Polynomial& A, const Polynomial& B)
	{
		Polynomial rs;
		for (unsigned int i = 0; i < A.arr.size(); i++)
		{
			for (unsigned int j = 0; j < B.arr.size(); j++)
			{
				rs.addMono(A.arr.at(i).coefficient * B.arr.at(j).coefficient, A.arr.at(i).degree + B.arr.at(j).degree);
			}
		}
		return rs;
	}
	friend Polynomial operator/(const Polynomial& A, const Polynomial& B)
	{
		if (B == 0) throw "";
		if (A == 0 || A.arr.at(0).degree < B.arr.at(0).degree) return 0;
		Polynomial rs = Polynomial(A.arr.at(0).coefficient / B.arr.at(0).coefficient, A.arr.at(0).degree - B.arr.at(0).degree);
		return rs + (A - (rs * B)) / B;
	}

	friend ostream& operator<<(ostream& os, const Polynomial& p)
	{
		if (p.arr.size() == 0)
		{
			os << 0;
		}
		else
		{
			for (unsigned int i = 0; i < p.arr.size(); i++)
			{
				os << p.arr.at(i).coefficient << "x^" << p.arr.at(i).degree;
				if (i != p.arr.size() - 1) os << " + ";
			}
		}
		return os;
	}
	friend istream& operator>>(istream& is, Polynomial& p)
	{
		p.arr.clear();
		int n;
		is >> n;
		for (int i = 0; i < n; i++)
		{
			double a; int b;
			is >> a >> b;
			p.addMono(a, b);
		}
		return is;
	}


};

