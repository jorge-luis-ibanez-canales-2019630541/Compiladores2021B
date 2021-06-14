#ifndef _ELEMENTLR0_
#define _ELEMENTLR0_

#include "../../LR/Element.h"
#include "../../../Grammar/ProductionRule.h"

class ElementLR0: public Element{
    private:

        ProductionRule PR;
        int idx_point;

    public:

        ElementLR0() { }
        ElementLR0(ProductionRule _PR, int idx_point=0): PR(_PR), idx_point(idx_point) { PR.insert_symbol_by_idx(idx_point, Symbol(".")); }

        void move_point_right();

        int get_idx_point();
        ProductionRule get_production();

        bool operator<(const ElementLR0 &E) const;
        bool operator==(const ElementLR0 &E) const;
};

#endif