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
void deleteDLL(int);
int lengthDLL(void);

int main(void)
{
    fputs("Creating doubly linked list...\n", stdout);
    createDLL();
    int lenDLL = lengthDLL();
    fputs("The positions available are: ", stdout);
    for(int pos_count = 0; pos_count < lenDLL; pos_count++)
        printf("%d ", pos_count); 
    int pos;
    fputs("\nEnter a valid position to delete:\n", stdout);
    while(scanf("%d", &pos) && (pos < 0 || pos > lenDLL))
        fputs("Please enter a valid position.\n", stdout);
    deleteDLL(pos);
    fputs("Displaying linked list...\n", stdout);
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

void deleteDLL(int pos)
{
    NODE *ptr = start;
    if(pos == 0)
    {
        start = ptr->next;
        free(ptr); 
    }
    else
    {
        for(int count_pos = 0; count_pos < pos - 1; count_pos++)
            ptr = ptr->next;
        NODE *targetNode = ptr->next;
        ptr->next = targetNode->next;
        if(targetNode->next != NULL)
            targetNode->next->prev = ptr;
        free(targetNode);
    }
}

int lengthDLL(void)
{
    NODE *temp = start;
    int length = 0;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}