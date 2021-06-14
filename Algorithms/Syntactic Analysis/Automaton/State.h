#ifndef _STATE_
#define _STATE_

#include <map>
#include <set>

using std::map;
using std::set;

const char eps = 'E';

class State{
    private:
        int id;
        map<char, set<State*>> trans;

    public:
        State(int _id): id(_id) {}

        //Getters
        int get_id();
        set<State*> query_trans(char label);
        map<char, set<State*>> get_trans();

        //Setters
        void set_id(int id);
        void make_trans(State *dest, char label);
        void copy_trans(State *S);
};

#endif 