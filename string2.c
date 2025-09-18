#include <stdio.h>
#include <string.h>

//Finding the length of a string without the use of strlen function

int main(void)
{
    char str[50];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && str[i] != '\t')
        count++;
    }

    printf("The length of string: %i",count);
}