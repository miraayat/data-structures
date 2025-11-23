#include <stdio.h>

#define MAX 100

void push(int arr[], int *top, int data);
void pop(int *top);
void isEmpty(int top);
void isFull(int top, int maxSize);

int main()
{
    int top = -1;

    int stack[MAX];

    push(stack, &top, 5);
    isEmpty(top);
    isFull(top, MAX);

    // printf("%d", stack[top]);
}

void push(int arr[], int *top, int data)
{
    (*top)++;
    arr[*top] = data;
}

void isEmpty(int top)
{
    if (top == -1)
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Stack is not empty \n");
    }
}

void pop(int *top)
{
    (*top)--;
}

void isFull(int top, int maxSize)
{

    if (top == maxSize - 1)
    {
        printf("Stack is full! \n");
    }
    else
    {
        printf("Stack is not full! \n");
    }
}