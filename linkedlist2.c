//creation and traversal of linked list using fumctions
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

int main(void)
{
    int num; node *header;
    printf("Enter size of linkedlist: ");
    scanf("%i", &num);

    header = linkedlist(num);
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