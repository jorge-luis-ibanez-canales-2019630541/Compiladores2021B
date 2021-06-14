#ifndef _CLOSURE_
#define _CLOSURE_

#include <set>
#include "Element.h"
#include "Kernel.h"

using std::set;

class Closure{
    private:
        Kernel kernel;
        set< Element* > elements;


    public:
        Closure() {}
        Closure(Kernel K): kernel(K)
        {
            for(Element* E: K)
                elements.insert(E);
        }

        set< Element* > get_elements();
        bool is_inside(Element* E);


        void insert(Element* E);

        bool operator<(const Closure &C) const;


        using iterator = set<Element*>::iterator;
        iterator begin(){ return elements.begin(); }
        iterator end(){ return elements.end(); }
};

#endif