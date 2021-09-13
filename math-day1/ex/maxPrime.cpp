#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int j,i,dem=0;
    int n=9;
    for (i=n;i>=2;i=i-1)
    {
        dem=0;
        for (j=2;j<=sqrt(i);j++) 
        {
            if (i%j==0)
            {dem=dem+1;
            break;}
        }
        if (dem==0) 
            {
                cout<<"So nguyen to lon nhat nho hon "<<n<<" la "<<i;
                cout<<"\n";
                break;
            }
    }
    return 0;
}