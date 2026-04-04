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

void show_poly(Node* head) // = traverse and print
{
    Node* current = head;
    while (current != null)
    {
        printf("%dx^%d", current->coef, current->pow);
        current = current->next;

        if (current != null)
            printf(" + ");
    }
    printf("\n");
}

void add_poly(Node* poly1, Node* poly2, Node* result)
{
    while (poly1->next && poly2->next)
    {
        if (poly1->pow > poly2->pow)
        {
            result->pow = poly1->pow;
            result->coef = poly1->coef;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow)
        {
            result->pow = poly2->pow;
            result->coef = poly2->coef;
            poly2 = poly2->next;
        }
        else
        {
            result->pow = poly1->pow;
            result->coef = poly1->coef + poly2->coef;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }


    }
}

int main(void)
{
    Node* poly1 = null;
    Node* poly2 = null;

    // poly1 : 5x^2 + 4x^1 + 2x^0
    create_node(&poly1, 5, 2);
    create_node(&poly1, 4, 1);
    create_node(&poly1, 2, 0);

    // poly2 : -5x^1 - 5x^0
    create_node(&poly2, -5, 1);
    create_node(&poly2, -5, 0);

    // print generated polynomials
    printf("1st Polynomial: ");
    show_poly(poly1);
    printf("2nd Polynomial: ");
    show_poly(poly2);

    // add two polinomials
    Node* result_poly = (Node*)malloc(sizeof(Node));
    add_poly(poly1, poly2, result_poly);

    // print add-result
    printf("Added Polynomial: ");
    show_poly(result_poly);

    return 0;
}