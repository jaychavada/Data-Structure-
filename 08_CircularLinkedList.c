#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *head)
{
    // struct Node *ptr = head;
    // printf("Element is : %d\n", ptr->data);
    // ptr = ptr->next;
    // while (ptr != head)
    // {
    //     printf("Element is : %d\n", ptr->data);
    //     ptr = ptr->next;
    // }

    // for clear traversal we will use DO...WHILE loop
    struct Node *ptr = head;
    do
    {
        printf("Element is : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 01;
    head->next = second;

    // link second and third nodes
    second->data = 05;
    second->next = third;

    // link third and fourth nodes
    third->data = 03;
    third->next = fourth;

    // link last node with head
    fourth->data = 15;
    fourth->next = head;

    linkedlistTraversal(head);

    return 0;
}