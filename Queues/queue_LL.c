#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *front = NULL;
NODE *rear = NULL;

void enqueue(int);
int dequeue(void);
void display(void);

int main(void)
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    fputs("\nDisplaying...\n", stdout);
    display();
    return 0;
}

void enqueue(int ele)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL)//to check if heap is full
    {
        fputs("Queue is FULL!\n", stdout);
        return;
    }
    else
    {
        newNode->data = ele;
        newNode->next = NULL;
        if(front == NULL)//to check if Queue is empty
        {
            front = newNode;//setting to the first node of the queue
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int dequeue(void)
{
    if(front == NULL)//if we do (front == rear) then last node in the queue won't be dequeued
    {
        fputs("Queue is EMPTY!\n", stdout);
        return -1;
    }
    else
    {
        NODE *temp = front->next;
        int ele = front->data;
        free(front);//node at which front points to is deleted. Unlike array where front initially points
        //one position behind the item to be deleted 
        front = temp;
        return ele;
    }
}

void display(void)
{
    if(front == NULL)//when front pointer crosses rear pointer
        fputs("Queue is EMPTY!\n", stdout);
    else
    {
        NODE *start = front;
        while(start != NULL)
        {
            printf("%d ", start->data);
            start = start->next;
        }
        putchar('\n');
    }
}
