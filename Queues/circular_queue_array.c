#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front; 
    int rear;
    int *arr;
};
typedef struct Queue QUEUE;

//there is always one empty space in the array
void enqueue(QUEUE *, int);
int dequeue(QUEUE *); 
void display(QUEUE *);

int main(void)
{
    QUEUE qu;
    qu.front = 0;
    qu.rear = 0;
    fputs("Enter the size of the array:\n", stdout);
    scanf("%d", &qu.size);
    qu.arr = (int *)malloc(qu.size*sizeof(int));
    enqueue(&qu, 1);
    enqueue(&qu, 2);
    enqueue(&qu, 3);
    dequeue(&qu);
    dequeue(&qu);
    fputs("\nDisplaying Queue:\n", stdout);
    display(&qu);
    return 0;
}

void enqueue(QUEUE *qu, int data)
{
    if(qu->front == (qu->rear + 1) % qu->size)//the array index where front points to is always empty 
        fputs("Queue is FULL!\n", stdout);
    else
    {
        qu->rear = (qu->rear + 1) % qu->size;
        qu->arr[qu->rear] = data;   
    }
}

int dequeue(QUEUE *qu)
{
    if(qu->rear == qu->front)
    {
        fputs("\nQueue is EMPTY!\n", stdout);
    }
    else
    {
        qu->front = (qu->front + 1) % qu->size;
        return qu->arr[qu->front];
    }
}

void display(QUEUE *qu)
{
    if(qu->rear == qu->front)
        fputs("Queue is EMPTY!\n", stdout);
    else
    {
        size_t index = qu->front + 1;
        while(index != qu->rear)// (index <= qu->rear) will not work in some cases because at the time of displaying front can be at a greater index than rear pointer
        {
            printf("%d ", qu->arr[index]);
            index = (index + 1) % qu->size;
        }
        printf("%d ", qu->arr[index]);
        putchar('\n');
    }
}