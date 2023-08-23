/*
FILE: Holding.cpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Adds functionality to the methods and overloads.
*/

#include "Holding.hpp"

// Operator Overload: <<
// Parameters: ostream(output), and a Holding object
// Purpose: Makes it possible to output a Holding object to a stream (console/file/etc..)
ostream &operator<<(ostream &os, const Holding &holding)
{
    os << holding._ISBN << " " << holding._name;
    if (holding._copyCount > 1)
    {
        os << "Copy Number: " << holding._copyCount;
    }
    return os;
}
