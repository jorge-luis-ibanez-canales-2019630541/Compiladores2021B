
#include <vector>
#include "Grammar.h"
#include "CyclesDetector.h"
#include "FirstFactory.h"
#include "Symbol.h"
#include "ProductionRule.h"
#include "Follow.h"
#include "FollowFactory.h"
#include <utility> //para pair

using std::vector;
using std::pair;


Follow FollowFactory::try_rule1(NonTerminal NT)
{
    if(G.get_start() == NT) return Follow({"$"});
    return Follow(set<Terminal>{});
}

Follow FollowFactory::try_rule2(int idx_finded, ProductionRule PR, int id_pr)
{
    //assert(PR == G.get_production_rule(id_pr));

    Follow Follow_total;
    int n_right_part = PR.get_sz();
    if(idx_finded + 1 < n_right_part ) //Hay alguien enfrente
    {
        First First_next = FirstFact.get_first( get_symbols(PR, idx_finded+1, -1)   );
        if(First_next.is_inside(epsilon)) 
        {
            Follow_total.merge(try_rule3(idx_finded, PR, id_pr));
            First_next.remove(epsilon);
        }
        Follow_total.merge(First_next); /////////////////////
    }
    
    return Follow_total;
}

Follow FollowFactory::try_rule3(int idx_finded, ProductionRule PR, int id_pr)
{
    //assert(PR == G.get_production_rule(id_pr));

    First First_next;
    int n_right_part = PR.get_sz();
    if(idx_finded + 1 < n_right_part) //Hay alguien enfrente
        First_next = FirstFact.get_first(get_symbols(PR, idx_finded+1, -1));


    if((idx_finded + 1 == n_right_part || First_next.is_inside(epsilon)) && (!CD.is_inside({id_pr, idx_finded}))) //Solo asi aplica la regla 3
    {
        CD.insert({id_pr, idx_finded}); //Para checar que no entre en ciclos
        auto A = get_follow(PR.get_left_part());
        CD.remove({id_pr, idx_finded}); 
        return A;
    }

    return Follow(set<Terminal>{});
}

vector<int> FollowFactory::find_symbol(NonTerminal NT, vector<Symbol> Symbols)
{
    vector<int> indexes_finded;
    size_t n_Symbols = Symbols.size();
    for(size_t i = 0; i < n_Symbols; i++)
    {
        if(Symbols[i] == NT) indexes_finded.push_back(i);
    }
    return indexes_finded;
}

vector<Symbol> FollowFactory::get_symbols(ProductionRule PR, int idx_left, int idx_right)
{
    int n_PR = PR.get_sz();
    if(idx_right == -1) idx_right = n_PR-1;

    vector<Symbol> symbols;
    for(int i = idx_left; i <= idx_right; i++) symbols.push_back(PR.get_symbol_right(i));

    return symbols;
}

Follow FollowFactory::get_follow(NonTerminal NT) 
{
    Follow Follow_total;
    
    if(G.get_start() == NT) Follow_total.merge(try_rule1(NT));

    
    for(int i = 0; i<G.get_sz(); i++)
    {
        ProductionRule PR = G.get_production_rule(i);

        vector<int> indexes_finded = find_symbol(NT, PR.get_right_part());
        
        for(int idx_finded: indexes_finded)
        {
            Follow_total.merge(try_rule2(idx_finded, PR, i));
            Follow_total.merge(try_rule3(idx_finded, PR, i));
        }
    }


    return Follow_total;
}

