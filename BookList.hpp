#ifndef _BOOK_LIST_HPP
#define _BOOK_LIST_HPP
#include "Book.hpp"
#define MAX_SIZE 100
using namespace std;

class BookList
{
private:
    Book *_bookList;
    int _bookCount;

public:
    BookList()
    {
        _bookList = new Book[MAX_SIZE];
        _bookCount = 0;
    }
    // Function: addBook
    // Parameters: none
    // Purpose: Add book information to specified file
    Book addBook()
    {
        string ISBN;
        int year;
        string author;
        string title;

        cin >> ISBN >> year >> author >> title;

        Book book(ISBN, year, author, title);

        return book;
    };
    BookList(ifstream &bookFile)
    {
        _bookCount = 0;
        _bookList = new Book[MAX_SIZE];

        Book book;
        bookFile >> book;
        _bookList[_bookCount] = book;
        _bookCount++;

        while (bookFile >> book)
        {
            _bookList[_bookCount] = book;
            _bookCount++;
        }
    }

    // Accessor Methods
    int getBookCount() const { return _bookCount; }

    // Method: findByISBN
    // Parameters: int (isbn number of boook)
    // Purpose: Return nothing.
    void addByISBN(string isbnInput);

    // Operator Overlead: +=
    //  Parameters: Book
    //  Purpose: Return a copy of the updated Fleet as efficiently as possible
    BookList &operator+=(const Book &book);

    // Operator Overload: <<
    // Parameters: Reference of type ostream
    // Purpose: return ostream
    friend ostream &operator<<(ostream &os, BookList booklist);
};

#endif