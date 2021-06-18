#ifndef _NODEALGO_
#define _NODEALGO_

#include<set>
#include<map>
#include<string>
#include<sstream>
#include "../../Automaton/NFA.h"
#include "../../Automaton/Regex.h"
#include "../../Automaton/GV.h"
#include "Node.h"

using std::set;
using std::map;
using std::string;
using std::stringstream;

class NodeAlgo: public Node{
    private:
        bool nullable = false;
        set<int> starting, ending;

    public:

        //Constructor
        NodeAlgo() {}
        NodeAlgo(char _val, bool _leaf = false, int _id = 0): Node(_val, _leaf, _id) { }

        //Setters
        void set_left(NodeAlgo *L);
        void set_right(NodeAlgo *R);
        void set_nullable(bool nullable);
        void set_starting(set<int> starting);
        void set_ending(set<int> ending);

        //Getters
        NodeAlgo* get_left();
        NodeAlgo* get_right();
        set<int> get_starting();
        set<int> get_ending();
        bool is_nullable();                
};



#endif
