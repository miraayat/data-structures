#include <stdio.h>

int main(void)
{
    //Deletion from the beginning of an int array
        int n;
    int arr[50];
    
    printf("Enter the size of array\n"); 
    scanf("%i", &n);

    printf("Enter the element of array\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    //shifting array to the left
    for(int i = 1; i < n; i++)
    {
        arr[i-1] = arr[i];
    }
    n--;

    printf("Array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%i ",arr[i]);
    }

    return 0;
}