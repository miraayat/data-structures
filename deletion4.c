#include <stdio.h>

int main(void)
{
    // deletion of any value fom an int array
    int n, val, pos, flag = 0;
    int arr[50];
    
    printf("Enter the size of array\n"); 
    scanf("%i", &n);

    printf("Enter the element of array\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }
    
    printf("Enter the value to be deleted\n");
    scanf("%i",&val);

    //implementing linear search to find the location of the said element
    for(int i = 0; i < n; i++)
    {
        if(val == arr[i])
        {
             pos = i;
             flag = 1;
             break;
        } 
    }
    if (flag == 0)
    {
        printf("Invalid input");
        return 1;
    }

    //shifting elements to the left
    for(int i = pos; i < n; i++)
    {
       arr[i] = arr[i+1];
    } n--;

    printf("Array:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%i ",arr[i]);
    }

    return 0;
}