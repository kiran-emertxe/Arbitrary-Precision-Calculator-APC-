#include "apc.h"
#include<stdio.h>
#include <stdlib.h>
#include "fun.h"

void insert_front(Dlist **headR, Dlist **tailR, int digit) 
{
    Dlist *newnode = malloc(sizeof(Dlist));
    if (newnode == NULL) 
    {
        perror("malloc");
        return ;
    }
    newnode->data = digit;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (*headR == NULL)                                            // First node in the list
    {
        *headR = newnode;
        *tailR = newnode;
    } 
    else 
    {
        newnode->next = *headR;
        (*headR)->prev = newnode;
        *headR = newnode;
    }
}

void print_list_forward(Dlist *head) 
{
    Dlist *red = head;
    while (red) 
    {
        printf("%d", red->data);
        red = red->next;
    }
    printf("\n");
}

int compare(Dlist **head1, Dlist **head2)
{
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    int len1 = 0;
    int len2 = 0;

    while (temp1 != NULL)                                   // Calculate the length of the first list
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)                                   // Calculate the length of the second list
    {
        len2++;
        temp2 = temp2->next;
    }

    if (len1 > len2)                                         // Compare the lengths of the lists
    {
        return 1;                                            // List 1 is greater
    }
    else if (len1 < len2)
    {
        return -1;                                          // List 2 is greater
    }
    else                                                   // If lengths are equal, compare data in each node
    {
        temp1 = *head1;
        temp2 = *head2;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                return 1;                                  // List 1 is greater
            }
            else if (temp1->data < temp2->data)
            {
                return -1;                                 // List 2 is greater
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return 0;
    }
    
}
