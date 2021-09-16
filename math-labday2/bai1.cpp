//1. Viết CT tính a^m mod n

#include <iostream>
using namespace std;

int sqr(int x){
	return x*x;
}

int mod(int a, int m, int n)
{
	if(m==0 ) return 1%n;
	if (m%2==0) return sqr(pow(a,m/2))%n;
	if(m%2==1) return a*(sqr(pow(a,m/2))%n)%n;
	return 0;
}

int main(){
	int a=2;
	int m=5;
	int n =10;
	cout<< "so du la: " << mod(a,m,n) << "\n" ;
	return 0;
}