// Binary representation of BINARY TREE

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
int main()
{ /*
    // root node creation
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // second node creation
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // third node creation
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;
*/
    // constucting the root node - Using Function
    struct node *p = createnode(2);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(4);
    struct node *p3 = createnode(11);
    struct node *p4 = createnode(12);
    struct node *p5 = createnode(13);
    struct node *p6 = createnode(3);

    // linking the root node with left and right child
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;
    return 0;
}

/*
                2
              /    \
            1       4
           / \     / \
         11   12  13   3
*/