#include <stdio.h>
#include <math.h>
 
int main() {
    int n=9;
    int i;
    printf("%d = ", n);
 
    for (i = 2; i <= n; i++) {
        while(n % i == 0) {
            printf("%d.", i);
            n /= i;
        }
    }
    return 0;
}