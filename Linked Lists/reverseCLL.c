#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *head = NULL;
NODE *prev = NULL;

void createCLL(void);
void displayCLL(void);
void reverseCLL(NODE *, NODE *);
NODE* findLastNode(void);

int main(void)
{
    fputs("Creating a linked list...\n", stdout);
    createCLL();
    fputs("Displaying LL: \n", stdout);
    displayCLL();
    fputs("\nReversing linked list...\n", stdout);
    NODE *lastNode;
    lastNode = findLastNode();
    reverseCLL(lastNode, head);
    fputs("Displaying modified LL: \n", stdout);
    displayCLL();

    return 0;
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

void reverseCLL(NODE *follow, NODE *leader)
{
    static int flag = 0;
    if(leader != head || flag == 0)
    {
        flag = 1;
        reverseCLL(leader, leader->next);
        leader->next = follow; 
    }
    else
    {
        head = follow;
    }
}

void displayCLL(void)
{
    NODE *ptr;
    ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

NODE* findLastNode(void)
{
    NODE *ptr;
    ptr = head;
    do
    {
        ptr = ptr->next;
    } while(ptr->next != head);
    return ptr;
}
