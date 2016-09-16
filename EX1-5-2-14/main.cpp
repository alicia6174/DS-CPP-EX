#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void showArrWrtTrueFalse(vector<int> a, vector<char> s)
{
    printf("{");

    bool first = false;

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == 1)
        {
            if (first)
            {
               printf(",");
            }
            first = true;

            printf("%c", s[i]);

        }
    }
    printf("}");
    printf("\n");
}

void showPowerset(int n, vector<int> a, vector<char> s)
{
    if (n == 1)
    {
        a[0] = 0;
        showArrWrtTrueFalse(a, s);
        a[0] = 1;
        showArrWrtTrueFalse(a, s);
        return;
    }
    a[n-1] = 0;
    showPowerset(n-1, a, s);
    a[n-1] = 1;
    showPowerset(n-1, a, s);
}

void showPowerset(vector<char> s)
{
    showPowerset(s.size(), vector<int>(s.size(), 0), s);
}

int main(int argc, const char * argv[])
{
    vector<char> s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');
    showPowerset(s);

    return 0;
}
