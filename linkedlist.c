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
    return 0;
}
void insert_front(linkedlist *l, int value)
{
};
void insert_back(linkedlist *l, int value)
{
}
boolean get_head(linkedlist *l, int *v)
{
    return FALSE;
}
boolean get_tail(linkedlist *l, int *v)
{
    return FALSE;
}
boolean remove_head(linkedlist *l, int *v)
{
    return FALSE;
}
boolean remove_tail(linkedlist *l, int *v)
{
    return FALSE;
}
