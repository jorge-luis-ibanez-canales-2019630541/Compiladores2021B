%{
    #include "calc_symtable.h"
    #include "calculadora.tab.h"
    #include <stdlib.h>
%}


%%
[0-9]+                  { yylval.NUM = atof(yytext);  return NUM; }
[0-9]*"."[0-9]+         { yylval.NUM = atof(yytext);  return NUM; }
[+]                     { return '+'; }
[-]                     { return '-'; }
[*]                     { return '*'; }
[/]                     { return '/'; }
[\^]                    { return '^'; }
"="                     { return '='; }
"("                     { return '('; }
")"                     { return ')'; }
\n                      { return '\n'; }
[a-zA-Z_]+[a-zA-Z0-9_]* {
                            symrec *s = getsym(yytext);
                            
                            if(!s)
                                s = putsym(yytext, VAR);
                            if(s->type == VAR)
                                yylval.VAR = s;
                            else
                                yylval.FUN = s;
                            return s->type;
                        }
.
%%
