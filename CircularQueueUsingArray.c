#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();
void peek();

void enqueue()
{
    int x;
    printf("enter the value of x:\n");
    scanf("%d", &x);
    if (front == -1 && front == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("queue is full");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && front == -1)
    {
        printf("queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("the dequeue element is :%d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front;
    if (front == -1 && front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("the queue is:\n");
        while (i != rear)
        {

            printf("%d\t", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d", queue[rear]);
    }
}

void peek()
{
    if (front == -1 && front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("%d", queue[front]);
    }
}

int main()
{
    int choice;
    char ch;
    do
    {
        printf("Press 1: enqueue, 2: dequeue, 3: display, 4: peek, 5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
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
        ch = getch();
    } while (ch == 'y');
    return 0;
}
