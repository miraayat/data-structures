#include <stdio.h>

int main(void)
{
    // insertion of an element at the end of an array

    int n, end;
    int arr[50];
    
    printf("Enter the size of array\n"); 
    scanf("%i",&n);

    printf("Enter the element of array\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    printf("Enter element to be inserted at end\n");
    scanf("%i",&end);

    arr[n] = end;

    printf("Array:\n");

    for(int i = 0; i < n+1; i++)
    {
        printf("%i ",arr[i]);
    }

    return 0;
}