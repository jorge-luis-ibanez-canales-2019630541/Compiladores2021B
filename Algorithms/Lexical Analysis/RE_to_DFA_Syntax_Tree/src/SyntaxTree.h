#ifndef _SYNTAXTREE_
#define _SYNTAXTREE_

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

class SyntaxTree{
    protected:
        Node *root;
        Regex regex;
        map<int, char> id_to_val; //Id of Node to Val

    public:
        SyntaxTree() {}
        SyntaxTree(Regex _regex): regex(_regex) { get_SyntaxTree( regex.get_postfix() ) ; }

        //Getters
        Node* get_root();
        char get_val(int id);

        void get_SyntaxTree(string regex_postfix);
};





#endif
