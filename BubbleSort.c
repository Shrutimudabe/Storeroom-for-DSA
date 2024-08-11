#include<stdio.h>
int main(){
    int arr[100],n;

    printf("enter value for n:");
    scanf("%d",&n);

    printf("enter array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp ;
            }
        }
    }
    printf("sorted array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
