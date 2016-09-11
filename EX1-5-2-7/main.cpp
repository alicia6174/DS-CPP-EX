#include <stdio.h>

int getNthFib_itr(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int ret = 1;
    int tmp1;
    int tmp2 = 0;
    for (int i = 2; i <= n; ++i)
    {
        tmp1 = ret;
        ret += tmp2;
        tmp2 = tmp1;
    }
    return ret;
}

int getNthFib_rec(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getNthFib_rec(n-2) + getNthFib_rec(n-1);
}

int main(int argc, const char * argv[])
{
    for (int i = 0; i <= 10; ++i)
    {
        //printf("%d\n", getNthFib_itr(i));
        printf("%d\n", getNthFib_rec(i));
    }

    return 0;
}
