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
    Holding()
    {
        _ISBN = "";
        _name = "";
    }

    Holding(string newISBN, string newName)
    {
        _ISBN = newISBN;
        _name = newName;
    }

    friend ostream &operator<<(ostream &os, const Holding &holding);
};

#endif