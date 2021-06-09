#ifndef _SYMBOL_
#define _SYMBOL_

#include<string>

using std::string;

const string epsilon = "3";
class Symbol: public string{
    private:
        
    public:
        bool terminal; 
        Symbol() { }
        Symbol(char _symbol) { this->push_back(_symbol);}
        Symbol(string _symbol) { *this += _symbol; }


        bool is_terminal();
        bool is_epsilon();
};

class Terminal: public Symbol{
    public:
        Terminal() { terminal = true; }
        Terminal(char _symbolT): Symbol(_symbolT) { terminal = true; }
        Terminal(string _symbolsT): Symbol(_symbolsT) { terminal = true; }

};

class NonTerminal: public Symbol{
    public:
        NonTerminal() { terminal = false; }
        NonTerminal(char _symbolN): Symbol(_symbolN) { terminal = false; }
        NonTerminal(string _symbolsN): Symbol(_symbolsN) { terminal = false; }
};


#endif