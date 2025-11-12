#include <stdio.h>
#include <string.h>

void f(char *p)
{
    if(*p != 0){
        printf("%c", *p);
        f(p + 1);
    }
    printf("%c", *p);
}
int main(void)
{
    char s[5] = "GATE";
    f(s);
    return 0;
}