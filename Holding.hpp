/*
FILE: Holding.hpp
AUTHOR: jmblankley
DATE: 8/24/2023
PURPOSE: Creates the Holdings class for use in main. Defines constructors, methods, and overloads
*/

#ifndef _HOLDINGS_HPP_
#define _HOLDINGS_HPP_
#include "Book.hpp"
#include "Library.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class Holding
{
private:
    Book _book;
    string _libraryName;
    int _copyNumber;

public:
    // Default Contructor Method for Holdings Class
    // Parameters: none
    // Purpose: To initialize instance variables.
    Holding()
    {
        _libraryName = "";
        _copyNumber = 0;
    }

    // Constructor of Holdings Class
    // Parameters: Book, Library, int represting the copyNumber
    // Purpose: Initializes a new holdings with variables passed in
    Holding(Book newBook, string newLibrary)
    {
        string newBookISBN = newBook.getISBN();
        int newBookYear = newBook.getYear();
        string newBookAuthor = newBook.getAuthor();
        string newBookTitle = newBook.getTitle();

        Book newestBook(newBookISBN, newBookYear, newBookAuthor, newBookTitle);

        _book = newestBook;

        _libraryName = newLibrary;
    }

    // Accessor Methods
    Book getBook() const { return _book; }
    string getBookISBN() const { return _book.getISBN(); }
    int getBookYear() const { return _book.getYear(); }
    string getBookAuthor() const { return _book.getAuthor(); }
    string getBookTitle() const { return _book.getTitle(); }
    string getLibraryName() const { return _libraryName; }

    // Operator Overload: <<
    // Parameters: ostream(output), and a Holding
    // Purpose: Makes it possible to output a Holding object to a stream (console/file/etc..)
    friend ostream &operator<<(ostream &os, const Holding &holding);

    // Operator Overload: >>
    // Parameters: istream, Holding
    // Purpose:
    friend istream &operator>>(istream &is, Holding &holding);
};

#endif