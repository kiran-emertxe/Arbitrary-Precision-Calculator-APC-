#include "apc.h"
#include "fun.h"
#include <stdio.h>
#include <stdlib.h>

// Function to multiply two large numbers using doubly linked lists
int multiplication(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    Dlist *temp2 = *tail2;  // Least significant digit of 2nd number
    Dlist *temp1;
    Dlist *headr1 = NULL, *tailr1 = NULL;
    Dlist *headr2= NULL, *tailr2 = NULL;

    int carry, flag = 0;

    while (temp2 != NULL)
    {
        carry = 0;
        temp1 = *tail1;

        // Step 1: add zeros (shifting like manual multiplication)
        for (int i = 0; i < flag; i++)
        {
            insert_front(&headr1, &tailr1, 0);
        }

        // Step 2: multiply temp2->data with all digits of number1
        while (temp1 != NULL)
        {
            int mul = (temp1->data * temp2->data) + carry;
            int digit = mul % 10;
            carry = mul / 10;
            insert_front(&headr1, &tailr1, digit);
            temp1 = temp1->prev;
        }
        if (carry)
        {
            insert_front(&headr1, &tailr1, carry);
        }
        // Step 3: add current partial result to total sum
        addition(&headr2, &tailr2, &headr1, &tailr1, headR, tailR);
        // Now result is in headR/tailR, copy back for next iteration
        sl_delete_list(&headr2);
        headr2 = *headR;
        tailr2 = *tailR;
        headr1 = tailr1 = NULL;
        temp2 = temp2->prev;
        flag++;
    }
    return 0;
}
