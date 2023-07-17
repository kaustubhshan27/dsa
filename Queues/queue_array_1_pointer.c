#include<stdio.h>

static int rear = -1;

void enqueue(int *, int);
void dequeue(int *);
void display(int *);

int main(void)
{
    int arr[5] = {0};
    enqueue(arr, 1);
    enqueue(arr, 2);
    enqueue(arr, 3);

    dequeue(arr);
    dequeue(arr);
    dequeue(arr);

    display(arr);
}

void enqueue(int *arr, int data)//O(1)
{
    if(rear == sizeof(arr)/sizeof(arr[0]) - 1)
        fputs("Queue is full!\n", stdout);
    else
    {
        rear++;
        arr[rear] = data;
    }
}

void dequeue(int *arr)//O(n)
{
    if(rear == -1)
        fputs("Queue is empty!\n", stdout);
    else
    {
        for(size_t index = 1; index <= rear; index++)
            arr[index - 1] = arr[index];
        rear--;    
    }
}

void display(int *arr)
{
    if(rear == -1)
        fputs("Queue is empty!\n", stdout);
    else
    {
        for(size_t index = 0; index <= rear; index++)
        {
            printf("%d ", arr[index]);
        }
        putchar('\n');
    }
}
