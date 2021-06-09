#include "Symbol.h"



bool Symbol::is_terminal() { return terminal; }
bool Symbol::is_epsilon() { return *this == epsilon; }  


