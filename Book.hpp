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

public:
    // Default Contructor Method for Book Class
    // Parameters: none yet
    // Purpose: To initialize instance variables.
    Book()
    {
        _ISBN = "";
        _year = 0;
        _author = "";
        _title = "";
    }

    Book(string newISBN, int newYear, string newAuthor, string newTitle)
    {
        _ISBN = newISBN;
        _year = newYear;
        _author = newAuthor;
        _title = newTitle;
    };

    friend ostream &operator<<(ostream &os, const Book &book);
};

#endif