#include <set>
#include "Element.h"
#include "Kernel.h"
#include "Closure.h"

using std::set;



set< Element* > Closure::get_elements() {  return elements; }
bool Closure::is_inside(Element* E) {  return elements.count(E);  }


void Closure::insert(Element* E) { elements.insert(E);   }

bool Closure::operator<(const Closure &C) const { return elements <  C.elements;  }

