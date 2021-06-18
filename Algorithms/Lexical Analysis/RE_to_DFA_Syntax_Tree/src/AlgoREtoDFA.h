#include<map>
#include<set>

#include "SyntaxTree.h"
#include "../../Automaton/State.h"
#include "../../Automaton/DFA.h"
#include "../../Automaton/Regex.h"
#include "Node.h"
#include "NodeAlgo.h"
#include "SyntaxTreeAlgo.h"


using std::set;
using std::map;

struct AlgoREtoDFA{
    private:
        
        map<State*, set<int>> state_to_set;
        map<set<int>, State*> set_to_state;
        int id_DFA = 1;
        
        void dfs_get_nullable(NodeAlgo *curr);
        void dfs_get_starting(NodeAlgo *curr);
        void dfs_get_ending(NodeAlgo *curr);
        void dfs_get_follow(NodeAlgo *curr, map<int, set<int>> &table_follow);


        bool is_void_state(State *S);
        bool is_final_state(State *S);
        State* map_set(const set<int> &set_ST);

    public:
        SyntaxTreeAlgo *ST;
        AlgoREtoDFA(Regex regex) { ST = new SyntaxTreeAlgo( Regex( string("(") + regex.get_regex() + string(")") + string("#") ) ); }
        DFA* run();
};