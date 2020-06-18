#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
static NODE *start = NULL;
static NODE *prev = NULL;

void createLL(void);
void displayLL(void);

int main(void)
{
    fputs("Create a linked list...\n", stdout);
    fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
    char ch;
    while(scanf("%c", &ch) && ch != 'n')
    {
        createLL();
        fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
        while(getchar() != '\n')
            continue;
    }
    fputs("Displaying modified linked list:\n", stdout);
    displayLL();
    return 0;
}

void createLL(void)
{
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(NODE));
    fputs("Enter the element: \n", stdout);
    scanf("%d", &newNode->data);

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

void displayLL(void)
{
    NODE *ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    putchar('\n');
}