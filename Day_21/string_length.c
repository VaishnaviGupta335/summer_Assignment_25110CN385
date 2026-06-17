#include <stdio.h>

int main()
{
    char st[] = "hello";
    int i=0;
    char c=st[i];
    while(c!='\0'){
        i++;
        c=st[i];
    }
    printf("Length of string '%s' is %d",st,i);
    return 0;
}