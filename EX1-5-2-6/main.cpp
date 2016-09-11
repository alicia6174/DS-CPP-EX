#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int getNthFac_itr(int n)
{
    if (n <= 1) return 1;
    int ret = 1;
    for (int i = 1; i <= n; ++i)
    {
        ret *= i;
    }
    return ret;
}

int getNthFac_rec(int n)
{
    if (n <= 1) return 1;
    return n * getNthFac_rec(n-1);
}

int main(int argc, const char * argv[])
{
    for (int i = 0; i <= 10; ++i)
    {
        //printf("%d\n", getNthFac_itr(i));
        printf("%d\n", getNthFac_rec(i));
    }

    return 0;
}
