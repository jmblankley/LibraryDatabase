/*
FILE: HoldingList.cpp
AUTHOR: jmblankley
DATE: 8/24/2023
PURPOSE: Adds functionality to the methods and overloads for the HoldingList class.
*/

#include "HoldingList.hpp"

// Operator Overload: <<
// Parameters: Reference of type ostream
// Purpose: return ostream
ostream &operator<<(ostream &os, HoldingList holdinglist)
{
    for (int i = 0; i < holdinglist._holdingCount; i++)
    {
        os << holdinglist._holdingList[i];
    }
    return os;
}
