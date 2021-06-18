#include<set>
#include<stack>
#include<string>
#include<sstream>

#include "../../Automaton/Regex.h"
#include "../../Automaton/NFA.h"
#include "NodeAlgo.h"

using std::set;
using std::stack;
using std::string;


//Setters
void NodeAlgo::set_left(NodeAlgo *L){ this->L = L; }
void NodeAlgo::set_right(NodeAlgo *R){ this->R = R; }
void NodeAlgo::set_nullable(bool nullable){ this->nullable = nullable; }
void NodeAlgo::set_starting(set<int> starting) { this->starting = starting; }
void NodeAlgo::set_ending(set<int> ending) { this->ending = ending; }

//Getters
NodeAlgo* NodeAlgo::get_left(){ return (NodeAlgo*) L; }
NodeAlgo* NodeAlgo::get_right(){ return (NodeAlgo*) R; }
set<int> NodeAlgo::get_starting() { return starting; }
set<int> NodeAlgo::get_ending() { return ending; }
bool NodeAlgo::is_nullable(){ return nullable; }