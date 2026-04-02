#include <stdio.h>
#include <stdbool.h>

#define null NULL

typedef struct Node
{
    int data;
    Node* next;
} Node;

void traverse(Node* head)
{
    Node* current_node = head;

    while (current_node != null)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
}

bool search_iterative(Node* head, int key)
{
    Node* current_node = head;

    while (current_node != null)
    {
        if (current_node->data == key)
            return true;

        current_node = current_node->next;
    }

    return false;
}

bool search_recursive(Node* head, int key)
{
    if (head == null)
        return false;

    if (head->data == key)
        return true;

    search_recursive(head->next, key);
}

// back of the head
void insert_at_head_back(Node* head, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    new_node->next = head->next;
    head->next = new_node;
}

// front of the head
void insert_at_head_front(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
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
    
    current_node->next = new_node;
}

// back of the key --> INSPECT
void insert_at_mid(Node* head, int key, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;

    Node* current_node = head;
    whlie (current_node != null)
    {
        if (current_node->data == key)
            break;

        current_node = current_node->next;
    }

    new_node->next = current_node->next;
    current_node->next = new_node;
}

void delete_head(Node** head_ref)
{
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// custom version
void delete_end(Node* head)
{
    Node* current_node = head;
    Node* prev_node;
    while (current_node->next != null)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    prev_node->next = null;
    free(current_node);
}

// professor version
void delete_end(Node* head)
{
    Node* current_node = head;
    whlie (current_node->next->next != null)
    {
        current_node = current_node->next;
    }

    Node* temp = current_node->next;
    current_node->next = null;
    free(temp);
}

// custom version
void delete_mid(Node* head, int key)
{
    Node* current_node = head;
    Node* prev_node;

    whlie (current_node != null)
    {
        if (current_node->data == key)
            break;

        prev_node = current_node;
        current_node = current_node->next;
    }

    prev_node->next = current_node->next;
    free(current_node);
}

int main(void)
{
    Node* head;

    return 0;
}