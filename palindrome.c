#include <stdio.h>
#include <string.h>

//Check whether a string is palindrome or not using pointers
int main(void)
{
    char text[50];
    printf("Enter word: ");
    scanf("%s",&text);

    int length = strlen(text) - 1;

    char *s = text;
    char *t = &text[length];

    while(t > s)
    {
        if(*t != *s)
        {
            printf("Not a palindrome\n");
            return 1;
        }
        s++;
        t--;
    }
    printf("Is a palindrome\n");
    return 0;
}