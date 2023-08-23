/*
FILE: main.cpp
AUTHOR: jmblankley
DATE: 8/22/2023
PURPOSE: Main file for Library Database project.
*/
#include "Book.hpp"
#include "Library.hpp"
#include "Holding.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Function: addBook
// Parameters: none
// Purpose: Add book information to specified file
void addBook()
{
    string ISBN;
    int year;
    string author;
    string title;

    cin >> ISBN >> year >> author >> title;

    Book book(ISBN, year, author, title);

    ofstream booksFile;
    booksFile.open("books.txt", ios::app);
    booksFile << book;
    booksFile.close();

    return;
};

// Function: addLibrary
// Parameters: none
// Purpose: Add library information to specified file
void addLibrary()
{
    string name;
    string city;
    int zip;

    cin >> name >> city >> zip;

    Library library(name, city, zip);

    ofstream libraryFile;
    libraryFile.open("libraries.txt", ios::app);
    libraryFile << library;
    libraryFile.close();

    return;
};

// Function: addHolding
// Parameters: none
// Purpose: Add holding information to specified file
void addHolding()
{
    string ISBN;
    string library;

    cin >> ISBN >> library;
    Holding holding(ISBN, library);

    ofstream holdingFile;
    holdingFile.open("holdings.txt", ios::app);
    holdingFile << holding;
    holdingFile.close();

    return;
};

// Function: listBooks
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

// Function: listLibraries
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

// Function: findBooks
// Parameters: ISBN
// Purpose: Find the books in the holdings.txt by the ISBN number
void findBooks(string ISBN)
{
    // cout << ISBN << endl; // debugging line

    ifstream holdings;
    holdings.open("holdings.txt");
    string booksHeld;
    while (getline(holdings, booksHeld))
    {
        // cout << booksHeld << endl; // debugging line
        if (booksHeld == ISBN) // Need to figure out how to compare only the ISBN number on the line and not the whole file.
        {
            cout << booksHeld;
        }
    }

    return;
};

// Function: userInput
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
        cin >> secondSelector;
        findBooks(secondSelector);
    }
    userInput();
}

int main(int argc, char *argv[])
{
    userInput();

    return 0;
}