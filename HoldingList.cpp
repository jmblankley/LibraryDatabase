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
    for (int i = 0; i < holdingList._holdingCount; i++)
    {
        if (holdingList._holdingList[i].getBookISBN() == isbnInput)
        {
            Book newBook = holdingList._holdingList[i].getBook();
            string newLibrary = holdingList._holdingList[i].getLibraryName();

            int copyNumber = 1;

            for (int j = 0; j < i; j++)
            {
                if (holdingList._holdingList[j].getBook() == newBook &&
                    holdingList._holdingList[j].getLibraryName() == newLibrary)
                {
                    copyNumber++;
                }
            }

            Holding newHolding(newBook, newLibrary, copyNumber);

            cout << newHolding.getLibraryName() << ": " << newHolding.getBook().getISBN() << " " << newHolding.getBook().getYear() << " " << newHolding.getBook().getAuthor() << " " << newHolding.getBook().getTitle() << " Copy Number: " << copyNumber << endl;
        }
    }
}

// Operator Overload: <<
// Parameters: Reference of type ostream
// Purpose: return ostream
ostream &operator<<(ostream &os, HoldingList holdinglist)
{
    cout << holdinglist._holdingCount << endl;
    for (int i = 0; i < holdinglist._holdingCount; i++)
    {
        os << holdinglist._holdingList[i];
    }
    return os;
}
