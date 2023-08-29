#include "LibraryList.hpp"
#include <iostream>
using namespace std;

// Method: findByName
// Parameters: string (name of library)
// Purpose: Find the library with specified name, return nothing
bool LibraryList::findByName(string nameInput, LibraryList librarylist)
{
    for (int i = 0; i < librarylist._libraryCount; i++)
    {
        if (librarylist._libraryList[i].getName() == nameInput)
        {
            return true;
        }
    }
    return false;
}

// Operator Overload: <<
// Parameters: ostream, LibraryList
// Purpose: Enables the use of << to output a LibraryList object
ostream &operator<<(ostream &os, LibraryList librarylist)
{
    for (int i = 0; i < librarylist._libraryCount; i++)
    {
        os << librarylist._libraryList[i];
    }
    return os;
}