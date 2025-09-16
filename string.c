#include <stdio.h>

// Display a string
int main(void)
{
    char string [30];
    printf("Enter a string\n");
    scanf("%s",&string);

    printf("String: ");

    for(int i = 0; string[i] != '\0'; i++)
    {
        printf("%c",string[i]);
    }
    return 0;
}