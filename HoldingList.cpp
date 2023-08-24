/*
FILE: Holding.cpp
AUTHOR: jmblankley
DATE: 8/23/2023
PURPOSE: Adds functionality to the methods and overloads.
*/

#include "Holding.hpp"
#include "Book.hpp"

// Method: findByISBN
// Parameters: int (isbn number of boook)
// Purpose: Return nothing.
void BookList::addByISBN(string isbnInput, string libraryName, int copyNumber)
{
    ifstream books("books.txt");
    BookList booklist(books);
    for (int i = 0; i < booklist._bookCount; i++)
    {
        if (booklist._bookList[i].getISBN() == isbnInput)
        {
            cout << libraryName << booklist._bookList[i];
            ofstream holdingFile;
            holdingFile.open("holdings.txt", ios::app);
            holdingFile << libraryName << ": " << booklist._bookList[i];
            holdingFile.close();
        }
    }
}

// Operator Overload: <<
// Parameters: ostream(output), and a Holding object
// Purpose: Makes it possible to output a Holding object to a stream (console/file/etc..)
ostream &operator<<(ostream &os, const Holding &holding)
{
    os << holding._book << " " << holding._holdingLibrary;
    if (holding._copyNumber > 1)
    {
        os << " "
           << "Copy Number: " << holding._copyNumber << endl;
    }
    return os;
}
