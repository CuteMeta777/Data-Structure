#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define null NULL

typedef struct
{
    int data;
    Node* left;
    Node* right;
} Node;

Node* findMin(Node* root)
{
    if (root == null)
        return null;
    else if (root->left != null)
        return findMin(root->left);
    return root;
}

Node* findMax(Node* root)
{
    if (root == null)
        return null;
    else if (root->right != null)
        return findMin(root->right);
    return root;
}

Node* searchNode(Node* root, int key)
{
    if (root == null)
        return null;
    if (root->data > key)
        return searchNode(root->left, key);
    else if (root->data < key)
        return searchNode(root->right, key);
    else
        return root;
}

Node* insertNode(Node* root, int newData)
{
    if (root == null)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newData;
        newNode->left = null;
        newNode->right = null;
        return newNode;
    }
    
    if (newData < root->data)
        root->left = insertNode(root->left, newData);
    else if (newData > root->data)
        root->right = insertNode(root->right, newData);
    else
        ;
    return root;
}