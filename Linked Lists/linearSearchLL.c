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
int searchLL(int);
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
    fputs("Enter the element to be searched: \n", stdout);
    int element;
    scanf("%d", &element);
    int pos;
    pos = searchLL(element);
    if(pos != -1)
        printf("The elemnt is present at position %d\n", pos);
    else
        printf("Element is not present\n");
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

int searchLL(int element)
{
    NODE *ptr;
    ptr = start;
    prev = NULL;
    int pos = 0;
    while(ptr != NULL)
    {   
        pos++;
        if(ptr->data == element)
        {
            prev->next = ptr->next;
            ptr->next = start;
            start = ptr;
            return pos;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    return -1;
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