// travarsal in TREE : pre-order travarsal : root -> left subtree -> right subtree
//   : post-order travarsal : left subtree -> right subtree -> root
//   : in-order travarsal : left subtree -> root -> right subtree

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
};
void postOrderTravarsal(struct node *root){
    if(root != NULL){
        postOrderTravarsal(root->left);
        postOrderTravarsal(root->right);
        printf("%d ", root->data);
    }
};
void InOrderTravarsal(struct node *root){
    if(root != NULL){
        InOrderTravarsal(root->left);
        printf("%d ", root->data);
        InOrderTravarsal(root->right);
    }
}
int main()
{ // constucting the root node - Using Function
    struct node *p = createnode(2);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(4);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(6);
    struct node *p5 = createnode(9);
    struct node *p6 = createnode(3);

    // linking the root node with left and right child
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;


    p2->left = p5;
    p2->right = p6;

    // preOrderTravarsal(p);
    // postOrderTravarsal(p);
    InOrderTravarsal(p);
    return 0;
}

/*
                 2
              /    \
            1       4
           / \     / \
         5   6    9   3
*/