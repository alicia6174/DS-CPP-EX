#include <stdio.h>
#include <iostream>

using namespace std;

/*---------
'throw' is used to differentiate error types.
If you use 'throw' in a regular function.
Then you must catch it in main().

throw
try
{

}
catch()
{

}
---------*/

# if 0
int DivZero(int a, int b, int c)
{
    if ( a <= 0 || b <= 0 || c <= 0 )
        throw "All parameters should be >0";
    return a + b * c + b / c;
}
#endif

#if 1
//EX1-5-1
int DivZero(int a, int b, int c)
{
    if ( a < 0 && b < 0 && c < 0 )
        throw 1;
    if ( a == 0 && b == 0 && c == 0 )
        throw 2;
    return a + b * c + b / c;
}
#endif

//EX1-5-2
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
        printf("err = %d\n", e);
    }
    try{cout << DivZero(0, 0, 0) << endl;}
    catch(int e)
    {
        printf("err = %d\n", e);
    }
    try{cout << DivZero(1, 4, 2) << endl;}
    catch(int e)
    {
        printf("err = %d\n", e);

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
