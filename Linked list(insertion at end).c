#include<stdio.h>
#include<stdlib.h>


struct node{
    int data ;
    struct node* next;
};

struct node*  insertAtEnd(struct node* s){
    struct node *newnode,*temp;
    temp = s ;
    newnode = (struct node*)malloc(sizeof(struct node));
   
    printf("enter value which u want to insert:");
    scanf("%d",&newnode->data);
     
    while(s->next!=NULL)
    {
        s = s->next ;
    }
     s->next = newnode ;
     newnode->next = NULL;
     s = temp ;  

}
int main(){
  struct node *s,*p,*q;
  int n ;
  printf("enter the no.of elements u want in LL:");
  scanf("%d",&n);
 p = (struct node*)malloc(sizeof(struct node));
 printf("enter value for 1st node:");
 scanf("%d",&p->data);
   s = p ;
   int count = 1 ;
 do
 {
    q = (struct node*)malloc(sizeof(struct node));
    printf("enter value for next node:");
    scanf("%d",&q->data);

        p->next = q ;
        p = q ;
        count++;
       
 } while (count<n);
    p->next = NULL;

     s = insertAtEnd(s);
   printf("linked list after inserting element at end :\n");
     
 while(s!=NULL){
            printf("%d\n",s->data);
            s = s->next ;
        }
 return 0 ;
}

