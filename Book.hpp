#ifndef _BOOK_HPP_
#define _BOOK_HPP_
#include <iostream>
#include <string>
using namespace std;

class Book{
private:
    
public:
    string ISBN;
    int year;
    string author;
    string title;
    // Default Contructor Method for Book Class
    // Parameters: none yet
    // Purpose: To initialize instance variables.
    Book() {
        ISBN = "";
        year = 0;
        author = "";
        title ="";
    }
};


#endif