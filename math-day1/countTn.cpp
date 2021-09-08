#include <iostream>
using namespace std;
long Dem_UocSo(long N)
{
    long dem = 0;
    for (long i = 1; i <= N; i++)
    {
        if (N % i == 0)
            dem++;
    }

    return dem;
}

int main()
{
    long n=2000;
    for(long i =0;i<n;i++){
        if(Dem_UocSo(i)==10){
            printf("%ld có số ước là 10\n",i);
            break;
        }
    }
    return 0;
}