#include<iostream>
#include<math.h>

using namespace std;
class norm
{
    public:
    static int norm_p(int A[], int n, int p);
    static int norm_two(int A[], int n){
        int x = 0;
        for(int i = 0; i< n; i++){
            x += A[i]*A[i];
        }
        return pow(x,1/2);
    }
    static int norm_one(int A[], int n){
        int x = 0;
         for(int i = 0; i< n; i++){
            x += A[i];
        }
        return x;
    }
    static int norm_vo_cung(int A[], int n){
        int x = INT_MIN;
         for(int i = 0; i< n; i++){
            if(x<A[i]) x = A[i];
        }
        return x;
    }
};
int main(){
    int A[] = {2,3,4,5};
    int B[] ={3,4};
    cout << norm::norm_one(A, 1);
}