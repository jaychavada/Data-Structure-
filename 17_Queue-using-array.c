#include<stdio.h>
#include<stdlib.h>

struct queue 
{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct queue *q ){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *q ){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

//-------------------------Enqueue Function-------------------------
void enqueue(struct queue *q , int val){
    if (isFull(q))
    {
        printf("This Queue is overflow or is Full");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
    }
    
}
//-------------------------Dequeue Function-------------------------
int dequeue(struct queue *q ){
    int a=-1;
    if (isEmpty(q))
    {
        printf("This Queue is overflow or is Full");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
    
}
int main()
{
     struct queue q;
     q.size = 100;
     q.f = q.r = -1;
     q.arr = (int *) malloc(q.size * sizeof(int));

     //Enqueue Few elements
    enqueue(&q,05);
    enqueue(&q,03);
    enqueue(&q,20);

    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

     if (isEmpty(&q))
     {
        printf("Queue is Empty\n");
     }
     
      if (isFull(&q))
     {
        printf("Queue is Full\n");//not full cause only two elements added
     }
     
return 0;
}