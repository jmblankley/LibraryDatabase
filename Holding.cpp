/*
FILE: Holding.cpp
AUTHOR: jmblankley
DATE: 8/24/2023
PURPOSE: Adds functionality to the methods and overloads of the Holding class.
*/

#include "Holding.hpp"

// Operator Overload: <<
// Parameters: ostream(output), and a Holding
// Purpose: Makes it possible to output a Holding object to a stream (console/file/etc..)
ostream &operator<<(ostream &os, const Holding &holding)
{

    os << holding._libraryName << " " << holding._book.getISBN() << " " << holding._book.getYear() << " " << holding._book.getAuthor() << " " << holding._book.getTitle() << endl;

    return os;
}

// Operator Overload: >>
// Parameters: istream, Holding
// Purpose:
istream &operator>>(istream &is, Holding &holding)
{

    is >> holding._libraryName >> holding._book;

    return is;
}