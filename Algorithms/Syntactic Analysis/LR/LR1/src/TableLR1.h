#ifndef _TABLELR1_
#define _TABLELR1_

#include <map>
#include <utility>
#include <string>


#include "PowersetAlgoLR1.h"
#include "../../LR/TableLR.h"

#include "../../../Grammar/FollowFactory.h"

class TableLR1: public TableLR{
    private:
        PowersetAlgoLR1 PALR1;
        //Grammar G;
        FollowFactory FollowFact;
        ProductionRule extension;
        
        void get_action_accept();
        void get_action_reduce();

    public:

        TableLR1(Grammar G);

        
};



#endif