#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
    if (ptr == NULL)
    {
        printf("Linked List is empty");
        return;
    }

    while (ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
    
}

struct Node* insertAtBeggining(struct Node* ptr, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (ptr == NULL)
    {
        newNode->next = NULL;
        return newNode;
    }

    newNode->next = ptr;
    return newNode;
    
}

// struct Node* insertAtIdx(struct Node* ptr, int data)

int main() {
    struct Node* head = NULL;
    head = insertAtBeggining(head, 10);
    head = insertAtBeggining(head, 20);
    linkedListTraversal(head);
}