
%{
    #include "calculadora.tab.h"
    #include <stdlib.h>
%}


%%

[0-9]+          { yylval = atof(yytext);  return NUM;}
[0-9]*"."[0-9]+ { yylval = atof(yytext);  return NUM;}
[+]             {return '+';}
[-]             {return '-';}
[*]             {return '*';}
[\^]            {return '^';}
\n              {return '\n';}
.

%%
