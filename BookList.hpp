#ifndef _BOOK_LIST_HPP_
#define _BOOK_LIST_HPP_
#include "Book.hpp"
using namespace std;

class BookList
{
private:
    Book *_bookList;
    int _bookCount;
    int _maxSize;

public:
    // Defalut Constructor for the BookList class
    // Parameters: none
    // Purpose: To initialize instance variables.
    BookList()
    {
        _maxSize = 5;
        _bookList = new Book[_maxSize];
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

    // Constructor class for the BookList class
    // Parameters: ifstream to a file that holds the books in the database
    // Purpose: To initialize instance variables and update the BookList
    BookList(ifstream &bookFile)
    {
        _bookCount = 0;
        _maxSize = 5;
        _bookList = new Book[_maxSize];

        Book book;
        bookFile >> book;
        _bookList[_bookCount] = book;
        _bookCount++;

        while (bookFile >> book)
        {
            _bookList[_bookCount] = book;
            _bookCount++;

            if (_bookCount >= _maxSize)
            {
                _maxSize = _bookCount * 2;
                Book *newBookList = new Book[_maxSize];
                for (int i = 0; i < _bookCount; i++)
                {
                    newBookList[i] = _bookList[i];
                }
                delete[] _bookList;
                _bookList = newBookList;
            }
        }
    }

    // Accessor Methods
    int getBookCount() const { return _bookCount; }
    string getBookEntryISBN() const { return _bookList->getISBN(); }
    int getBookEntryYear() const { return _bookList->getYear(); }
    string getBookEntryAuthor() const { return _bookList->getAuthor(); }
    string getBookEntryTitle() const { return _bookList->getTitle(); }

    // Method: findByISBN
    // Parameters: string (isbn number of boook)
    // Purpose: Returns a copy of Book with updated ISBN, year, author, and title
    Book findByISBN(string isbnInput, BookList bookList, Book book);

    // Method: checkBookList
    // Parameters: string ISBN, BookList to look through
    // Purpose: returns a true if a book in the list's ISBN matches the incoming book's isbn
    bool checkBookList(string isbnInput, BookList bookList);

    // Operator Overload: <<
    // Parameters: Reference of type ostream
    // Purpose: return ostream
    friend ostream &operator<<(ostream &os, BookList &booklist);
};

#endif