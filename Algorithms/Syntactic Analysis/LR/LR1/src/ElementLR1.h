#ifndef _ELEMENTLR1_
#define _ELEMENTLR1_

#include "../../LR/Element.h"
#include "../../../Grammar/ProductionRule.h"

class ElementLR1: public Element{
    private:
        ProductionRule PR;
        Terminal lookahead;
        int idx_point;

    public:

        ElementLR1() { }
        ElementLR1(ProductionRule _PR, Terminal lookahead, int idx_point=0): PR(_PR), lookahead(lookahead), idx_point(idx_point) { PR.insert_symbol_by_idx(idx_point, Symbol(".")); }


        int get_idx_point();
        ProductionRule get_production();
        Terminal get_lookahead();

        bool operator<(const ElementLR1 &E) const;
        bool operator==(const ElementLR1 &E) const;
};

#endif