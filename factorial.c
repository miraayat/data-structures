#include <stdio.h>

int factorial(int n);
// factorial through recursion
int main(void)
{
    int num;
    printf("Enter the number: ");
    scanf("%i", &num);
    
    if (num < 0)
    {
        printf("Invalid input");
    }
    else
    printf("Factorial of %i is %i\n", num, factorial(num));

    return 0;
}
int factorial(int n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }
    else if (n > 1)
    {
       return n * factorial(n-1);
    }
}