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

struct Node* insertAtBeginning(struct Node* ptr, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = ptr;
    return newNode;
}

struct Node* insertAtIdx(struct Node* ptr, int data, int idx) {
    if (idx == 0) {
        return insertAtBeginning(ptr, data);
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
        return insertAtBeginning(ptr, data);
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

struct Node* insertAfterNode(struct Node* ptr, )

int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtIdx(head, 12, 0);
    head = insertAtIdx(head, 22, 1);
    head = insertAtEnd(head, 45);
    linkedListTraversal(head);

    return 0;
}