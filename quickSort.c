#include <stdio.h>
// implementation of quick sort using lomuto partitioning scheme 
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int* partition(int *low, int *high)
{
    int pivot = *high;
    int *i = low;

    for (int *j = low; j < high; j++)
    {
        if (*j <= pivot)
        {
            swap(j, i);
            i++;
        }
    }

    swap(i, high);
    return i;   
}

void quicksort(int *low, int *high)
{
    if (low < high)
    {
        int *p = partition(low, high);

        quicksort(low, p - 1);   
        quicksort(p + 1, high);  
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {20, 40, 60, 30, 25, 80, 75};
    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, arr + size - 1);
    print(arr, size);
}

