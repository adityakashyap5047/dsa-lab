#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    if (ptr == NULL) {
        printf("Linked List is empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtBeggining(struct Node* ptr, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = ptr;
    return newNode;
}

struct Node* insertAtIdx(struct Node* ptr, int data, int idx) {
    if (idx == 0) {
        return insertAtBeggining(ptr, data);
    }
    if (ptr == NULL) {
        printf("Can't insert at any index of the empty linked list\n");
        return NULL;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = ptr;

    int count = 0;
    while (count < idx - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Index is out of bounds\n");
        free(newNode);
        return ptr;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return ptr;
}

struct Node* insertAtEnd(struct Node* ptr, int data) {
    if (ptr == NULL) {
        return insertAtBeggining(ptr, data);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node* temp = ptr;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return ptr;
}

struct Node* insertAfterNode(struct Node* ptr, int data, int node) {
    if (ptr == NULL) {
        printf("Linked list is empty\n");
        return ptr;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = ptr;

    while (temp != NULL && temp->data != node) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid node\n");
        free(newNode);
        return ptr;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return ptr;
}

struct Node* deleteBeginingNode(struct Node* ptr){
    if(ptr == NULL){
        printf("Error! while deleting the node from the empty LinkedList");
        return NULL;
    }
    struct Node* temp = ptr;
    ptr = ptr->next;
    free(temp);
    return ptr;
}

struct Node* deleteAtIdx(struct Node* ptr, int idx){
    if(ptr == NULL){
        printf("Error! while deleting the node from the empty LinkedList");
        return NULL;
    }
    if (idx == 0)   
    {
        return deleteBeginingNode(ptr);
    }
    
    struct Node* temp = ptr;

    int i = 0;
    while (i != idx - 1)
    {
        temp = temp->next;
        i++;
    }
    struct Node* tempNode = temp->next;
    temp->next = tempNode->next;
    free(tempNode);

    return ptr;
}

struct Node* deleteEndNode(struct Node *ptr){
    if(ptr == NULL){
        printf("Error! while deleting the node from the empty LinkedList");
        return NULL;
    }
    struct Node* temp = ptr;
    struct Node* last = ptr->next;

    while (last->next != NULL)
    {
        last = last->next;
        temp = temp->next;
    }
    
    temp->next = NULL;
    free(last);
    return ptr;
}


int main() {
    struct Node* head = NULL;
    printf("Inserting at beggining");
    head = insertAtBeggining(head, 10);
    linkedListTraversal(head);
    printf("Inserting at beggining");
    head = insertAtBeggining(head, 20);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");
    printf("insert at index 0");
    head = insertAtIdx(head, 12, 0);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");
    printf("insert at index 1");
    head = insertAtIdx(head, 22, 1);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");
    printf("insert at end");
    head = insertAtEnd(head, 45);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");
    printf("insert after node");
    head = insertAfterNode(head, 34, 12);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");
    printf("deleting from beggining");
    head = deleteBeginingNode(head);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");
    printf("delete from index 2");
    head = deleteAtIdx(head, 2);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");
    printf("delete from end");
    head = deleteEndNode(head);
    printf("\n");
    linkedListTraversal(head);
    printf("\n");

    return 0;
}