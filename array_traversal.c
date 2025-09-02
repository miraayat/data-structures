#include <stdio.h>

int main(void)
{
    // program to traverse an integer array

    int n;
    int arr[50];
    
    printf("Enter the size of array\n"); 
    scanf("%i",&n);

    printf("Enter the element of array\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    printf("Array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%i ",arr[i]);
    }

    return 0;


}