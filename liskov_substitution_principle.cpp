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

    virtual void setWidth(int width)
    {
        Rectangle::width = width;
    }

    int getHeight()
    {
        return height;
    }

    virtual void setHeight(int height)
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

//However lets say down the line you decide to make a square that inherits from rectangle
struct Square : Rectangle
{
    //you make it so that Square only needs 1 input to generate two equal sizes
    Square(int size) : Rectangle(size, size) {}

    //you then override the setters to make them equal sides, which looks like a good idea...
    //But this VIOLATES the Liskove subsitution principle, because you can no longer substitute square into the process function
    //Doing so will no produce accurate results
    void setWidth(int width) override
    {
        this->width = this->height = width;
    }

    void setHeight(int height) override
    {
        this->height = this->width = height;
    }
};

int main()
{
    cout << "A rectangle with side 3 and 10 would have an expected area of 30" << endl;
    Rectangle r(3, 4); //process changes height to 10
    process(r);
    cout << "A square with a width of 5 and then a changed height of 10 through the process function, would have an expected area of 50" << endl;
    Square sq(5);
    process(sq);
    cout << "This is incorrect because square could not be substituted into the process function, therby breacking the Liskov Substitution Rule" << endl;
    return 0;
}