#include <stdio.h>
int main(void)
{
    int arr[5];
    int ele; int flag = 0;
    int length = sizeof(arr)/sizeof(int);

    printf("Enter 5 elements int the array: ");
    for(int i = 0; i < length; i++)
    {
        scanf("%i", &arr[i]);
    }

    printf("Enter the element you are looking for: ");
    scanf("%i", &ele);

    for(int i = 0; i < length; i++)
    {
        if(arr[i] == ele)
        {
            printf("Found at %i!!", i+1);
            flag = 1;
            return 1;
        }
    }

    if(flag == 0)
    {
        printf("Not found!!");
    }
    
}