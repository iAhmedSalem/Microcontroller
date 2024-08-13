#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node Added Thank You\n");
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("To add node enter 0\n");
        printf("To print the linked list enter 1\n");
        printf("To exit press 2\n");
        printf("Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Please Enter Node Value: ");
                scanf("%d", &value);
                addNode(&head, value);
                break;
            case 1:
                printList(head);
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Incorrect entry, please try again.\n");
                break;
        }
    }

    return 0;
}
