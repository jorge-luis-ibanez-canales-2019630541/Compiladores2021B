#include "SyntaxTree.h"
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include "../../Automaton/Regex.h"
#include "../../Automaton/NFA.h"

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


//SyntaxTree
Node* SyntaxTree::get_root() { return root; }

char SyntaxTree::get_val(int id) { return id_to_val[id]; }

void SyntaxTree::get_SyntaxTree(const string &regex_postfix)
{
    stack<Node*> Nodes;
    int id = 1;
    for(auto c: regex_postfix)
    {
        if(c == '.' || c == '|')
        {
            Node *right = Nodes.top(); Nodes.pop();
            Node *left = Nodes.top(); Nodes.pop();
            Node *new_node = new Node(c);
            new_node->set_left(left);
            new_node->set_right(right);
            Nodes.push(new_node);
        }
        else if(c == '*')
        {
            Node *below = Nodes.top(); Nodes.pop();
            Node *new_node = new Node('*');
            new_node->set_left(below);
            Nodes.push(new_node);
        }
        else if(c == eps) 
        {
            Nodes.push(new Node(c, true));
        }
        else //Symb of alphabet
        {
            id_to_val[id] = c;
            Nodes.push(new Node(c, true, id++));
        }
    }
    root = Nodes.top();
    Nodes.pop();
    return;
}

