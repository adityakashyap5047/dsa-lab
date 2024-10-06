#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

struct Node* insertAtBegging(struct Node *ptr, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(ptr == NULL){
        newNode->next = NULL;
        return newNode;
    }

    newNode->next = ptr;
    return newNode;

}

int main() {

    struct Node *head = NULL;
    head = insertAtBegging(head, 10);
    head = insertAtBegging(head, 20);
    head = insertAtBegging(head, 30);
    linkedListTraversal(head);
}