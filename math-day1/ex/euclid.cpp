#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a % b);
}

int main(){
	int m=42, n=72;
	cout <<"UCLN la: " << gcd(m,n) <<"\n";
	return 0;
}