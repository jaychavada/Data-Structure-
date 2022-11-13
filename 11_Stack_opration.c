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
// ****************************_PUSH..OPERATION_*******************************
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack is Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
// ****************************_POP.OPERATION_*******************************
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflow! Cannot pop from the stack\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// ****************************_PEEP.OPERATION_*******************************
int peep(struct stack *sp, int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
        return sp->arr[arrayInd];
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);
    push(sp, 50);
    push(sp, 60);
    push(sp, 70);
    push(sp, 80);
    push(sp, 90);
    push(sp, 100); // stack is full
    push(sp, 110); // stack is overflow so cannot push this value in stack

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!

// this loop is for printing values from the stack
    for (int j = 1; j < sp->top + 2; j++)
    {
        printf("The value at Position %d is %d\n", j, peep(sp, j));
    }

    return 0;
}