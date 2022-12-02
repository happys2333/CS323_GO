%{
    #include"lex.yy.c"
    #include "tree.h"
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    // int yydebug=1;
    void yyerror(const char*);
    node* root;
%}
%union {
    node* type_node;
}

%token<type_node> tCHAR tINT tFLOAT tID tTYPE tSTRUCT 
%token<type_node> tWHILE tRETURN tIF tELSE tFOR
%token<type_node> tLC tRC tLB tRB tLP tRP tDOT tSEMI tCOMMA 
%token<type_node> tASSIGN tPLUS tMINUS tMUL tDIV tD_PLUS tD_MINUS tPLUS_EQ tMINUS_EQ tMUL_EQ tDIV_EQ
%token<type_node> tAND tOR tNOT 
%token<type_node> tNE tEQ tLT tLE tGT tGE 
%token<type_node> INVALID_TOKEN

%right tASSIGN
%left tOR
%left tAND
%left tNE tEQ tLT tLE tGT tGE 
%left tMINUS tPLUS 
%left tMUL tDIV
%left tD_PLUS tD_MINUS tPLUS_EQ tMINUS_EQ tMUL_EQ tDIV_EQ

%right tNOT
%left tDOT tLP tRP tLB tRB 
%nonassoc tLOWERELSE
%nonassoc tELSE
%left INVALID_TOKEN 
%type<type_node> Program 
%type<type_node> ExtDefList ExtDef 
%type<type_node> ExtDecList
%type<type_node> Specifier StructSpecifier
%type<type_node> FunDec VarDec ParamDec
%type<type_node> VarList
%type<type_node> CompSt 
%type<type_node> StmtList Stmt
%type<type_node> DefList Def 
%type<type_node> DecList Dec
%type<type_node> Exp 
%type<type_node> Args

%%
Program :
    ExtDefList{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Program";
        add_child_node($$,1,$1);
        root=$$;
    }
    ;

ExtDefList :
    ExtDef ExtDefList{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="ExtDefList";
        add_child_node($$,2,$1,$2);
    }
    | %empty{
        $$=malloc(sizeof(node));
        $$->empty=TRUE;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="ExtDefList";
    }
    ;
ExtDef : 
    Specifier ExtDecList tSEMI{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="ExtDef";
        add_child_node($$, 3, $1, $2, $3);
    }
    | Specifier tSEMI{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="ExtDef";
        add_child_node($$, 2, $1, $2);
    }
    | Specifier error{
        printf("Missing A Semicolon ';'.\n");
    }
    | Specifier FunDec CompSt{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="ExtDef";
        add_child_node($$, 3, $1, $2, $3);
    }
    | error FunDec CompSt{
        printf("Missing specifier.\n");
    }
    ;

ExtDecList : 
    VarDec{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="ExtDecList";
        add_child_node($$, 1, $1);
    }
    | VarDec tCOMMA ExtDecList{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="ExtDecList";
        add_child_node($$, 3, $1, $2, $3);
    }
    ;

Specifier : 
    tTYPE{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->val="Specifier";
        $$->lval_or_rval=1;
        add_child_node($$, 1, $1);
    }
    | StructSpecifier{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->val="Specifier";
        $$->lval_or_rval=1;
        add_child_node($$, 1, $1);
    }
    ;

StructSpecifier : 
    tSTRUCT tID tLC DefList tRC{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="StructSpecifier";
        add_child_node($$, 5, $1, $2, $3, $4, $5);
    }
    | tSTRUCT tID{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="StructSpecifier";
        add_child_node($$, 2, $1, $2);
    }
    | tSTRUCT error tLC DefList tRC{
        printf("StructSpecifier has A Wrong ID or No ID\n");
    }

    ;

FunDec : 
    tID tLP tRP{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="FunDec";
        add_child_node($$, 3, $1, $2, $3);
    }
    | tID tLP VarList tRP{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="FunDec";
        add_child_node($$, 4, $1, $2, $3, $4);
    }

    | tID tLP VarList error{
        printf("Missing closing parenthesis: ')'\n");
    }
    | tID tLP error{
        printf("Missing closing parenthesis: ')'\n");
    }
    ;

VarDec : 
    VarDec tLB tINT tRB{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="VarDec";
        add_child_node($$, 4, $1, $2, $3, $4);
    }
    | tID{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="VarDec";
        add_child_node($$, 1, $1);
    }
    | VarDec tLB tINT error{
        printf("Missing closing bracket: ']'\n");
    }
    ;

VarList : 
    ParamDec tCOMMA VarList{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="VarList";
        add_child_node($$, 3, $1, $2, $3);
    }
    | ParamDec{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="VarList";
        add_child_node($$, 1, $1);
    }
    ;

ParamDec : 
    Specifier VarDec{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="ParamDec";
        add_child_node($$, 2, $1,$2);
    }
    | Specifier error{
        printf("Missing an ID\n");
    }
    ;

CompSt : 
    tLC DefList StmtList tRC{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="CompSt";
        add_child_node($$, 4, $1, $2, $3,$4);
    }
    | tLC DefList StmtList error{
        printf("Missing RC '}'\n");
    }
    ;

StmtList : 
    Stmt StmtList{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="StmtList";
        add_child_node($$, 2, $1, $2);
    }
    | %empty{
        $$=malloc(sizeof(node));
        $$->empty=TRUE;
        $$->line = @$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="StmtList";
    }
    ;

Stmt : 
    Exp tSEMI{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 2, $1, $2);
    }
    | CompSt{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 1, $1);
    }
    | tRETURN Exp tSEMI{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 3, $1, $2,$3);
    }
    | tRETURN Exp error{
        printf("Missing A Semicolon ';'.\n");
    }

    | tIF tLP Exp tRP Stmt %prec tLOWERELSE{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 5, $1, $2, $3, $4, $5);
    }
    | tIF tLP Exp tRP Stmt tELSE Stmt{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 7, $1, $2, $3, $4, $5,$6,$7);
    }
    | tIF tLP Exp error{
        printf("Missing closing parenthesis ')'\n");
    }
    | tWHILE tLP Exp tRP Stmt{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 5, $1, $2, $3, $4, $5);
    }
    | tWHILE tLP Exp error{
        printf("Missing closing parenthesis ')'\n");
    }
    | tFOR tLP tSEMI Exp tSEMI Args tRP Stmt{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 8, $1, $2, $3, $4, $5,$6,$7,$8);
    }
    | tFOR tLP DecList tSEMI Exp tSEMI Args tRP Stmt{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 9, $1, $2, $3, $4, $5,$6,$7,$8,$9);
    }
    | tFOR tLP Specifier DecList tSEMI Exp tSEMI Args tRP Stmt{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Stmt";
        add_child_node($$, 10, $1, $2, $3, $4, $5,$6,$7,$8,$9,$10);
    }
    ;

DefList : 
    Def DefList{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="DefList";
        add_child_node($$, 2, $1, $2);
    }
    | %empty{
        $$=malloc(sizeof(node));
        $$->empty=TRUE;
        $$->line = @$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="DefList";
    }
    ;

Def : 
    Specifier DecList tSEMI{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Def";
        add_child_node($$, 3, $1, $2,$3);
    }
    | Specifier error tSEMI{
        printf("Missing A Declaration \n");
    }
    | Specifier DecList error{
        printf("Missing A Semicolon ';'\n");
    }
    ;

DecList : 
    Dec{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="DecList";
        add_child_node($$, 1, $1);
    }
    | Dec tCOMMA DecList{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="DecList";
        add_child_node($$, 3, $1, $2,$3);
    }
    ;

Dec : 
    VarDec{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Dec";
        add_child_node($$, 1, $1);  
    }
    | VarDec tASSIGN Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Dec";
        add_child_node($$, 3, $1,$2,$3);
    }
    
    ;

Exp : 
    Exp tASSIGN Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3); 
    }
    | Exp tASSIGN error{
      printf("Missing an Expression, '=' need a right Expression\n");       
    }

    | Exp tD_PLUS{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 2, $1,$2); 
    }
    | Exp tD_MINUS{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 2, $1,$2); 
    }
    | Exp tPLUS_EQ Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3); 
    }
    | Exp tPLUS_EQ error{
      printf("Missing an Expression, '+=' need a right Expression\n");       
    }

    | Exp tMINUS_EQ Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3); 
    }
    | Exp tMINUS_EQ error{
      printf("Missing an Expression, '-=' need a right Expression\n");       
    }

    | Exp tMUL_EQ Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3); 
    }
    | Exp tMUL_EQ error{
      printf("Missing an Expression, '*=' need a right Expression\n");       
    }

    | Exp tDIV_EQ Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3); 
    }
    | Exp tDIV_EQ error{
      printf("Missing an Expression, '/=' need a right Expression\n");       
    }


    | Exp tAND Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);  
    }
    | Exp tAND error{
      printf("Missing an Expression, '&&' need a right Expression\n");       
    }

    | Exp tOR Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3); 
    }
    | Exp tOR error{
      printf("Missing an Expression, '||' need a right Expression\n");       
    }

    | Exp tLT Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);        
    }
    | Exp tLT error{
      printf("Missing an Expression, '<' need a right Expression\n");       
    }

    | Exp tLE Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3); 
    }
    | Exp tLE error{
      printf("Missing an Expression, '<=' need a right Expression\n");       
    }

    | Exp tGT Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);
    }
    | Exp tGT error{
      printf("Missing an Expression, '>' need a right Expression\n");       
    }

    | Exp tGE Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);
    }
    | Exp tGE error{
      printf("Missing an Expression, '>=' need a right Expression\n");       
    }

    | Exp tNE Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);
    }
    | Exp tNE error{
      printf("Missing an Expression, '!=' need a right Expression\n");       
    }

    | Exp tEQ Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);
    }
    | Exp tEQ error{
      printf("Missing an Expression, '==' need a right Expression\n");       
    }

    | Exp tPLUS Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);
    }
    | Exp tPLUS error{
      printf("Missing an Expression, '+' need a right Expression\n");       
    }

    | Exp tMINUS Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);   
    }
    | Exp tMINUS error{
      printf("Missing an Expression, '-' need a right Expression\n");       
    }

    | Exp tMUL Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);
    }
    | Exp tMUL error{
      printf("Missing an Expression, '*' need a right Expression\n");       
    }

    | Exp tDIV Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);      
    }
    | Exp tDIV error{
      printf("Missing an Expression, '/' need a right Expression\n");       
    }


    | tLP Exp tRP{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);  
    }
    | tLP Exp error{
        printf("Missing closing parenthesis: ')'\n");
    }
    | tMINUS Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 2, $1,$2);
    }
    | tNOT Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 2, $1,$2);
    }
    | tID tLP Args tRP{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 4, $1,$2,$3,$4);        
    }
    | tID tLP tRP{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);
    }
    | tID tLP Args error{
        printf("Missing closing parenthesis: ')'\n");
    }
    | tID tLP error{
        printf("Missing closing parenthesis: ')'\n");
    }
    | Exp tLB Exp tRB{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=0;
        $$->val="Exp";
        add_child_node($$, 4, $1,$2,$3,$4);
    }
    | Exp tLB Exp error{
        printf("Missing closing bracket ']'\n");
    }
    | Exp tDOT tID{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=0;
        $$->val="Exp";
        add_child_node($$, 3, $1,$2,$3);        
    }
    | tID{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=0;
        $$->val="Exp";
        add_child_node($$, 1, $1);        
    }
    | tINT{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 1, $1);        
    }
    | tFLOAT{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 1, $1);        
    }
    | tCHAR{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Exp";
        add_child_node($$, 1, $1);
    }
    | INVALID_TOKEN
    | Exp INVALID_TOKEN
    | INVALID_TOKEN Exp
    | Exp INVALID_TOKEN Exp 
    ;

Args :
    Exp tCOMMA Args{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Args";
        add_child_node($$, 3, $1,$2,$3);
    }
    | Exp{
        $$=malloc(sizeof(node));
        $$->line=@$.first_line;
        $$->word_type=NTERM;
        $$->lval_or_rval=1;
        $$->val="Args";
        add_child_node($$, 1, $1);
    }
    ;

%%

void yyerror(const char* s) {
    parser_error=SYNTAX_ERROR;
    printf("Error type B at Line %d: ",yylloc.first_line-1); 
}



