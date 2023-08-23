/*
FILE: Book.cpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Adds functionality to the methods and overloads.
*/

#include "Book.hpp"

// Operator Overload: <<
// Parameters: ostream(output), and a Book
// Purpose: Makes it possible to output a Book object to a stream (console/file/etc..)
ostream &operator<<(ostream &os, const Book &book)
{
    os << book._ISBN << " " << book._year << " " << book._author << " " << book._title << endl;
    return os;
}
