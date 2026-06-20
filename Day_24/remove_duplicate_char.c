#include <stdio.h>
#include <string.h>

int main(){
    char st[]="Hello  world";
    int n=strlen(st);
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (st[i] == ' ')
            continue;
            if (st[i]==st[j]){
                for(int k=j;k<n-1;k++){
                    st[k]=st[k+1];
                }
                n--;
                j--;
            }
        }
    }

    for (int i=0;i<n;i++){
        printf("%c", st[i]);
    }
    return 0;
}