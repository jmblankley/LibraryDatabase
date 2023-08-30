/*
FILE: HoldingList.hpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Creates the HoldingList class for use in main. Defines constructors, methods, and overloads
*/

#ifndef _HOLDING_HPP_
#define _HOLDING_HPP_
#include "Holding.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class HoldingList
{
private:
    Holding *_holdingList;
    int _holdingCount;
    int _maxSize;

public:
    // Default Contructor Method for Holding Class
    // Parameters: none
    // Purpose: To initialize instance variables.
    HoldingList()
    {
        _maxSize = 5;
        _holdingList = new Holding[_maxSize];
        _holdingCount = 0;
    }

    // Constructor of Holding Class
    // Parameters: ISBN number, and library name
    // Purpose: Initializes a new holding with variables passed in
    HoldingList(ifstream &holdingFile)
    {
        _maxSize = 5;
        _holdingList = new Holding[_maxSize];
        _holdingCount = 0;

        Holding holding;

        holdingFile >> holding;

        _holdingList[_holdingCount] = holding;

        _holdingCount++;

        while (holdingFile >> holding)
        {

            _holdingList[_holdingCount] = holding;
            _holdingCount++;

            if (_holdingCount >= _maxSize)
            {
                _maxSize = _holdingCount * 2;
                Holding *newHoldingList = new Holding[_maxSize];
                for (int i = 0; i < _holdingCount; i++)
                {
                    newHoldingList[i] = _holdingList[i];
                }
                delete[] _holdingList;
                _holdingList = newHoldingList;
            }
        }
    }

    // Accessor Methods
    int getHoldingCount() const { return _holdingCount; }
    Book getEntryBook() const { return _holdingList->getBook(); }
    string getEntryBookISBN() const { return _holdingList->getBookISBN(); }
    string getEntryLibraryName() const { return _holdingList->getLibraryName(); }

    // Method: findByISBN
    // Parameters: string (isbn number of boook)
    // Purpose: Print out books with corresponding ISBN numbers and copyNumber associated with the book if there is more than one copy at a library.
    void findByISBN(string isbnInput, HoldingList holdingList);

    // Operator Overload: <<
    // Parameters: Reference of type ostream
    // Purpose: return ostream
    friend ostream &operator<<(ostream &os, HoldingList holdinglist);
};

#endif