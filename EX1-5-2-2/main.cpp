#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void showVec(vector<int> a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        printf("[%d]", a[i]);
    }
    printf("\n");
}

void showAllTrueFalse(int n, vector<int> a)
{
    if (n == 1)
    {
        a[0] = 0;
        showVec(a);
        a[0] = 1;
        showVec(a);
        return;
    }
    a[n-1] = 0;
    showAllTrueFalse(n-1, a);
    a[n-1] = 1;
    showAllTrueFalse(n-1, a);
}

void showAllTrueFalse(int n)
{
    showAllTrueFalse(n, vector<int>(n,0));
}

int main(int argc, const char * argv[])
{
    showAllTrueFalse(4);

    return 0;
}
