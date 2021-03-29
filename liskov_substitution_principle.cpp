#include <iostream>
#include "helper_functions.hpp"

//Subtypes should be immediately substitutable for their base types
//say we have a basic rectangle with getter and setter functions for its dimensions
class Rectangle
{
protected:
    int width, height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int getWidth() const
    {
        return width;
    }

    void setWidth(int width)
    {
        Rectangle::width = width;
    }

    int getHeight()
    {
        return height;
    }

    void setHeight(int height)
    {
        Rectangle::height = height;
    }

    int area() const
    {
        return width * height;
    }
};

//Say you have a function called process that takes a reference to a rectangle and sets its width to 10.
//You would expect then, that the area of that rectangle is its width * 10
void process(Rectangle &r)
{
    int w = r.getWidth();
    r.setHeight(10);
    cout << "Expected area = " << (w * 10) << ", got " << r.area() << endl;
}

int main()
{

    return 0;
}