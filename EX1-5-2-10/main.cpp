#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX_NUM 102400

int A[MAX_NUM][MAX_NUM] = {{0}};

int getAck(int m, int n)
{
    if (m >= MAX_NUM || n >= MAX_NUM)
    {
        fprintf(stderr, "m = %d, n = %d\n", m, n);
        exit(-1);

    }

    if ( m < 0 || n < 0 )
    {
        fprintf(stderr, "Please input non-negative integers.");
        exit(-1);
    }
    if (m == 0)
    {
        A[0][n] = n+1;
        return n+1;
    }
    if (n == 0)
    {
        if (A[m][0] != 0) return A[m][0];
        A[m][0] = getAck(m-1, 1);
        return A[m][0];
    }

    if (A[m][n] != 0) return A[m][n];
    A[m][n] = getAck(m-1, getAck(m, n-1));
    return A[m][n];
}


int main(int argc, const char * argv[])
{
    for (int m = 0; m <= 3; ++m)
    {
        for (int n = 0; n <= 3; ++n)
        {
            printf("[%d]", getAck(m, n));
        }
        printf("\n");
    }

    return 0;
}

/*     n=0      n=1            n=2            n=3
 *m=0: 1        2              3
 *m=1: A(0,1)=2 A(0,A(1,0))=3  A(0,A(1,1))=4  A(0,A(1,2))=5 -->A(0,1),A(0,2),A(0,3)
 *m=2: A(1,1)=3 A(1,A(2,0))=5  A(1,A(2,1))=7  A(1,A(2,2))=9 -->A(1,1),A(1,3),A(1,5)
 *m=3: A(2,1)=5 A(2,A(3,0))=13 A(2,A(3,1))=29 A(2,A(3,2))=57-->A(2,1),A(2,5),A(2,13)
 */


