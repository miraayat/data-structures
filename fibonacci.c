#include <stdio.h>

int fibonacci (int n);
/* Calculating the fibonacci series and its nth term through recursion function */
int main(void)
{
    int num; 
    printf("Enter the number: ");
    scanf("%i", &num);

    printf("finonacci series upto %i terms: ");
    for(int i = 0; i < num; i++)
    {
        printf("%i ", fibonacci(i));
    }
    printf("\n");
    printf("%ith term  is %i\n",num, fibonacci(num));
}
int fibonacci (int n)
{
    if (n <= 1)
    {
        return n;
    }else{
       return fibonacci(n - 1)  + fibonacci(n - 2);
    }
}