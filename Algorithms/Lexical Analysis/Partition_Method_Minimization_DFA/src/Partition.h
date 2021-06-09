#ifndef _PARTITION_
#define _PARTITION_

#include<set>
#include<vector>
#include "../../Automaton/State.h"
#include "EquivClass.h"

using std::set;
using std::vector;

class Partition: public vector<EquivClass>{
    private:
        

    public:
        Partition() {}
        Partition(vector<EquivClass> classes) { this->assign(classes.begin(), classes.end()); }

        void push(EquivClass E);

};

#endif