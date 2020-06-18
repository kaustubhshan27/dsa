#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *head = NULL;
NODE *prev = NULL;

void createCLL(void);
void reverseCLL(void);//reverse using sliding pointers
void displayCLL(void);

int main(void)
{
    fputs("Creating a circular linked list...\n", stdout);
    createCLL();
    fputs("Reversing the circular linked list...\n", stdout);
    reverseCLL();
    fputs("Displaying circular linked list...\n", stdout);
    displayCLL();
}

void createCLL(void)
{
    char ch;
    fputs("Enter 'y' to continue or 'n' to QUIT: ", stdout);
    while(scanf("%c", &ch) && ch != 'n')
    {
        NODE *newNode;
        newNode = (NODE *)malloc(sizeof(NODE));
        fputs("Enter the data: ", stdout);
        int ele;
        scanf("%d", &ele);
        newNode->data = ele;

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            prev->next = newNode;
            newNode->next = head;
        }
        prev = newNode;
        while(getchar() != '\n')
            continue;
        fputs("Enter 'y' to continue or 'n' to QUIT: ", stdout);
    }
}

void displayCLL(void)
{
    NODE *ptr;
    ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

void reverseCLL(void)
{
    NODE *tail, *mid, *start;
    tail = NULL;
    mid = NULL;
    start = head;

    NODE *ptr = head;
    do//to get the last node
    {
        ptr = ptr->next;
    } while (ptr->next != head);
    
    do
    {
        tail = mid;
        mid = start;
        start = start->next;

        if(mid == head)
            mid->next = ptr;
        else
            mid->next = tail;
    }while(start != head);
    head = mid;
}