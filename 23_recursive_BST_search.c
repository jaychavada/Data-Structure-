#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *n;                                 // creating node pointer
    n = (struct node *)malloc(sizeof(struct node)); // memory allocation
    n->data = data;                                 // set data
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrderTravarsal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTravarsal(root->left);
        preOrderTravarsal(root->right);
    }
}
void postOrderTravarsal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTravarsal(root->left);
        postOrderTravarsal(root->right);
        printf("%d ", root->data);
    }
}
void InOrderTravarsal(struct node *root)
{
    if (root != NULL)
    {
        InOrderTravarsal(root->left);
        printf("%d ", root->data);
        InOrderTravarsal(root->right);
    }
}

// THIS FUNCTION IS FOR CHECKING THAT THE NODES OF TREE ARE ASSCENDING OR NOT
int isBST(struct node *root)
{
    static struct node *prev = NULL; // USE OF STATIC MEANS THE VALUE OF THIS POINTER IS SAME FOR ALL INPUTS
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
        return search(root->right, key);
}

struct node *itersearch(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
            root = root->right;
    }
    return NULL;
}
int main()
{
    // constucting the root node - Using Function
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    // linking the root node with left and right child
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    // struct node *n = search(p, 6);
    struct node *n = itersearch(p, 6);
    if (n != NULL)
    {
        printf("Found : %d", n->data);
    }
    else
        printf("Element not found");

    return 0;
}

/*
                 5
              /    \
            3       6
           / \
          1   4

     FOR ASSCENDING ORDER OF ARRAU FROM TREE WE HAVE TO USE IN-ORDER TRAVARSAL IN BINARY SEARCH TREE

*/