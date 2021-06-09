#include <bits/stdc++.h>
#include "../Grammar/ProductionRule.h"
#include "../Grammar/FirstFactory.h"
#include "../Grammar/First.h"
#include "../Grammar/FollowFactory.h"
#include "../Grammar/Follow.h"
#include "../Grammar/Grammar.h"
#include "../Grammar//Symbol.h"
#include "src/TableLL1.h"
#include "src/AnalyzerLL1.h"

using namespace std;


int main () {
	//fastIO();
    
    /*
    Terminal mas("+");
    Terminal por("*");
    Terminal or2("|");
    Terminal eps("3");
    Terminal izq("(");
    Terminal der(")");
    Terminal id("i");

    NonTerminal E("E");
    NonTerminal Ep("E'");
    NonTerminal T("T");
    NonTerminal Tp("T'");
    NonTerminal F("F");

    ProductionRule P1(E, {T,Ep});        // E -> T E'
    ProductionRule P2(Ep, {mas,T,Ep});   // E' -> + T E'
    ProductionRule P3(Ep, {eps});        // E' -> eps
    ProductionRule P4(T, {F,Tp});        // T -> F T'
    ProductionRule P5(Tp, {por, F, Tp}); // T' -> * F T'
    ProductionRule P6(Tp, {eps});        // T' -> eps
    ProductionRule P7(F, {izq,E, der});  // F -> ( E )
    ProductionRule P8(F, {id});          // F -> i
    */
    
    /*
    ProductionRule P1("A->aBC");
    ProductionRule P2("A->bAa");
    ProductionRule P3("B->cCa");
    ProductionRule P4("B->CA");
    ProductionRule P5("C->3");
    ProductionRule P6("C->d");
    ProductionRule P7("C->CA");
    //ProductionRule P8("E->3");
    */

    
    ProductionRule P1("A->a");
    ProductionRule P2("B->b");
    ProductionRule P3("C->c");
    ProductionRule P4("D->d");
    ProductionRule P5("E->e");

    ProductionRule P6("C->3");
    ProductionRule P7("D->3");

    ProductionRule P8("A->CDfE");
    ProductionRule P9("B->ADEg");
    ProductionRule P10("C->hijB");
    
    

    vector< ProductionRule > productions = {P1, P2, P3, P4, P5, P6, P7, P8, P9, P10};


    Grammar G(NonTerminal("A"), productions);
    cout << G << endl;

    TableLL1 TLL1(G);
    TLL1.print();

    AnalyzerLL1 ALL1(G);

    while(true)
    {
        string s; getline(cin, s);
        cout << ALL1.analyze_string(s) << endl;
    }


	return 0;
}


