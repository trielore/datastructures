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
    int i = 0;
    for (node *p = l->head; p != 0; p = p->next)
    {
        ++i;
    }
    return i;
}
void insert_front(linkedlist *l, int value)
{
    node *oldhead = l->head;
    l->head = (node *)malloc(sizeof(node));
    l->head->value = value;
    l->head->next = oldhead;
};
void insert_back(linkedlist *l, int value)
{
    if (l->head == 0)
    {
        insert_front(l, value);
    }
    node *i = l->head;
    for (; i->next != 0; i = i->next)
        ;
    i->next = (node *)malloc(sizeof(node));
    i->next->value = value;
    i->next->next = 0;
}
// bool replace_value_with(int old_value, int new_value)
// bool replace_value_at_pos(int pos, int new_value);
boolean get_head(linkedlist *l, int *v)
{
    node *h = l->head;
    if (h == 0)
    {
        return FALSE;
    }
    *v = h->value;
    return TRUE
}
boolean get_tail(linkedlist *l, int *v)
{
    node *i = l->head;
    if (i == 0)
    {
        return FALSE;
    }
    for (; i->next != 0; i = i->next)
        ;
    *v = i->value;
    return TRUE;
}
boolean remove_head(linkedlist *l, int *v)
{
    node *h = l->head;
    if (h == 0)
    {
        return FALSE;
    }
    *v = h->value;
    node *nh = h->next;
    free(h);
    l->head = nh;
    return TRUE
}
boolean remove_tail(linkedlist *l, int *v)
{
    node *i = l->head;
    if (i == 0)
    {
        return FALSE;
    }
    node* p = i;
    i = i->next;
    if (i == 0) {
        *v = p->value;
        free(p);
        l->head = 0;
        return TRUE;
    }
    while (i->next != 0) {
        p = i;
        i = i->next;
    }
    *v = i->value;
    free(i);
    p->next = 0;
    return TRUE
}