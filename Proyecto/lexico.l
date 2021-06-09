%{
    #include <stdio.h>
    #include "gramatica.tab.h"
%}

D     [0-9]
WS    [ \t\v\n\f]
EXP   [Ee][+-]?{D}+
ID    [a-zA-Z][a-zA-Z0-9]*

%%
 /* ---------  Key Words --------- */

 /* --- Comments --- */
"/*"            {return (START_COMMENT);}
"*/"            {return (END_COMMENT);}
"//".*          {return (LINE_COMMENT);}


 /* --- Data type --- */
"bool"          {return (BOOL);}
"char"          {return (CHAR);}
"int"           {return (INT);}
"long"          {return (LONG);}
"c_int"         {return (CINT);}
"string"        {return (STRING);}
"float"         {return (FLOAT);}
"double"        {return (DOUBLE);}
 /*"null"          {return NULL;}*/
"undefined"     {return (UNDEFINED);}
"void"          {return (VOID);}

 /* --- Control Structures ---  */
"for"           {return (FOR);}
 /*"in"            {return (FOR);}*/
"while"         {return (WHILE);}
"if"            {return (IF);}
"else"          {return (ELSE);}
"break"         {return (BREAK);}
"continue"      {return (CONTINUE);}
"return"        {return (RETURN);}

 /* --- Declaration --- */
"let"           {return (LET);}
"const"         {return (CONST);}
"def"           {return (DEF);}

 /* --- Operators --- */
"+"             {return ('+');}
"-"             {return ('-');}
 /*"**"            {//return ("**");}*/
"/"             {return ('/');}
"*"             {return ('*');}
"%"             {return ('%');}
"!"             {return ('!');}
"."             {return ('.');}
"="             {return ('=');}
"("             {return ('(');}
")"             {return (')');}
"|"             {return ('|');}
"&"             {return ('&');}
"~"             {return ('~');}
"^"             {return ('^');}
"?"             {return ('?');}

"+="            {return (ADD_ASSIGN);}
"-="            {return (SUB_ASSIGN);}
"**="           {return (POW_ASSIGN);} 
"*="            {return (MUL_ASSIGN);}
"/="            {return (DIV_ASSIGN);}
"%="            {return (MOD_ASSIGN);}
"&="            {return (AND_ASSIGN);}
"|="            {return (OR_ASSIGN);}
"^="            {return (XOR_ASSIGN);}
">>="           {return (RIGHT_ASSIGN);}
"<<="           {return (LEFT_ASSIGN);}

">>"            {return (RIGHT_OP);}
"<<"            {return (LEFT_OP);}
"++"            {return (INC_OP);}
"--"            {return (DEC_OP);}
"&&"            {return (AND_OP);}
"||"            {return (OR_OP);}
"=="            {return (EQ_OP);}
"!="            {return (NE_OP);}
"<"             {return (L_OP);}
">"             {return (G_OP);}
"<="            {return (LE_OP);}
">="            {return (GE_OP);}

 /* --- MISC --- */
"{"             {return ('{');}
"}"             {return ('}');}
"["             {return ('[');}
"]"             {return (']');}
";"             {return (';');}
":"             {return (':');}
","             {return (',');}
 /*"->"            {return (ARROW) //return ("->");} Para list -> list -> int*/
 /* "=>"            {return (DOUBLE_ARROW) //return ("=>");} Para lambdas */
"import"        {return (IMPORT);}
 /* "from"          {return (FROM);} */
"export"        {return (EXPORT);}
 /* "as"            {return (AS);}  */



 /* --- CONSTANTS --- */
-?{D}+{EXP}?      {return (INTEGER_C);}
                
{D}+"."{D}*       {return (FLOAT_C);}

(\"([^"\\\n])*\")+  {return (STRING_C);}





{ID}          {return (ID);} 

{WS}          { /*return (WHITE_SPACE);*/ }
.              {/*return (" ");*/}

%%

/*
int main(int argc, char **argv)
{
    ++argv, --argc;
    if( argc > 0 )
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;

    yylex();
}
*/

