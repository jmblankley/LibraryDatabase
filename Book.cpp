/*
FILE: Book.cpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Adds functionality to the methods and overloads of the Book class.
*/

#include "Book.hpp"

// Operator Overload: ==
// Parameters: Book on left and right side of ==
// Purpose: Makes it possible to compare the attributes of a Book object against the attributes of the Book object on the right side
bool Book::operator==(const Book &other) const
{
    return _ISBN == other._ISBN && _year == other._year && _author == other._author && _title == other._title;
}

// Operator Overload: <<
// Parameters: ostream(output), and a Book
// Purpose: Makes it possible to output a Book object to a stream (console/file/etc..)
ostream &operator<<(ostream &os, const Book &book)
{
    os << book._ISBN << " " << book._year << " " << book._author << " " << book._title << endl;
    return os;
}

// Operator Overload: >>
// Parameters: istream, Book
// Purpose:
istream &operator>>(istream &is, Book &book)
{
    is >> book._ISBN >> book._year >> book._author >> book._title;
    return is;
}
