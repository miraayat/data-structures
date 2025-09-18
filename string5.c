#include <stdio.h>

// Display a string using 
int main(void)
{
    char str[50]; char *p;
    printf("Enter a string: ");
    scanf("%s",&str);

    p = &str[0]; // by default points to first charater of an array
    
    while(*p != '\0')
    {
        printf("%c",*p);
        p++;
    }
}