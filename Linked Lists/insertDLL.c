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
void insertDLL(int, int);
void displayDLL(void);
int lengthDLL(void);

int main(void)
{
    fputs("Creating doubly linked list...\n", stdout);
    createDLL();
    int lenDLL = lengthDLL();
    fputs("Enter element to insert:\n", stdout);
    int ele;
    scanf("%d", &ele);
    fputs("The positions available are: ", stdout);
    for(int pos_count = 0; pos_count <= lenDLL; pos_count++)
        printf("%d ", pos_count); 
    int pos;
    fputs("\nEnter a valid position to insert:\n", stdout);
    while(scanf("%d", &pos) && (pos < 0 || pos > lenDLL))
        fputs("Please enter a valid position.\n", stdout);
    insertDLL(ele, pos);
    fputs("Displaying linked list...\n", stdout);
    displayDLL();
    return 0;
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

void insertDLL(int ele, int pos)
{
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = ele;
    NODE *ptr = start;
    if(pos == 0)
    {
        newNode->prev = NULL;
        newNode->next = start;
        start->prev = newNode;//even without adding this line it "worked" because we're just printing in forward direction
        start = newNode; 
    }
    else
    {
        for(int count_pos = 1; count_pos < pos; count_pos++)
            ptr = ptr->next;
        newNode->next = ptr->next;
        newNode->prev = ptr;
        if(ptr->next != NULL)
            ptr->next->prev = newNode;//even without adding this line it "worked" because we're just printing in forward direction
        ptr->next = newNode;//order of assignment is important
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
