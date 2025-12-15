#include <stdio.h>
//implementation of Insertion Sort

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
void sort(int arr[], int size) //Time Complexity: O(n^2)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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