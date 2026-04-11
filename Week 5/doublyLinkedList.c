#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define null NULL

typedef struct
{
    int data;
    Node* prev;
    Node* next;
} Node;

void insertBeforeHead(Node** headRef, int newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;

    newNode->prev = null;
    newNode->next = *headRef;

    (*headRef)->prev = newNode;

    *headRef = newNode;
}

void insertAfterTail(Node* head, int newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;

    Node* current = head;
    while (current->next != null)
        current = current->next;
    Node* tail = current;

    newNode->prev = tail;
    newNode->next = null;
    
    tail->next = newNode;
}

void insertAfterKey(Node* head, int key, int newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;

    Node* current = head;
    while (current->next != null && current != key)
        current = current->next;
    Node* keyNode = current;

    if (keyNode->data == key)
    {
        newNode->prev = keyNode;
        newNode->next = keyNode->next;

        keyNode->next->prev = newNode;
        keyNode->next = newNode;
    }
    else
    {
        printf("no element matches the key!\n");
        return;
    }
}

void deleteHead(Node** headRef)
{
    Node* temp = *headRef;
    *headRef = (*headRef)->next;
    (*headRef)->prev = null;
    free(temp);
}

void deleteTail(Node* head)
{
    Node* current = head;
    while (current->next != null)
        current = current->next;
    Node* tail = current;

    tail->prev->next = null;
    free(tail);
}

void deleteKey(Node* head, int key)
{
    Node* current = head;
    while (current->next != null && current->data != key)
        current = current->next;
    Node* keyNode = current;

    if (keyNode->data == key)
    {
        keyNode->prev->next = keyNode->next;
        keyNode->next->prev = keyNode->prev;
    }
    else
    {
        printf("no element matches the key!\n");
        return;
    }
}