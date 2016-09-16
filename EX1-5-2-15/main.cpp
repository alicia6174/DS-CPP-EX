#include <stdio.h>

void doHanoi(int n, int org, int tmp, int tag)
{
    if (n == 1)
    {
        printf("Move from %d to %d.\n", org, tag);
        return;
    }
    if (n == 2)
    {
        printf("Move from %d to %d.\n", org, tmp);
        printf("Move from %d to %d.\n", org, tag);
        printf("Move from %d to %d.\n", tmp, tag);
        return;
    }

    doHanoi(n-1, org, tag, tmp);
    printf("Move from %d to %d.\n", org, tag);
    doHanoi(n-1, tmp, org, tag);
}

int main(int argc, const char * argv[])
{
    doHanoi(3, 1, 2, 3);
    return 0;
}
