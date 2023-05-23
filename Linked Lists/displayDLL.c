#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *start = NULL;

void createDLL(void);
void displayDLL(void);


int main(void)
{
    fputs("Creating linked list...\n", stdout);
    createDLL();
    fputs("Displaying the linked list...\n", stdout);
    displayDLL();
    return 0;
}

void createDLL(void)
{
    NODE *prevNode;
    char ch;
    fputs("Enter 'y' to CONTINUE and 'n' to QUIT...\n", stdout);
    while(scanf("%c", &ch) && ch != 'n')
    {
        NODE * newNode;
        newNode = (NODE *)malloc(sizeof(NODE));
        int ele;
        fputs("Enter element:\n", stdout);
        scanf("%d", &ele);
        newNode->data = ele;
        if(start == NULL)
        {
            start = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }
        else
        {
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = NULL;
        }
        prevNode = newNode;
        fputs("Enter 'y' to CONTINUE and 'n' to QUIT...\n", stdout);
        while(getchar() != '\n')
            continue;
    }
}

void displayDLL(void)
{
    NODE *ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    putchar('\n');
}
