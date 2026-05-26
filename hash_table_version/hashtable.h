#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
using namespace std;

//high number to reduce collisions
const int table_size = 20000;

//using a struct because it is the easiest solution, there is no need to use separate arrays or anything of the sort, the struct below will show one row from the CSV file.
struct Translation
{
    string english;
    string french;
    string german;
    string italian;
    string spanish;
    bool used;
};

//hashtable class
class HashTable
{
    private:
    //dynamic memory
    Translation *table;

    int Hash(string key);
    
    public:
    HashTable();
    ~HashTable();
    //insert function for all languages
    bool Insert(string english, string french, string german, string italian, string spanish);
    //search function
    bool Search(string english, Translation &result);
    //print function
    void PrintTranslation(Translation result);

};

#endif