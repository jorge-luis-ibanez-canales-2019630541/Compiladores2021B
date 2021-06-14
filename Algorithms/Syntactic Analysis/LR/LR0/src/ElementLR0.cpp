#include "../../LR/Element.h"
#include "ElementLR0.h"
#include "../../../Grammar/ProductionRule.h"



void ElementLR0::move_point_right()
{
    PR.erase_symbol_by_idx(idx_point);
    PR.insert_symbol_by_idx(idx_point+1, Symbol("."));
    idx_point++;
}

int ElementLR0::get_idx_point() { return idx_point; }
ProductionRule ElementLR0::get_production() { return PR; }

bool ElementLR0::operator<(const ElementLR0 &E) const { return PR < E.PR || (PR == E.PR && idx_point < E.idx_point);  }
bool ElementLR0::operator==(const ElementLR0 &E) const { return PR == E.PR && idx_point == E.idx_point;  }
