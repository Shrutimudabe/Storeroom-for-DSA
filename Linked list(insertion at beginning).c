#include<stdio.h>
#include<stdlib.h>


struct node{
    int data ;
    struct node* next;
};

struct node*  insertAtBeginning(struct node* s){
    struct node *q;
    q = (struct node*)malloc(sizeof(struct node));
    printf("enter value which u want to insert:");
    scanf("%d",&q->data);

     q->next = s ;
     s = q ;
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

   int count = 1;
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

     s = insertAtBeginning(s);

printf("linked list after inserting element at beginning:\n");
 while(s!=NULL){
            printf("%d\n",s->data);
            s = s->next ;
        }
 return 0 ;
}
