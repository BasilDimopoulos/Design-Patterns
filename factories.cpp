#include <iostream>
#include "helper_functions.hpp"

//Factories are important because object creation can become too convoluted
//Especially when the constructors are not descriptive
//Factories a responsible for the wholesale, while the builder is responsible for the creation of objects
//Factories can create multiple different instances with just a constructor like call which can exist in a sperate file or class

enum class PointType
{
    cartesian,
    polar
};

//struct Point
//{
//lets say you have a point and the constructor initialises the points on the cartiesean plane
float x, y;
//Point(float x, float y) : x(x), y(y) {}

//then lets say something changes and you know want to initialise it with polar coordinates. So you make a new constructor
//Point(float rho, float theta) {}
//Unfortunately you cannot make two constructors

//so you make an enum class specifying the type of point and then use that for the initialisation
//Unfortunately the below code is a bit confusing. You dont know what a and b are refering to, whether they are point x&y in the cartesean plane or rho&theta in the polar plane
//     Point(float a, float b, PointType type = PointType::cartesian)
//     {
//         if (type == PointType::cartesian)
//         {
//             x = a;
//             y = b;
//         }
//         else
//         {
//             x = a * cos(b);
//             y = a * sin(b);
//         }
//     }
// };

//A better approach would be using encapsulation to hide the constructor and then utilizing functions inside to call the constructer. However by doing so you will not be able to call the constructor on creation as you normally would.
class Point
{
    Point(float x, float y) : x(y), y(y) {}

public:
    float x, y;
    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

int main()
{
    auto p = Point::NewPolar(5, 3.42);
    cout << p.x << endl;
    return 0;
}