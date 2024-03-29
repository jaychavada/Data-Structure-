// INSERTION & ROTATION (LL,RR,LR,RL ROTATION)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int HeightOfTree(struct Node *n)
{
    if (n == NULL)
        return 0;
    else
        return n->height;
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int BalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return HeightOfTree(n->left) - HeightOfTree(n->right);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(HeightOfTree(x->right), HeightOfTree(x->left)) + 1;
    y->height = max(HeightOfTree(y->right), HeightOfTree(y->left)) + 1;

    return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(HeightOfTree(x->right), HeightOfTree(x->left)) + 1;
    y->height = max(HeightOfTree(y->right), HeightOfTree(y->left)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return (createNode(key));
    }
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
    node->height = 1 + max(HeightOfTree(node->left), HeightOfTree(node->right));

    int BF = BalanceFactor(node);

    // left left case:
    if (BF > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // right right case:
    if (BF < -1 && key > node->left->key)
    {
        return leftRotate(node);
    }
    // left right case:
    if (BF > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right left case:
    if (BF < -1 && key > node->left->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrderTraversal(root);
    return 0;
}
