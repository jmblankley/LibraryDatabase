/*
FILE: Library.cpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Adds functionality to the methods and overloads.
*/

#include "Library.hpp"

// Operator Overload: <<
// Parameters: ostream(output), and a Library object
// Purpose: Makes it possible to output a Library object to a stream (console/file/etc..)
ostream &operator<<(ostream &os, const Library &library)
{
    os << library._name << " " << library._city << " " << library._zip << endl;
    return os;
}
