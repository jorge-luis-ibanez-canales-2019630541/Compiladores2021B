%{
    #include <stdio.h>
    extern char yytext[];
    int yylex(void);

    extern int column;
    yyerror(s)
    char *s;
    {
        fflush(stdout);
        printf("\n%*s\n%*s\n", column, "^", column, s);
    }


    void test(char *mensaje)
    {
        printf("%s", mensaje);
    }

%}



/* COMENTARIOS */
%token START_COMMENT END_COMMENT LINE_COMMENT
%token IN_FOR

/* TIPOS DE DATO */
%token BOOL CHAR INT LONG CINT STRING FLOAT DOUBLE UNDEFINED VOID

/* ESTRUCTURAS DE CONTROL */
%token FOR WHILE IF ELSE BREAK CONTINUE RETURN

/* DECLARACION */
%token LET CONST DEF

/* OPERADORES */
// +, -, **, /, %, ...

%token ADD_ASSIGN SUB_ASSIGN POW_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token AND_ASSIGN OR_ASSIGN XOR_ASSIGN RIGHT_ASSIGN LEFT_ASSIGN
%token POW

%token RIGHT_OP LEFT_OP INC_OP DEC_OP AND_OP OR_OP EQ_OP NE_OP L_OP
%token G_OP LE_OP GE_OP

/* OTROS */
/* {, }, [, ], ;, :, ... */

%token IMPORT EXPORT 


/* CONSTANTES */
%token INTEGER_C FLOAT_C STRING_C


%token ID 
/*%token WHITE_SPACE*/

/*
%precedence '='
%left '+' '-'
%left '*' '/'
%left '%'
%precedence UN_POS
%precedence UN_NEG
%right '^'
*/

//%start expression
%start god

%%




primary_expression: 
    ID            
|   INTEGER_C      
|   FLOAT_C
|   STRING_C
;


postfix_expression: 
    primary_expression 
|   postfix_expression '(' ')' /*Llamadas a funciones*/
|   postfix_expression '(' argument_expression_list ')' /*Con argumentos*/
|   postfix_expression '[' ']'
|   postfix_expression '.' ID
|   postfix_expression INC_OP
|   postfix_expression DEC_OP
;

argument_expression_list: 
    assignment_expression  
|   argument_expression_list ',' assignment_expression 
;


unary_expression:
    postfix_expression
|   INC_OP unary_expression
|   DEC_OP unary_expression
;


/*
unary_operator:
    '!'
|   '&'
|   '~'
|   '-'
;

|   INC_OP
|   DEC_OP
*/

power_expression:
    unary_expression
|   unary_expression POW power_expression
;


multiplicative_expression:
    power_expression
|   multiplicative_expression '*' power_expression
|   multiplicative_expression '/' power_expression
|   multiplicative_expression '%' power_expression
;

additive_expression: 
    multiplicative_expression
|   additive_expression '+' multiplicative_expression
|   additive_expression '-' multiplicative_expression
;

shift_expression:
    additive_expression
|   shift_expression LEFT_OP additive_expression
|   shift_expression RIGHT_OP additive_expression
;

relational_expression:
    shift_expression
|   relational_expression '<' shift_expression
|   relational_expression '>' shift_expression
|   relational_expression LE_OP shift_expression
|   relational_expression GE_OP shift_expression
;

equality_expression:
    relational_expression
|   equality_expression EQ_OP relational_expression
|   equality_expression NE_OP relational_expression
;

and_expression:
    equality_expression
|   and_expression '&' equality_expression
;

exclusive_or_expression:
    and_expression
|   exclusive_or_expression '^' and_expression
;

inclusive_or_expression:
    exclusive_or_expression
|   inclusive_or_expression '|' exclusive_or_expression
;

logical_and_expression:
    inclusive_or_expression
|   logical_and_expression AND_OP inclusive_or_expression
;

logical_or_expression:
    logical_and_expression
|   logical_or_expression OR_OP logical_and_expression
;

conditional_expression:
    logical_or_expression
/*|   logical_or_expression '?' expression ':' conditional_expression*/
;

assignment_expression:
    conditional_expression   
|   unary_expression assignment_operator assignment_expression  
;
/*  arreglo[5] *= (3 + 4^5)*(1&2) || 1  ====  assignment_expression
    (funcion(1,2,3))  ==== (assingment_expression)
*/


assignment_operator:
    '='
|   POW_ASSIGN
|   MUL_ASSIGN
|   DIV_ASSIGN
|   MOD_ASSIGN
|   ADD_ASSIGN
|   SUB_ASSIGN
|   LEFT_ASSIGN
|   RIGHT_ASSIGN
|   AND_ASSIGN
|   XOR_ASSIGN
|   OR_ASSIGN
;

/*
constant_expression:
    conditional_expression
;
*/

/* Lista de assignment_expression 
   Lista de valores y separados por coma
*/
expression:
    assignment_expression               
|   expression ',' assignment_expression 
;


declaration:
    type_declaration ';'
|   type_declaration init_declaration_list ';'    
;


init_declaration_list:
    init_declaration
|   init_declaration_list ','  init_declaration
;

init_declaration:
    identifier_list ':' data_type 
|   identifier_list ':' data_type '=' initializer_list 
;


type_declaration:
    LET 
|   CONST
;


/*
value_list:
    assignment_expression
|   value_list ',' assignment_expression
;
*/


/* ------------------------------- */



/*----------DECLARATION-----------*/

/*
declarator:
    ID     
|   '(' declarator ')' //no se muy bien para que es
//| declarator '[' constant_expression ']' // para arreglos
//| declarator '[' ']'
|   declarator '(' parameter_list ')' //para funciones
//|   declarator '(' identifier_list ')' No entiendo muy bien este
|   declarator '(' ')' //Para funciones
;
*/


data_type:
    BOOL
|   CHAR
|   INT
|   LONG
|   CINT
|   STRING
|   FLOAT   
|   DOUBLE
|   UNDEFINED
|   VOID
;


parameters_function:
    '(' parameter_list ')'  
|   '(' ')'                 
;
parameter_list: 
    parameter_declaration   
|   parameter_list ',' parameter_declaration 
;

parameter_declaration:
    identifier_list ':' data_type
//|   data_type
;

identifier_list:
    ID
|   identifier_list ',' ID
;

initializer:
    assignment_expression
;

initializer_list:
    initializer
|   initializer_list ',' initializer //valores de inicializacion separados por coma
;


/*-----------------------------*/


/*---------STATEMENTS---------*/
statement:
    composed_statement
|   expression_statement
|   conditional_statement
|   special_iteration_statement
|   iteration_statement
|   jump_statement
;


composed_statement:
    '{' '}'
|   '{' block_item_list '}'
;

block_item_list:
    block_item
|   block_item_list block_item
;

block_item:
    declaration
|   statement
;

declaration_list:
    declaration
|   declaration_list declaration 
;

expression_statement: 
    ';'
|   expression ';'
;

conditional_statement:
    IF '(' expression ')' statement
|   IF '(' expression ')' statement ELSE statement
;

special_iteration_statement:
    FOR '(' ID IN_FOR ID ')' statement
;


iteration_statement:
    WHILE '(' expression ')' statement 

|   FOR '(' expression_statement expression_statement ')' statement
|   FOR '(' expression_statement expression_statement expression ')' statement
|   FOR '(' declaration_list expression_statement expression ')' statement
;

jump_statement:
    CONTINUE ';'
|   BREAK ';'
|   RETURN ';'
|   RETURN expression ';'
;


/* ------------------------------ */

god:
    external_declaration
|   god external_declaration
;


external_declaration:
    function_definition 
|   declaration     
;


function_definition: 
    DEF ID ':' data_type parameters_function composed_statement
;
%%


int main()
{
    yyparse();

    

	return 0;
}