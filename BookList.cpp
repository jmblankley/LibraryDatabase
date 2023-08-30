#include "BookList.hpp"
#include <fstream>
#include <iostream>
using namespace std;

// Method: findByISBN
// Parameters: int (isbn number of boook)
// Purpose: Returns a copy of Book with updated ISBN, year, author, and title.
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

// Method: checkBookList
// Parameters: string ISBN, BookList to look through
// Purpose: returns a true if a book in the list's ISBN matches the incoming book's isbn
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
ostream &operator<<(ostream &os, BookList &booklist)
{
    for (int i = 0; i < booklist._bookCount; i++)
    {
        if (booklist._bookCount == 0)
        {
            cout << "No books in the database." << endl;
        }
        os << booklist._bookList[i];
    }
    return os;
}