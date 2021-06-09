#include <string>
#include <stack>
#include <iostream>
#include "Regex.h"

using std::string;
using std::stack;
using std::istream;
using std::ostream;


string Regex::get_regex(){ return regex;  }

void Regex::set_regex(string regex){ this->regex = regex; }

bool Regex::is_operator(char c)
{
    if(c == '(' || c == ')' || c == '*' || c == '|' || c == '.')
        return true;
    return false;
}

string Regex::put_points(string regex)
{
    string with_parenth;
    for(auto c: regex)
    {
        if( !is_operator(c) )
            with_parenth += "(" + string(1,c) + ")";
        else
            with_parenth += string(1,c);
    }

    string ans;
    int sz_cad = with_parenth.size();
    with_parenth.push_back('#'); // Final de la cadena
    for(int i = 0; i<sz_cad; i++)
    {
        char current = with_parenth[i], in_front = with_parenth[i+1];
        if(in_front == '#') ans += current;
        else if( (current == ')' || current == '*') && in_front == '(' )
        {
            ans += current;
            ans += ".";
            ans += in_front;
            i++;
        }
        else
        {
            ans += current;
        } 
    }
    return ans;
}

int Regex::get_presc(char op)
{
    switch(op)
    {
        case ')':
            return 1;
        case '|':
            return 2;
        case '.':
            return 3;
        case '*':
            return 4;
    }
    return -1;
}

string Regex::get_postfix()
{
    stack<char> ops;
    regex = "(" + put_points(regex) + ")";

    string ans;
    for(auto c: regex)
    {
        if(c == '(')
        {
            ops.push(c);
        }
        else if(c == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                ans += ops.top();
                ops.pop();
            }
            if(!ops.empty()) ops.pop();
        }
        else if( is_operator(c) )
        {
            while(!ops.empty() && get_presc(c) <= get_presc(ops.top()))
            {
                ans += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
        else //Alfabeto
        {
            ans += c;
        }
    }
    return ans;
}



istream& operator>>(istream& is, Regex& Re) {
    is >> Re.regex;
    return is;
}
ostream& operator<<(ostream& os, const Regex& Re) {
    os << Re.regex;
    return os;
}
