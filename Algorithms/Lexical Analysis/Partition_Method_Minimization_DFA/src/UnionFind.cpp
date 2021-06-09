#include<algorithm>


using std::swap;

template<typename T>
class UnionFind {
    private:
        size_t n;
        map<T, T> dad;
        map<T, int> _size;

    public:
        UnionFind(vector<T> initial) : n( initial.size() ){
            for(T node: initial)
            {   
                dad[node] = node;
                _size[node] = 1;
            }
        }
        T root(T u) {
            if (dad[u] == u) return u;
            return dad[u] = root(dad[u]);
        }
        void join(T u, T v) {
            T Ru = root(u), Rv = root(v);
            if (Ru == Rv) return;
            if (_size[Ru] > _size[Rv]) swap(Ru, Rv);
            --n, dad[Ru] = Rv;
            _size[Rv] += _size[Ru];
        }
        bool areConnected(T u, T v) { return root(u) == root(v); }
        int numberOfSets() { return n; }
};