#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node *right;
}node;

node *create( int value);// create node
node *createTree (int index, int arr[], int size);//creates complete tree
void traversal_inOrder(node *root); 
void max_heap(node *root);//makes the tree into a max heap
void swap(node *a, node *b);
void heapify(node *root);
void heapSort(node *root);//heap sort

int main()
{
    int arr[] = {4, 5, 3, 9, 7, 15, 21, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    node *root = createTree(0, arr, size);
    max_heap(root);
    
    heapSort(root);
}
node *create( int value)
{
    node *newnode = malloc(sizeof(node));
    if(newnode == NULL)
    exit(1);

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void traversal_inOrder(node *root)
{
    if(root == NULL)
    {
        return;
    }

    traversal_inOrder(root->left);
    printf(" %d ", root->data);
    traversal_inOrder(root->right);
}

node *createTree (int index, int arr[], int size)
{
    if(index >= size)
    {
        return NULL;
    }
    node *root = create(arr[index]);

    root->left = createTree(2*index + 1 , arr, size);
    root->right = createTree(2*index + 2, arr, size);

    return root;
}

void heapify(node *root)
{
    if(root == NULL)
    {
        return;
    }
    
    node *largest = root;

    if(root->left && root->left->data > largest->data)
    largest = root->left;

    if(root->right && root->right->data > largest->data)
    largest = root->right;

    if (largest != root)
    {
        swap(root, largest);
        heapify(largest);
    }
}

void swap(node *a, node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void max_heap(node *root)
{
    if (root == NULL)
    return;

    max_heap(root->left);
    max_heap(root->right);

    heapify(root);
}
/*code for heap sort*/