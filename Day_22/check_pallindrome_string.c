#include <stdio.h>
#include <string.h>

int main() {
    char st[] = "racecar";
    int n = strlen(st);
    int palindrome = 1;

    for (int i = 0; i < n / 2; i++) {
        if (st[i] != st[n - 1 - i]) {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("String is a palindrome");
    else
        printf("String is not a palindrome");

    return 0;
}