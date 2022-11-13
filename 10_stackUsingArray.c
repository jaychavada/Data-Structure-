#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) 
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else 
        return 0;  
}

int main()
{
    // struct stack s;
    //     s.size = 80;
    //     s.top = -1;
    //     s.arr = (int *) malloc(s.size * sizeof (int));

    // s as a pointer
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing an element manually
    s->arr[0] = 5;
    s->arr[1] = 55;
    s->top++;

    // check if stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty");
    }
    else
        printf("The stack is not empty");
    return 0;
}