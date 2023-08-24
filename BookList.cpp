#include "BookList.hpp"
#include <fstream>
#include <iostream>
using namespace std;

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
            ofstream holdingFile;
            holdingFile.open("holdings.txt", ios::app);
            holdingFile << libraryName << ": " << booklist._bookList[i];
            holdingFile.close();
        }
    }
}

// Operator Overlead: +=
//  Parameters: Book
//  Purpose: Return a copy of the updated Fleet as efficiently as possible
BookList &BookList::operator+=(const Book &book)
{
    Book emptySpace("", 0, "", "");

    for (int i = 0; i <= _bookCount; i++)
    {
        if (_bookList[i] == emptySpace)
        {
            _bookList[i] = book;
            _bookCount++;
            break;
        }
    }
    return *this;
}

// Operator Overload: <<
// Parameters: Reference of type ostream
// Purpose: return ostream
ostream &operator<<(ostream &os, BookList booklist)
{
    for (int i = 0; i < booklist._bookCount; i++)
    {
        os << booklist._bookList[i];
    }
    return os;
}