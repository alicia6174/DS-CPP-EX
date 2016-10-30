#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <memory.h>
using namespace std;

#define CARS_NUM 3
int Moves[CARS_NUM*2+1] = {0};
stack<int> Cars;

void MoveCars()
{
    int c = 0;
    for (int i = 1; i <= CARS_NUM*2; ++i)
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
// h: # of pushs
// p: # of pops
// c: total # of pushs or cursor of cars
// m: total # of steps
void ArrangeCars(int h, int p, int c, int m)
{
    if (c == CARS_NUM & h > 0)
    {
        Moves[m+1] = 2;
        if (h == 1)
        {
            Moves[CARS_NUM*2] = 2;
            MoveCars();
            return;
        }
        ArrangeCars(h-1, p+1, CARS_NUM, m+1);
    }

    if (c < CARS_NUM & h == 0)
    {
        Moves[m+1] = 1;
        ArrangeCars(1, p, c+1, m+1);
    }

    if (c < CARS_NUM & h > 0)
    {
        Moves[m+1] = 1;
        ArrangeCars(h+1, p, c+1, m+1);
        Moves[m+1] = 2;
        ArrangeCars(h-1, p+1, c, m+1);
    }
}

void Arrange(int n)
{
    Moves[1] = 1;
    ArrangeCars(1, 0, 1, 1);
}

int main(int argc, const char * argv[])
{
    Arrange(CARS_NUM);

    return 0;
}
