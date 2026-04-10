#include <iostream>
#include <vector>
#include <stdlib.h>

#define null NULL

using namespace std;

class LinkedList
{
    typedef struct Node
    {
        int data;
        struct Node* next;
    } Node;

private:
    Node* head;

public:
    LinkedList()
    {
        head = null;
    }

    void append(int new_data)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = new_data;
        new_node->next = null;

        if (head == null)
        {
            head = new_node;
        }
        else
        {
            Node* current = head;
            while (current->next != null)
                current = current->next;
            Node* tail = current;
            tail->next = new_node;
        }
    }

    void traverse()
    {
        if (head == null) return;

        Node* current = head;
        while (current != null)
        {
            printf("%d\n", current->data);
            current = current->next;
        }
    }

    int search(int key)
    {
        if (head == null) return -1;

        Node* current = head;
        while (current->data != key && current->next != null)
            current = current->next;
        Node* key_node = current;

        if (key_node->data != key) return -1;
        
        else return 1;
    }

    void insert_before_head(int new_data)
    {
        if (head == null) return;

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = new_data;
        new_node->next = head;

        head = new_node;
    }

    void insert_after_key(int new_data, int key)
    {
        if (head == null) return;

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = new_data;
        
        Node* current = head;
        while (current->next != null && current->data != key)
            current = current->next;
        
        if (current->data != key) { free(new_node); return; }

        Node* key_node = current;
        new_node->next = key_node->next;
        key_node->next = new_node;
    }

    void delete_key(int key)
    {
        if (head == null) return;

        if (head->data == key)
        {
            if (head->next == null)
            {
                Node* temp = head;
                head = null;
                free(temp);
            }
            else
            {
                Node* temp = head;
                head = head->next;
                free(temp);
            }
        }
        else
        {
            Node* prev;
            Node* current = head;
            while (current->next != null && current->data != key)
            {
                prev = current;
                current = current->next;
            }

            if (current->data != key) return;

            prev->next = current->next;
            free(current);
        }
    }
};

int main(void)
{
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    list.insert_after_key(-10, 10);

    list.traverse();

    return 0;
}