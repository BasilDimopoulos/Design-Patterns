#include <iostream>
#include "helper_functions.hpp"

// Lets say you are making a website that sells products and your manager wants you to add functionality that filters these products by
//certain traits like color and size

enum class Color
{
    re,
    green,
    blue
};
enum class Size
{
    small,
    medium,
    large
};

//Product is defined by its name, its color and its size
struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    //takes a vector of products and a color and returns a vector of products matching that color
    vector<Product *> by_color(vector<Product *> items, Color color)
    {
        vector<Product *> result;
        for (auto &i : items)
        {
            if (i->color == color)
            {
                result.push_back(i);
                return result;
            }
        }
    }
};

int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product *> items{&apple, &tree, &house};
    ProductFilter pf;
    auto green_things = pf.by_color(items, Color::green);

    return 0;
}