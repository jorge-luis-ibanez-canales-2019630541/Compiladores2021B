#include "../../Automaton/NFA.h"
#include "../../Automaton/State.h"
#include "TemplateFactory.h"
#include <assert.h>



NFA* TemplateFactory::get_label(char label)
{
    auto A1 = new NFA();

    A1->set_start(new State(A1->sz_NFA++));

    A1->insert_final(new State(A1->sz_NFA++));

    A1->get_start()->make_trans(A1->get_final(), label);

    return A1;
}

NFA* TemplateFactory::get_concatenation(NFA *A1, NFA *A2)
{

    assert(A1 != NULL && A2 != NULL);
    A1->get_final()->copy_trans(A2->get_start());

    
    A1->delete_finales();
    A1->insert_final(A2->get_final());
    

    A1->set_sz(A1->get_sz() + A2->get_sz()-1);

    return A1;
}

NFA* TemplateFactory::get_closure(NFA *A1)
{
    assert(A1 != NULL);

    A1->get_final()->make_trans(A1->get_start(), eps);


    State *start = new State(A1->sz_NFA++);
    State *final = new State(A1->sz_NFA++);

    start->make_trans(A1->get_start(), eps);
    start->make_trans(final, eps);
    

    A1->get_final()->make_trans(final, eps);
    

    A1->set_start(start);
    

    A1->delete_finales();
    A1->insert_final(final);

    return A1;

}

NFA* TemplateFactory::get_or(NFA *A1, NFA *A2)
{

    assert(A1 != NULL && A2 != NULL);

    State *start = new State(A1->sz_NFA++);
    State *final = new State(A1->sz_NFA++);

    A1->set_sz(A1->get_sz() + A2->get_sz());

    start->make_trans(A1->get_start(), eps);
    
    start->make_trans(A2->get_start(), eps);
    

    A1->get_final()->make_trans(final, eps);
    
    A2->get_final()->make_trans(final, eps);
    
    A1->set_start(start);
    
    
    A1->delete_finales();
    A1->insert_final(final);

    return A1;
}

