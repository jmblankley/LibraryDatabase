/*
FILE: Library.hpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Creates the Library class for use in main. Defines constructors, methods, and overloads
*/

#ifndef _LIBRARY_HPP_
#define _LIBRARY_HPP_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Library
{
private:
    string _name;
    string _city;
    int _zip;

public:
    // Default Contructor Method for Library Class
    // Parameters: none
    // Purpose: To initialize instance variables.
    Library()
    {
        _name = "";
        _city = "";
        _zip = 0;
    }

    // Constructor of Library Class
    // Parameters: library name, city name, zipcode
    // Purpose: Initializes a new library with variables passed in
    Library(string newName, string newCity, int newZip)
    {
        _name = newName;
        _city = newCity;
        _zip = newZip;
    }

    // Operator Overload: <<
    // Parameters: ostream(output), and a Library object
    // Purpose: Makes it possible to output a Library object to a stream (console/file/etc..)
    friend ostream &operator<<(ostream &os, const Library &library);
};

#endif