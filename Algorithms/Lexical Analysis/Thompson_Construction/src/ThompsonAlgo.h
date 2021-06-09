#ifndef _THOMPSONALGO_
#define _THOMPSONALGO_

#include "../../Automaton/NFA.h"
#include "../../Automaton/State.h"
#include "../../Automaton/Regex.h"
#include <string>

using std::string;


class ThompsonAlgo{
    private:
        Regex regex;

        //NFA_T* template_T(int option, NFA_T *A1, NFA_T *A2, char label); //Plantillas
    
        NFA* get_NFA(Regex &regex); //Recibe una regex en postfix y regresa el NFA de la regex

    public:
        ThompsonAlgo(Regex _regex): regex(_regex) {}
        NFA* run(); //Corre el algoritmo con la regex debidamente procesada
};


#endif