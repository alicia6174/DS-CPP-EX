#include <stdio.h>

/*
 * x =  3,  x^2 + 2x + 1 : 9 + 6 + 1 = 16
 * x =  2,  x^3 + x      : 10
 * x = -1,  x^4 - 1      : 0
 *
 */

double poly(const double * coef, int deg, double x, int * cnt)
{
    if (cnt)
        *cnt += 1;

    return (deg == 0)? coef[0]:
        x * poly(coef + 1, deg - 1, x, cnt) + coef[0];
}

double poly(const double * coef, int deg, double x)
{
    int cnt = 0;
    double ret = poly(coef, deg, x, &cnt);
    printf("cnt = %d\n", cnt);
    return ret;
}

int main(int argc, const char * argv[])
{
    double c1[] = {1, 2, 1};
    double c2[] = {0,1, 0, 1};
    double c3[] = {-1, 0, 0, 0, 1};

    printf("%.2lf\n", poly(c1, 2, 3));
    printf("%.2lf\n", poly(c2, 3, 2));
    printf("%.2lf\n", poly(c3, 4, -1));
    return 0;
}
