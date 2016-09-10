#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void showArr(int * a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("[%d]", a[i]);
    }
    printf("\n");
}

void showAllTrueFalse(int n, int * a)
{
    if (n == 1)
    {
        a[0] = 0;
        showArr(a, 4);
        a[0] = 1;
        showArr(a, 4);
        return;
    }
    a[n-1] = 0;
    showAllTrueFalse(n-1, a);
    a[n-1] = 1;
    showAllTrueFalse(n-1, a);
}

int main(int argc, const char * argv[])
{
    int a[4] = {0};
    showAllTrueFalse(4, a);

    return 0;
}
