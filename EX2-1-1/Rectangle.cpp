#include <stdio.h>
#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int x, int y, int h, int w)
{
    xLow = x; yLow = y;
    height = h; width = w;
}

// Why can't 'int x=0'?
// Rectangle::Rectangle(int x=0, int y=0, int h=0, int w=0)
// :xLow(x), yLow(y), height(h), width(w)
// {}

// What does a deconstructor usually look like?
Rectangle::~Rectangle()
{
    return;
}

int Rectangle::GetHeight(){return height;}

int Rectangle::GetWidth(){return width;}

int Rectangle::GetXLow(){return xLow;}

int Rectangle::GetYLow(){return yLow;}

// Why can't we use 's.GetXLow()'?
bool Rectangle::operator==(const Rectangle &s)
{
    if (this == &s) return true;
    if ( (xLow == s.xLow) && (yLow == s.yLow)
        && (height == s.height) && (width == s.width) ) return true;
    else return false;
}

bool Rectangle::operator<(const Rectangle &s)
{
    if ( (height)*(width) < (s.height)*(s.width) ) return true;
    else return false;
}
