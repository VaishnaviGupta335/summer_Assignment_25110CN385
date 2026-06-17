#include <stdio.h>

int main() {
    char st[] = "Hello World";

    for (int i = 0; st[i] != '\0'; i++) {
        if (st[i] >= 'a' && st[i] <= 'z') {
            st[i] = st[i] - 32;
        }
    }

    printf("%s", st);
    return 0;
}