#include <iostream>
using namespace std;

double Norm(int a[10][10], int row, int col, int p)
{
	double s = 0.0;
	if (p == 1)
	{
		for (int i = 0; i < col; i++)
		{
			double tempt = 0.0;
			for (int j = 0; j < row; j++)
			{
				tempt += a[i][j];
			}
			if (tempt > s)
			{
				s = tempt;
			}
		}
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				s += pow(a[i][j],2);
			}
		}
		s = pow(s, 1.0 / 2);
	}
	return s;
}
void nhap(double arr[10][10], int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
void xuat(double arr[10][10], int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int main()
{
	int arr[10][10];
	int n = 2;
	int m = 3;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
      {
        arr[i][j] = rand()%(15);
      }
 	}
	for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++) cout<<arr[i][j]<< " " ;
    	cout<<"\n";
    }
	cout << Norm(arr, n, m, 3);
}