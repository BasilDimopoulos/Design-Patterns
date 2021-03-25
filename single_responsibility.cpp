#include <iostream>
#include <vector>
#include <string>
#include<sstream>  

using namespace std;

string intToString(int number){
        stringstream ss;  
        ss << number;  
        string countNumber;
        ss >> countNumber;
        cout << countNumber << endl;
        return countNumber;
}

int main(){
    Journal journal{"Dear Diary"};
    journal.addEntry("I ate a bug");
    journal.addEntry("I cried today");
    
    return 0;
}

// Single Responsibiltiy Princible is a class that has a single reason to change
// A class should have a primary responsiblity and should not take up other responsibilities

//Lets say you have a journal for storing your thoughts
struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string title): title(title){}

    void addEntry(const string entry){
        int count = 1;
        entries.push_back(intToString(count) + ": " + entry);
        count++;
    }

    // void save(string filename){
    //     ofstream ofs(filename);
    //     for(auto e: entries)
    //     ofs << e << endl;

    // }
};
