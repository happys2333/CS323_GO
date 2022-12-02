//
// Created by happys on 22-10-16.
//

#ifndef EASYCOMPILER_TREE_H
#define EASYCOMPILER_TREE_H
#define BOOL int
#define TRUE 1
#define FALSE 0
#include "./util/linked_list.h"
typedef enum wordType
{
    ID,
    TYPE,
    INT,
    FLOAT,
    CHAR,
    NTERM,
    STRUCT,
    IF,
    ELSE,
    WHILE,
    RETURN,
    FOR,
    DOT,
    SEMI,
    COMMA,
    ASSIGN,
    LE,
    LT,
    GE,
    GT,
    NE,
    EQ,
    PLUS,
    MINUS,
    MUL,
    DIV,
    D_PLUS,
    D_MINUS,
    PLUS_EQ,
    MINUS_EQ,
    MUL_EQ,
    DIV_EQ,
    AND,
    OR,
    NOT,
    LP,
    RP,
    LB,
    RB,
    LC,
    RC,
    UNKNOWN_TYPE_OF_WORD
} word_types;
typedef struct Node node;
struct Node{
    word_types word_type;
    int line;
    void* val;
    linked_list* list;
    node* per;
    int lval_or_rval;
    BOOL empty;
};
void add_child_node(node* ,int ,...);
void print_tree(node*, int);

#endif //EASYCOMPILER_TREE_H
