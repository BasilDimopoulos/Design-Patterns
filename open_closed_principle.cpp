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

//The open closed principle state that your functions should be open to extension by inheritance but closed for modification
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
//Templates are great for the open-closed principle, because they allow a function or class to work on many different data types without being rewritten for each one.
template <typename T>
struct Specification
{
    virtual bool is_satisfied(T *item) = 0;
};

template <typename T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override
    {
        vector<Product *> result;
        for (auto &item : items)
        {
            if (spec.is_satisfied(item))
            {
                result.push_back(item);
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

    for (auto &item : green_things)
    {
        cout << item->name << " is green\n";
    }

    return 0;
}