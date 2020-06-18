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
//Creation by insertion
void insertLL(int, int);
int countNodes();
void displayLL(void);

int main(void)
{
    fputs("Create a linked list...\n", stdout);
    fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
    char ch;
    int pos;
    int ele;
    int nodes;
    while(scanf("%c", &ch) && ch != 'n')
    {
        nodes = countNodes();
        printf("Nodes = %d\n", nodes);
        fputs("The available positions are: ", stdout);
        for(int available_pos = 0; available_pos <= nodes; available_pos++)
            printf("%d ", available_pos);
        fputs("\nEnter position to be inserted: \n", stdout);
        while(scanf("%d", &pos) && (pos < 0 || pos > nodes))
            fputs("Please enter a valid position.\n", stdout);
        fputs("Enter an element: \n", stdout);
        scanf("%d", &ele);
        insertLL(pos, ele);
        fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
        while(getchar() != '\n')
            continue;
    }
    fputs("Displaying modified linked list:\n", stdout);
    displayLL();
    return 0;
}

void insertLL(int pos, int ele)
{
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = ele;

    NODE *ptr = start;

    if(pos == 0)
    {
        newNode->next = start;
        start = newNode;
    }
    else
    {
        for(int pos_count = 1; pos_count < pos; pos_count++)
            ptr = ptr->next;
        newNode->next = ptr->next;
        ptr->next = newNode;
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

int countNodes()
{
    NODE *ptr;
    ptr = start;
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}