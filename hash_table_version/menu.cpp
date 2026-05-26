#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <ctime>
#include "hashtable.h"

using namespace std;

//functions that reads the dictionary file and inserts it
void read(string filename, HashTable &dictionary)
{
    ifstream infile(filename);

    if (!infile)
    {
        cout << "Error: Could not find that file name " << filename << endl;
        return;
    }

    string line;

    // skip header file
    getline(infile, line);

    int count = 0;

    //read the file line by line
    while (getline(infile, line))
    {
        stringstream ss(line);

        string english, spanish, french, german, italian;

        //help split each row
        getline(ss, english, ',');
        getline(ss, spanish, ',');
        getline(ss, french, ',');
        getline(ss, german, ',');
        getline(ss, italian, ',');

        //inserts the row into the table
        if (dictionary.Insert(english, spanish, french, german, italian))
        {
            count++;
        }
    }

    infile.close();

    cout << count << " word loaded into dictionary." << endl;
}

//print a translation
void PrintSelectedLanguage(Translation result, int choice)
{
    cout << "\nEnglish: " << result.english << endl;

    if (choice == 1)
        cout << "Spanish: " << result.spanish << endl;
    else if (choice == 2)
        cout << "French: " << result.french << endl;
    else if (choice == 3)
        cout << "German: " << result.german << endl;
    else if (choice == 4)
        cout << "Italian: " << result.italian << endl;
}

int main()
{
    HashTable dictionary;

    //start timer
    clock_t initial = clock();

    // Load file
    read("dictionary.csv", dictionary);

    //stop timer
    clock_t final = clock();

    //convert to seconds
    double cpu_time = double(final - initial) / CLOCKS_PER_SEC;

    //print time
    cout << "Hash Table CPU time: " << cpu_time << " seconds" << endl;

    int choice = -1;
    //menu 
    while (true)
{
    cout << "\nTranslator" << endl;
    cout << "1. English to Spanish" << endl;
    cout << "2. English to French" << endl;
    cout << "3. English to German" << endl;
    cout << "4. English to Italian" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter choice: ";

    if (!(cin >> choice))
    {
        cout << "Invalid choice. Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

    if (choice == 0)
    {
        cout << "Goodbye!" << endl;
        break;
    }

    if (choice < 1 || choice > 4)
    {
        cout << "Invalid choice." << endl;
        continue;
    }

        string word;

        cout << "Enter an English word to translate it: ";
        cin >> word;

        Translation result;
        //if found print the language
        if (dictionary.Search(word, result))
        {
            PrintSelectedLanguage(result, choice);
        }
        else
        {
            cout << "Word was not found." << endl;
        }
    }

    return 0;
}