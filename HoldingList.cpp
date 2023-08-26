/*
FILE: HoldingList.cpp
AUTHOR: jmblankley
DATE: 8/24/2023
PURPOSE: Adds functionality to the methods and overloads for the HoldingList class.
*/

#include "HoldingList.hpp"

// Method: findByISBN
// Parameters: string (isbn number of boook)
// Purpose: Return nothing.
void HoldingList::findByISBN(string isbnInput, HoldingList holdingList)
{
    // cout << "findBooks call" << endl;
    for (int i = 0; i < holdingList._holdingCount; i++)
    {
        if (holdingList._holdingList[i].getBookISBN() == isbnInput)
        {
            Book newBook = holdingList._holdingList[i].getBook();
            // cout << newBook << endl;
            string newLibrary = holdingList._holdingList[i].getLibraryName();

            Holding newHolding(newBook, newLibrary);

            cout << newHolding;
        }
    }
}

// Operator Overload: <<
// Parameters: Reference of type ostream
// Purpose: return ostream
ostream &operator<<(ostream &os, HoldingList holdinglist)
{
    for (int i = 0; i < holdinglist._holdingCount; i++)
    {
        os << holdinglist._holdingList[i].getLibraryName() << endl;
        os << holdinglist._holdingList[i].getBook() << endl;
    }
    return os;
}
