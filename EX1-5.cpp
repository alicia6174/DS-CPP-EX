#include <stdio.h>
#include <iostream>

using namespace std;

# if 0
int DivZero(int a, int b, int c)
{
    if ( a <= 0 || b <= 0 || c <= 0 )
        throw "All parameters should be >0";
    return a + b * c + b / c;
}
#endif

#if 1
int DivZero(int a, int b, int c)
{
    if ( a < 0 && b < 0 && c < 0 )
        throw 1;
    if ( a == 0 && b == 0 && c == 0 )
        throw 2;
    if ( a <= 0 || b <= 0 || c <= 0 )
    {
        fprintf(stderr, "a, b, and c shoud be >0.\n");
        return -1;
        //exit(-1);
    }
    return a + b * c + b / c;
}
#endif

int sumArr(int * arr, int n)
{
    if ( n < 0 )
     throw "n shoud be >= 0.";
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ret += i;
    }
    return ret;
}

int main(int argc, const char * argv[])
{
#if 0
    try{cout << DivZero(2, 0, 4) << endl;}
    catch(char const *e)
    {
        cout << "The parameters to DivZero were 2, 0, and 4" << endl;
        cout << "An exception has been thrown" << endl;
        cout << e << endl;
        return 1;
    }
#endif

#if 1
    try{cout << DivZero(-1, -2, -3) << endl;}
    catch(int e)
    {
        cout << "An exception has been thrown" << endl;
        cout << e << endl;
        //return 1;
    }
    try{cout << DivZero(0, 0, 0) << endl;}
    catch(int e)
    {
        cout << "An exception has been thrown" << endl;
        cout << e << endl;
        //return 1;
    }
    int ret = 0;
    ret = DivZero(-1, 0, 1);
    //try{cout << DivZero(0, 0, 0) << endl;}
    //catch(...)
    //{
    //     cout << "An exception has been thrown" << endl;
    //     cout << e << endl;
    //     return 1;
    // }
    try{cout << DivZero(1, 4, 2) << endl;}
    catch(int e)
    {
        cout << "An exception has been thrown" << endl;
        cout << e << endl;
        //return 1;
    }
#endif

#if 0
    int a[5] = {1, 2, 3, 4, 5};
    try{cout << sumArr(a, -1) << endl;}
    catch(char const * e)
    {
        cout << e << endl;
        return 1;
    }
#endif

    return 0;
}
