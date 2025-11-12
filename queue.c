#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
}queue;

queue *createqueue (queue *head, int size);//creating fifo structure
void traversal(queue *head); //traversal of queue
/* functions same as linkedlist*/
int main(void)
{
    queue *head = NULL;
    int size;

    printf("Enter the size of queue: ");
    scanf("%i",&size);

    head = createqueue(head,size);

   traversal(head);

}

queue *createqueue (queue *head, int size)
{
    for(int i = 0; i < size; i++)
    {
        queue *newqueue = malloc(sizeof(queue));
        if (newqueue == NULL)
        {
            printf("Unable to allocate memory");
            break;
        }
        else
        {
            printf("Enter data: ");
            scanf("%i", &newqueue->data);
            newqueue->next = NULL;
        }
        if(head == NULL)
        {
            head = newqueue;
        }else
        {
            queue *ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }ptr->next = newqueue;
        }
    }
    return head;
}

void traversal(queue *head)
{
    if(head == NULL)
    return;

    queue *ptr = head;
    while(ptr != NULL)
    {
        printf("%i ",ptr->data);
        ptr = ptr->next;
    }
}
