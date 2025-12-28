#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create_list(node *header, int n);//creating a circular linked list
void traversal(node *header);//traversal of a circular linked list
node *insertion(node *header, int pos);
/*TODO: operations*/

int main(void)
{
    node *header = NULL;int n;
    printf("Enter size of linked list: ");
    scanf("%i",&n);

    header = create_list(header, n);
    traversal(header);

    header = insertion(header, 3);
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
    printf("\n");
}

node *insertion(node *header, int pos)
{
    node *temp = header;

    node *ptr = malloc(sizeof(node));
    ptr->data = 5;
    if(pos == 1)
    {
        do
        {
            temp=temp->next;
        }while(temp->next != header);

        ptr->next = header;
        header = ptr;

        temp->next = header;
    }

    else
    {
        int i = 1;
        while( i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    return header;
}