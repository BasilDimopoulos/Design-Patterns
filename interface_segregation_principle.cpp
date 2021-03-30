#include <iostream>
#include "helper_functions.hpp"

//The goal of the interface segregation principle is to not create interfaces that are too large
//Large interfaces cause the inherited structures to implement too much

struct Document
{
    /* data */
};

//Observe the following interface
//You want a machine that can scan, print and fax documents. So you create an interface for each functionality
//The problem with the interface below is that now you have too many implementations to handle for one interface
struct IMachine{
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
};

//lets say you just wanted a printer. However now you have to implement the scan and fax functionality as well, even though it doesnt make sense too 
struct MPrinter : IMachine{
    void print(Document& doc) override{

    }

    void scan(Document& doc) override{

    }

    void fax(Document& doc) override{

    }
};

//A better solution, is to create separate interfaces, and combining with the single responsibility principle to create simple, understandble templates

struct Printer{
    virtual void print(Document &doc) = 0;
};

struct Scanner{
    virtual void scanner(Document &doc) = 0;
};

struct Fax{
    virtual void fax(Document &doc) = 0;
};

//Now there is no need for methods to be left empty or too throw exceptions in inherited structures. Nothing is redundant.
int main(){
    
    return 0;
}