#include <stdio.h>

// Display a string using pointers
int main(void)
{
    char str[50]; char *p;
    printf("Enter a string: ");
    scanf("%s",&str);

    p = &str[0]; 
    
    while(*p != '\0')
    {
        printf("%c",*p);
        p++;
    }
}
