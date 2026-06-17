#include <stdio.h>
#include <string.h>

int main(){
    char st[]="hello";
    int n=strlen(st);
    for (int i=n-1;i>=0;i--){
        printf("%c", st[i]);
    }
    return 0;
}