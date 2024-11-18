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

void enqueue()
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    printf("enter the node\n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(rear==NULL)
    {
        rear=front=p;
        rear->next=front;
    }
    else
    {
        rear->next=p;
        rear=p;
        rear->next=front;
    }

}

void dequeue()
{
    struct node *q;
    q=front;
    if(front==NULL&&rear==NULL)
    {
        printf("queue is empty\n");
    }
    else if(front==rear)
    {
        front=rear=NULL;
        free(q);
    }
    else
    {
       front= front->next;
        rear->next=front;
        free(q);
    }
}

void peek()
{
    if(front==NULL&&rear==NULL)
    {
    printf("queue is empty\n");
    }
else{
    printf("%d\n",front->data);
}

}

void display()
{
    struct node *q;
    q=front;
      if(front==NULL&&rear==NULL)
  {
  printf("queue is empty\n");
  }

  else
  { while(q->next!=front)
  {
    printf("%d\n",q->data);
    q=q->next;
  }
  printf("%d\n",q->data);

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
