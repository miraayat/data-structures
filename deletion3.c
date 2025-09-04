#include <stdio.h>

int main(void)
{
    // Deletion from any location
        int n;
    int arr[20] , pos;
    
    printf("Enter the size of array\n"); 
    scanf("%i", &n);

    printf("Enter the element of array\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    printf("Enter the location to be deleted\n");//indexed at 1 for user
    scanf("%i", &pos);

    // shifting array to the left to fill the deleted location
    for(int i = pos-1; i < n; i++)
    {
        arr[i] = arr[i+1];
    }n--;

    printf("Array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%i ",arr[i]);
    }

    return 0;
}