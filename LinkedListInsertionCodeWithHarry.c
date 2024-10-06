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

struct Node* insertAtIndex(struct Node *ptr, int data, int idx){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(idx == 0){
        struct Node *head = insertAtBegging(ptr, data);
        return head;
    }

    if(ptr == NULL){
        printf("Error! while inserting at any index in the empty LinkedList");
        return NULL;
    }

    struct Node * temp = ptr;
    int i = 0;
    while(i != idx - 1){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return ptr;
}

int main() {

    struct Node *head = NULL;
    head = insertAtBegging(head, 10);
    head = insertAtBegging(head, 20);
    head = insertAtBegging(head, 30);
    head = insertAtIndex(head, 20, 0);
    linkedListTraversal(head);
    head = insertAtIndex(head, 12, 2);
    head = insertAtIndex(head, 22, 4);
    head = insertAtIndex(head, 32, 3);
    linkedListTraversal(head);
}