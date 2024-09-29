#include<Stdio.h>
#define MAX 50
int stack[MAX];
int top = -1 ;

void push(int num){
    if(top==MAX-1){
        printf("stack overflow");
    }
    else{
        top = top+1;
        stack[top] = num ;
    }
}

int pop(){
    if(top==-1){
        printf("stack underflow\n");
    }
    return stack[top--];
}

void display(){
    if(top==-1){
        printf("tack is empty.\n");
    }
    else
    {
        printf("stack elements are:\n");
        for(int i=top ;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }

}
void main()
{
    int  num , choice ;
    
    while(1){

        printf("Stacck operations:\n");
        printf("1.push\n2.pop \n3.display\n 4.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : printf("enter no you want to push into stack:");
                     scanf("%d",&num);
                     push(num);
                     break ;
            case 2 : 
                    pop();
                    break ;
            case 3 : 
                    display();
                    break ;
            case 4 :
                    return ;

            dafault : printf("please enter valid choice.\n");
                      break;
        }
        

        
    }
}

