
#include <stdio.h>

int main()
{
    char card[16] = "1234567890123456";

    for (int i = 0; card[i] != '\0'; i++)
    {

        if (i < 12)
        {
            printf("*");
        }
        else
        {
            printf("%c", card[i]);
        }
    }
}
