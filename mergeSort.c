#include <stdio.h>

// implementation of merge 
// Time complexity: O(nlogn)
void sort(int arr[], int l, int r);
void print(int arr[], int size);
int main(void)
{
    int arr[] = {20, 40, 60, 30, 25, 80, 75};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, 0, size - 1);
    print(arr, size);
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int a1[n1], a2[n2];

    for (int i = 0; i < n1; i++)
        a1[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        a2[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            arr[k++] = a1[i++];
        else
            arr[k++] = a2[j++];
    }

    while (i < n1)
        arr[k++] = a1[i++];

    while (j < n2)
        arr[k++] = a2[j++];
}

void sort(int arr[], int l, int r)
{
    if (l >= r)
        return;   

    int m = l + (r - l) / 2;

    sort(arr, l, m);
    sort(arr, m + 1, r);
    merge(arr, l, m, r);
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