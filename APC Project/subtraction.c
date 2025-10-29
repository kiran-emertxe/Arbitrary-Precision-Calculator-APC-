
#include <stdio.h>
#include <stdlib.h>
#include "apc.h"
#include "fun.h"
void trim_leading_zeros(Dlist **head)
{
    if (head == NULL || *head == NULL)
        return;
    Dlist *cur = *head;
    // skip nodes whose digit is zero until a non-zero or end
    while (cur != NULL && cur->data == 0)
    {
        Dlist *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *head = cur;
    // if cur is not NULL, optionally fix prev pointer if you have prev
}
int subtraction(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int borrow = 0;

    *headR = *tailR = NULL;

    while (t1 != NULL || t2 != NULL || borrow)
    {
        int d1 = 0, d2 = 0;
        if (t1)
            d1 = t1->data;
        if (t2)
            d2 = t2->data;

        d1 -= borrow; // Subtract borrow from d1

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int diff = d1 - d2;
        insert_front(headR, tailR, diff);

        if (t1)
            t1 = t1->prev;
        if (t2)
            t2 = t2->prev;
    }
    trim_leading_zeros(headR);
    return 0;
}
