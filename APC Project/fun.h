#ifndef FUN_H
#define FUN_H
#include "apc.h"                                               // for Dlist definition
void insert_front(Dlist **headR, Dlist **tailR, int digit);
void print_list_forward(Dlist *head);
int compare(Dlist **head1, Dlist **head2);


#endif /* FUN_H */