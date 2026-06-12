#include <stdio.h>

int main(){
    int n,sum=0,array_sum=0,missing_element;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];//this array contains number from 1-n in which any one number is missing from 1-n
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    for (int i = 1; i <= n+1; i++){
        sum+=i;
    }

    for (int i = 0; i < n; i++){
        array_sum+=A[i];
    }

    missing_element=sum-array_sum;
    printf("Missing element from array is %d", missing_element);
    return 0;
}