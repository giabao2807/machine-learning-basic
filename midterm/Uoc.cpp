#include <iostream>
#include <stdio.h>

int SoUoc(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;
    }
    return count;
}

int tongUoc(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}
unsigned long long tichUoc(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            p *= i;
    }
    return p;
}
int main()
{
    int n = 1000;
    printf("So cac uoc cua 1000: %d", SoUoc(n));
    printf("\n");
    printf("Tong cac uoc cua 1000: %d", tongUoc(n));
    printf("\n");
    printf("Tich cac uoc cua 1000: %lld", tichUoc(n));
    printf("\n");
    return 0;
}