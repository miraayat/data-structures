#include <stdbool.h>
#include <stdio.h>

//implementation of bubble sort

void swap(int *x, int *y);
void bubblesort(int arr[], int n);
void print(int arr[], int size);
int main(void)
{
    int arr[] = {20, 40, 60, 30, 25, 80, 75};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, size);
    print(arr, size);
    return 0;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubblesort(int arr[], int n)/*Time complexity : O(n^2)*/
{
    bool swapped;
    for(int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
               swap(&arr[j], &arr[j+1]);
               swapped = true;
            }
        }
        if(swapped == false)
        break;
    }
}
void print(int arr[], int size)
{
    printf("Sorted Array: ");
    for(int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}