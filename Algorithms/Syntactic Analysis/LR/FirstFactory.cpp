#include "Grammar.h"
#include "CyclesDetector.h"
#include "First.h"
#include "Symbol.h"
#include "ProductionRule.h"
#include "FirstFactory.h"


First FirstFactory::do_rule1(Terminal T) { return {T};  }


First FirstFactory::do_rule2(NonTerminal NT)
{
    First F_total;
    //for(ProductionRule PR: G.production_rules)
    for(int i = 0; i<G.get_sz(); i++)
    {
        ProductionRule PR = G.get_production_rule(i);
        if(PR.get_left_part() == NT && !CD.is_inside(i)) // Por cada PR que sea NT -> Y1 Y2 Y3
        {
            CD.insert(i);
            First F_production = do_second_per_production(PR);
            F_total.merge(F_production);
            CD.remove(i);
        }
    }
    return F_total;
}

First FirstFactory::do_second_per_production(ProductionRule PR)
{
    NonTerminal NT = PR.get_left_part();
    First F_total;
    bool all_eps = true;
    
    for(Symbol Yi: PR.get_right_part())
    {
        First F_Yi = get_first(Yi);

        if( !F_Yi.is_inside(epsilon)   )
        {
            all_eps = false;
            F_total.merge(F_Yi);
            break;
        }
        else
        {
            F_Yi.remove(epsilon);
            F_total.merge(F_Yi);
        }
    }


    if(all_eps) F_total.insert(epsilon);


    return F_total;
}


First FirstFactory::do_rule3(Symbol S) { return {S}; } //Asumir que S = epsilon


First FirstFactory::do_rule4(vector<Symbol> Ss)
{
    First F_total;
    bool all_eps = true;

    for(Symbol Xi: Ss)
    {
        First F_Xi = get_first(Xi);
        if(!F_Xi.is_inside(epsilon))
        {
            all_eps = false;
            F_total.merge(F_Xi);
            break;
        }
        else
        {
            F_Xi.remove(epsilon);
            F_total.merge(F_Xi);
        }
    }

    if(all_eps) F_total.insert(epsilon);

    return F_total;
}

First FirstFactory::get_first(Symbol S)
{
    First F;


    if(S.is_terminal())
        F = do_rule1(Terminal(S));
    else
        F = do_rule2(NonTerminal(S));


    return F;
}     

First FirstFactory::get_first(vector<Symbol> S)
{
    return do_rule4(S);
}     
