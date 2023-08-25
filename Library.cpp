/*
FILE: Library.cpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Adds functionality to the methods and overloads of the Library class.
*/

#include "Library.hpp"

// Operator Overload: ==
// Parameters: Library on left and right side of ==
// Purpose: Makes it possible to compare two Library objects
bool Library::operator==(const Library &other) const
{
    return _name == other._name && _city == other._city && _zip == other._zip;
}

// Operator Overload: <<
// Parameters: ostream(output), and a Library object
// Purpose: Makes it possible to output a Library object to a stream (console/file/etc..)
ostream &operator<<(ostream &os, const Library &library)
{
    os << library._name << " " << library._city << " " << library._zip << endl;
    return os;
}

// Operator Overload: >>
// Parameters: istream, Library
// Purpose:
istream &operator>>(istream &is, Library &library)
{
    is >> library._name >> library._city >> library._zip;
    return is;
}
