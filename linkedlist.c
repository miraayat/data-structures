#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void copy(node *header);//Display a linked list in reverese order

int main(void)
{
    node *header = NULL;  //creation and traversal of a linked list

    for(int i = 0; i < 3; i++)
    {
        node *newNode = malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%i",&newNode->data);

        newNode-> next = NULL;

        if(header == NULL)
        {
            header = newNode; //first node
        }else 
        { // when list already has nodes
            for(node *tmp = header; tmp != NULL; tmp = tmp->next)
            {
                if(tmp->next == NULL)
                {
                    tmp->next = newNode;
                    break;
                }
            }
        }
    }
    printf("Data: ");
    for(node *tmp = header; tmp != NULL; tmp = tmp->next)
    {
        printf("%i ",tmp->data);
    }printf("\n");

    printf("List in reverse order: ");
    copy(header);
    
    return 0;
}
void copy(node *header)
{
    int arr[3],i = 0;
    node *ptr = header;
    while(ptr != NULL)
    {
        arr[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }

    for(i = 3; i >0; i--)
    {
        printf("%i ", arr[i-1]);
    }
}