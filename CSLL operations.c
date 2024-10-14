#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a circular singly linked list
struct Node* createCSLL(struct Node* last, int data) {
    struct Node* newNode = createNode(data);
    if (last == NULL) {
        last = newNode;
        last->next = last;  // Point to itself
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    return last;
}

// Traverse the CSLL
void traverse(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("HEAD\n");
}

// Insert at the beginning
struct Node* insertBeg(struct Node* last, int data) {
    struct Node* newNode = createNode(data);
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    return last;
}

// Insert at the end
struct Node* insertEnd(struct Node* last, int data) {
    return createCSLL(last, data);
}

// Delete from the beginning
struct Node* deleteBeg(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = last->next;
    if (last == last->next) {  // Only one node
        free(temp);
        last = NULL;
    } else {
        last->next = temp->next;
        free(temp);
    }
    return last;
}

// Delete from the end
struct Node* deleteEnd(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = last->next;
    if (last == last->next) {  // Only one node
        free(temp);
        last = NULL;
    } else {
        // Traverse to the second last node
        while (temp->next != last) {
            temp = temp->next;
        }
        struct Node* endNode = temp->next;
        temp->next = last->next;
        free(endNode);
        last = temp;
    }
    return last;
}

// Main function with menu
int main() {
    struct Node* last = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Create Node\n");
        printf("2. Traverse\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                last = createCSLL(last, data);
                break;

            case 2:
                traverse(last);
                break;

            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                last = insertBeg(last, data);
                break;

            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                last = insertEnd(last, data);
                break;

            case 5:
                last = deleteBeg(last);
                break;

            case 6:
                last = deleteEnd(last);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
