#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *start1 = NULL;
NODE *start2 = NULL;
NODE *prev;

void createLL(NODE **);
void displayLL(NODE *);
void join(NODE *, NODE *);

int main(void)
{
    prev = NULL;
    fputs("Creating a linked list 1...\n", stdout);
    createLL(&start1);
    prev = NULL;
    fputs("Creating a linked list 2...\n", stdout);
    createLL(&start2);

    fputs("Displaying LL1: \n", stdout);
    displayLL(start1);
    fputs("Displaying LL2: \n", stdout);
    displayLL(start2);
    //Concatenating the 2 linked lists
    join(start1, start2);
    fputs("Displaying joined LL: \n", stdout);
    displayLL(start1);

    return 0;
}

void createLL(NODE **begin)
{ 
    fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
    char ch;
    while(scanf("%c", &ch) && ch != 'n')
    {
        NODE *newNode;
        newNode = (NODE *)malloc(sizeof(NODE));
        int element;
        fputs("Enter element: ", stdout);
        scanf("%d", &element);
        newNode->data = element;
        if(*begin == NULL)
        {
            *begin = newNode;
            newNode->next = NULL;
        }    
        else
        {
            prev->next = newNode;
            newNode->next = NULL;
        }
        prev = newNode;
        fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
        while(getchar() != '\n')
            continue;
    }
    while(getchar() != '\n')
        continue;
}

void join(NODE *begin1, NODE *begin2)
{
    NODE *ptr;
    ptr = begin1;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = begin2;
}

void displayLL(NODE *begin)
{
    NODE *ptr;
    ptr = begin;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    putchar('\n');
}