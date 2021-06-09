%{
    #include<stdio.h>
    #include<math.h>

    int yylex(void);

    void yyerror(char const *error)    
    {
        printf("Tuvimos un pequenho error papi: %s", error);
    }


%}


%define api.value.type {double}
%token  NUM;
%nterm  expr;

%%
input:  %empty
|       input line
;

line:
    '\n'
|   expr '\n'      { printf("Resultado: %f\n", $1); }
;


expr:
    NUM
|   expr expr '+'   { $$ = $1 + $2; }
|   expr expr '*'   { $$ = $1 * $2; }
|   expr expr '^'   { $$ = pow($1, $2); }
|   expr expr '-'   { $$ = $1 - $2; }
;


%%

int main()
{
    yyparse();

    return 0;
}


