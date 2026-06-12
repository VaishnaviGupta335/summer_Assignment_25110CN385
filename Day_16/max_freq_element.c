#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    // To find maximum frequency
    int maxFreq=0;
    for (int i = 0; i < n; i++){
        
        int frequency=0;
        for (int j=0;j<n;j++){
            if(A[i]==A[j]){
                frequency+=1;
            }
        }

        if (frequency>maxFreq){
            maxFreq=frequency;
        }
    }

    // TO print elemnts having maximum frequency
    printf("Elements with maximum frequency are\n");
    for (int i = 0; i < n; i++) {
        int alreadyPrinted = 0;

        for (int k = 0; k < i; k++) {
            if (A[i] == A[k]) {
                alreadyPrinted = 1;
                break;
            }
        }

        if (alreadyPrinted)
            continue;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (A[i] == A[j]) {
                count++;
            }
        }

        if (count == maxFreq) {
            printf("%d ", A[i]);
        }
    }
    printf("\nFrequency:- %d", maxFreq);
    return 0;
}