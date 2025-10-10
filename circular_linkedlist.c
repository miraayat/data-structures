#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create_list(node *header, int n);//creating a circular linked list
void traversal(node *header);//traversal of a circular linked list
/*TODO: operations*/

int main(void)
{
    node *header = NULL;int n;
    printf("Enter size of linked list: ");
    scanf("%i",&n);

    header = create_list(header, n);
    traversal(header);
}

node *create_list(node *header, int n)
{
    for(int i = 0; i < n; i++)
    {
        node *newnode = malloc(sizeof(node));
        if(newnode == NULL)
        {
            printf("Unable to allocate memory!");
            break;
        }
        printf("Enter the data in node %i: ", i+1);
        scanf("%i",&newnode->data);
        newnode->next = NULL;

        if(header == NULL)
        {
            header = newnode;
        }else{

        node *temp = header;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    }
    node *temp = header;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = header;
    return header;
}

void traversal(node *header)
{
    if(header == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node *temp = header;

    printf("Data: ");
    do
    {
        printf("%i ",temp->data);
        temp = temp->next;
    }while(temp != header);
}