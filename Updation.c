#include<stdio.h>
void main(){
    int n ,arr[100], k ,idx ;

printf("enter the value for n:");
scanf("%d",&n);

printf("enter array elements:\n");
for(int i=0;i<n;i++){
 scanf("%d",&arr[i]);
}
printf("enter element :");
scanf("%d",&k);

printf("enter the index:");
scanf("%d",&idx);

arr[idx]=k;
printf("updated array:\n");
for(int i=0;i<n;i++){
    printf("%d\n",arr[i]);
}
}
