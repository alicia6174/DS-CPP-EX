#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle();
    Rectangle(int x, int y, int h, int w);
    ~Rectangle();
    int GetHeight();
    int GetWidth();
    int GetXLow();
    int GetYLow();
    bool operator==(const Rectangle &s);
    bool operator<(const Rectangle &s);
private:
    int xLow, yLow, height, width;
};

#endif
