%{
    #include <stdio.h>
    #include "gramatica.tab.h"
%}

D     [0-9]
WS    [ \t\v\n\f]
EXP   [Ee][+-]?{D}+
ID    [a-zA-Z_][a-zA-Z0-9_]*

%%
 /* ---------  Key Words --------- */

 /* --- Comments --- */
"/*"            {count();return (START_COMMENT);}
"*/"            {count();return (END_COMMENT);}
"//".*          {count();return (LINE_COMMENT);}


 /* --- Data type --- */
"bool"          {count();return (BOOL);}
"char"          {count();return (CHAR);}
"int"           {count();return (INT);}
"long"          {count();return (LONG);}
"c_int"         {count();return (CINT);}
"string"        {count();return (STRING);}
"float"         {count();return (FLOAT);}
"double"        {count();return (DOUBLE);}
 /*"null"          {return NULL;}*/
"undefined"     {count();return (UNDEFINED);}
"void"          {count();return (VOID);}

 /* --- Control Structures ---  */
"for"           {count();return (FOR);}
"in"            {count();return (IN_FOR);}
"while"         {count();return (WHILE);}
"if"            {count();return (IF);}
"else"          {count();return (ELSE);}
"break"         {count();return (BREAK);}
"continue"      {count();return (CONTINUE);}
"return"        {count();return (RETURN);}

 /* --- Declaration --- */
"let"           {count();return (LET);}
"const"         {count();return (CONST);}
"def"           {count();return (DEF);}

 /* --- Operators --- */
"+"             {count();return ('+');}
"-"             {count();return ('-');}
 /*"**"            {//return ("**");}*/
"/"             {count();return ('/');}
"*"             {count();return ('*');}
"%"             {count();return ('%');}
"!"             {count();return ('!');}
"."             {count();return ('.');}
"="             {count();return ('=');}
"("             {count();return ('(');}
")"             {count();return (')');}
"|"             {count();return ('|');}
"&"             {count();return ('&');}
"~"             {count();return ('~');}
"^"             {count();return ('^');}
"**"            {count();return (POW);}
"?"             {count();return ('?');}

"+="            {count();return (ADD_ASSIGN);}
"-="            {count();return (SUB_ASSIGN);}
"**="           {count();return (POW_ASSIGN);} 
"*="            {count();return (MUL_ASSIGN);}
"/="            {count();return (DIV_ASSIGN);}
"%="            {count();return (MOD_ASSIGN);}
"&="            {count();return (AND_ASSIGN);}
"|="            {count();return (OR_ASSIGN);}
"^="            {count();return (XOR_ASSIGN);}
">>="           {count();return (RIGHT_ASSIGN);}
"<<="           {count();return (LEFT_ASSIGN);}

">>"            {count();return (RIGHT_OP);}
"<<"            {count();return (LEFT_OP);}
"++"            {count();return (INC_OP);}
"--"            {count();return (DEC_OP);}
"&&"            {count();return (AND_OP);}
"||"            {count();return (OR_OP);}
"=="            {count();return (EQ_OP);}
"!="            {count();return (NE_OP);}
"<"             {count();return ('<');}
">"             {count();return ('>');}
"<="            {count();return (LE_OP);}
">="            {count();return (GE_OP);}

 /* --- MISC --- */
"{"             {count();return ('{');}
"}"             {count();return ('}');}
"["             {count();return ('[');}
"]"             {count();return (']');}
";"             {count();return (';');}
":"             {count();return (':');}
","             {count();return (',');}
 /*"->"            {return (ARROW) //return ("->");} Para list -> list -> int*/
 /* "=>"            {return (DOUBLE_ARROW) //return ("=>");} Para lambdas */
"import"        {count();return (IMPORT);}
 /* "from"          {return (FROM);} */
"export"        {count();return (EXPORT);}
 /* "as"            {return (AS);}  */



 /* --- CONSTANTS --- */
{D}+{EXP}?      {count();return (INTEGER_C);}
                
{D}+"."{D}*       {count();return (FLOAT_C);}

(\"([^"\\\n])*\")+  {count();return (STRING_C);}





{ID}          {count();return (ID);} 

{WS}          { count();/*return (WHITE_SPACE);*/ }
.              {/*return (" ");*/}

%%

int column = 0;
void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


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

