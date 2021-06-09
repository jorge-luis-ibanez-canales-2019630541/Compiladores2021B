#ifndef _REGEX_
#define _REGEX_

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Regex{
    private:
        string regex;

    public:
        Regex() {}
        Regex(string _regex): regex(_regex) {}

        string get_regex();

        void set_regex(string regex);

        bool is_operator(char c);
        string put_points(string regex);
        int get_presc(char op);
        string get_postfix();


        friend istream& operator>>(istream&, Regex&);
        friend ostream& operator<<(ostream&, const Regex&);
};


#endif