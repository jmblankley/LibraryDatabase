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

    cin >> ISBN >> year >> author >> title;

    Book book(ISBN, year, author, title);

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
            Holding holding(holdingBook, libraryName);
            ofstream holdingFile;
            holdingFile.open("holdings.txt", ios::app);
            holdingFile << holding;
            holdingFile.close();
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

// Unneccessary function for testing.
void listHoldings()
{
    ifstream getHoldings("holdings.txt");
    HoldingList holdinglist(getHoldings);

    cout << holdinglist;

    getHoldings.close();
}

// Function: findBooks
// Parameters: ISBN
// Purpose: Find the books in the holdings.txt by the ISBN number
void findBooks(string ISBN, BookList booklist){
    // Need to search through holdings.txt/HoldingList
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
        // findBooks(secondSelector);
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