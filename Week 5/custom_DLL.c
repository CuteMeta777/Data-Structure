#include <stdio.h>
#include <stdbool.h>

#define null NULL

typedef struct Node
{
    int data;
    Node* prev;
    Node* next;
} Node;

// front of the head
void insert_at_head_front(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    new_node->next = *head_ref;
    new_node->prev = null;
    (*head_ref)->prev = new_node;

    *head_ref = new_node;
}

// back of the end
void insert_at_end_back(Node* head, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = null;

    Node* current_node = head;
    while (current_node->next != null)
        current_node = current_node->next;
    Node* end_node = current_node;

    end_node->next = new_node;
    new_node->prev = end_node;
}

// back of the key
void insert_at_mid_back(Node* head, int key, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    Node* current_node = head;
    while (current_node != null)
    {
        if (current_node->data == key)
            break;

        current_node = current_node->next;
    }

    Node* key_node = current_node;

    new_node->next = key_node->next;
    new_node->prev = key_node;
    key_node->next = new_node;
    new_node->next->prev = new_node;
}

void delete_head(Node** head_ref)
{
    Node* temp = *head_ref;
    temp->next->prev = null;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void delete_end(Node* head)
{
    Node* current_node = head;
    while (current_node->next != null)
        current_node = current_node->next;

    Node* end_node = current_node;
    end_node->prev->next = null;
    free(end_node);
}

// back of the key
void delete_mid(Node* head, int key)
{
    Node* current_node = head;
    while (current_node != null)
    {
        if (current_node->data == key)
            break;
        
        current_node = current_node->next;
    }

    Node* key_node = current_node;
    key_node->prev->next = key_node->next;
    key_node->next->prev = key_node->prev;
    free(key_node);
}

int main(void)
{

    return 0;
}