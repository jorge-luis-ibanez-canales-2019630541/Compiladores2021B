#include<set>
#include<stack>
#include<string>
#include<sstream>

#include "../../Automaton/Regex.h"
#include "../../Automaton/NFA.h"
#include "SyntaxTreeAlgo.h"
#include "NodeAlgo.h"

using std::set;
using std::stack;
using std::string;


//SyntaxTree
NodeAlgo* SyntaxTreeAlgo::get_root() { return (NodeAlgo*) root; }


void SyntaxTreeAlgo::get_SyntaxTree(const string &regex_postfix)
{
    stack<NodeAlgo*> Nodes;
    int id = 1;
    for(auto c: regex_postfix)
    {
        if(c == '.' || c == '|')
        {
            NodeAlgo *right = Nodes.top(); Nodes.pop();
            NodeAlgo *left = Nodes.top(); Nodes.pop();
            NodeAlgo *new_node = new NodeAlgo(c);
            new_node->set_left(left);
            new_node->set_right(right);
            Nodes.push(new_node);
        }
        else if(c == '*')
        {
            NodeAlgo *below = Nodes.top(); Nodes.pop();
            NodeAlgo *new_node = new NodeAlgo('*');
            new_node->set_left(below);
            Nodes.push(new_node);
        }
        else if(c == eps) 
        {
            Nodes.push(new NodeAlgo(c, true));
        }
        else //Symb of alphabet
        {
            id_to_val[id] = c;
            Nodes.push(new NodeAlgo(c, true, id++));
        }
    }
    root = Nodes.top();
    Nodes.pop();
    return;
}

