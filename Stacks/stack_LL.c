#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE* top = NULL;

void push(int);
int pop(void);
int peek(int);

int main(void)
{
    push(1);
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", peek(3));
    printf("%d\n", peek(1));
    printf("%d\n", peek(2));
    return 0;
}

void push(int ele)
{
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(newNode));
    if(newNode != NULL)//if heap becomes full newNode == NULL
    {
        newNode->data = ele;
        if(top == NULL)
        {
            newNode->next = NULL;
            top = newNode;
        }
        else
        {
            newNode->next = top;//Growing the stack from the 1st node in the linked list
            top = newNode;
        }
    }
    else
        fputs("STACK OVERFLOW!!\n", stdout);
    
}

int pop(void)
{
    int ele;
    if(top != NULL)
    {
        NODE *temp;
        ele = top->data;//storing top data before freeing it from heap
        temp = top->next;
        free(top);//freeing up the popped node in the stack from heap
        top = temp;   
        return ele;
    }
    else
    {
        fputs("STACK UNDERFLOW!!\n", stdin);
        return -1;
    }
}

int peek(int pos)
{
    NODE *temp = top;
    for(size_t count = 1; count < pos && temp != NULL; count++)
        temp = temp->next;
    if(temp != NULL)
        return temp->data;
    else
    {
        fputs("Invalid position!\n", stdout);
        return -1;
    }
}