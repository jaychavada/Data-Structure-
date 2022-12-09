#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peep(int position)
{
    int top;
    struct Node *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int main()
{
    struct Node *top = NULL;
    top = push(top, 99);
    top = push(top, 98);
    top = push(top, 97);
    top = push(top, 96);
    top = push(top, 95);

    linkedlistTraversal(top);

    // int element = pop(&top);
    // printf("Popped element is %d\n", element);
    // linkedlistTraversal(top);
    for (int i = 1; i <= 5; i++)
    {
        printf("Value at position %d is : %d\n", i, peep(i));
    }

    return 0;
}