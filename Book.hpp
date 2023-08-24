/*
FILE: Book.hpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Creates the Book class for use in main. Defines constructors, methods, and overloads
*/

#ifndef _BOOK_HPP_
#define _BOOK_HPP_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
private:
    string _ISBN;
    int _year;
    string _author;
    string _title;
    string _libraryName;
    int _copyNumber;

public:
    // Default Contructor Method for Book Class
    // Parameters: none
    // Purpose: To initialize instance variables.
    Book()
    {
        _ISBN = "";
        _year = 0;
        _author = "";
        _title = "";
    }

    // Constructor of Book Class
    // Parameters: ISBN number, year, author name, and title of book
    // Purpose: Initializes a new book with variables passed in
    Book(string newISBN, int newYear, string newAuthor, string newTitle)
    {
        _ISBN = newISBN;
        _year = newYear;
        _author = newAuthor;
        _title = newTitle;
    };

    Book(string newISBN, int newYear, string newAuthor, string newTitle, string newLibraryName, int newCopyNumber)
    {
        _ISBN = newISBN;
        _year = newYear;
        _author = newAuthor;
        _title = newTitle;
        _libraryName = newLibraryName;
        _copyNumber = newCopyNumber;
    }

    // Accessor methods for Book data.
    string getISBN() const { return _ISBN; }
    int getYear() const { return _year; }
    string getAuthor() const { return _author; }
    string getTitle() const { return _title; }

    bool operator==(const Book &other) const;

    // Operator Overload: <<
    // Parameters: ostream(output), and a Book
    // Purpose: Makes it possible to output a Book object to a stream (console/file/etc..)
    friend ostream &operator<<(ostream &os, const Book &book);

    // Operator Overload: >>
    // Parameters: istream, Book
    // Purpose:
    friend istream &operator>>(istream &is, Book &book);
};

#endif