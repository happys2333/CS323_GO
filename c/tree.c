//
// Created by happys on 22-10-16.
//

#include "tree.h"
#include <stdio.h>
#include <stdarg.h>
#include "./util/linked_list.c"

void print_node(node* n){
    switch (n->word_type) {
        case ID:
            printf("ID: %s\n", (char*) n->val);
            break;
        case TYPE:
            printf("TYPE: %s\n", (char*) n->val);
            break;
        case INT:
            printf("INT: %d\n", *(int *) n->val);
            break;
        case FLOAT:
            printf("FLOAT: %f\n", *(float *) n->val);
            break;
        case CHAR:
            printf("CHAR: %s\n", (char *) n->val);
            break;
        case NTERM:
            printf("%s (%d)\n", (char *) n->val,n->line);
            break;
        case STRUCT:
            printf("STRUCT\n");
            break;
        case IF:
            printf("IF\n");
            break;
        case WHILE:
            printf("WHILE\n");
            break;
        case FOR:
            printf("FOR\n");
            break;
        case ELSE:
            printf("ELSE\n");
            break;
        case RETURN:
            printf("RETURN\n");
            break;
        case DOT:
            printf("DOT\n");
            break;
        case SEMI:
            printf("SEMI\n");
            break;
        case COMMA:
            printf("COMMA\n");
            break;
        case ASSIGN:
            printf("ASSIGN\n");
            break;
        case LE:
            printf("LE\n");
            break;
        case LT:
            printf("LT\n");
            break;
        case GE:
            printf("GE\n");
            break;
        case GT:
            printf("GT\n");
            break;
        case EQ:
            printf("EQ\n");
            break;
        case NE:
            printf("NE\n");
            break;
        case OR:
            printf("OR\n");
            break;
        case AND:
            printf("AND\n");
            break;
        case NOT:
            printf("NOT\n");
            break;
        case PLUS:
            printf("ADD\n");
            break;
        case MINUS:
            printf("SUB\n");
            break;
        case MUL:
            printf("MUL\n");
            break;
        case DIV:
            printf("DIV\n");
            break;
        case D_PLUS:
            printf("DOUBLE PLUS\n");
            break;
        case D_MINUS:
            printf("DOUBLE MINUS\n");
            break;
        case PLUS_EQ:
            printf("PLUS EQUAL\n");
            break;
        case MINUS_EQ:
            printf("MINUS EQUAL\n");
            break;
        case DIV_EQ:
            printf("DIV EQUAL\n");
            break;
        case MUL_EQ:
            printf("MUL EQUAL\n");
            break;
        case LP:
            printf("LP\n");
            break;
        case RP:
            printf("RP\n");
            break;
        case LB:
            printf("LB\n");
            break;
        case RB:
            printf("RB\n");
            break;
        case LC:
            printf("LC\n");
            break;
        case RC:
            printf("RC\n");
            break;
    }
}

void print_tree(node *n, int depth)
{
    if (n->empty == TRUE)
        return;
    for (int i = 0; i < depth; i++)
    {
        printf("  ");
    }
    print_node(n);
    linked_list * l = n->list;
    if (l == NULL) return;
    if (l->length == 0) return;
    list_node* node = l->first;
    while (node != NULL)
    {
        print_tree(node->data, depth + 1);
        node = node->next;
    }
}

void add_child_node(node *n, int num, ...)
{
    n->list = new_linked_list();
    va_list val_list;
    va_start(val_list, num);
    for (int i = 0; i < num; ++i) {
        node* c = va_arg(val_list,node*);
        c->per = n;
        add_to_list(n->list,c,6);
    }
    va_end(val_list);
}