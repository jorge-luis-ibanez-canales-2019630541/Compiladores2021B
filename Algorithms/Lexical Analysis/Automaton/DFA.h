#ifndef _DFA_
#define _DFA_

#include <vector>
#include "NFA.h"

using std::vector;

struct DFA: public NFA
{
    vector<char> alph = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
};

#endif