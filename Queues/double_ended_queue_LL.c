#include<stdio.h>
#include<stdlib.h>
//DEQUEUE can function like a stack or a queue
struct Node
{
    struct Node *last;
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *front = NULL;
NODE *rear = NULL;

void insert_front(NODE *, int);//Adds an item at the front of Deque
void insert_rear(NODE *, int);//Adds an item at the rear of Deque
int delete_front(NODE *);// Deletes an item from front of Deque
int delete_rear(NODE *);// Deletes an item from rear of Deque
void display(NODE *);

int main(void)
{
    NODE dq;
    insert_front(&dq, 1);//should throw exception

    insert_rear(&dq, 1);
    insert_rear(&dq, 2);
    
    insert_front(&dq, 0);
    insert_front(&dq, 3);
    insert_rear(&dq, 4);
    
    display(&dq);

    delete_front(&dq);
    delete_front(&dq);

    delete_rear(&dq);

    display(&dq);
}

void insert_front(NODE *dq, int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL)
    {
        fputs("The DEQUEUE is full!\n", stdout);
    }
    else
    {
        if(front == NULL)//checking for empty or full condition in dequeue. If queue is empty inserting only from rear possible
        {
            fputs("No space to insert in the front!\n", stdout);
            return;
        }
        else
        {
            newNode->data = data;

            front->last = newNode;
            newNode->next = front;
            front = newNode;
        }
    }
}

void insert_rear(NODE *dq, int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(newNode));
    if(newNode == NULL)
    {
        fputs("DEQUEUE is Full!\n", stdout);
        return;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        if(front == NULL)//checking for empty condition in dequeue
        {
            newNode->last = NULL;
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->last = rear;
            rear = newNode;
        }
    }
}

int delete_front(NODE *dq)
{
    if(front == NULL)
    {
        fputs("The DEQUEUE is Empty!\n", stdout);
        return -1;
    }
    else
    {
        NODE *temp = front->next;
        int ele = front->data;
        free(front);
        front = temp;
        return ele;
    }
}

int delete_rear(NODE *dq)
{
    if(front == NULL)
    {
        fputs("DEQUEUE is Empty!\n", stdout);
        return -1;
    }
    else
    {
        NODE *temp = rear->last;
        int ele = rear->data;
        free(rear);
        rear = temp;
        return ele;
    }
}

void display(NODE *dq)
{
    if(front == NULL)
    {
        fputs("DQUEUE is empty!\n", stdout);
        return;
    }
    else
    {
        NODE *ptr = front;
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        putchar('\n');
    }
}
