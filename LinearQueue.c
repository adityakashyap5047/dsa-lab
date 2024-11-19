#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printQueue(struct Queue *q)
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue is: ");
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("The queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty \n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct Queue q;
    printf("Enter the size of queue you want to create: ");
    scanf("%d", &q.size);
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
    {
        printf("Queue is empty\n");
    }

    // Enqueue few elements
    enqueue(&q, 5); 
    printQueue(&q);
    enqueue(&q, 7);
    printQueue(&q);
    enqueue(&q, 8);
    printQueue(&q);
    enqueue(&q, 10);
    printQueue(&q);
    printf("dequeueing element %d \n", dequeue(&q));
    printf("dequeueing element %d \n", dequeue(&q));
    printf("dequeueing element %d \n", dequeue(&q));
    return 0;
}