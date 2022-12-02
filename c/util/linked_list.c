//
// Created by happys on 22-11-15.
//

#include <malloc.h>
#include <stdlib.h>
#include "linked_list.h"

list_node *new_list_node(void *data, int type)
{
    list_node *node = (list_node *)malloc(sizeof(list_node));
    node->data = data;
    node->typeNum = type;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int del_list_node(list_node *node)
{
    if (node == NULL)
        return 1;
    node->typeNum = 0;
    node->data = NULL;
    node->next = NULL;
    node->prev = NULL;
    free(node);
    return 0;
}

char *get_val_string(list_node *node)
{
    char *return_char = malloc(sizeof(char) * 512);
    switch (node->typeNum)
    {
    case 0:
        sprintf(return_char, "%d", *(int *)node->data);
        break;
    case 1:
        sprintf(return_char, "%f", *(float *)node->data);
        break;
    case 2:
        free(return_char);
        return (char *)node->data;
    default:
        return "No Such Node Type";
    }
    return return_char;
}

linked_list *new_linked_list()
{
    linked_list *list = malloc(sizeof(linked_list));
    list->length = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void link_first(linked_list *list, void *val, list_type type)
{
    list_node *node = new_list_node(val, type);
    if (list->first == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        list_node *f = list->first;
        list->first = node;
        node->next = f;
        f->prev = node;
    }
    list->length++;
}

void add_to_list(linked_list *list, void *val, list_type type)
{
    list_node *node = new_list_node(val, type);
    list_node *last = list->last;
    node->next = NULL;
    node->prev = last;
    if (last == NULL)
    {
        list->first = node;
    }
    else
    {
        last->next = node;
    }
    list->last = node;
    list->length++;
}
int index_of_linked_list(linked_list *list, list_node *node)
{
    list_node *nodes = list->first;
    int i = 0;
    while (nodes != NULL)
    {
        if (nodes == node)
            return i;
        i++;
        nodes = nodes->next;
    }
    return -1;
}
void remove_node_from_list(linked_list *list, list_node *x)
{
    if (x == NULL)
    {
        return;
    }
    list_node *next = x->next;
    list_node *prev = x->prev;
    if (next == NULL)
    {
        list->last = prev;
    }
    else
    {
        next->prev = prev;
        x->next = NULL;
    }
    if (prev == NULL)
    {
        list->first = next;
    }
    else
    {
        prev->next = next;
        x->prev = NULL;
    }
    del_list_node(x);
    list->length--;
}
void remove_from_list(linked_list *list, int index)
{
    if (index >= list->length)
    {
        return;
    }
    list_node *node;
    int i;
    if (index < list->length >> 1)
    {
        node = list->first;
        for (i = 0; i < index; i++)
        {
            node = node->next;
        }
    }
    else
    {
        node = list->last;
        for (i = list->length - 1; i > index; i--)
        {
            node = node->prev;
        }
    }
    remove_node_from_list(list, node);
}
void remove_last(linked_list *list)
{
    if (list->length == 0)
    {
        return;
    }
    else if (list->length == 1)
    {
        list->first = NULL;
        del_list_node(list->last);
        list->last = NULL;
        list->length = 0;
        return;
    }
    list_node *node = list->last;
    list_node *prev = node->prev;
    prev->next = NULL;
    list->last = prev;
    del_list_node(node);
    list->length--;
}
void remove_first(linked_list *list)
{
    if (list->length == 0)
    {
        return;
    }
    else if (list->length == 1)
    {
        list->first = NULL;
        del_list_node(list->last);
        list->last = NULL;
        list->length = 0;
        return;
    }
    list_node *node = list->first;
    list_node *next = node->next;
    next->prev = NULL;
    list->first = next;
    del_list_node(node);
    list->length--;
}
list_node *get_by_index(linked_list *list, int index)
{
    list_node *node;
    int i;
    if (index < list->length >> 1)
    {
        node = list->first;
        for (i = 0; i < index; i++)
        {
            node = node->next;
        }
        return node;
    }
    else
    {
        node = list->last;
        for (i = list->length - 1; i > index; i--)
        {
            node = node->prev;
        }
        return node;
    }
}
list_node *get_first(linked_list *list)
{
    return list->first;
}
list_node *get_last(linked_list *list)
{
    return list->last;
}
int contains_val(linked_list *list, void *val)
{
    list_node *nodes = list->first;
    int i = 0;
    while (nodes != NULL)
    {
        if (nodes->data == val)
            return i;
        i++;
        nodes = nodes->next;
    }
    return -1;
}

void free_linked_list(linked_list *list)
{
    list_node *node = list->first;
    while (node != NULL)
    {
        list_node *next = node->next;
        del_list_node(node);
        node = next;
    }
    list->length = 0;
    list->first = NULL;
    list->last = NULL;
    free(list);
}

linked_list* connect_to_linked_list(linked_list *left, linked_list *right){
    if(left->length == 0){
        left->length = right->length;
        left->first = right->first;
        left->last = right->last;
        return left;
    }
    if (right->length == 0){
        right->length = left->length;
        right->first = left->first;
        right->last = left->last;
        return left;
    }
    left->length += right->length;
    right->length = left->length;
    left->last->next = right->first;
    right->first->prev = left->last;
    left->last = right->last;
    right->first = left->first;
    return left;
}