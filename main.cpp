/*
FILE: main.cpp
AUTHOR: jmblankley
DATE: 8/22/2023
PURPOSE: Main file for Library Database project.
*/
#include "Book.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Method: addBook
// Parameters: none
// Purpose: Add book information to specified file
void addBook()
{
    string ISBN;
    int year;
    string author;
    string title;

    cin >> ISBN >> year >> author >> title;
    ofstream booksFile;
    booksFile.open("books.txt", ios::app);
    booksFile << ISBN << " " << year << " " << author << " " << title << endl;
    booksFile.close();

    return;
};

// Method: addLibrary
// Parameters: none
// Purpose: Add library information to specified file
void addLibrary()
{
    string name;
    string city;
    int zip;

    cin >> name >> city >> zip;
    ofstream libraryFile;
    libraryFile.open("libraries.txt", ios::app);
    libraryFile << name << " " << city << " " << zip << endl;
    libraryFile.close();

    return;
};

// Method: addHolding
// Parameters: none
// Purpose: Add holding information to specified file
void addHolding()
{
    string ISBN;
    string library;

    cin >> ISBN >> library;
    ofstream holdingFile;
    holdingFile.open("holdings.txt", ios::app);
    holdingFile << ISBN << " " << library << endl;
    holdingFile.close();

    return;
};

// Method: listBooks
// Parameters: none
// Purpose: List the books into the console from the books.txt file
void listBooks()
{
    ifstream books;
    books.open("books.txt");
    string bookInfo;
    while (getline(books, bookInfo))
    {
        cout << bookInfo << "\n";
    }
    return;
};

// Method: listLibraries
// Parameters: none
// Purpose: List the libraries into the console from the libraries.txt file
void listLibraries()
{
    ifstream libraries;
    libraries.open("libraries.txt");
    string libraryInfo;
    while (getline(libraries, libraryInfo))
    {
        cout << libraryInfo << "\n";
    }

    return;
};

// Method: findBooks
// Parameters: none
// Purpose: Find the books in the holdings.txt by the ISBN number
void findBooks() { return; };

// Method: userInput
// Parameters: none
// Purpose: Take in user input and navigate to other functions depending on the input
void userInput()
{
    string firstSelector;
    string secondSelector;

    cout << ">>> ";
    cin >> firstSelector;
    // cout << firstSelector << secondSelector;
    if (firstSelector == "q")
    { // stops program
        return;
    }
    if (firstSelector == "a")
    { // adds book, library, or holding
        cin >> secondSelector;
        if (secondSelector == "b")
        {
            addBook();
        }
        else if (secondSelector == "l")
        {
            addLibrary();
        }
        else if (secondSelector == "h")
        {
            addHolding();
        }
        else
        {
            cout << "Invalid input, try again." << endl;
        }
    }
    if (firstSelector == "l")
    {
        cin >> secondSelector;
        if (secondSelector == "b")
        {
            listBooks();
        }
        if (secondSelector == "l")
        {
            listLibraries();
        }
    }
    if (firstSelector == "f")
    {
        findBooks();
    }
    userInput();
}

int main(int argc, char *argv[])
{
    userInput();

    return 0;
}