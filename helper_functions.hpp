#pragma once
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string intToString(int number)
{
    stringstream ss;
    ss << number;
    string countNumber;
    ss >> countNumber;
    return countNumber;
}