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
#include "NodeAlgo.h"

using std::set;
using std::map;
using std::string;
using std::stringstream;

class SyntaxTreeAlgo: public SyntaxTree{
    private:

    public:
        SyntaxTreeAlgo(Regex _regex) { regex = _regex; get_SyntaxTree( regex.get_postfix() ) ; }


        
        //Getters
        NodeAlgo* get_root();

        void get_SyntaxTree(const string &regex_postfix);
};





#endif
