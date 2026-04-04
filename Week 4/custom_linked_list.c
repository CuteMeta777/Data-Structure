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
        printf("%d\n", current->data);
        current = current->next;
    }
}

bool search_iterative(Node* head, int key)
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

bool search_recursive(Node* head, int key)
{
    if (head == null) return false;

    if (head->data == key)
        return true;
    
    return search_recursive(head->next, key);
}

void insert_before_head(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
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
}

void insert_after_mid(Node* head, int key, int new_data)
{
    if (search_iterative(head, key) == false)
        return;

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    Node* current = head;
    while (current != null)
    {
        if (current->data == key)
            break;
        current = current->next;
    }

    Node* key_node = current;
    new_node->next = key_node->next;
    key_node->next = new_node;
}

void delete_head(Node** head_ref)
{
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void delete_tail(Node* head)
{
    Node* current = head;
    Node* prev;

    while (current->next != null)
    {
        prev = current;
        current = current->next;
    }
    
    prev->next = null;
    free(current);
}

void delete_mid_target(Node* head, int key)
{
    Node* current = head;
    Node* prev;

    while (current != null)
    {
        if (current->data == key)
            break;

        prev = current;
        current = current->next;
    }

    Node* key_node = current;
    prev->next = current->next;
    free(current);
}

void delete_universal(Node** head_ref, int key)
{
    if (*head_ref != null)
    {
        // delete head
        if ((*head_ref)->data == key)
        {
            Node* temp = *head_ref;
            *head_ref = (*head_ref)->next;
            free(temp);
        }
        // delete mid or tail
        else
        {
            Node* prev = *head_ref;
            Node* current = (*head_ref)->next;
            while (current->next != null && current->data != key)
            {
                prev = current;
                current = current->next;
            }
            if (current->data != key)
                printf("Target Node doesn't Exist!\n");
            else
            {
                Node* temp = current;
                prev->next = current->next;
                free(temp);
            }
        }
    }
    else
    {
        printf("List is Empty\n");
    }
}

void delete_list(Node** head_ref)
{
    Node* current = *head_ref;
    Node* next;
    
    while(current != null)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = null;
}

int main(void)
{


    return 0;
}