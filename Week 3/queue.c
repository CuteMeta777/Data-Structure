#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define null NULL

typedef struct
{
    int front, rear;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity)
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));

    if (newQueue == null)
        return null;

    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->capacity = capacity;

    newQueue->array = (int*)malloc(capacity * sizeof(int));

    if (newQueue->array == null)
        return null;

    return newQueue;
}

bool isFull(Queue* queue)
{
    return queue->rear == queue->capacity-1;
}

bool isEmpty(Queue* queue)
{
    return queue->front > queue->rear;
}

void enqueue(Queue* queue, int newData)
{
    if (!isFull(queue))
    {
        queue->array[++queue->rear] = newData;
    }
    else
    {
        printf("queue is full!\n");
    }
}

int dequeue(Queue* queue)
{
    if (!isEmpty(queue))
        return queue->array[queue->front++];
    else
    {
        printf("queue is empty!\n");
        return -1;
    }
}

int front(Queue* queue)
{
    if (!isEmpty(queue))
        return queue->array[queue->front];
    else
    {
        printf("queue is empty!\n");
        return -1;
    }
}

int rear(Queue* queue)
{
    if (!isEmpty(queue))
        return queue->array[queue->rear];
    else
    {
        printf("queue is empty!\n");
        return -1;
    }
}