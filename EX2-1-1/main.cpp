#include <stdio.h>
#include <iostream>
#include "Rectangle.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Rectangle r(0,0,1,2), s(0,0,3,4);
    Rectangle *t = &s;

    if (r.GetHeight()*r.GetWidth() < t->GetHeight()*t->GetWidth())
        cout << "r";
    else cout << "s";
    cout << " has the less area." << endl;

    if (r < s)
    {
        cout << "r has the less area." << endl;
    }

    return 0;
}
