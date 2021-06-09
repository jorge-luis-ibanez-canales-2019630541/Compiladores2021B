%{
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include "calc_symtable.h"

    int yylex(void);
    void yyerror(char *error)
    {
        printf("Ha ocurrido un error: %s", error);
    }
    
%}

%define api.value.type union
%token <double> NUM
%token <symrec*> VAR FUN
%nterm <double> expr;

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
|   expr '\n'               { printf("Resultado = %.10g\n", $1); }
;

expr:
    NUM                     { $$ = $1;  }
|   VAR                     { $$ = $1->value.var; }
|   VAR  '=' expr           { $$ = $3, $1->value.var = $3; }
|   FUN  '(' expr ')'       { $$ = ($1->value.fun($3));   }   
|   expr '+' expr           { $$ =  $1 + $3; }
|   expr '-' expr           { $$ =  $1 - $3; }
|   expr '*' expr           { $$ =  $1 * $3; }
|   expr '/' expr           { $$ =  $1 / $3; }
|   '-' expr  %prec NEG     { $$ =  -$2; }
|   expr '^' expr           { $$ =  pow($1, $3); }
|   '(' expr ')'            { $$ =  $2; }
;

%%

struct fun{
    char *name;
    func_t *fun;
};

struct fun init_funs[] = {
    { "sin", sin  },
    { "cos", cos  },
    { "tan", tan  },
    { "exp", exp  },
    { "ln",  log  },
    {0,0}
};

symrec *sym_table = NULL;

void init_table(void)
{
    for(int i = 0; init_funs[i].name; i++)
    {
        symrec *p = putsym(init_funs[i].name, FUN);
        p->value.fun = init_funs[i].fun;
    }
}


symrec *putsym(char const *name, int sym_type)
{
    symrec* new_node = (symrec *)malloc(sizeof(symrec));
    new_node->name = strdup(name);
    new_node->type = sym_type;
    new_node->value.var = 0;
    new_node->next = sym_table;
    sym_table = new_node;
    return sym_table;
}


symrec *getsym(char const *name)
{
    for(symrec* p = sym_table; p; p = p->next)
        if(strcmp( p->name, name ) == 0)
            return p;
    return NULL;
}




int main()
{
    init_table();
    yyparse();
    return 0;
}

