#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num = rand() % 100 + 1;

    int guessed, count=1;
    printf("Guess a number between 1-100: ");
    scanf("%d", &guessed);

    while (guessed != num)
    {
        if (guessed < num)
        {
            printf("Guess higher: ");
            scanf("%d", &guessed);
        }
        else if (guessed > num)
        {
            printf("guess lower: ");
            scanf("%d", &guessed);
        }
        count++;
    }
    if (guessed==num)
        printf("You guessed the right number which is %d in %d guesses", num, count);
    return 0;
}