#include "../../LR/Element.h"
#include "ElementLR1.h"
#include "../../../Grammar/ProductionRule.h"



int ElementLR1::get_idx_point() { return idx_point; }
ProductionRule ElementLR1::get_production() { return PR; }
Terminal ElementLR1::get_lookahead() { return lookahead;  }


