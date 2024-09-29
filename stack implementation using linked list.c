#include<stdio.h>
#include<stdlib.h>
struct node{

    int data ;
    struct node*next;
};
struct node*top = NULL;

void push(int x){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode ->data = x;
    newnode->next = top;
    top = newnode ;
}
void display(){
    if(top==0){
        printf("stack is empty.");
    }
    else{
        struct node* temp = top;
        while(temp!=0){
            printf("%d\n",temp->data);
             temp = temp->next;
        }
    }
}
void pop(){
    struct node*temp = top ;
     top = top->next ;
     free(temp);
}

void main(){
    int num ,choice;
    
   

    while(1){
         printf("stack operations:\n1.push\n2.pop\n3.display\n4.exit\n");
         printf("enter your choice:");
         scanf("%d",&choice);

        switch(choice){

            case 1 : 
                 printf("enter value for newnode:");
                 scanf("%d",&num);
                 push(num);
                 break;

            case 2 :
                    pop();
                    break;
            case 3 :
                    display();
                    break;
            case 4 :
                    return ;
            default :
                printf("enter valid choice.\n");
                break ;
        }
    }

}
