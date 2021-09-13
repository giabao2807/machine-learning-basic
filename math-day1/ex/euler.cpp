#include<iostream>
using namespace std;
 
int eulerPhi(int n) { 
    if (n == 0) return 0;
    int rs = n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i== 0) {
            rs -= rs / i;
            while (n % i== 0) n /= i;
        }
    }
    if (n > 1) rs -= rs / n;
    return rs;
}
 
int main(){
    int n=7;
    
    cout << "Phi = " << eulerPhi(n) << "\n";
    return 0;
}