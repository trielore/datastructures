#ifndef INCLUDED_LINKEDLIST_H
#define INCLUDED_LINKEDLIST_H

typedef char boolean;
#define TRUE 1;
#define FALSE 0;

typedef struct  node {
    int value;
    struct node* next;
} node;

typedef struct {
    node* head;
} linkedlist;

linkedlist *create_linkedlist();
void delete_linkedlist(linkedlist* l);
void insert_front(linkedlist* l, int value);
void insert_back(linkedlist* l, int value);
// boolean replace_value_with(linkedlist* l, int old_value, int new_value);
// boolean replace_value_at_pos(linkedlist* l, int pos, int new_value);
boolean get_head(linkedlist* l, int* v);
boolean get_tail(linkedlist* l, int* v);
boolean remove_head(linkedlist* l, int* v);
boolean remove_tail(linkedlist* l, int* v);
int size_linkedlist(linkedlist* l);


#endif
