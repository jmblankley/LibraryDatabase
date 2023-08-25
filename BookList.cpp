#include "BookList.hpp"
#include <fstream>
#include <iostream>
using namespace std;

// Method: findByISBN
// Parameters: int (isbn number of boook)
// Purpose: Return nothing.
Book BookList::findByISBN(string isbnInput, BookList booklist, Book book)
{
    for (int i = 0; i < booklist._bookCount; i++)
    {
        if (booklist._bookList[i].getISBN() == isbnInput)
        {
            string newISBN = booklist._bookList[i].getISBN();
            int newYear = booklist._bookList[i].getYear();
            string newAuthor = booklist._bookList[i].getAuthor();
            string newTitle = booklist._bookList[i].getTitle();

            Book newBook(newISBN, newYear, newAuthor, newTitle);

            book = newBook;

            return book;
        }
    }
}

bool BookList::checkBookList(string isbnInput, BookList booklist)
{
    for (int i = 0; i < booklist._bookCount; i++)
    {
        if (booklist._bookList[i].getISBN() == isbnInput)
        {
            return true;
        }
    }
    return false;
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