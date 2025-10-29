/*
Name: Kiran V
DATE: 29/10/2025
Project: Arbitrary Precision Calculator
Description: 
To design and implement an Arbitrary Precision Calculator capable of performing arithmetic operations
(Addition, Subtraction, Multiplication, and Division) on integers of any size,
beyond the storage limits of standard C data types, using Doubly Linked Lists (DLL).
*/

#include <stdio.h>
#include <stdlib.h>
#include "apc.h"
#include "fun.h"
void sl_delete_list(Dlist **head1)
{
    if (head1 == NULL || *head1 == NULL)
    {
        return;                                             // List is already empty
    }

    Dlist *temp;
    while (*head1 != NULL)
    {
        temp = *head1;
        *head1 = (*head1)->next;
        free(temp);
    }
}
void insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newnode = malloc(sizeof(Dlist));
    if (newnode == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = *tail;

    if (*tail)
    {
        (*tail)->next = newnode;
    }
    else
    {
        *head = newnode;
    }
    *tail = newnode;
}

void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    char *str1 = argv[1];
    char *str2 = argv[3];
    while (*str1)
    {
        insert_last(head1, tail1, *str1 - '0');
        str1++;
    }
    while (*str2)
    {
        insert_last(head2, tail2, *str2 - '0');
        str2++;
    }
}
int main(int argc, char *argv[])
{
    int count = 0;
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    char operator = argv[2][0];
    int res;
    switch (operator)
    {
     case '+':
        digit_to_list(&head1, &tail1, &head2, &tail2, argv);
        addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        break;
        
     case '-':
        digit_to_list(&head1, &tail1, &head2, &tail2, argv);
        res = compare(&head1, &head2);
        if (res == 1)
        {
            subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            print_list_forward(headR);
        }
        else
        {
            subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
            print_list_forward(headR);
        }
        break;
     case 'x':
        digit_to_list(&head1, &tail1, &head2, &tail2, argv);
        multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        print_list_forward(headR);
        break;
     case '/':
        digit_to_list(&head1, &tail1, &head2, &tail2, argv);
        division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
        print_list_forward(headR);
        break;

        default:
        printf("Invalid Input:-( Try again...\n");
    }
    return 0;
}
