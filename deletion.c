#include <stdio.h>

int main(void)
{
    // Deletion at the end of an array
    int n, arr[10] ;

    printf("Enter the size of array\n");
    scanf("%i",&n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    // deallocating the last value
    n--;

    printf("Array: ");

    for(int i = 0; i < n; i++)
    {
         printf("%i ",arr[i]);
    }

    return 0;
}