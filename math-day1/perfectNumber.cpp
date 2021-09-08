#include<stdio.h>
bool checkNum(int n){
    int sum = 0;
    for(int i=1;i<=n/2;i++){
        if(n%i==0)
            sum+=i;
    }
    if(sum==n) return true;
    return false;
}
int main(){
    for(int i =1;i< 3000; i++) {
        if(checkNum(i)){
            printf("%d\n", i);
    }
    }
    return 0;
}