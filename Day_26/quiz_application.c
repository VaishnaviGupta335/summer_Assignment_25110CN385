#include <stdio.h>

int main()
{
    printf("*******************Instructions for the quiz*******************\n");
    printf("1. This quiz has 5 questions.\n");
    printf("2. Each question has 4 option, and only one option is correct.\n");
    printf("3. You have to enter one option.\n");
    printf("4. For each correct answer, the score will increase by 1.\n");
    printf("5. Each question is compulsory.\n");
    printf("***************************************************************\n");
    printf("\n");

    char questions[][100] = {"Q-1. Which city is known as the Garden City of India?", "Q-2. Which city is home to the famous opera house with sail-shaped roofs?", "Q-3. Which city is famous for the Golden Gate Bridge?", "Q-4. Which city is known as the Pearl City of India?", "Q-5. Which city is famous for its canals and gondolas?"};
    char options[][100] = {"1. Hyderabad 2. Bengaluru 3. Lucknow 4. Mumbai ", "1. Paris 2. London 3. Venice 4. Sydney ", "1. San Francisco 2. Sydney 3. Paris 4. Dubai", "1. Saharanpur 2. Udaipur 3. Hyderabad 4. Ajmer ", "1. Venice 2. Lucknow 3. Berlin 4. Tokyo"};
    int answers[] = {2, 4, 1, 3, 1};

    int option, score = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", questions[i]);
        printf("%s\n", options[i]);
        printf("Enter the correct option: ");
        scanf("%d", &option);
        if (option == answers[i])
        {
            printf("Correct answer!!\n");
            score++;
        }
        else if (option >= 1 && option <= 4)
        {
            printf("Wrong answer!!\n");
            printf("Correct answer is option %d\n", answers[i]);
        }
        else
        {
            printf("Invalid option!!\nAttempt the question again.\n");
            i--;
        }
        printf("\n");
    }

    printf("Quiz over!!\nYour score is %d/5\n", score);
    switch (score)
    {
    case 5:
        printf(" Excellent!!");
        break;
    case 4:
        printf("Very Good!!");
        break;
    case 3:
        printf("Good!!");
        break;
    case 2:
        printf("Fair!!");
        break;
    case 1:
    case 0:
        printf("Need more practice!!");
        break;
    }
    return 0;
}