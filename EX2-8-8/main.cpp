#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define MAX_SIZE 15
#define MAX_ITER 50000
using namespace std;

int A[MAX_SIZE][MAX_SIZE] = {{0}};
int imove[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int jmove[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int istart = 9;
int jstart = 9;



bool isFinish()
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            if (A[i][j] == 0) return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int cnt = 0;
    int itr = 0;
    srand( (unsigned)time(NULL) );
    rand();
    while ((!isFinish()) && (itr <= MAX_ITER))
    {
        int num = (int)(rand() / (RAND_MAX+1.0)*8.0);
        int inow = istart + imove[num];
        int jnow = jstart + jmove[num];
        if (inow >= 0 && inow < MAX_SIZE && jnow >= 0 && jnow < MAX_SIZE)
        {
            A[istart + imove[num]][jstart + jmove[num]] += 1;
            istart = inow;
            jstart = jnow;
            cnt += 1;
        }
        itr += 1;
    }
    printf("Total steps = %d\n", cnt);

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        for (int j = 0; j < MAX_SIZE; ++j)
        {
            printf("[%.2d]", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
