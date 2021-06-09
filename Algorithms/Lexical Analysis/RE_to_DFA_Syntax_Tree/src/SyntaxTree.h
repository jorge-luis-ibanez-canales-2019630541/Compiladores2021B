#ifndef _SYNTAXTREE_
#define _SYNTAXTREE_

#include<set>
#include<map>
#include<string>
#include<sstream>
#include "../../Automaton/NFA.h"
#include "../../Automaton/Regex.h"
#include "../../Automaton/GV.h"

using std::set;
using std::map;
using std::string;
using std::stringstream;

class Node{
    protected:
    //private:
        Node *L=NULL, *R=NULL;
        char val;
        bool leaf;
        int id;
    public:

        //Constructor
        Node() {}
        Node(char _val, bool _leaf = false, int _id=0): val(_val), leaf(_leaf), id(_id) {
            
        }

        //Setters
        void set_left(Node *L);
        void set_right(Node *R);
        void set_val(char val);
        void set_is_leaf(bool is_leaf);
        void set_id(int id);


        //Getters
        Node* get_left();
        Node* get_right();
        char get_val();
        int get_id();
        bool is_leaf();
        bool has_left();
        bool has_right();
};

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

        virtual void get_SyntaxTree(const string &regex_postfix);
};





#endif
