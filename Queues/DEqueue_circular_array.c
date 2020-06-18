#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int front;
    int rear;
    int size;
    int *arr;
};
typedef struct Queue QUEUE;

void insert_front(QUEUE *, int);
void insert_rear(QUEUE *, int);
int delete_front(QUEUE *);
int delete_rear(QUEUE *);
void display(QUEUE *);

int main(void)
{
    QUEUE dq;
    dq.front = dq.rear = 0;
    fputs("Enter Size:\n", stdout);
    scanf("%d", &dq.size);
    dq.arr = (int *)malloc(sizeof(int) * dq.size);

    //insert_front(&dq, 1);
    insert_rear(&dq, 1);
    insert_rear(&dq, 2);
    //insert_rear(&dq, 3);
    //insert_front(&dq, 10);
    //insert_front(&dq, 9);

    delete_front(&dq);
    //delete_front(&dq);
    delete_rear(&dq);
    delete_rear(&dq);

    display(&dq);
    return 0;
}

void insert_front(QUEUE *dq, int ele)
{
    /*
    if(dq->front == 0)
    {
        fputs("Cannot Insert in Front. No space!\n", stdout);
        return;
    }
    else
    */
    {
        if((dq->rear + 1) % dq->size != dq->front)//To check full dequeue
        {
            dq->arr[dq->front] = ele;
            if(dq->front == 0)//if equal to 0, go to the end of array
            {
                dq->front = dq->size - 1;
            }
            else
                dq->front = dq->front - 1;
        }
        else
            fputs("DEQUEUE is Full!\n", stdout);
        return;
    }
}

void insert_rear(QUEUE *dq, int ele)
{
    if((dq->rear + 1) % dq->size != dq->front)//to check full dequeue
    {
        dq->rear = (dq->rear + 1) % dq->size;
        dq->arr[dq->rear] = ele;
    }
    else
        fputs("DEQUEUE is Full!\n", stdout);
    return;
}

int delete_front(QUEUE *dq)
{
    if(dq->front == dq->rear)//to check empty dequeue
    {
        fputs("DEQUEUE is Empty!\n", stdout);
        return -1;
    }
    else
    {
        dq->front = (dq->front + 1) % dq->size;
        return dq->arr[dq->front];
    }
}

int delete_rear(QUEUE *dq)
{
    if(dq->front == dq->rear)//to check empty dequeue
    {
        fputs("DEQUEUE is Empty!\n", stdout);
        return -1;
    }
    else
    {
        int deleted_item = dq->arr[dq->rear];
        if(dq->rear == 0)
            dq->rear = dq->size - 1;
        else
            dq->rear = dq->rear - 1;
        return deleted_item;
    }
}

void display(QUEUE *dq)
{
    if(dq->front == dq->rear)
        fputs("DEQUEUE is Empty!\n", stdout);
    else
    {
        int index = (dq->front + 1) % dq->size;
        while(index != dq->rear)
        {
            printf("%d ", dq->arr[index]);
            index = (index + 1) % dq->size;
        }
        printf("%d ", dq->arr[index]);
        putchar('\n');
    }
}



