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
void insertion(node **header);//insertion at any location
void deletion(node **header);//deletion from any location
int length(node *header);//calculate length of linkedlist

int main(void)
{
    node *header = NULL; int size;
    printf("Enter the size of the list: ");
    scanf("%i", &size);

    header = linkedlist(header,size);
    
    fwd_traversal(header);

    bwd_traversal(header);

    insertion(&header);

    deletion(&header);

    length(header);

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
        printf("Enter the data in node %i: ", i+1);
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
        return;
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
        return;
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
    } printf("\n");
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

void insertion(node **header)
{
    int pos; 

    node *newnode = malloc(sizeof(node));
    if(newnode == NULL)
    { 
        printf("Unable to allocate memory");
        return;
    }
    else
    {
        printf("Enter the position of the newnode: ");
        scanf("%i", &pos);
        printf("Enter data into the new node: " );
        scanf("%i",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    
    node *ptr = *header;

    if (pos == 1) /*insertion at beginning*/
    {
        *header = newnode;
        newnode->next = ptr;
        if(ptr != NULL)
        ptr->prev = newnode;
    }
    else // insertion at any position or at last
    {
        for(int i = 1; i < pos-1 && ptr != NULL; i++)
        {
            ptr = ptr->next;
        }
        
        if (ptr == NULL)
        {
            printf("Position out of bounds\n");
            free(newnode);
            return;
        }

        newnode->next = ptr->next;//if at end ptr->next points to null
        if(ptr->next != NULL)
        ptr->next->prev = newnode;
        ptr->next = newnode;
        newnode->prev  = ptr;
    }
    fwd_traversal(*header);//display list
}

void deletion (node **header)
{
    int pos;

    printf("Enter the node to be deleted: ");
    scanf("%i",&pos);

    if(*header == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    node *temp = *header;
    node *next = *header;

    if(pos == 1)
    {
        temp = temp->next;
        if(temp != NULL)
        temp->prev = NULL;
        free(*header);
        *header = temp;
    }
    else{
        for(int i = 1; i < pos-1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        for(int i = 1; i < pos && next != NULL; i++)
        {
            next = next->next;
        }
        if(temp == NULL || next == NULL)
        {
            printf("Position out of bounds!!");
            return;
        }
        temp->next = next->next;
        if(next->next != NULL)
        {
            next->next->prev = temp;
        }
        free(next);
    }
    fwd_traversal(*header);
}
int length(node *header)
{
    node * temp = header;

    if(header == NULL){
        printf("length is: 0");
        return 1;
    }

    int count = 1;

    for(int i = 0; temp->next != NULL; temp = temp->next)
    {
        count++;
    }
    printf("length of linkedlist: %i", count);
}