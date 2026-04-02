#define NULL 0

typedef struct 
{
    int front, rear;
    int capacity;
    int *array; // element date type: char, int, float, double, ...
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    if (!queue)
        return NULL;     // out of space error

    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(capacity * sizeof(int)); // for element data

    if (!queue->array)
        return NULL;     // out of space error

    return queue;
}

int isFull(Queue *queue)
{
    return (queue->rear == queue->capacity-1);
}

int isEmpty(Queue *queue)
{
    return (queue->front == queue->rear);
}

void enqueue(Queue *queue, int new_element)
{
    if (!isFull(queue)) // check whether the queue is full
        queue->array[++queue->rear] = new_element;
    else
        printf ("Queue is Full!\n");
    return;
}

int dequeue(Queue *queue)
{
    if (!isEmpty(queue)) // check whether the queue is empty
        return queue->array[queue->front++];
    else
        printf ("Queue is Empty!\n");
    return -1;
}

int front(Queue *queue)
{
    if (!isEmpty(queue)) // check whether the queue is full
        return queue->array[queue->front];
    printf ("Queue is Empty!\n");
    return -1;
}

int rear(Queue *queue)
{
    if (!isEmpty(queue)) // check whether the queue is full
        return queue->array[queue->rear];
    printf ("Queue is Empty!\n");
    return -1;
}