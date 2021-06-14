#include "../../LR/Element.h"
#include "ElementLR1.h"
#include "../../../Grammar/ProductionRule.h"



int ElementLR1::get_idx_point() { return idx_point; }
ProductionRule ElementLR1::get_production() { return PR; }
Terminal ElementLR1::get_lookahead() { return lookahead;  }

//bool ElementLR1::operator<(const ElementLR1 &E) const { return PR < E.PR || (PR == E.PR && idx_point < E.idx_point);  }
//bool ElementLR1::operator==(const ElementLR1 &E) const { return PR == E.PR && idx_point == E.idx_point;  }

