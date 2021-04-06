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

struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

//We may want some sort of low level structure for storing relationships
struct Relationships : RelationshipBrowser
{
    //We can make a tuple that stores two people and their relationship
    vector<tuple<Person, Relationship, Person>> relations;

    //Lets say we have a function that can take a parent and child and map their relationship
    void add_parent_and_child(const Person &parent, const Person &child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
        //Remember we need to map both the parents relationship to the child, and the childs relationship to the parent
    }

    vector<Person> find_all_children_of(const string &name) override
    {
        vector<Person> result;
        for (auto &&[first, rel, second] : relations)
        {
            if (first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;
    }
};

struct Research //high level
{
    Research(Relationships &relationships)
    {
        // this is bad, a high level module should not depend on a low level module
        // if the relationshions storage module was to change or the relations module was made private, the high level code would be completly broken
        auto &relations = relationships.relations;
        for (auto &&[first, rel, second] : relations)
        {
            if (first.name == "John" && rel == Relationship::parent)
            {
                cout << "John has a child called" << second.name << endl;
            }
        }
    }
};

int main()
{
    Person parent{"John"};
    Person child{"Matt"}, child2{"Tim"};
    Relationships relationships;
    relationships.add_parent_and_child(parent, child);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);
    return 0;
}