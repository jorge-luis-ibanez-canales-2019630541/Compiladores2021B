#include <set>
#include <iostream>
#include <utility>
#include "CyclesDetector.h"

using std::pair;
using std::cout;
using std::set;


template<class T>
void CyclesDetector<T>::insert(T element) { checker.insert(element); }

template<class T>
void CyclesDetector<T>::remove(T element) { checker.erase(element); }

template<class T>
bool CyclesDetector<T>::is_inside(T element)
{
    if(checker.count(element)) return true;
    return false;
}



template class CyclesDetector<int>;
template class CyclesDetector<pair<int,int>>;