#include <string>
#include <stack>
#include <assert.h>
#include "../../Automaton/NFA.h"
#include "../../Automaton/State.h"
#include "../../Automaton/Regex.h"
#include "TemplateFactory.h"
#include "ThompsonAlgo.h"
#include "../../Automaton/Regex.h"

using std::string;
using std::stack;


NFA* ThompsonAlgo::get_NFA(Regex &regex) //Recibe una regex en postfix y regresa el NFA de la regex
{
    stack<NFA*> NFAs;
    TemplateFactory *TF = new TemplateFactory();
    string regex_postfix = regex.get_postfix();
    for(auto c: regex_postfix)
    {
        if(c == '.') //Si se encuentra una concatenación significa que los dos ultimos operandos serán concatenados
        {
            
            auto A2 = NFAs.top(); NFAs.pop();
            auto A1 = NFAs.top(); NFAs.pop();
            
            NFAs.push(TF->get_concatenation(A1, A2));
        }
        else if(c == '*') //Si se encuentra una cerradura, significa que lo ultimo que este en la pila se le aplica cerradura
        {
            auto A1 = NFAs.top(); NFAs.pop();

            NFAs.push(TF->get_closure(A1));
        }
        else if(c == '|') //Si se encuentra un or significa que habrá un or entre los dos ultimos operandos de la pila
        {
            auto A2 = NFAs.top(); NFAs.pop();
            auto A1 = NFAs.top(); NFAs.pop();

            NFAs.push(TF->get_or(A1, A2));
        }
        else
        {
            NFAs.push(TF->get_label(c)); //Significa que es un simbolo del alfabeto
        }
    }
    //assert(NFAs.size() == 1);
    return NFAs.top();
}   

NFA* ThompsonAlgo::run() //Corre el algoritmo con la regex debidamente procesada
{
    return get_NFA( regex );
}

