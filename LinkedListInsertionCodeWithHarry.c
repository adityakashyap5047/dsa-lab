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

struct Node* insertAtBeggining(struct Node *ptr, int data){
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
        struct Node *head = insertAtBeggining(ptr, data);
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

struct Node* insertAtEnd(struct Node* ptr, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if(ptr == NULL){
        newNode->next = NULL;
        return newNode;
    }

    struct Node* temp = ptr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = NULL;

    return ptr;

}

struct Node* insertAfterNode(struct Node*ptr, int data, int node){

    if(ptr == NULL){
        printf("Error! while inserting in the empty LinkedList");
        return NULL;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node * temp = ptr;
    while (temp->data != node) 
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return ptr;
}

struct Node* deleteBeginingNode(struct Node* ptr){
    if(ptr == NULL){
        printf("Error! while inserting in the empty LinkedList");
        return NULL;
    }
    struct Node* temp = ptr;
    ptr = ptr->next;
    free(temp);
    return ptr;
}

int main() {

    struct Node *head = NULL;
    head = insertAtBeggining(head, 10);
    head = insertAtBeggining(head, 20);
    head = insertAtBeggining(head, 30);
    // head = insertAtIndex(head, 20, 0);
    // linkedListTraversal(head);
    // head = insertAtIndex(head, 12, 2);
    // head = insertAtIndex(head, 22, 4);
    // head = insertAtIndex(head, 32, 3);
    // linkedListTraversal(head);
    // head = insertAtEnd(head, 10);
    // head = insertAtEnd(head, 20);
    // head = insertAfterNode(head, 30, 20);
    head = deleteBeginingNode(head);
    linkedListTraversal(head);
}