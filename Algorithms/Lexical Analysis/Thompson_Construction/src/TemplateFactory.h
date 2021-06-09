#ifndef _TEMPLATEFACTORY_
#define _TEMPLATEFACTORY_

#include "../../Automaton/NFA.h"


using std::string;

class TemplateFactory{
    private:

    public:
        NFA* get_label(char c);
        NFA* get_concatenation(NFA *A1, NFA *A2);
        NFA* get_closure(NFA *A1);
        NFA* get_or(NFA *A1, NFA *A2);
        
};


#endif