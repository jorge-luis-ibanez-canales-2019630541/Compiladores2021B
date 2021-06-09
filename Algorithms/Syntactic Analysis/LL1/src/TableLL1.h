#ifndef _TABLELL1_
#define _TABLELL1_


#include <map>
#include <utility>
#include "../../Grammar/Symbol.h"
#include "../../Grammar/Grammar.h"

using std::map;
using std::pair;


class TableLL1{
    private:
        Grammar G;
        map< pair<NonTerminal, Terminal>, int > table;
        bool LL1 = true;

        void insert_entry(NonTerminal NT, Terminal T, int id_rule);

    public: 

        TableLL1() {}
        TableLL1(Grammar G): G(G) { get_table(); }

        void get_table();
        bool check_entry(NonTerminal NT, Terminal T);
        int get_query(pair<NonTerminal, Terminal> query);
        void print();
        bool is_LL1();

};

#endif