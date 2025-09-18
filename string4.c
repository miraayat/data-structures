#include <stdio.h>
#include <string.h>

//display a string in reverse order using string library
int main(void)
{
    char *s = "reverse";
    for(int i = strlen(s)-1; i >= 0; i--)
    {
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}