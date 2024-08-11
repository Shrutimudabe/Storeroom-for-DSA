#include<stdio.h>
void main(){
    int arr[100],n,x;
    
    printf("enter the value for n:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
      scanf("%d", &arr[i]);
    }
    printf("enter element want to search:");
    scanf("%d",&x);
      
      int count = 0 ;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
          count = 1 ;
           printf("Element found at:%d",i+1);
           break ;
        }
    }
    if(count==0){
      printf("invalid input.");
    }
}
