#ifndef _BOOK_LIST_HPP_
#define _BOOK_LIST_HPP_
#include "Book.hpp"
#define MAX_SIZE 100
using namespace std;

class BookList
{
private:
    Book *_bookList;
    int _bookCount;

public:
    // Defalut Constructor for the BookList class
    // Parameters: none
    // Purpose: To initialize instance variables.
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

    // Constructor class for the BookList class
    // Parameters: ifstream to a file that holds the books in the database
    // Purpose: To initialize instance variables and update the BookList
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
    string getBookEntryISBN() const { return _bookList->getISBN(); }
    int getBookEntryYear() const { return _bookList->getYear(); }
    string getBookEntryAuthor() const { return _bookList->getAuthor(); }
    string getBookEntryTitle() const { return _bookList->getTitle(); }

    // Method: findByISBN
    // Parameters: string (isbn number of boook)
    // Purpose: Return nothing.
    Book findByISBN(string isbnInput, BookList bookList, Book book);

    bool checkBookList(string isbnInput, BookList bookList);

    // Operator Overload: <<
    // Parameters: Reference of type ostream
    // Purpose: return ostream
    friend ostream &operator<<(ostream &os, BookList booklist);
};

#endif