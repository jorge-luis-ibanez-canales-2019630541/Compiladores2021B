
#include <set>
#include <iostream>
#include "Symbol.h"
#include "Follow.h"

using std::set;
using std::istream;
using std::ostream;




bool Follow::is_inside(const Terminal &T) const { return this->count(T);  }
void Follow::remove(const Terminal &T) { this->erase(T);  }
void Follow::merge(const Follow &F) { this->insert(F.begin(), F.end());  }





//friend istream& operator>>(istream&, Follow&);
ostream &operator<<(ostream &os, const Follow & F)
{
    for(auto symbol: F) os << symbol << " ";
    return os;
}
