#include <stdio.h>

int main(){
    char st1[]="Hello world";
    char st2[]="String";

    int found=0;
    for (int i=0;st1[i]!='\0';i++){
        
        int alreadyPrinted = 0;
        for (int k = 0; k < i; k++) {
            if (st1[i] == st1[k]) {
                alreadyPrinted = 1;
                break;
            }
        }

        if (alreadyPrinted)
            continue;

        for (int j=0;st2[j]!='\0';j++){
            if (st1[i]==st2[j]){
                printf("%c ",st1[i]);
                found=1;
                break;
            }
        }
    }
    if(!found)
        printf("There is no common characters in %s and %s", st1,st2);
    return 0;
}