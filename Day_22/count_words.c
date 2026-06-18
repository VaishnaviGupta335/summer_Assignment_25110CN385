#include <stdio.h>

int main(){
    char st[]="my name is vaishnavi";
    int i = 0, words = 0;
    char c = st[i];
    for (int i=0;st[i]!='\0';i++){
        if (st[i] != ' ' && (i == 0 || st[i-1] == ' '))
            words++;
    }
    printf("Total words in the sentence= %d", words);
    return 0;
}