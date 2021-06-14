#include <set>
#include "Element.h"
#include "Kernel.h"

using std::set;


int Kernel::size() { return kernel.size(); }
set<Element*> Kernel::get_kernel( ) { return kernel; }
