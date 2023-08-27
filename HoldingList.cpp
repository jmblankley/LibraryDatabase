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
    cout << "findBooks call" << endl;

    for (int i = 0; i < holdingList._holdingCount; i++)
    {
        if (holdingList._holdingList[i].getBookISBN() == isbnInput)
        {
            Book newBook = holdingList._holdingList[i].getBook();
            // cout << newBook << endl;
            string newLibrary = holdingList._holdingList[i].getLibraryName();

            Holding newHolding(newBook, newLibrary, 1);

            cout << newHolding.getLibraryName() << ": " << newHolding.getBook();
            if (newHolding.getCopyNumber() > 1)
            {
                cout << newHolding.getCopyNumber();
            }
        }
    }
}

// Method: checkHoldingList
// Parameters: string libraryName, Book bookInfo, HoldingList holdingList
// Purpose: to check if any holdings in the file match the incoming holding, and incrementing the copyCounter if it does
bool HoldingList::checkHoldingList(string libraryName, Book incomingBook, HoldingList holdingList)
{
    for (int i = 0; i < holdingList._holdingCount; i++)
    {
        if (holdingList._holdingList[i].getLibraryName() == libraryName && holdingList._holdingList[i].getBook() == incomingBook)
        {
            // cout << holdingList._holdingCount << endl;
            return true;
        }
    }
    return false;
}

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
