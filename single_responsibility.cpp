#include <iostream>
#include "helper_functions.hpp"

// Single Responsibiltiy Princible is a class that has a single reason to change
// A class should have a primary responsiblity and should not take up other responsibilities

//Lets say you have a journal for storing your thoughts
struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string title) : title(title) {}

    void addEntry(const string entry)
    {
        int count = 1;
        entries.push_back(intToString(count) + ": " + entry);
        count++;
    }
};

//Lets say we wanted to have the ability to save the journal in a notebook. We could add some funcationality to the JOurnal class but it would be much better to
//SEPERATE the concern into another class/structure

struct Writer
{
    void save(const Journal j, const string &filename)
    {
        ofstream ofs(filename);
        for (auto e : j.entries)
        {
            ofs << e << endl;
        }
    }
};

int main()
{
    Journal journal{"Dear Diary"};
    journal.addEntry("I set by a shallow creek lake");
    journal.addEntry("And patiently wait for the stars");
    Writer writer;
    writer.save(journal, "diary.txt");

    return 0;
}