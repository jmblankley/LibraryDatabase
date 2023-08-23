#include "Library.hpp"

using namespace std;

ostream &operator<<(ostream &os, const Library &library)
{
    os << library._name << " " << library._city << " " << library._zip << endl;
    return os;
}
