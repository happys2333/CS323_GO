// Package c +build ignore
package c

/*
struct Node{
    int word_type;
    int line;
    void* val;
    struct Node *next;
    struct Node *friend_node;
    int lval_or_rval;
    int empty;
};
*/
import "C"

type GrammarNode C.struct_Node
