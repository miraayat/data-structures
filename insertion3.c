#include <stdio.h>

int main(void)
{
    //insertion at any location
    int arr[10], n, ele, pos;
    printf("Enter the no of elements in array\n");
    scanf("%i", &n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%i",&arr[i]);
    }
    
    printf("Enter the element to be inserted\n");
    scanf("%i",&ele);

    printf("Enter the location at which the elemnt is to be inserted\n");
    scanf("%i",&pos);

    //shifting elements from the given location to the right
    for(int i = n-1; i >= pos-1; i-- )
    {
        arr[i+1]= arr[i];
    }
    arr[pos-1] = ele;

    printf("ARRAY:\n");
    
    for(int i = 0; i <=n; i++)
    {
        printf("%i ", arr[i]);
    }
    return 0;
}