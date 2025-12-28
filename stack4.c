#include <stdio.h>
#include <stdlib.h>

#define MAX = 10
typedef struct stack
{
    int top; 
    int size;
    int *arr;
}stack;

void create(stack *stack)
{
    stack->top = -1;
    stack->size = 4;
    stack->arr = malloc(stack->size*(sizeof(int)));
    printf("-----stack created------\n");
}

int isEmpty(stack *stack)
{
    return stack->top == -1;
}

int isFull(stack *stack)
{
    return stack->top == stack->size - 1;
}

void push(stack *stack, int data)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = data;
}

int pop(stack *stack)
{
    if(isEmpty(stack))
    {
        printf("stack is empty\n");
        return -1;
    }
    int ele = stack->arr[stack->top--];

    return ele;
}

int peek(stack *stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    int ele = stack->arr[stack->top];
    return ele;
}

void display(stack *stack)
{
    printf("stack top-bottom\n");
    for(int i = stack->top; i >= 0; i--)
    {
        printf("| %d |\n", stack->arr[i]);
    }
}

int main()
{
    stack *stack = malloc(sizeof(stack));
    create(stack);

    if(isEmpty(stack))
    {
        printf("stack is empty\n");
    }else
    printf("stack is not empty\n");

    if(isFull(stack))
    {
        printf("stack is full\n");
    }else
    printf("stack is not full\n");

    push(stack, 1);
    push(stack, 2);
    int x = pop(stack);
    printf("popped element: %d\n", x );
    push(stack, 3);
    push(stack, 4);
    printf("Element on top: %d\n", peek(stack));
    display(stack);
    printf("-------------------\n");

}