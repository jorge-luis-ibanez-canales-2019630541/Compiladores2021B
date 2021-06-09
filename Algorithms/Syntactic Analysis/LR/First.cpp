#include <set>
#include <iostream>
#include "Symbol.h"
#include "First.h"

using std::set;
using std::ostream;


bool First::is_inside(const Terminal &T) const { return this->count(T);  }
void First::remove(const Terminal &T) { this->erase(T);  }
void First::merge(const First &F) { this->insert(F.begin(), F.end());  }



//istream& operator>>(istream&, First&);
ostream &operator<<(ostream &os, const First & F)
{
    for(auto symbol: F) os << symbol << " ";
    return os;
}
