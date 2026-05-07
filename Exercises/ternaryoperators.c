#include <stdio.h>

int main()
{

    int age = 16;
    int x = 1, y = 3;
    int max = x > y ? x : y;
    int isOnline = 1;
    int hours = 13;
    int minutes = 30;
    char *meridiem = (hours < 12) ? "AM" : "PM";

    printf("%s\n", (age > 18) ? "adult" : "child");
    printf("%d\n", max);
    printf("%s\n",  (isOnline == 1) ? "online" : "offline");
    printf("%02d:%02d %s",hours, minutes,meridiem );
    return 0;
}

