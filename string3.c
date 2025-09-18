#include <stdio.h>
#include <string.h>

// calculating length of a string using strlen function
int main(void)
{
    char str[50];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("%i\n",strlen(str));
}