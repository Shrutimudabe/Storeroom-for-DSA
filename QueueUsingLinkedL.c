#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* rear = NULL;
struct node* front = NULL;

void enqueue();
void dequeue();
void display();
void peek();

void enqueue() {
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &p->data);
    p->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
}

void dequeue() {
    struct node* q;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        q = front;
        printf("The dequeued element is %d\n", front->data);
        front = front->next; 
        free(q);
    }
}

void peek() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

void display() {
    struct node* q;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        q = front;
        while (q != NULL) {
            printf("%d\n", q->data);
            q = q->next;
        }
    }
}

int main() {
    int choice;
    char ch;
    do {
        printf("Press 1: enqueue, 2: dequeue, 3: display, 4: peek, 5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("Press y to continue: ");
         getchar();
        ch = getchar();
    } while (ch == 'y');
    return 0;
}
