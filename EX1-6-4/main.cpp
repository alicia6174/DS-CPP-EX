#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int countIniVal(int * a, int n)
{
    return count(a, a+n, a[0]);
}

int main(int argc, const char * argv[])
{
    int a[10] = {1, 6, 2, 1, 8, 1, 4, 1, 3, 0};
    printf("%d\n", countIniVal(a, 10));

    return 0;
}
