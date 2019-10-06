#include "linkedlist.h"

#include <stdlib.h>

linkedlist *create_linkedlist()
{
    linkedlist *l = (linkedlist *)malloc(sizeof(linkedlist));
    l->head = 0;
    return l;
}
void delete_linkedlist(linkedlist *l)
{
    int ignore;
    while (remove_head(l, &ignore));
    free(l);
}
int size_linkedlist(linkedlist *l)
{
    int sz = 0;
    node* it = l->head;
    while (it) {
        ++sz;
        it = it->next;
    }
    return sz;
}
void insert_front(linkedlist *l, int value)
{
    node* nh = (node*)malloc(sizeof(node));
    nh->next = l->head;
    nh->value = value;
    l->head = nh;
};
void insert_back(linkedlist *l, int value)
{
    node* it = l->head;
    if (it == 0) {
        insert_front(l, value);
    }
    while (it->next) {
        it = it->next;
    }
    node* nh = (node*)malloc(sizeof(node));
    nh->next = 0;
    nh->value = value;
    it->next = nh;
}

node* get_head_node(linkedlist* l) 
{
    return l->head;
}

int get_node_value(node* v) {
    return v->value;
}

node* get_next(node* it)
{
    return it->next;
}
void insert_after(node* it, int value)
{
    node* nh = (node*)malloc(sizeof(node));
    nh->next = it->next;
    nh->value = value;
    it->next = nh; 
}

void replace_value_with(node* n, int new_value) {
    n->value = new_value;
}

boolean get_head_value(linkedlist *l, int *v)
{
    if (!l->head)
        return FALSE;
    *v = l->head->value;
    return TRUE;
}
boolean get_tail_value(linkedlist *l, int *v)
{
    node* it = l->head;
    if (it == 0) {
        return FALSE;
    }
    while (it->next) {
        it = it->next;
    }
    *v = it->value;
    return TRUE;
}
boolean remove_head(linkedlist *l, int *v)
{
    node* it = l->head;
    if (!it)
        return FALSE;
    *v = it->value;
    l->head = it->next;
    free(it);
    return TRUE;
}
boolean remove_tail(linkedlist *l, int *v)
{
    node* it = l->head;
    if (it == 0) {
        return FALSE;
    }
    node* pit = it;
    while (it->next) {
        pit = it;
        it = it->next;
    }
    if (pit == it) {
        //we are deleting the last element in the list
        l->head = 0;
    } else {
        pit->next = 0;
    }
    *v = it->value;
    free(it);
    return TRUE;
}
