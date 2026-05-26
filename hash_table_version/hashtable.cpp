#include "hashtable.h"
#include <iostream>
using namespace std;

//constructors
HashTable::HashTable()
{
    table = new Translation[table_size];

    for (int i = 0; i < table_size; i++)
    {
        table[i].used = false;
    }
}
//destructor
HashTable::~HashTable()
{
    delete[] table;
    table = NULL;
}

//actual Hash function that convert the string into an index
int HashTable::Hash(string key)
{
    //initialize value tom0
    int hashValue = 0;
    //for loop that goes through each character
    for (int i = 0; i < (int)key.length(); i++)
    {
        //use a prime number like 17 to help distribute the strings then add the ASCII
        hashValue = (hashValue * 17 + key[i]) % table_size;
    }
    return hashValue;
}

//insert function that adds a new word
bool HashTable::Insert(string english, string spanish, string french, string german, string italian)
{
    //gets the intial index
    int index = Hash(english);

    //to avoid infinite loops
    int start = index;

    //find next open slot if used
    while (table[index].used)
    {
        //dont insert any duplicates
        if (table[index].english == english)
        {
            return false;
        }

        // next index
        index = (index + 1) % table_size;

        //full table checker
        if (index == start)
        {
            return false;
        }
    }

    //insert into empty slots
    table[index].english = english;
    table[index].spanish = spanish;
    table[index].french = french;
    table[index].german = german;
    table[index].italian = italian;

    table[index].used = true;

    return true;
}

//search function that finds a word in the table and produces its translations
bool HashTable::Search(string english, Translation &result)
{
    //starting index
    int index = Hash(english);
    int start = index;

    //searching
    while (table[index].used)
    {
        //return word if found
        if (table[index].english == english)
        {
            result = table[index];
            return true;
        }

        //next index
        index = (index + 1) % table_size;

        //loop back to start if not found
        if (index == start)
        {
            return false;
        }
    }
    return false;
}

//print function that displays translations
void HashTable::PrintTranslation(Translation result)
{
    cout << "English: " << result.english << endl;
    cout << "Spanish: " << result.spanish << endl;
    cout << "French: " << result.french << endl;
    cout << "German: " << result.german << endl;
    cout << "Italian: " << result.italian << endl;
}