%{
    #include <stdio.h>
    extern char yytext[];
    int yylex(void);

    void yyerror(char *error)
    {
        printf("Ha ocurrido un error: %s", error);
    }    
%}



/* COMENTARIOS */
%token START_COMMENT END_COMMENT LINE_COMMENT

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
%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
*/


/* %precedence '='*/
%left '+' '-'
%left '*' '/'
%left '%'
%precedence UN_POS
%precedence UN_NEG
%right '^'


%%

false_start:
    unary_expression
|   unary_operator
|   assignment_operator
|   primary_expression
;


primary_expression:
    ID
|   INTEGER_C
|   FLOAT_C
|   STRING_C
;


unary_expression:
    primary_expression
|    INC_OP unary_expression
|   DEC_OP unary_expression
;


unary_operator:
    '!'
|   '&'
|   '~'
|   '-'
;
/*
|   INC_OP
|   DEC_OP
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



%%


int main()
{
    yyparse();
	return 0;
}