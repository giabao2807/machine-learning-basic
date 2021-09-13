#include<iostream>
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
    int a = 5, b = 7;
    int lcm = a * b / gcd(a, b);
    
    cout << "BCNN la: " << lcm << "\n";
    return 0;
}