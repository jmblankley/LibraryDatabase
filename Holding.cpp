#include "Holding.hpp"

using namespace std;

ostream &operator<<(ostream &os, const Holding &holding)
{
    os << holding._ISBN << " " << holding._name << endl;
    return os;
}
