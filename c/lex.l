%{
    #include "tree.h"
    #include "check.h"
    #include "string.h"
    #include "syntax.tab.h"
    static error_type parser_error = NO_ERROR;
    int yycolno = 1;
    #define YY_USER_ACTION \
        yylloc.first_line = yylineno; \
        yylloc.first_column = yycolno; \
        yylloc.last_line = yylineno; \
        yylloc.last_column = yycolno + yyleng - 1; \
        yycolno += yyleng;
%}

%option noyywrap
%option yylineno
w [_a-zA-Z0-9]
d [0-9]
D16 [0-9a-fA-F]
SingleLineComment [/][/].*
MultiLineComment [/][*]
Int32 0|[1-9]{d}*
Int32_64 0[xX](0|[1-9a-fA-F]{D16}*)
Id [_A-Za-z]{w}*
Float {d}+[.]{d}+
Char '[^']'|'\\[xX](0|[1-9a-fA-F]{D16}{0,1})'
WrongId {d}+[_A-Za-z]{w}*
WrongInt32 (0{d}+)|(0[xX](0{D16}+))|(0[xX]{D16}*[G-Zg-z]*{D16}*)
WrongChar '\\[xX]((00)|({D16}*[^0-9a-fA-F]*{D16}*)|({D16}{3,}))'
%%

int {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = TYPE;
    yylval.type_node->val = "int";
    return tTYPE;
}

float {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->val = "float";
    yylval.type_node->word_type = TYPE;
    return tTYPE;
}
char {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->val = "char";
    yylval.type_node->word_type = TYPE;
    return tTYPE;
}
struct {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = STRUCT;
    return tSTRUCT;
}
if { 
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = IF;
    return tIF;
}
else {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = ELSE;
    return tELSE;
}
while { 
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = WHILE;
    return tWHILE;
}
return { 
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = RETURN;
    return tRETURN;
}
for {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = FOR;
    return tFOR;
}
"." { 
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = DOT;
    return tDOT;
}
";" { 
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = SEMI;
    return tSEMI;
}
"," {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = COMMA;
    return tCOMMA;
}
"=" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = ASSIGN;
    return tASSIGN;
}
"<=" {
     yylval.type_node = malloc(sizeof(node));
     yylval.type_node->word_type = LE;
     return tLE;
 }
"<" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = LT;
    return tLT;
}
">=" {
   yylval.type_node = malloc(sizeof(node));
   yylval.type_node->word_type = GE;
   return tGE;
     }
">" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = GT;
    return tGT;
}
"!=" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = NE;
    return tNE;
}
"==" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = EQ;
    return tEQ;
}
"+" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = PLUS;
    return tPLUS;
}
"-" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = MINUS;
    return tMINUS;
}
"*" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = MUL;
    return tMUL;
}
"/" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = DIV;
    return tDIV;
}
"++" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = D_PLUS;
    return tD_PLUS;
}
"--" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = D_MINUS;
    return tD_MINUS;
}
"+=" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = PLUS_EQ;
    return tPLUS_EQ;
}
"-=" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = MINUS_EQ;
    return tMINUS_EQ;
}
"*=" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = MUL_EQ;
    return tMUL_EQ;
}
"/=" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = DIV_EQ;
    return tDIV_EQ;
}
"&&" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = AND;
     return tAND;
}
"||" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = OR;
     return tOR;
}
"!" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = NOT;
     return tNOT;
}
"(" { 
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = LP;
    return tLP;
}
")" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = RP;
     return tRP;
}
"[" { 
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = LB;
    return tLB;
}
"]" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = RB;
     return tRB;
}

"{" {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = LC;
     return tLC;
}
"}" { 
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = RC;
    return tRC;
}
{Int32} {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = INT;
    int val = (int) strtol(yytext, NULL, 10);
    int* save= malloc(sizeof(int));
    *save = val;
    yylval.type_node->val = save;
    return tINT;
}
{Int32_64} {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = INT;
    int val = (int) strtol(yytext, NULL, 16);
    int* save= malloc(sizeof(int));
    *save = val;
    yylval.type_node->val = save;
    return tINT;
}
{Float} {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = FLOAT;
    float val = (float) strtof(yytext,NULL);
    float* save= malloc(sizeof(float));
    *save = val;
    yylval.type_node->val = save;
    return tFLOAT;
}
{Char} {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = CHAR;
    char* val = malloc(sizeof(char)*strlen(yytext));
    strcpy(val, yytext);
    yylval.type_node->val = val;
    return tCHAR;
}
{Id} {
    yylval.type_node = malloc(sizeof(node));
    yylval.type_node->word_type = ID;
    char* val = malloc(sizeof(char)*strlen(yytext));
    strcpy(val, yytext);
    yylval.type_node->val = val;
    return tID;
}



{WrongInt32} {
    printf("Error type A at Line %d: wrong int : %s\n",
        yylineno, yytext);
    parser_error = WRONG_INT;
    return tINT;
}
{WrongChar} {
    printf("Error type A at Line %d: wrong char : %s\n",
        yylineno, yytext);
    parser_error = WRONG_CHAR;
    return tCHAR;
}
{WrongId} {
    printf("Error type A at Line %d: wrong id : %s\n",
        yylineno, yytext);
    parser_error = WRONG_ID;
    return tID;
}

{SingleLineComment} {}
{MultiLineComment} {
    int c;
    while(1){
            c = input();
            while( c != '*' && c != 0)
                c = input();
            if ( c == '*' ){
                while ( (c = input()) == '*' );
                    if ( c == '/')
                        break;
            }
            if ( c == 0 ){
                printf("Error type A at Line %d: Unterminated /* comment \n",yylineno);
                parser_error = WRONG_COMMENT;
                break;
            }
        }
}


\n { yycolno = 1; }
[ \t\r]+ {}
. {
    printf("Error type A at Line %d: Unknown characters ’%s’ \n",yylineno, yytext);
    parser_error = UNKNOWN_WORD;
    return INVALID_TOKEN;
 }

%%