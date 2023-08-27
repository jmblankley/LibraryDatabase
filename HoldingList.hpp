/*
FILE: HoldingList.hpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Creates the HoldingList class for use in main. Defines constructors, methods, and overloads
*/

#ifndef _HOLDING_HPP_
#define _HOLDING_HPP_
#include "Holding.hpp"
#define MAX_SIZE 100
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class HoldingList
{
private:
    Holding *_holdingList;
    int _holdingCount;

public:
    // Default Contructor Method for Holding Class
    // Parameters: none
    // Purpose: To initialize instance variables.
    HoldingList()
    {
        _holdingList = new Holding[MAX_SIZE];
        _holdingCount = 0;
    }

    /*Holding addHolding()
    {
        Book book;
        string libraryName;
    }*/

    // Constructor of Holding Class
    // Parameters: ISBN number, and library name
    // Purpose: Initializes a new holding with variables passed in
    HoldingList(ifstream &holdingFile)
    {
        _holdingList = new Holding[MAX_SIZE];
        _holdingCount = 0;

        Holding holding;
        holdingFile >> holding;
        _holdingList[_holdingCount] = holding;
        _holdingCount++;

        while (holdingFile >> holding)
        {
            _holdingList[_holdingCount] = holding;
            _holdingCount++;
        }
    }

    // Accessor Methods
    int getHoldingCount() const { return _holdingCount; }
    Book getEntryBook() const { return _holdingList->getBook(); }
    string getEntryBookISBN() const { return _holdingList->getBookISBN(); }
    string getEntryLibraryName() const { return _holdingList->getLibraryName(); }

    // Method: findByISBN
    // Parameters: string (isbn number of boook)
    // Purpose: Return nothing.
    void findByISBN(string isbnInput, HoldingList holdingList);

    // Method: checkHoldingList
    // Parameters: string libraryName, Book bookInfo, HoldingList holdingList
    // Purpose: to check if any holdings in the file match the incoming holding, and incrementing the copyCounter if it does
    bool checkHoldingList(string libraryName, Book bookInfo, HoldingList holdingList);

    // Operator Overload: <<
    // Parameters: Reference of type ostream
    // Purpose: return ostream
    friend ostream &operator<<(ostream &os, HoldingList holdinglist);
};

#endif