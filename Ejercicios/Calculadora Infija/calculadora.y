%{
    #include <stdio.h>
    #include <math.h>

    int yylex(void);
    void yyerror(char *error)
    {
        printf("Ha ocurrido un error: %s", error);
    }
    
%}

%define api.value.type union
%token <double> NUM
%nterm <double> exp;


%precedence '='
%left '+' '-'
%left '*' '/'
%precedence NEG
%right '^'

%%

input:
    %empty
|   input line
;

line:
    '\n'
|   expr '\n'               { printf("Resultado = %d\n", $1); }
;

expr:
    NUM          
|   VAR
|   VAR  '=' expr
|   FUN  '(' expr ')'          
|   expr '+' expr           { $$ =  $1 + $3; }
|   expr '-' expr           { $$ =  $1 - $3; }
|   expr '*' expr           { $$ =  $1 * $3; }
|   expr '/' expr           { $$ =  $1 / $3; }
|   '-' expr  %prec NEG     { $$ =  -$2; }
|   expr '^' expr           { $$ =  pow($1, $3); }
|   '(' expr ')'            { $$ =  $2; }
;

%%

int main()
{
    yyparse();
    return 0;
}

