#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define null NULL

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

void insert_before_head(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    new_node->prev = null;
    new_node->next = *head_ref;

    (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

void insert_after_tail(Node* head, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    new_node->next = null;

    Node* current = head;
    while (current->next != null)
        current = current->next;
    Node* tail = current;

    tail->next = new_node;
    new_node->prev = tail;
}

void insert_after_key(Node* head, int new_data, int key)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    Node* current = head;
    while (current->data != key)
        current = current->next;
    Node* key_node = current;

    new_node->next = key_node->next;
    new_node->prev = key_node;
    new_node->next->prev = new_node;
    key_node->next = new_node;
}

void delete_head(Node** head_ref)
{
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    (*head_ref)->prev = null;
    free(temp);
}

void delete_tail(Node* head)
{
    Node* current = head;
    while (current->next != null)
        current = current->next;
    Node* tail = current;

    tail->prev->next = null;
    free(tail);
}

void delete_key_node(Node* head, int key)
{
    Node* current = head;
    while (current->data != key && current->next != null)
        current = current->next;
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

int main(void)
{


    return 0;
}