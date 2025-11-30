#include<stdio.h>

void printArray(int A[], int n){
    printf("\n********************\n");
    for(int i=1;i<=n;i++){
        printf("%d ",A[i]);
    }
    printf("\n********************\n");
}

void bubbleSort(int A[],int n){
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-1;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int A[n+1];

    printf("Enter the array elements\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }

    printArray(A,n);
    bubbleSort(A,n);
    printArray(A,n);

    return 0;
}
