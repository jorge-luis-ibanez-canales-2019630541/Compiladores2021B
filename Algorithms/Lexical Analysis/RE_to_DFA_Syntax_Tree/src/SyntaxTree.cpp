#include<set>
#include<stack>
#include<string>
#include<sstream>

#include "../../Automaton/Regex.h"
#include "../../Automaton/NFA.h"
#include "SyntaxTree.h"
#include "Node.h"

using std::set;
using std::stack;
using std::string;


//SyntaxTree
Node* SyntaxTree::get_root() { return root; }

char SyntaxTree::get_val(int id) { return id_to_val[id]; }

void SyntaxTree::get_SyntaxTree(string regex_postfix)
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

