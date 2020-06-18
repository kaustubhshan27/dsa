#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct  Node *prev;
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *start = NULL;

void displayDLL(void);
void createDLL(void);
void reverseDLL(void);


int main(void)
{
    fputs("Creating doubly linked list...\n", stdout);
    createDLL();
    fputs("Displaying linked list...\n", stdout);
    displayDLL();
    fputs("Reversing linked list...\n", stdout);
    reverseDLL();
    fputs("Displaying reversed linked list...\n", stdout);
    displayDLL();
    return 0;
}

void displayDLL(void)
{
    NODE *temp = start;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next; 
    }
    putchar('\n');
}

void createDLL(void)
{
    NODE *newNode;
    NODE *prev;
    fputs("Enter 'y' to CONTINUE or 'n' to QUIT...\n", stdout);
    char ch;
    while(scanf("%c", &ch) && ch != 'n')
    {
        newNode = (NODE *)malloc(sizeof(NODE));
        fputs("Enter data:\n", stdout);
        scanf("%d", &(newNode->data));
        if(start == NULL)
        {
            start = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }
        else
        {
            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = NULL;
        }
        prev = newNode;
        fputs("Enter 'y' to CONTINUE or 'n' to QUIT...\n", stdout);
        while(getchar() != '\n')
            continue;
    }
}

void reverseDLL(void)
{
    NODE *ptr = start;
    while(ptr != NULL)
    {
        if(ptr->next == NULL)
            start = ptr;
        NODE *temp;
        temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        ptr = ptr->prev;
    }
    
}
