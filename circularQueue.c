#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int queue[5];

void enqueue(int data); 
void traverse(void);
void dequeue(void);
void peek(void);// to view the no of elements in the queue
int main(void)
{
    int n, data, choice, value;
    printf("Enter no. of elemnts to be inserted in queue(max 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("data: ");
        scanf("%i", &data);
        enqueue(data);
    }

    do{
    printf("\n--- Queue Menu ---\n");
    printf("1. Enqueue\n");
    printf("2. Traverse\n");
    printf("3. Dequeue\n");
    printf("4. Peek\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            traverse();
            break;
        case 3:
            dequeue();
            break; 
        case 4:
            peek();
            break;   
        case 5:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
    }
} while(choice != 5);
    return 0;

}

void enqueue(int data)
{
    if((rear + 1) % 5 == front)
    {
        printf("Queue is full\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % 5;
    }
    queue[rear] = data;
}

void traverse(void)
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else{
        int i = front;
        while(1)
        {
            printf("%d ", queue[i]);
            if(i == rear)
                break;
            i = (i + 1) % 5;
        }
    }
}
void dequeue(void)
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front == rear)
    {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % 5;
    }

}
void peek(void)
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if((rear + 1 )% 5 == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("There are %d elements in the queue\n", (rear - front + 5) % 5 + 1);
        printf("Front element: %d\n", queue[front]);
    }
}