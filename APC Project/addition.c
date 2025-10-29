
#include <stdio.h>
#include <stdlib.h>
#include "apc.h"
#include "fun.h"

int addition(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int carry = 0;

    *headR = NULL;
    *tailR = NULL;

    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        int d1 = 0, d2 = 0;
        if (temp1)
        {
            d1 = temp1->data;
        }
        if (temp2)
        {
            d2 = temp2->data;
        }

        int sum = d1 + d2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        insert_front(headR, tailR, digit);

        if (temp1) 
            temp1 = temp1->prev;
        if (temp2) 
            temp2 = temp2->prev;
    }
    // print_list_forward(*headR);
    return SUCCESS;
}