#ifndef _CYCLESDETECTOR_
#define _CYCLESDETECTOR_

#include <set>

using std::set;

template<class T>
class CyclesDetector{
    private:
        set<T> checker;

    public:
        CyclesDetector() { }
        void insert(T element);

        void remove(T element);

        bool is_inside(T element);

};

#endif