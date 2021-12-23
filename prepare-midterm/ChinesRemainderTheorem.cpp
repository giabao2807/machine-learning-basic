#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modInverseVer1(int x, int m)
{
    int result;
    if (gcd(x, m) != 1)
        return -1;
    else
    {
        for (result = 1; result < m; result++)
        {
            if (((x % m) * (result % m)) % m == 1)
                return result;
        }
    }
    return result;
}

int findMinX(int num[], int rem[], int k)
{
    int prod = 1, result = 0;
    for (int i = 0; i < k; i++)
    {
        prod *= num[i]; // Find X = m1*m2*m3...*mk
    }
    for (int i = 0; i < k; i++)
    {
        int p = prod / num[i]; // Find X1, X2, X3
        result += rem[i] * p * modInverseVer1(p, num[i]);
    }
    return result % prod;
}

int main()
{
    int num[] = {2, 3, 5};
    int rem[] = {3, 5, 7};
    int k = sizeof(num) / sizeof(num[0]);
    long X = 1;
    for (int i = 0; i < k; i++)
    {
        X *= num[i];
    }
    cout << "\n\n\n\n";
    cout << "x = " << findMinX(num, rem, k) << "(mod " << X << ")";
    cout << "\n\n\n";
    return 0;
}