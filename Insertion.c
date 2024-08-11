#include<stdio.h>
int main(){
    int n,arr[100],value,position,i,choice;

    printf("enter value for n:");
    scanf("%d",&n);

    printf("enter array element:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);    
    }
    
    printf("Choose the insertion operation:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Insert at any position\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the value to insert at the beginning:\n");
            scanf("%d", &value);
            
            for (i = n; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            n++;
            break;

        case 2:
            printf("Enter the value to insert at the end:\n");
            scanf("%d", &value);
            
            arr[n] = value;
            n++;
            break;
        
        case 3:
            printf("Enter the position where you want to insert the new element (1 to %d):\n", n + 1);
            scanf("%d", &position);
            
            
            printf("Enter the value to insert:\n");
            scanf("%d", &value);
            
            for (i = n; i >= position; i--) {
                arr[i] = arr[i - 1];
             }
            arr[position - 1] = value;
            n++;
            break;
        
        default:
            printf("Invalid choice.\n");
            return 1;
    }
     printf("Resultant array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


}
