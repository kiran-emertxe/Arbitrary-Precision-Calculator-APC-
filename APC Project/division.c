#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
#include "apc.h"

int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    *headR = NULL;
    *tailR = NULL;
    if (*head2 == NULL)                        // check divisor zero
    {
        return -1;
    }
    int count = 0;
    while (1) 
    {
        int cmp = compare(head1, head2);

        if (cmp < 0)                           // dividend < divisor: quotient = count
        {
            insert_front(headR, tailR, count);
            break;
        }
        else if (cmp == 0)                   // dividend == divisor: quotient = count + 1
        {
            insert_front(headR, tailR, count + 1);
            break;
        }
        else                                  // dividend > divisor: subtract once
        {
            subtraction(head1, tail1, head2, tail2, headR, tailR);

            sl_delete_list(head1);            // free old dividend list
            
            *head1 = *headR;                  // new dividend = result of subtraction (headR/tailR)
            *tail1 = *tailR;
            
            *headR = NULL;                   // reset result list pointers for next iteration
            *tailR = NULL;
            count++;
        }
    }
    return 0;
}
