#include <stdbool.h>
#include <stdio.h>

//implementation of Selection Sort

void swap(int *x, int *y);
void sort(int arr[], int size);
void print(int arr[], int size);
int main(void)
{
    int arr[] = {20, 40, 60, 30, 25, 80, 75};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    print(arr, size);
    return 0;
}

void sort(int arr[], int size)// Time complexity: O(n^2)
{
    for(int j = 0; j < size; j++)
    {
       int min_indx = j;
       for(int i = j + 1; i < size; i++)
       {
          if(arr[min_indx] > arr[i])
          min_indx = i;
          swap(&arr[j], &arr[min_indx]);
       }
    }   
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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