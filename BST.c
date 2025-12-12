#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int data;
    struct treenode *right;
    struct treenode *left;
}treenode;

treenode *firstNode(int value);
treenode* insert(treenode *root, int value);
void traversalInOrder(treenode *root);
void preOrderTraversal(treenode *root);
void postOrderTraversal(treenode *root);
bool binarySearch(treenode *root, int value);

int main(void)
{
    treenode *root = NULL;
    root = firstNode(50);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    printf("In Order Travesal: ");
    traversalInOrder(root);
    printf("\nPre Order Traversal: ");
    preOrderTraversal(root);
    printf("\nPost Order Traversal: ");
    postOrderTraversal(root);
    printf("\nis 30 in the tree? %s", binarySearch(root, 30) ? "yes" : "no");
}
treenode *firstNode(int value)
{
    treenode *newnode = malloc(sizeof(treenode));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory!");
        exit(1);
    }
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = value;
    return newnode;
}
treenode* insert(treenode *root, int value) 
{
    if (root == NULL) {
        return firstNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}


void traversalInOrder(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        traversalInOrder(root->left);
        printf(" %d ",root->data);
        traversalInOrder(root->right);
    }
}
void preOrderTraversal(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(treenode *root)
{
    if(root == NULL)
    return ;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" %d ", root->data);
}

bool binarySearch(treenode *root, int value)
{
    if(root == NULL)
    {
        return false;
    }
    else if(value > root->data)
     return binarySearch(root->right, value);
    else if (value < root->data)
    return binarySearch(root->left, value);
    else
    {
        return true;
    }
}