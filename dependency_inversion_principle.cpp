#include <iostream>
#include "helper_functions.hpp"

//The dependency inversion principle specifies the best way to form dependencies between two objects,
// IDEA 1: High level modules shuold not depend on low-level modules
//         Both should depend on abstractions
// IDEA 2: Abstractions should not depend on details
//         Details should depend on abstractions

//Lets say we are trying to model the relationship between people
enum class Relationship
{
    parent,
    child,
    sibling,
};

struct Person
{
    string name;
};

//We may want some sort of low level structure for storing relationships
struct Relationships
{
    //We can make a tuple that stores two people and their relationship
    vector<tuple<Person, Relationship, Person>> relations;

    //Lets say we have a function that can take a parent and child and map their relationship
    void add_parent_and_child(const Person &parent, const Person &child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
        //Remember we need to map both the parents relatinship to the child, and the childs relationship to the parent
    }
};

int main()
{
    Person parent{"John"};
    Person child{"Matt"}, child2{"Tim"};
    Relationships relationships;
    relationships.add_parent_and_child(parent, child);
    relationships.add_parent_and_child(parent, child2);
    return 0;
}