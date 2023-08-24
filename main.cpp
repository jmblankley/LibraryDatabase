/*
FILE: main.cpp
AUTHOR: jmblankley
DATE: 8/22/2023
PURPOSE: Main file for Library Database project.
*/
#include "Book.hpp"
#include "Library.hpp"
#include "BookList.hpp"
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

    ifstream getBooks("books.txt");
    BookList booklist(getBooks);

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
    Book pulledBook;
    string library;
    string ISBN;
    // int copyNumber;

    //  user input for ISBN and the library name
    cin >> ISBN >> library;

    //  Look through "books.txt" for the matching ISBN
    ifstream books("books.txt");
    BookList bookList(books);

    bookList.addByISBN(ISBN);
};

// Function: listBooks
// Parameters: none
// Purpose: List the books into the console from the books.txt file
void listBooks()
{
    ifstream getBooks("books.txt");
    BookList booklist(getBooks);

    cout << booklist;
};

void listHoldings()
{
    ifstream getBooks("holdings.txt");
    BookList holdinglist(getBooks);

    cout << holdinglist;
}

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
    ifstream holdings;
    holdings.open("holdings.txt");
    string booksHeld;
    while (getline(holdings, booksHeld))
    {
        if (!booksHeld.find(ISBN))
        {
            cout << booksHeld << endl;
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
        if (secondSelector == "h")
        {
            listHoldings();
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
    // Testing accessor methods
    /*Book testBook("12345", 1999, "Blankley", "YowSauce");
    string test = testBook.getTitle();
    cout << test;*/

    /*ifstream bookFile("books.txt");

    BookList booklist(bookFile);

    Book newBook("696969", 1996, "Yartman", "Pooter");

    cout << booklist;

    booklist += newBook;

    cout << booklist;*/

    userInput();

    return 0;
}