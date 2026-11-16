#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert a node at the end
void insert() {
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted successfully.\n");
}

// Delete a node
void deleteNode() {
    int value;
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    // Search for the node
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    // If deleting the first node
    if (temp == head) {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    } else {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted successfully.\n");
}

// Forward traversal
void forwardTraversal() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward Traversal: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Backward traversal
void backwardTraversal() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward Traversal: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Forward Traversal\n");
        printf("4. Backward Traversal\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                forwardTraversal();
                break;

            case 4:
                backwardTraversal();
                break;

            case 5:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

