#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *linkedlist(node *header, int size);//Creating a doubly linked list
void fwd_traversal(node *header);//display the data 
void bwd_traversal(node *header);//display the data in reverse order
void freelist(node *header);//free list
/*todo: insertion operations*/

int main(void)
{
    node *header = NULL; int size;
    printf("Enter the size of the list: ");
    scanf("%i", &size);

    header = linkedlist(header,size);
    
    fwd_traversal(header);

    bwd_traversal(header);

    freelist(header);
    header = NULL;

}

node *linkedlist(node *header, int size)
{
    for(int i = 0; i < size; i++)
    {
        node *newnode = malloc(sizeof(node));
        if(newnode == NULL)
        {
            printf("Unable to allocate memory");
            break;
        }
        printf("Enter the data in %ith node: ", i+1);
        scanf("%i",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        
        if(header == NULL)
        {
            header = newnode;
        }
        else
        {
            node *ptr = header;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
        }
    }
    return header;
}

void fwd_traversal(node *header)
{
    if (header == NULL)
    {
        printf("List is empty\n");
    }
    node *temp = header;
    printf("Data: ");
    while (temp != NULL)
    {
        printf("%i ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bwd_traversal(node *header)
{
    if (header == NULL)
    {
        printf("List is empty\n");
    }
    node *temp = header;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Data in reverese order: ");
    
    while (temp != NULL)
    {
        printf("%i ",temp->data);
        temp = temp->prev;
    }
    printf("%i\n", temp->data);
}

void freelist(node *header)
{
    node *ptr = header;
    while(header != NULL)
    {
        ptr = header;
        header = header->next;
        free(ptr);
    }
}