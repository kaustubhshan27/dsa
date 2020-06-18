#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node NODE;
NODE *start = NULL;

void createLL(void);
void displayLL(void);
int midpointLL(void);

int main(void)
{
    fputs("Creating a linked list...\n", stdout);
    createLL();
    fputs("Displaying linked list:\n", stdout);
    displayLL();
    fputs("Finding mid-point in linked list:\n", stdout);
    printf("The midpoint of linked list is %d\n", midpointLL());
    return 0;
}

void createLL(void)
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
            newNode->next = NULL;
        }
        else
        {
            prev->next = newNode;
            newNode->next = NULL;
        }
        prev = newNode;
        fputs("Enter 'y' to CONTINUE or 'n' to QUIT...\n", stdout);
        while(getchar() != '\n')
            continue;
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

int midpointLL(void)
{
    NODE *leader = start;
    NODE *trailer = start;
    while(leader->next != NULL)
    {
        for(size_t times = 0; times < 2; times++)
            if(leader->next != NULL)
                leader = leader->next;
            else
                break;
        trailer = trailer->next;
    }
    return trailer->data;
}