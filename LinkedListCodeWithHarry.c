#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocate memory for nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    //Link 1st and 2nd nodes
    head->data = 7;
    head->next = second;

    //Link 2nd and 3rd nodes
    second->data = 9;
    second->next = third;

    //Link 3rd and 4th nodes
    third->data = 2;
    third->next = fourth;

    //Terminate the LinkedList
    fourth->data = 5;
    fourth->next = NULL;

    linkedListTraversal(head);
}