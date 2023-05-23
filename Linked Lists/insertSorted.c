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

void displayLL(void);
void createLL(void);
void insertSorted(int);

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
    fputs("Enter the element to insert: \n", stdout);
    int ele;
    scanf("%d", &ele);
    insertSorted(ele);
    fputs("Displaying modified linked list:\n", stdout);
    displayLL();
    return 0;
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

void insertSorted(int ele)
{
    NODE *ptr;
    ptr = start;
    prev = NULL;
    while(ptr->data < ele)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = ele;

    newNode->next = prev->next;
    prev->next = newNode;
}
