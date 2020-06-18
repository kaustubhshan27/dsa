#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *start = NULL;
NODE *prev = NULL;

void createLL(void);
void displayLL(void);
void reverseLL(void);

int main(void)
{
    fputs("Creating a linked list...\n", stdout);
    fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
    char ch;
    while(scanf("%c", &ch) && ch != 'n')
    {
        createLL();
        fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
        while(getchar() != '\n')
            continue;
    }
    fputs("Displaying LL: \n", stdout);
    displayLL();
    fputs("Reversing linked list...\n", stdout);
    reverseLL();
    fputs("Displaying modified LL: \n", stdout);
    displayLL();

    return 0;
}

void createLL(void)
{
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(NODE));
    int element;
    fputs("Enter element: ", stdout);
    scanf("%d", &element);
    newNode->data = element;
    //printf("\n---YULU---\n");
    if(start == NULL)
    {
        start = newNode;
        newNode->next = NULL;
    } 
    else
    {
        prev->next = newNode;
        newNode->next = NULL;
    }
    prev = newNode;
}

void reverseLL(void)
{
    NODE *head, *mid, *tail;
    head = start;
    mid = NULL;
    tail = NULL;
    while(head != NULL)
    {
        tail = mid;
        mid = head;
        head = head->next;

        mid->next = tail;
    }
    start = mid;
}

void displayLL(void)
{
    NODE *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    putchar('\n');
}