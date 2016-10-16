#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
//#include <vector>
#include <memory.h>
using namespace std;

int board[8][8] = {{0}};
int istart = 0;
int jstart = 0;
int iktmov[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int jktmov[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int inext[8] = {0};
int jnext[8] = {0};
int steps = 1;
int napos = 0;
int exits[8] = {0};

void showArray(int *A)
{
    for (int i = 0; i < 8; ++i)
    {
        printf("[%d]", A[i]);
    }
    printf("\n");
}

void showBoard()
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("[%.2d]", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


bool canMov()
{
    for (int l = 0; l < 8; ++l)
    {
        int iwill = istart + iktmov[l];
        int jwill = jstart + jktmov[l];
        if ( (board[iwill][jwill] == 0) && (iwill >= 0) && (iwill < 8) && (jwill >= 0) && (jwill < 8) )
        {
            inext[l] = iwill;
            jnext[l] = jwill;
            napos += 1;
        }
    }
    return (napos > 0)?true:false;
}

long unsigned findMinIdx()
{
    int B[8] = {};
    copy(exits, exits+8, B);
    sort(B, B+8);
    int mini = B[8-napos]; // we consider only non-zero exits
    long signed min_idx = (find(exits, exits+8, mini) - exits);
    return min_idx;
}

int main(int argc, const char * argv[])
{
    board[istart][jstart] = 1;
    while (steps < 64)
    {
        napos = 0;
        memset(exits, 0, sizeof(int)*8);

        for (int l = 0; l < 8; ++l)
        {
            int iwill = istart + iktmov[l];
            int jwill = jstart + jktmov[l];
            if ( (board[iwill][jwill] == 0) && (iwill >= 0) && (iwill < 8) && (jwill >= 0) && (jwill < 8) )
            {
                inext[l] = iwill;
                jnext[l] = jwill;
                napos += 1;


                int num_exits = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int iexit = inext[l] + iktmov[k];
                    int jexit = jnext[l] + jktmov[k];
                    if ( (board[iexit][jexit] == 0) && (iexit >= 0) && (iexit < 8) && (jexit >= 0) && (jexit < 8) )
                    {
                        num_exits += 1;
                    }
                }
                exits[l] = num_exits;
            }
        }

        if ((steps < 64) && (napos == 0))
        {
            printf("Fail! The total steps is %d.", steps);
            showBoard();
            exit(-1);
        }

        long unsigned min_idx = findMinIdx();
        istart = inext[min_idx];
        jstart = jnext[min_idx];
        steps += 1;
        board[istart][jstart] = steps;

        // showArray(exits);
        // printf("napos = %d, min_idx = %lu\n", napos, min_idx);
        // showArray(inext);
        // showArray(jnext);
        // printf("\n");
        // showBoard();
        // printf("[%d][%d]\n", istart, jstart);
    }
    showBoard();

    return 0;
}
