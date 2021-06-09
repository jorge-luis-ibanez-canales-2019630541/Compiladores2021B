#ifndef _FOLLOW_
#define _FOLLOW_

#include "Symbol.h"
#include <set>
#include <iostream>

using std::set;
using std::istream;
using std::ostream;

class Follow: public set<Terminal>{
    public:
        Follow() {}
        Follow(Terminal F) { this->insert(F);  }
        Follow(set<Terminal> F) { this->insert(F.begin(), F.end());  }


        bool is_inside(const Terminal &T) const;
        void remove(const Terminal &T);
        void merge(const Follow &F);



        friend istream& operator>>(istream&, Follow&);
        friend ostream& operator<<(ostream&, const Follow&);
};


#endif