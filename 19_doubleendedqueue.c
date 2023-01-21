#include <stdio.h>
#include <stdlib.h>
//first in first out
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isfull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueueR(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("this queue is full");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}
int enqueueF(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("this queue is full");
    }
    else
    {
        q->rear--;
        val=q->arr[q->rear];
        return val;
    }
}

int dequeueF(struct queue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("this queue is empty");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
        return a;
    }
}
int main()
{
    struct queue q;
    q.size = 5;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    // if(isempty(&q)){
    //     printf("queue is empty");
    // }
    enqueueR(&q, 42);
    enqueueR(&q, 52);
    enqueueR(&q, 62);
    enqueueR(&q, 72);
    // enqueueF(&q, 82);
    // enqueueF(&q, 92);
    // enqueueF(&q, 102);
    printf("DEQUEUED ELEMENT IS %d\n",dequeueF(&q));
    printf("DEQUEUED ELEMENT IS %d\n",dequeueF(&q));
    printf("DEQUEUED ELEMENT IS %d\n",dequeueF(&q));

    if (isfull(&q))
    {
        printf("queue is full");
    }
    return 0;
}