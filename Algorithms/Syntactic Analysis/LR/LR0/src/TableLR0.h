#ifndef _TABLELR0_
#define _TABLELR0_

#include <map>
#include <utility>
#include <string>


#include "PowersetAlgoLR0.h"
#include "../../LR/TableLR.h"

#include "../../../Grammar/FollowFactory.h"

class TableLR0: public TableLR{
    private:
        PowersetAlgoLR0 PALR0;
        //Grammar G;
        FollowFactory FollowFact;

        void get_action_accept();
        void get_action_reduce();

    public:

        TableLR0(Grammar G);

        

};



#endif