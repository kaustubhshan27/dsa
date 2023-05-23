#include<stdio.h>
#include<stdlib.h>
//displaying linked list in forward direction
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *head = NULL;
NODE *prev = NULL;

void createCLL(void);
void recursiveDisplayCLL(NODE *);

int main(void)
{
    fputs("Creating a linked list...\n", stdout);
    createCLL();
    fputs("Displaying circular linked list:\n ", stdout);
    recursiveDisplayCLL(head);
}

void createCLL(void)
{
    fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
    char ch;
    NODE *newNode;
    while(scanf("%c", &ch) && ch != 'n')
    {
        newNode = (NODE *)malloc(sizeof(NODE));
        int element;
        fputs("Enter element: ", stdout);
        scanf("%d", &element);
        newNode->data = element;
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
        fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
        while(getchar() != '\n')
            continue;
    }
}

void recursiveDisplayCLL(NODE *ptr)
{
    static int flag = 0;
    if(ptr != head || flag == 0)
    {
        flag = 1;
        printf("%d ", ptr->data);
        recursiveDisplayCLL(ptr->next);
    }
}
