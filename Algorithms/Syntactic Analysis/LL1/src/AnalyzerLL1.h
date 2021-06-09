#ifndef _ANALYZERLL1_
#define _ANALYZERLL1_

#include <string>
#include <vector>
#include "../../Grammar/Grammar.h"
#include "TableLL1.h"

using std::string;
using std::vector;

class AnalyzerLL1 {
        public:
        Grammar G;
        TableLL1 Table;

        AnalyzerLL1(Grammar G): G(G) { Table = TableLL1(G); }

        string analyze_string(string string_tocheck);
        string analyze_string(vector<Symbol> string_tocheck);
};

#endif