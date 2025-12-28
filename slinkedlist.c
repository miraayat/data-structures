#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *creation(node *head, int size);
void traversal(node *head);
node *insertion(node *head, int pos);
node *deletion(node *head, int pos);
int search(node *head, int key);
int countnodes(node *head);
node *reverse(node *head, int count);

int main(void)
{
    node *head = NULL;
    head = creation(head, 3);
    head = insertion(head, 2);
    traversal(head);

    head = deletion(head, 4);
    traversal(head);

    printf("Found at position: %d\n", search(head, 2));

    int c = countnodes(head);
    printf("%d nodes", c);

    reverse(head, c);

}

node *creation(node *head, int size)
{
    for(int i = 0; i < size; i++)
    {
        node *newnode = malloc(sizeof(node));
        if(newnode == NULL)
        {
            break;
        }
        printf("Enter data into node: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
    return head;
}

void traversal(node *head)
{
    if(head == NULL)
    {
        return;
    }
    node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

node *insertion(node *head, int pos)
{
    node *ptr = NULL;
    printf("---ADDING NODE-----\n");
    ptr = creation(ptr, 1);
    node *temp = head;

    if(pos == 1)
    {
        ptr->next = temp;
        head = ptr;
    }
    else
    {
        int i = 1;
        while(i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }

    return head;
    
}

node *deletion(node *head, int pos)
{
    node *temp = head;
    printf("\n----DELETING NODE------\n");

    if(pos == 1)
    {
        head = head->next;
    }
    else
    {
        int i = 1;
        while(i < pos-1)
        {
            temp = temp->next;
            if(temp == NULL || temp->next == NULL)
            {
                printf("out of bounds!");
                break;
            }
            i++;
        }
        temp->next = temp->next->next;
    }
    
    
    return head;
}

int search(node *head, int key)
{
    int pos = 0;
    node *temp = head;

    printf("\nSEARCHING...\n");

    while(temp != NULL)
    {
        pos++;
        if(temp->data == key)
        {
            return pos;
        }
        temp = temp->next;
    }
    return -1;
}

int countnodes(node *head)
{
    int count = 0;
    node *temp = head;

    printf("\nCOUNTING...\n");
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    free(temp);
    return count;
}

node *reverse(node *head, int count)
{
    int arr[count];
    node *temp = head;

    printf("\n---REVERSING LIST----");
    int i = 0;
    while(temp != NULL)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    printf("\n");
    for(int i = count - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }

}