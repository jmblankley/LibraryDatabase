#ifndef _LIBRARY_LIST_HPP_
#define _LIBRARY_LIST_HPP_
#include "Library.hpp"

class LibraryList
{
private:
    Library *_libraryList;
    int _libraryCount;
    int _maxSize;

public:
    // Defalut Constructor for the LibraryList class
    // Parameters: none
    // Purpose: To initialize instance variables.
    LibraryList()
    {
        _maxSize = 5;
        _libraryList = new Library[_maxSize];
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
        _maxSize = 5;
        _libraryList = new Library[_maxSize];
        _libraryCount = 0;

        Library library;
        libraryFile >> library;
        _libraryList[_libraryCount] = library;
        _libraryCount++;

        while (libraryFile >> library)
        {
            _libraryList[_libraryCount] = library;
            _libraryCount++;
            if (_libraryCount >= _maxSize)
            {
                _maxSize = _libraryCount * 2;
                Library *newLibraryList = new Library[_maxSize];
                for (int i = 0; i < _libraryCount; i++)
                {
                    newLibraryList[i] = _libraryList[i];
                }
                _libraryList = newLibraryList;
            }
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