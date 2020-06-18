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
void insertLL(int);
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
    fputs("Enter the position to insert: \n", stdout);
    int pos;
    scanf("%d", &pos);
    insertLL(pos);
    fputs("Displaying modified linked list:\n", stdout);
    displayLL();
    return 0;
}

void createLL(void)
{
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    fputs("Enter the element: \n", stdout);
    scanf("%d", &ptr->data);

    if(start == NULL)
    {
        start = ptr;
        ptr->next = NULL;
    }
    else
    {
        prev->next = ptr;
        ptr->next = NULL;
    }
    prev = ptr;
}

void insertLL(int pos)
{
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(NODE));
    fputs("Enter element to be inserted: \n", stdout);
    scanf("%d", &(newNode->data));
    NODE *ptr;
    ptr = start;
    prev = NULL;
    int count = 0;
    while(ptr != NULL)
    {   
        count++;
        if(count == pos)
        {
            prev->next = newNode;
            newNode->next = ptr;
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
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