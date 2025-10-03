#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *linkedlist(int n);//creates linkedlist
void traversal(node *header); // traversal of linkedlist
void freelist(node *header);//returning memory malloc'd after use
void insert_beginning(node **header);//insertion of node at the start of a linkedlist
void inserton_end_list(node **header);//insert at the end of list
void insert_arb_location(node **header,int pos);//insertion at arbitary position

int main(void)
{
    int num,pos; node *header;
    printf("Enter size of linkedlist: ");
    scanf("%i", &num);

    header = linkedlist(num);
    traversal(header);

    insert_beginning(&header);
    traversal(header);

    inserton_end_list(&header);
    traversal(header);

    printf("Enter location for insertion of node: ");
    scanf("%i",&pos);
    insert_arb_location(&header, pos);
    traversal(header);

    freelist(header);
    header = NULL;

    return 0;

}

node *linkedlist(int n)
{
    node *header = NULL;
    for (int i = 0; i < n; i++ )
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("Memory not alloted!");
            break;
        }
        printf("Enter data of %ist node: ", i+1);
        scanf("%i", &newNode->data);
        newNode->next = NULL;

        if (header == NULL)
        {
            header = newNode;
        }
        else
        {
            node *ptr = header;
            while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
        }
    }
    return header;
}

void traversal(node *header)
{
    if (header == NULL)
    {
        printf("List is empty\n");
    }else{
        node *ptr = header;
        while(ptr != NULL)
        {
            printf("Data: %i\n", ptr->data);
            ptr = ptr->next;
        }
    }
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

void insert_beginning(node **header)
{
    node *newnode = malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Unable to allot memory");
        return ;
    }
    printf("Enter data to be added at beginning of list: ");
    scanf("%i", &newnode->data);

    newnode->next = *header;
    *header = newnode;
}

void inserton_end_list(node **header)
{
    node *newnode = malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory");
        return ;
    }
    printf("Enter data to be added at the end of list: ");
    scanf("%i",&newnode->data);
    newnode->next = NULL;

    node *ptr = *header;
    while (ptr->next != NULL)
    {
        ptr= ptr->next;
    }
    ptr->next = newnode;
}

void insert_arb_location(node **header,int pos)
{
    node *newnode = malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    printf("Enter the data: ");
    scanf("%i", &newnode->data);
    newnode->next = NULL;

    node *ptr = *header;
    if(pos == 1)
    {
        insert_beginning(header);
    }else
    {
        for(int i = 1; i < pos-1; i++)
        {
           if (ptr == NULL)
            {
                printf("Position out of bounds.\n");
                free(newnode);
                return;
            }
            ptr = ptr->next;
        }
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}