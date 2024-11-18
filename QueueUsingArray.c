#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();
void peek();

void enqueue() {
    int x;
    if (rear == N - 1) {
        printf("Queue is overflow\n");
    } else
     {
        printf("Enter the element: ");
        scanf("%d", &x);
        if (front == -1)
         {  
            front = 0;
        }
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear==-1) {
        printf("The queue is underflow\n");
    } else {
        printf("The dequeued element is: %d\n", queue[front]);
        front++;
        
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
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
       ch=getch();
    } while (ch == 'y');
    return 0;
}
