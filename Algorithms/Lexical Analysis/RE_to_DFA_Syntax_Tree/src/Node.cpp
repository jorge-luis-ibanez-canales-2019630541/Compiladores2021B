#include<set>
#include<stack>
#include<string>
#include<sstream>

#include "../../Automaton/Regex.h"
#include "../../Automaton/NFA.h"
#include "Node.h"

using std::set;
using std::stack;
using std::string;



//Node
//Setters
void Node::set_left(Node *L){ this->L = L; }
void Node::set_right(Node *R){ this->R = R; }
void Node::set_val(char val){ this->val = val; }
void Node::set_is_leaf(bool is_leaf){ this->leaf = leaf; }
void Node::set_id(int id){ this->id = id; }

//Getters
Node* Node::get_left(){ return L; }
Node* Node::get_right(){ return R; }
char Node::get_val(){ return val; }
int Node::get_id() { return id; }
bool Node::is_leaf(){ return leaf; }
bool Node::has_left(){ return L != NULL; }
bool Node::has_right(){ return R != NULL; }

