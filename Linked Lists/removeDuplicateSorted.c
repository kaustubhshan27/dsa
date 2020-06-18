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
void deleteDuplicate(void);

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
    fputs("Removing duplicates...\n", stdout);
    deleteDuplicate();
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

void deleteDuplicate(void)
{
    NODE *ptr;
    ptr = start->next;//RIGID MIND!!!
    prev = start;
    while(ptr != NULL)
    {
        //printf("\n---YULU1---\n");
        if(prev->data == ptr->data)
        {
            prev->next = ptr->next;
            //printf("\n---YULU2---\n");
            free(ptr);
            ptr = prev->next;
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
    }
}