#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b;
        }else{
            b -= a;
        }
    }
    return a; 
}

int main(){
	int m=42, n=72;
	cout <<"UCLN la: " << gcd(m,n) << "\n";
	return 0;
}