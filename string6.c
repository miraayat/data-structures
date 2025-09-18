#include <stdio.h>

// Finding length of a string using pointers
int main(void)
{
    char str[50]; char *p; int count = 0;
    printf("Enter a string: ");
    scanf("%s",&str);

    p = &str[0];

    while(*p != '\0')
    {
        count++;
        p++;
    }

    printf("Length of string:%i",count);
}