%{
    #include <stdio.h>
%}

D     [0-9]
WS    [ \t\v\n\f]
EXP   [Ee][+-]?{D}+
ID    [a-zA-Z][a-zA-Z0-9]*

%%
 /* ---------  Key Words --------- */

 /* --- Comments --- */
"/*"            {printf("<START_COMMENT>");}
"*/"            {printf("<END_COMMENT>");}
"//".*          {printf("<LINE_COMMENT>");}


 /* --- Data type --- */
"bool"          {printf("<BOOL>");}
"char"          {printf("<CHAR>");}
"int"           {printf("<INT>");}
"long"          {printf("<LONG>");}
"c_int"         {printf("<CINT>");}
"string"        {printf("<STRING>");}
"float"         {printf("<FLOAT>");}
"double"        {printf("<DOUBLE>");}
"null"          {printf("<NULL>");}
"undefined"     {printf("<UNDEFINED>");}
"void"          {printf("<VOID>");}

 /* --- Control Structures ---  */
"for"           {printf("<FOR>");}
"in"            {printf("<FOR>");}
"while"         {printf("<WHILE>");}
"if"            {printf("<IF>");}
"else"          {printf("<ELSE>");}
"break"         {printf("<BREAK>");}
"continue"      {printf("<CONTINUE>");}
"return"        {printf("<RETURN>");}

 /* --- Declaration --- */
"let"           {printf("<LET>");}
"const"         {printf("<LET>");}
"def"           {printf("<DEF>");}

 /* --- Operators --- */
"+"             {printf("+");}
"-"             {printf("-");}
"**"            {printf("**");}
"/"             {printf("/");}
"*"             {printf("*");}
"%"             {printf("%%");}
"!"             {printf("!");}
"."             {printf(".");}
"="             {printf("=");}
"("             {printf("(");}
")"             {printf(")");}
"|"             {printf("|");}
"&"             {printf("&");}
"~"             {printf("~");}
"^"             {printf("^");}
"?"             {printf("?");}

"+="            {printf("<ADD_ASSIGN>");}
"-="            {printf("<SUB_ASSIGN>");}
"**="           {printf("<POW_ASSIGN>");} 
"*="            {printf("<MUL_ASSIGN>");}
"/="            {printf("<DIV_ASSIGN>");}
"%="            {printf("<MOD_ASSIGN>");}
"&="            {printf("<AND_ASSIGN>");}
"|="            {printf("<OR_ASSIGN>");}
"^="            {printf("<XOR_ASSIGN>");}
">>="           {printf("<RIGHT_ASSIGN>");}
"<<="           {printf("<LEFT_ASSIGN>");}

">>"            {printf("<RIGHT_OP>");}
"<<"            {printf("<LEFT_OP>");}
"++"            {printf("<INC_OP>");}
"--"            {printf("<DEC_OP>");}
"&&"            {printf("<AND_OP>");}
"||"            {printf("<OR_OP>");}
"=="            {printf("<EQ_OP>");}
"!="            {printf("<NE_OP>");}
"<"             {printf("<L_OP>");}
">"             {printf("<G_OP>");}
"<="            {printf("<LE_OP>");}
">="            {printf("<GE_OP>");}

 /* --- MISC --- */
"{"             {printf("{");}
"}"             {printf("}");}
"["             {printf("[");}
"]"             {printf("]");}
";"             {printf(";");}
":"             {printf(":");}
","             {printf(",");}
"->"            {printf("->");} /*Para list -> list -> int*/
"=>"            {printf("=>");} /*Para lambdas*/
"import"        {printf("<IMPORT>");}
 /* "from"          {printf("<FROM>");} */
"export"        {printf("<EXPORT>");}
"as"            {printf("<AS>");}

 /* --- CONSTANTS --- */
-?{D}+{EXP}?      {printf("<INTEGER_C>");}
                
{D}+"."{D}*       {printf("<FLOAT_C>");}

(\"([^"\\\n])*\")+  {printf("<STRING_C>");}





{ID}          {printf("<ID>");} 

 /* {WS}+          {printf("<WHITE_SPACE>");} */
.              {printf(" ");}

%%

int main(int argc, char **argv)
{
    ++argv, --argc;
    if( argc > 0 )
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;

    yylex();
}


