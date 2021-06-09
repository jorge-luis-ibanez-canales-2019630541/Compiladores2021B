#ifndef _FIRST_
#define _FIRST_


#include "Symbol.h"
#include <set>
#include <iostream>

using std::set;
using std::istream;
using std::ostream;

class First: public set<Terminal>{
    public:
        First() {}
        First(Terminal F) { this->insert(F);  }
        First(set<Terminal> F) { this->insert(F.begin(), F.end());  }

        bool is_inside(const Terminal &T) const;
        void remove(const Terminal &T);
        void merge(const First &F);
        friend istream& operator>>(istream&, First&);
        friend ostream& operator<<(ostream&, const First&);

};

#endif