#include <iostream>

void leftShift(int *R , int n , int p)
{
    int t , i ;
    for(i = 0 ; i < p/2 ; i++)//逆置【0, ... , p-1】
    {
        t = R[i];
        R[i] = R[p-1-i];
        R[p-1-i] = t;
    }
    for(i = p ; i < (n+p)/2 ; i++)
    {
        t = R[i];
        R[i] = R[n-1-i+p];
        R[n-1-i+p] = t;
    }
    for( i = 0 ; i < n/2 ; i++)
    {
        t = R[i];
        R[i] = R[n-1-i];
        R[n-1-i] = t;
    }
}

int main()
{
    int a[10];
    for(int i = 0 ; i < 10 ; i++)
    {
        a[i] = i;
    }
    leftShift(a,10,5);
    for(int i = 0 ; i < 10 ; i++)
    std::cout << a[i] << std::endl;
    return 0;
}

