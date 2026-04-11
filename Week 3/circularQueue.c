#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define null NULL

typedef struct
{
    int front, rear;
    int capacity;
    int size;
    int* array;
} Queue;

Queue* createQueue(int capacity)
{
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));

    if (newQueue == null)
        return null;

    newQueue->front = 0;
    newQueue->rear = -1;
    newQueue->size = 0;
    newQueue->capacity = capacity;

    newQueue->array = (int*)malloc(capacity * sizeof(int));

    if (newQueue->array == null)
        return null;

    return newQueue;
}

bool isFull(Queue* queue)
{
    return queue->size == queue->capacity;
}

bool isEmpty(Queue* queue)
{
    return queue->size == 0;
}

void enqueue(Queue* queue, int newData)
{
    if (!isFull(queue))
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = newData;
        queue->size += 1;
    }
    else
    {
        printf("queue is full!\n");
    }
}

int dequeue(Queue* queue)
{
    if (!isEmpty(queue))
    {
        int element = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size -= 1;
        return element;
    }
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