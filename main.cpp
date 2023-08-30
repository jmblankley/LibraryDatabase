/*
FILE: main.cpp
AUTHOR: jmblankley
DATE: 8/22/2023
PURPOSE: Main file for Library Database project.
*/
#include "Book.hpp"
#include "BookList.hpp"
#include "Library.hpp"
#include "LibraryList.hpp"
#include "Holding.hpp"
#include "HoldingList.hpp"
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
    cin >> ISBN >> year >> author;
    cin.ignore();
    getline(cin, title);

    Book book(ISBN, year, author, title);

    cout << book;

    ifstream booksFile("books.txt");
    BookList booklist(booksFile);
    if (!booklist.checkBookList(ISBN, booklist))
    {
        ofstream booksFile;
        booksFile.open("books.txt", ios::app);
        booksFile << book;
        booksFile.close();
    }
    else
    {
        cout << "Sorry, that book is already in the database!" << endl;
    }

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

    ifstream librariesFile("libraries.txt");
    LibraryList librarylist(librariesFile);

    if (!librarylist.findByName(name, librarylist))
    {
        ofstream libraryFile;
        libraryFile.open("libraries.txt", ios::app);
        libraryFile << library;
        libraryFile.close();
    }
    else
    {
        cout << "Sorry, that library already is in the database!" << endl;
    }
    librariesFile.close();

    return;
};

// Function: addHolding
// Parameters: none
// Purpose: Add holding information to specified file
void addHolding()
{
    string ISBN;
    string libraryName;
    Book pulledBook("", 0, "", "");
    Book holdingBook;
    Holding holding;

    cin >> ISBN >> libraryName;

    ifstream booksFile("books.txt");
    BookList bookList(booksFile);
    if (bookList.checkBookList(ISBN, bookList))
    {
        Book newBook = bookList.findByISBN(ISBN, bookList, pulledBook);
        holdingBook = newBook;
        ifstream libraryFile("libraries.txt");
        LibraryList libraryList(libraryFile);

        if (libraryList.findByName(libraryName, libraryList))
        {
            int copyNumber = 1;
            Holding holding(holdingBook, libraryName, copyNumber);

            ifstream holdingsFile("holdings.txt");

            HoldingList holdinglist(holdingsFile);

            ofstream holdingFile;
            holdingFile.open("holdings.txt", ios::app);
            holdingFile << holding;

            holdingFile.close();
            holdingsFile.close();
        }
        else if (!libraryList.findByName(libraryName, libraryList))
        {
            cout << "Sorry, that library is not in the database!" << endl;
            return;
        }
        else
        {
            return;
        }
        libraryFile.close();
    }
    else
    {
        cout << "Sorry, that book is not in the database!" << endl;
    }
    booksFile.close();
};

// Function: listBooks
// Parameters: none
// Purpose: List the books into the console from the books.txt file
void listBooks()
{
    ifstream getBooks("books.txt");
    BookList booklist(getBooks);

    cout << booklist;

    getBooks.close();
};

// Function: listLibraries
// Parameters: none
// Purpose: List the libraries into the console from the libraries.txt file
void listLibraries()
{
    ifstream getLibraries("libraries.txt");
    LibraryList librarylist(getLibraries);

    cout << librarylist;

    getLibraries.close();
};

// Function: findBooks
// Parameters: ISBN
// Purpose: Find the books in the holdings.txt by the ISBN number
void findBooks(string ISBN, HoldingList holdinglist)
{
    holdinglist.findByISBN(ISBN, holdinglist);
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
    if (firstSelector == "q") // stops program
    {
        return;
    }
    if (firstSelector == "a") // adds book, library, or holding depending on the secondSelector
    {
        cin >> secondSelector;
        if (secondSelector == "b") // adds book
        {
            addBook();
        }
        else if (secondSelector == "l") // adds library
        {
            addLibrary();
        }
        else if (secondSelector == "h") // adds holding
        {
            addHolding();
        }
        else
        {
            cout << "Sorry, that was not a valid entry. Please try again." << endl;
        }
    }
    if (firstSelector == "l") // lists out books or libraries depending on secondSelector
    {
        cin >> secondSelector;
        if (secondSelector == "b") // lists books
        {
            listBooks();
        }
        else if (secondSelector == "l") // lists libraries
        {
            listLibraries();
        }
        else
        {
            cout << "Sorry, that was not a valid entry. Please try again." << endl;
        }
    }
    if (firstSelector == "f") // finds book in a library with second selector being an ISBN number
    {
        cin >> secondSelector;
        ifstream getHoldings("holdings.txt");
        HoldingList holdinglist(getHoldings);
        findBooks(secondSelector, holdinglist);
        getHoldings.close();
    }
    userInput();
}

int main(int argc, char *argv[])
{
    userInput();

    return 0;
}