#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void rockpaperscissor();
void checkWinner(int userChoice, int computerChoice);
void guessnumber();

int getPlayerChoice();
int getComputerChoice();

int main()
{

    int option;
    printf("Select a game you wanna play: \n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        guessnumber();
        break;

    case 2:
        rockpaperscissor();
        break;
    }

    return 0;
}

void rockpaperscissor()
{
    int userChoice = getPlayerChoice();
    int computerChoice = getComputerChoice();

    printf("*** ROCK, PAPER, SCISSOR GAME: ***\n");

    switch (userChoice)
    {
    case 1:
        printf("You chose ROCK\n");
        break;

    case 2:
        printf("You chose PAPER\n");
        break;

    case 3:
        printf("You chose SCISSOR\n");
        break;
    }

    switch (computerChoice)
    {
    case 1:
        printf("computer chose ROCK\n");
        break;

    case 2:
        printf("computer chose PAPER\n");
        break;

    case 3:
        printf("computer chose SCISSOR\n");
        break;
    }
    checkWinner(userChoice, computerChoice);
}

int getComputerChoice()
{
    srand(time(NULL));

    return ((rand() % 3) + 1);
};

int getPlayerChoice()
{

    int choice = 0;

    do
    {
        printf("Insert your choice: \n");
        printf("1 - ROCK\t  2 - PAPER\t 3 - SCISSORS: \n");
        scanf("%d", &choice);

    } while (choice < 1 || choice > 3);

    return choice;
};

void checkWinner(int userChoice, int computerChoice)
{
    if ((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2))
    {
        printf("you WIN");
    }
    else if (userChoice == computerChoice)
    {
        printf("EMPATE");
    }
    else
    {
        printf("you LOSE!");
    }
};

void guessnumber()
{

    srand(time(NULL));

    int guess = 0, tries = 0, min = 0, max = 100;

    int answer = (rand() % (max - min) + 1) + min;
    printf("*** NUMBER GUESSING GAME: ***\n");

    do
    {
        printf("Insert a number: \n");
        scanf("%d", &guess);

        if (guess == answer)
        {
            break;
        }
        else if (guess > answer)
        {
            printf("A bit too HIGH, keep going!\n");
            ++tries;
        }
        else
        {
            printf("A bit too LOW, keep going!\n");
            ++tries;
        }

    } while (guess != answer);

    printf("The answer is: %d\n", answer);
    printf("it took you %d tries", tries);
}