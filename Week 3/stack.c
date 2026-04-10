#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define null NULL

typedef struct 
{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity)
{
    Stack* newStack = (Stack*)malloc(sizeof(Stack));

    if (newStack == null)
        return null;

    newStack->top = -1;
    newStack->capacity = capacity;
    newStack->array = (int*)malloc(capacity * sizeof(int));

    if (newStack->array == null)
        return null;

    return newStack;
}

bool isFull(Stack* stack)
{
    return stack->top == stack->capacity-1;
}

bool isEmpty(Stack* stack)
{
    return stack->top == -1;
}

int push(Stack* stack, int newData)
{
    if (!isFull(stack))
        return stack->array[++(stack->top)] = newData;
    printf("push() didn't work since stack was full.\n");
    return 0;
}

int pop(Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    printf("pop() didn't work since stack was empty.\n");
    return 0;
}

int peek(Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top];
    printf("peek() didn't work since stack was empty.\n");
    return 0;
}

bool isPalindrome(char word[], int length)
{
    Stack* stack = createStack(length);

    int i = 0;
    while (i < length / 2)
    {
        push(stack, word[i]);
        i++;
    }

    if (length % 2 != 0)
        i++;

    while (i < length)
    {
        if (word[i] != pop(stack))
            return false;
        i++;
    }

    return true;
}

int main()
{
    char word[10] = "HELLO";
    int length = 5;
    printf("%d", isPalindrome(word, length));

    return 0;
}