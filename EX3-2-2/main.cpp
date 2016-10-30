#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;

stack<int> Cars;
int Moves[7] = {0};

void MoveCars()
{
    int c = 0;
    for (int i = 1; i <= 6; ++i)
    {
        if (Moves[i] == 1)
        {
            c += 1;
            Cars.push(c);
        }
        if (Moves[i] == 2)
        {
            printf("[%d]", Cars.top());
            Cars.pop();
        }
    }
    printf("\n");
}
// h: # of pushs, p: # of pops
// c: total # of pushs or cursor of cars, n: total # of steps
void ArrangeCars(int h, int p, int c, int n)
{
    if (c == 3 & h > 0)
    {
        Moves[n+1] = 2;
        if (h == 1)
        {
            Moves[6] = 2;
            MoveCars();
            return;
        }
        ArrangeCars(h-1, p+1, 3, n+1);
    }

    if (c < 3 & h == 0)
    {
        Moves[n+1] = 1;
        ArrangeCars(1, p, c+1, n+1);
    }

    if (c < 3 & h > 0)
    {
        Moves[n+1] = 1;
        ArrangeCars(h+1, p, c+1, n+1);
        Moves[n+1] = 2;
        ArrangeCars(h-1, p+1, c, n+1);
    }
}

int main(int argc, const char * argv[])
{
    Moves[1] = 1;
    ArrangeCars(1, 0, 1, 1);

    return 0;
}
