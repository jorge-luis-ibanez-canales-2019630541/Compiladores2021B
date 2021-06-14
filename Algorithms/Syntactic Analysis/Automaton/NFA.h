#ifndef _NFA_
#define _NFA_

#include <map>
#include <set>
#include "State.h"

using std::map;
using std::set;

class NFA{
    private:
        State *start;
        //State *final;
        set<State*> finales;
        

        void dfs(State *current, map< State*, map<char, set<State*>>> &ans); //Auxiliar para get_trans()

    public:
        int sz_NFA = 0;
        //Getters    
        State* get_start();
        State* get_final();
        set<State*> get_finales();
        int get_sz();

        //Setters
        void set_start(State *start);
        void insert_final(State *start); 
        void delete_final(State *final);
        void delete_finales();
        void set_sz(int sz_NFA);

    
        //Functions
        map< State*, map<char, set<State*>>> get_trans();
        
};


#endif