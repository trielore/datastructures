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

int size_linkedlist(linkedlist* l);

node* get_head_node(linkedlist* l);
int get_node_value(node* v);
node* get_next(node* l);
void insert_after(node* it, int value);

void replace_value_with(node* n, int new_value);

boolean remove_head(linkedlist* l, int* v);
boolean remove_tail(linkedlist* l, int* v);

boolean get_head_value(linkedlist* l, int* v);
boolean get_tail_value(linkedlist* l, int* v);


#endif
