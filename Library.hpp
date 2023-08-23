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
    Library()
    {
        _name = "";
        _city = "";
        _zip = 0;
    }

    Library(string newName, string newCity, int newZip)
    {
        _name = newName;
        _city = newCity;
        _zip = newZip;
    }

    friend ostream &operator<<(ostream &os, const Library &library);
};

#endif