#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Reverse the linked list
void reverse() {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next; // store next
        current->next = prev; // reverse link
        prev = current; // move prev
        current = next; // move current
    }
    head = prev;
}

// Display list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Original Linked List:\n");
    display();

    reverse();

    printf("Reversed Linked List:\n");
    display();

    return 0;
}
