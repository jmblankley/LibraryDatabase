#include "Book.hpp"

using namespace std;

ostream &operator<<(ostream &os, const Book &book)
{
    os << book._ISBN << " " << book._year << " " << book._author << " " << book._title << endl;
    return os;
}
