#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

void showArr(int * a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("[%d]", a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[])
{
    const int n = 10;
    int a[n];
    showArr(a, n);
    fill(a, a+n, 0);
    showArr(a, n);

    return 0;
}
