#include <iostream>
#include "helper_functions.hpp"

// Lets say you are making a website that sells products and your manager wants you to add functionality that filters these products by
//certain traits like color and size

enum class Color
{
    red,
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

//The open closed principle states that your functions should be open to extension by inheritance but closed for modification
//The problem with the below structure is that if you were receive a request to filter by different catergories or even combine
//different filters, you would have to reuse much of the code
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
//Templates are great for the open-closed principle, because they allow a function or class to work
//on many different data types without being rewritten for each one.
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

struct ColorSpecification : Specification<Product>
{
    Color color;
    ColorSpecification(Color color) : color(color)
    {
    }

    bool is_satisfied(Product *item) override
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;
    SizeSpecification(Size size) : size(size)
    {
    }

    bool is_satisfied(Product *item) override
    {
        return item->size == size;
    }
};

template <typename T>
struct AndSpecification : Specification<T>
{
    Specification<T> &first;
    Specification<T> &second;
    AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {}
    bool is_satisfied(T *item) override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product *> items{&apple, &tree, &house};
    BetterFilter bf;
    ColorSpecification green(Color::green);
    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);
    for (auto &item : bf.filter(items, green))
    {
        cout << item->name << " item is green" << endl;
    }

    for (auto &item : bf.filter(items, green_and_large))
    {
        cout << item->name << " item is green and large" << endl;
    }

    return 0;
}