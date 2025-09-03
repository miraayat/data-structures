#include <stdio.h>

int main(void)
{
    //insertion at the beginning of an array

    int n, begin;
    int arr[50];
    
    printf("Enter the size of array\n"); 
    scanf("%i",&n);

    printf("Enter the element of array\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    printf("Enter the element to be inserted at the beginning of array\n");
    scanf("%i",&begin);

    //shifting elemnts to the right
    for(int i = n+1; i >= 0; i-- )
    {
        arr[i+1] = arr[i];
    } 
    
    arr[0] = begin;

    // displaying array
    for (int i = 0; i <= n; i++)
    {
        printf("%i ",arr[i]);
    }

    return 0;
}