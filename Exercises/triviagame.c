#include <stdio.h>
#include <string.h>

int main()
{

    char questions[][120] = {"Which is the largest planet in the our solar system?",
                             "What is the hottest planet?",
                             "What planet has the most amount of moons?"};

    char options[][100] = {"A. Jupiter", "B. Saturn", "C. Mercury", "D. Uranus",
                           "A. Earth", "B. Sun", "C. Venus", "D. Saturn",
                           "A. Mars", "B. Jupiter", "C. Saturn", "D. Neptune"};
    char answerKey[] = {'A', 'C', 'C'};
    char choice;
    int score = 0;

    int question_rows = sizeof(questions) / sizeof(questions[0]);

    for (int i = 0; i < question_rows; i++)
    {
        printf("%s\n", questions[i]);

        for (int j = i * 4; j < i * 4 + 4; j++)
        {
            printf(" %s", options[j]);
        }
        printf("\n");
        scanf(" %c", &choice);

        if (choice == answerKey[i])
        {
            printf("You nailed it! The answer is indeed: %c\n", answerKey[i]);
            score++;
        }
        else
        {
            printf("Wrong answer :(. The corret was: %c\n", answerKey[i]);
        }
    }
    printf("Congratulations! you made the incredible score of: %d", score);

    return 0;
}