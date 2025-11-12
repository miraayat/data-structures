#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *linkedlist (node * header, int n);//create linkedlist
void traversal(node *header);//traversal
void freelist(node *header);//free linkedlist

int main(void)
{
    node *header = NULL;int n;
    printf("Enter the size of linkedlist: ");
    scanf("%i",&n);

    header = linkedlist(header, n);
    traversal(header);

    freelist(header);
}
node *linkedlist (node * header, int n)
{
    for(int i = 0; i < n; i++)
    {
        node *newnode = malloc(sizeof(node));
        if(newnode == NULL)
        {
            printf("Unable to allocate memory!");
            break;
        }else{
            printf("Enter data: ");
            scanf("%d", &newnode->data);
            newnode->next = header;

            header = newnode;
        }
    }
    return header;
}
void traversal(node *header)
{
    if(header == NULL)
    {
        printf("list is empty!");
        return;
    }
    node *ptr = header;
    printf("Data: ");
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void freelist(node *header)
{
    node *ptr = header;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        free(header);
        header = ptr; 
    }
}