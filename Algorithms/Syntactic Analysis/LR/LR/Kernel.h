#ifndef _KERNEL_
#define _KERNEL_

#include <set>
#include "Element.h"

using std::set;

class Kernel{
    private:

    public:
        set<Element*> kernel;

        Kernel() { }
        Kernel(set<Element*> _kernel): kernel(_kernel) { }

        int size();
        set<Element*> get_kernel();


        using iterator = set<Element*>::iterator;
        iterator begin(){ return kernel.begin(); }
        iterator end(){ return kernel.end(); }
};

#endif