//
// Created by happys on 22-11-15.
//

#ifndef SPLC_LINKED_LIST_H
#define SPLC_LINKED_LIST_H

typedef struct ListNode list_node;
typedef enum ListType {
    INT_NUM,
    FLOAT_NUM,
    CHAR_NUM,
    ARRAY_NUM,
    STRUCT_NUM,
    FUNC_NUM,
    NODE_TYPE,
    LIST_TYPE,
    LIST_NODE_TYPE,
    TYPE_NODE_TYPE,
    UNKNOWN_TYPE
} list_type;

struct ListNode
{
    void *data;
    list_type typeNum;
    /**
     * type of the data
     * -1 unset
     * 0 int*
     * 1 float*
     * 2 char*
     * 3 array
     * 4 structure
     * 5 function
     * 6 node type
     * **/
    list_node *next;
    list_node *prev;
};
char *get_val_string(list_node *node);

typedef struct LinkedList
{
    list_node *first;
    list_node *last;
    int length;
} linked_list;

linked_list *new_linked_list();
void link_first(linked_list *list, void *val, list_type type);
void add_to_list(linked_list *list, void *val, list_type type);
int index_of_linked_list(linked_list *list, list_node *node);
void remove_from_list(linked_list *list, int index);
void remove_node_from_list(linked_list *list, list_node *node);
void remove_last(linked_list *list);
void remove_first(linked_list *list);
list_node *get_by_index(linked_list *list, int index);
list_node *get_first(linked_list *list);
list_node *get_last(linked_list *list);
int contains_val(linked_list *list, void *val);

void free_linked_list(linked_list *list);
linked_list* connect_to_linked_list(linked_list *left, linked_list *right);
#endif // SPLC_LINKED_LIST_H
