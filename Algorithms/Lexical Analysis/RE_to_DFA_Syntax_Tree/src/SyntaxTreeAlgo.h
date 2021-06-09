#ifndef _SYNTAXTREEALGO_
#define _SYNTAXTREEALGO_

#include<set>
#include<map>
#include<string>
#include<sstream>
#include "../../Automaton/NFA.h"
#include "../../Automaton/Regex.h"
#include "../../Automaton/GV.h"
#include "SyntaxTree.h"

using std::set;
using std::map;
using std::string;
using std::stringstream;

class NodeAlgo: public Node{
    private:
        bool nullable;
        set<int> starting, ending;
    public:

        //Constructor
        NodeAlgo() {}
        NodeAlgo(char _val, bool _leaf = false, int _id=0): Node(_val, _leaf, _id){
            if(val == '*' || val == eps) nullable = true;
            if(leaf && val != eps)
            {
                starting.insert(id);
                ending.insert(id);
            } 
         }

        //Setters
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

class SyntaxTreeAlgo: public SyntaxTree{


    public:
        SyntaxTreeAlgo(Regex _regex) {regex = _regex; get_SyntaxTree( regex.get_postfix() ) ; }
        void get_SyntaxTree(const string &regex_postfix) override;

        NodeAlgo* get_root();
};





#endif
