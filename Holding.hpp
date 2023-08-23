/*
FILE: Holding.hpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Creates the Holding class for use in main. Defines constructors, methods, and overloads
*/

#ifndef _HOLDING_HPP_
#define _HOLDING_HPP_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Holding
{
private:
    string _ISBN;
    string _name;

public:
    // Default Contructor Method for Holding Class
    // Parameters: none
    // Purpose: To initialize instance variables.
    Holding()
    {
        _ISBN = "";
        _name = "";
    }

    // Constructor of Holding Class
    // Parameters: ISBN number, and library name
    // Purpose: Initializes a new holding with variables passed in
    Holding(string newISBN, string newName)
    {
        _ISBN = newISBN;
        _name = newName;
    }

    // Operator Overload: <<
    // Parameters: ostream(output), and a Holding object
    // Purpose: Makes it possible to output a Holding object to a stream (console/file/etc..)
    friend ostream &operator<<(ostream &os, const Holding &holding);
};

#endif