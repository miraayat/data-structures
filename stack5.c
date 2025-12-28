#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct stack
{
    node *top;
}stack;

void innitStack(stack *stack)
{
    stack->top = NULL;
}

int isEmpty(stack *stack)
{
    return stack->top == NULL;
}

void push(stack *stack, int data)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = stack->top;
    stack->top = newnode;
}

int pop(stack *stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    int ele = stack->top->data;
    stack->top = stack->top->next;
    return ele;
}

void display(stack *stack)
{
    node *ptr = stack->top;
    while(ptr != NULL)
    {
        printf("| %d |\n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    stack *stack = malloc(sizeof(stack));
    innitStack(stack);

    if(isEmpty(stack))
    {
        printf("Stack is empty!\n");
    }else
    {
        printf("not empty!\n");
    }
    push(stack, 1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    display(stack);

    printf("-----pop-------\n");
    printf("%d ", pop(stack));

    printf("\n=====================\n");
    display(stack);
    printf("\n=====================\n");

}
