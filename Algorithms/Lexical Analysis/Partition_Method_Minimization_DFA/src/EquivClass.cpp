#include "EquivClass.h"
#include "../../Automaton/State.h"



bool EquivClass::is_inside(State* S) { return this->count(S); }