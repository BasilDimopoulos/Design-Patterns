#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    getchar();
    return 0;
}

// Single Responsibiltiy Princible is a class that has a single reason to change
// A class should have a primary responsiblity and should not take up other responsibilities

//Lets say you have a journal for storing your thoughts
struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string title): title(title)){}

    void addEntry(const string entry){
        
    }
};
