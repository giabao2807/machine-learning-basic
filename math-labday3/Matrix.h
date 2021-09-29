#pragma once
#include<iostream>
#include<assert.h>
#include"Polynomial.h"
using namespace std;

#define MATRIX_MAX 10
template <class T>
struct Matrix
{

public:
	T arr[MATRIX_MAX][MATRIX_MAX];
	int n_r;
	int n_c;


	Matrix(int n_of_rows=1, int n_of_cols=1)
		:n_r(n_of_rows), n_c(n_of_cols)
	{
		for (int i = 0; i < MATRIX_MAX; i++)
			for (int j = 0; j < MATRIX_MAX; j++)
				arr[i][j] = 0;
	}
private:
	Matrix remove_row(int row)
	{
		Matrix m = *this;
		for (int i = row; i < m.n_r - 1; i++)
			for (int j = 0; j < m.n_c; j++)
				m.arr[i][j] = m.arr[i + 1][j];
		m.n_r--;
		return m;
	}
	Matrix remove_col(int col)
	{
		Matrix m = *this;
		for (int i = col; i < m.n_c - 1; i++)
			for (int j = 0; j < m.n_r; j++)
				m.arr[j][i] = m.arr[j][i + 1];
		m.n_c--;
		return m;
	}
public:
	/*Tinh dinh thuc bang bareiss*/
	T det()
	{
		if (n_r != n_c) assert("");
		Matrix m = *this;
		Matrix n = m;
		for (int r = 0; r < n_r; r++)
		{

			T pivot = ( r == 0 ? 1 : m.arr[r - 1][r - 1]);
			for (int i = 0; i < n_r; i++)
			{
				if (r == i) continue;


				for (int j = 0; j < n_r; j++)
					n.arr[i][j] = (m.arr[r][r] * m.arr[i][j] - m.arr[i][r] * m.arr[r][j]) / pivot;
			}
			m = n;
		}
		return m.arr[n_r - 1][n_r - 1];
	}

	T& at(int row,int col) {
		return arr[row][col];
	}

	Matrix InverseMatrix() 
	{
		Matrix m = *this;
		T determinant = this->det();
		cout << determinant << endl;
		for (int i = 0; i < n_r; i++)
			for (int j = 0; j < n_r; j++)
				m.arr[i][j] = 1 / determinant * pow(-1, i + j) * this->remove_col(i).remove_row(j).det();
		return m;
	}

	void Decomposition(Matrix& eigenvectors, Matrix& eigenvalues)
	{
		Matrix<Polynomial> polyMatrix = Matrix<Polynomial>(n_r, n_c);
		for (int i = 0; i < n_r; i++)
			for (int j = 0; j < n_c; j++)
			{
				if (i == j) polyMatrix.at(i, j) = arr[i][j] - Polynomial(1, 1);
				else polyMatrix.at(i, j) = arr[i][j];
			}
		vector<double> eigenval = polyMatrix.det().solve();
		eigenvectors = Matrix<double>(n_r, n_c);
		eigenvalues = Matrix<double>(n_r, n_c);
		for (unsigned int i = 0; i < n_r; i++)
		{
			eigenvalues.arr[i][i] =eigenval[i];
		}
		for (unsigned int value_i=0; value_i < eigenval.size(); value_i++)
		{
			Matrix<double> temp = *this;
			for (unsigned int i=0; i < n_r; i++)
			{
				temp.arr[i][i] = temp.arr[i][i] - eigenval[value_i];
			}
			for (int i = 0; i < n_r; i++)
			{
				for (int j = i+1; j < n_r; j++)
				{
					double factor = -temp.arr[j][i] / temp.arr[i][i];
					for (int k = 0; k < n_r; k++)
					{
						temp.arr[j][k] = temp.arr[i][k] * factor + temp.arr[j][k];
						if (fabs(temp.arr[j][k]) < EPSILON*10) temp.arr[j][k] = 0;
					}
				}
			}
			eigenvectors.arr[n_r - 1][value_i] = 1;
			for (int i = n_r - 2; i >= 0; i--)
			{
				double s =0;
				for (int j = i+1; j < n_r; j++)
				{
					s = s + temp.arr[i][j] * eigenvectors.arr[j][value_i];
				}
				eigenvectors.arr[i][value_i] = -s / temp.arr[i][i];
			}
		}

	}



	

	friend ostream& operator<<(ostream& os, const Matrix& matrix)
	{
		for (int i = 0; i < matrix.n_r; i++)
		{
			for (int j = 0; j < matrix.n_c; j++)
				os << matrix.arr[i][j] <<", ";
			os << endl;
		}
		return os;
	}

	friend istream& operator>>(istream& is, Matrix& matrix) {
		is >> matrix.n_r >> matrix.n_c;
		for (int i = 0; i < matrix.n_r; i++)
			for (int j = 0; j < matrix.n_c; j++)
				is >> matrix.arr[i][j];
		return is;
	}

};

