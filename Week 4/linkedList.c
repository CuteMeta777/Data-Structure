#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define null NULL

typedef struct
{
    int data;
    struct Node* next;
} Node;

void traverse(Node* head)
{
    Node* current = head;
    while (current != null)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

bool search_recursive(Node* head, int key)
{
    if (head == null)
        return false;
    
    if (head->data == key)
        return true;

    return search_recursive(head->next, key);
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

// insert before head, and make the inserted one the new head
void insertAtHead(Node** headRef, int newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// insert after tail.
void insertAtEnd(Node* head, int newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = null;

    Node* current = head;
    while (current->next != null)
        current = current->next;

    Node* tail = current;
    tail->next = newNode;
}

void insertAfterPosition(Node* head, int key, int newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;

    Node* current = head;
    while (current->next != null && current->data != key)
        current = current->next;
    
    if (current->data == key)
    {
        newNode->next = current->next;
        current->next = newNode;
        return;
    }
    else
    {
        printf("there was no node with the same key value!\n");
        return;
    }
}

void deleteNode(Node** headRef, int key)
{
    if (*headRef != null)
    {
        if ((*headRef)->data == key)
        {
            Node* temp = *headRef;
            *headRef = (*headRef)->next;
            free(temp);
        }
        else
        {
            Node* prev;
            Node* current = *headRef;
            while (current->next != null && current->data != key)
            {
                prev = current;
                current = current->next;
            }

            if (current->data == key)
            {
                prev->next = current->next;
                free(current);
            }
            else
            {
                printf("there was no node with the same key value!\n");
                return;
            }
        }
    }
    else
    {
        printf("list is empty!\n");
    }
}

void deleteList(Node** headRef)
{
    Node* current = *headRef;
    Node* next;

    while (current != null)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = null;
}