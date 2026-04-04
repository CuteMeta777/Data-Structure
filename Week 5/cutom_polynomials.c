#include <stdio.h>
#include <stdlib.h>

#define null NULL

typedef struct Node
{
    int coef;
    int pow;
    struct Node* next;
} Node;

void create_node(Node** head_ref, int coef, int pow)
{
    Node* new_term = (Node*)malloc(sizeof(Node));
    new_term->coef = coef; new_term->pow = pow;
    new_term->next = null;

    if (*head_ref == null)
    {
        *head_ref = new_term;
    }
    else
    {
        Node* current = *head_ref;
        while (current->next != null)
            current = current->next;
        Node* tail = current;
        
        tail->next = new_term;
    }
}

int main(void)
{


    return 0;
}