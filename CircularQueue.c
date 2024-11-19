#include <stdio.h>
#define SIZE 4
typedef struct circularq_t
{
    int front, rear;
    int item[SIZE];
} circularQ;

/********** Function Declaration begins **********/
void create(circularQ *);
void display(circularQ *);
void encqueue(circularQ *, int);
void decqueue(circularQ *, int);
/********** Function Declaration ends **********/

void main()
{
    int data, ch;
    circularQ CQ;
    create(&CQ);

    //enqueue elements
    encqueue(&CQ, 10);
    display(&CQ);
    encqueue(&CQ, 20);
    display(&CQ);
    encqueue(&CQ, 30);
    display(&CQ);
    encqueue(&CQ, 40);
    display(&CQ);

    //dequeue elements
    decqueue(&CQ, data);
    display(&CQ);
    decqueue(&CQ, data);
    display(&CQ);
    encqueue(&CQ, 50);
    display(&CQ);


}
/********** Creating an empty circular queue **********/
/********** Function Definition begins **********/
void create(circularQ *CQ)
{
    CQ->front = 0;
    CQ->rear = 0;
}
/********** Function Definition ends **********/
/********** Inserting elements in circular queue **********/
/********** Function Definition begins **********/
void encqueue(circularQ *CQ, int data)
{
    if (((CQ->rear == (SIZE - 1)) && (CQ->front == 1)) ||
        (CQ->front == (CQ->rear + 1)))
    {
        printf("\n Circular queue is full");
        return;
    }
    else
    {
        if (CQ->front == 0)
        {
            CQ->front = 1;
            CQ->rear = 1;
            CQ->item[CQ->rear] = data;
        }
        else if (CQ->rear == SIZE - 1)
        {

            CQ->rear = 1;
            CQ->item[CQ->rear] = data;
        }
        else
        {
            CQ->rear = CQ->rear + 1;
            CQ->item[CQ->rear] = data;
        }
    }
}
/********** Function Definition ends **********/
/********** Deleting element from circular queue **********/
/********** Function Definition begins **********/
void decqueue(circularQ *CQ, int data)
{
    if (CQ->front == 0)
    {
        printf("\n Circular queue underflow");
        return;
    }
    data = CQ->item[CQ->front];
    CQ->item[CQ->front] = 0;
    printf("\n Element %d is deleted :", data);
    if (CQ->front == CQ->rear)
    {
        CQ->front = 0;
        CQ->rear = 0;
        printf("\n Circular queue is empty");
    }
    else if (CQ->front == (SIZE - 1))
        CQ->front = 1;
    else
        CQ->front = CQ->front + 1;
}
/********** Function Definition ends **********/
/********** Displaying elements of circular queue **********/
/********** Function Definition begins **********/
void display(circularQ *CQ)
{
    int x;
    if ((CQ->rear > 1) && (CQ->front == (CQ->rear + 1)))
    {
        for (x = 1; x < SIZE; x++)
        {
            printf("%d\t", CQ->item[x]);
        }
        printf("\n");
    }
    else if (CQ->front == (CQ->rear + 1))
    {
        for (x = CQ->rear; x <= SIZE; x++)
        {
            printf("%d\t", CQ->item[x]);
        }
        printf("\n");
    }
    else if (CQ->front > (CQ->rear + 1))
    {
        for (x = 1; x <= CQ->rear; x++)
        {
            printf("%d\t", CQ->item[x]);
        }
        for (x = CQ->front; x < SIZE; x++)
        {
            printf("%d\t", CQ->item[x]);
        }
        printf("\n");
    }
    else
    {
        printf("\n Circular queue is: ");
        for (x = CQ->front; x <= CQ->rear; x++)
        {
            printf("%d\t", CQ->item[x]);
        }
        printf("\n");
    }
}
/********** Function Definition ends **********/
