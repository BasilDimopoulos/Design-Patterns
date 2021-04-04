#include <iostream>
#include "helper_functions.hpp"

// Lets say we wanted a server that served html elements
// We need a scalable object oriented approach to handling all the different types of elements and tags

struct HTMLElement
{
    string name, text;
    vector<HTMLElement> elements;

    const size_t indent_size = 2;
    HTMLElement() {}
    HTMLElement(string &name, string &text) : name(name), text(text)
    {
    }
    string str(int indent = 0)
    {
        //return html element
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
            oss << string(indent_size * (indent + 1), ' ') << text << endl;

        for (auto &e : elements)
            oss << e.str(indent + 1);

        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }
    static HTMLBuilder build(string root_name)
    {
        return {root_name};
    }
};

struct HTMLBuilder
{
    HTMLElement root;
    HTMLBuilder(string root_name)
    {
        root.name = root_name;
    }
    //This is where we add the fluent builder functionality
    HTMLBuilder &add_child(string child_name, string child_text)
    {
        HTMLElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }

    string str() { return root.str(); }

    operator HTMLElement() const { return root; }
};

int main()
{
    HTMLBuilder builder{"ul"};
    builder.add_child("li", "hello").add_child("li", "world");
    cout << builder.str() << endl;
    auto builder = HTMLElement::build("ul").add_child("", "");
    return 0;
}