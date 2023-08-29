#ifndef _LIBRARY_LIST_HPP_
#define _LIBRARY_LIST_HPP_
#include "Library.hpp"
#define MAX_SIZE 100

class LibraryList
{
private:
    Library *_libraryList;
    int _libraryCount;

public:
    // Defalut Constructor for the LibraryList class
    // Parameters: none
    // Purpose: To initialize instance variables.
    LibraryList()
    {
        _libraryList = new Library[MAX_SIZE];
        _libraryCount = 0;
    }

    // Function: addLibrary
    // Parameters: none
    // Purpose: Add library information to specified file
    Library addLibrary()
    {
        string name;
        string city;
        int zip;

        cin >> name >> city >> zip;

        Library library(name, city, zip);

        return library;
    };

    // Constructor class for the LibraryList class
    // Parameters: ifstream to a file that holds the libraries in the database
    // Purpose: To initialize instance variables and update the LibraryList
    LibraryList(ifstream &libraryFile)
    {
        _libraryList = new Library[MAX_SIZE];
        _libraryCount = 0;

        Library library;
        libraryFile >> library;
        _libraryList[_libraryCount] = library;
        _libraryCount++;

        while (libraryFile >> library)
        {
            _libraryList[_libraryCount] = library;
            _libraryCount++;
        }
    }

    // Accessor Methods
    string getLibraryEntryName() const { return _libraryList->getName(); }

    // Method: findByName
    // Parameters: string (name of library)
    // Purpose: Find the library with specified name, return nothing
    bool findByName(string nameInput, LibraryList librarylist);

    // Operator Overload: <<
    // Parameters: ostream, LibraryList
    // Purpose: Enables the use of << to output a LibraryList object
    friend ostream &operator<<(ostream &os, LibraryList librarylist);
};

#endif