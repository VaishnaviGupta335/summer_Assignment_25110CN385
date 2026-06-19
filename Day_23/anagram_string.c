#include <stdio.h>
#include <string.h>

int main()
{
    char st1[] = "race";
    int m = strlen(st1);
    char st2[] = "care";
    int n = strlen(st2);
    char st11[m + 1], st22[n + 1];
    strcpy(st11, st1);
    strcpy(st22, st2);
    if (n != m)
        printf("%s and %s are not anagrams", st11, st22);
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m - 1 - i; j++)
            {
                if (st1[j] > st1[j + 1])
                {
                    int temp = st1[j];
                    st1[j] = st1[j + 1];
                    st1[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (st2[j] > st2[j + 1])
                {
                    int temp = st2[j];
                    st2[j] = st2[j + 1];
                    st2[j + 1] = temp;
                }
            }
        }
        int is_anagram = 1;
        for (int i = 0; i < n; i++)
        {
            if (st1[i] != st2[i])
            {
                is_anagram = 0;
                break;
            }
        }
        if (is_anagram)
            printf("%s and %s are anagrams", st11, st22);
        else
            printf("%s and %s are not anagrams", st11, st22);
    }
    return 0;
}
