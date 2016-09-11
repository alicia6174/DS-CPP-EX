#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int getCnm(int n, int m)
{
    if ( n < 0 || m < 0 || m > n )
    {
        fprintf(stderr, "Please input non-negative integers n,m with n >= m!");
        exit(-1);
    }
    if ( m == 0 || m == n ) return 1;
    return getCnm(n-1, m-1) + getCnm(n-1, m);
}

int main(int argc, const char * argv[])
{
    for (int n = 0; n <= 4; ++n)
    {
        for (int m = 0; m <= n; ++m)
        {
            printf("%d", getCnm(n, m));
        }
        printf("\n");
    }

    return 0;
}
