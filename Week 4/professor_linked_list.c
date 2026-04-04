#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define null NULL

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void traverse(Node* head)
{
    Node* current = head;
    while (current != null)
    {
        printf("%d", current->data);
        current = current->next;
    }
}

void search_iterative(Node* head, int key)
{
    Node* current = head;
    while (current != null)
    {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

void search_recursive(Node* head, int key)
{
    if (head == null)
        return false;

    if (head->data == key)
        return true;

    return search_recursive(head->next, key);
}

void insert_before_head(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    new_node->next = *head_ref;
    *head_ref = (*head_ref)->next;
}

void insert_after_tail(Node* head, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    new_node->next = null;

    Node* last = head;
    while (last->next != null)
        last = last->next;
    
    last->next = new_node;
}

void insert_after_key(Node* head, int key, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    Node* current = head;
    while (current->data != key)
        current = current->next;
    
    new_node->next = current->next;
    current->next = new_node;
}

void delete_universal(Node** head_ref, int key)
{
    if (*head_ref != null)
    {
        if ((*head_ref)->data == key)
        {
            Node* temp = *head_ref;
            *head_ref = (*head_ref)->next;
            free(temp);
        }
        else
        {
            Node* prev;
            Node* current = *head_ref;
            while (current->data != key && current->next != null)
            {
                prev = current;
                current = current->next;
            }
            if (current->data != key)
            {
                printf("Target Node Doesn't Exist!\n");
                return;
            }
            else
            {
                prev->next = current->next;
                free(current);
            }
        }
    }
    else
    {
        printf("This list is EMPTY!\n");
        return;
    }
}

void delete_list(Node** head_ref)
{
    Node* current = *head_ref;
    Node* next_node;

    while (current != null)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head_ref = null;
}

int main(void)
{
    printf("Hello!\n");

    return 0;
}