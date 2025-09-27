#include <stdio.h>
#include <stdlib.h>

//creation and traversal of a linked list
typedef struct node
{
    int data;
    struct node *next;
}node;
int main(void)
{
    node *header = NULL;

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
    for(node *tmp = header; tmp != NULL; tmp = tmp->next)
    {
        printf("%i ",tmp->data);
    }
    
    return 0;
}