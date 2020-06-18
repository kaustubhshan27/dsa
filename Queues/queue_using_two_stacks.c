#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *head1 = NULL;
NODE *head2 = NULL;

void enqueue(int);
int dequeue();
void push(NODE **, int);
int pop(NODE **);

int main(void)
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    printf("%d ", dequeue());
    printf("%d ", dequeue());
}

void push(NODE **stack_head, int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL)
    {
        fputs("Stack is FULL!\n", stdout);
        return;
    }
    else
    {
        newNode->data = data;
        if(*stack_head == NULL)
        {
            newNode->next = NULL;
            *stack_head = newNode;
        }
        else
        {
            newNode->next = *stack_head;
            *stack_head = newNode;
        }
    }
}

int pop(NODE **stack_head)
{
    if(*stack_head == NULL)
    {
        fputs("Stack is Empty!\n", stdout);
        return -1;
    }
    else
    {
        int ele = (*stack_head)->data;
        NODE *temp = (*stack_head)->next;
        free(*stack_head);
        *stack_head = temp;
        return ele;
    }
}

void enqueue(int data)
{
    push(&head1, data);
}

int dequeue(void)
{
    if(head2 == NULL)
    {
        if(head1 == NULL)
        {
            fputs("Queue is EMPTY!\n", stdout);
            return -1;
        }
        else
        {
            while(head1 != NULL)
                push(&head2, pop(&head1));
        }
    }
    return pop(&head2);
}