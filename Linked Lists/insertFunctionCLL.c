#include<stdio.h>
#include<stdlib.h>
//In this program, CLL is being created using insert function
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
static NODE *head = NULL;
static NODE *prev = NULL;

void insertCLL(int, int);
int countNodes();
void displayCLL(void);

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
        insertCLL(pos, ele);
        fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
        while(getchar() != '\n')
            continue;
    }
    fputs("Displaying modified linked list:\n", stdout);
    displayCLL();
    return 0;
}

void insertCLL(int pos, int ele)
{
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = ele;
    NODE *ptr = head;

    if(pos == 0)
    {   
        if(ptr != NULL)
        {
            do
            {
                ptr = ptr->next;
            }while(ptr->next != head);
            
            ptr->next = newNode; 
            newNode->next = head;
            head = newNode;  
        }
        else
        {
            head = newNode;
            newNode->next = head;
        }
    }
    else
    {
        for(int pos_count = 1; pos_count < pos; pos_count++)
            ptr = ptr->next;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void displayCLL(void)
{
    NODE *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    putchar('\n');
}

int countNodes()
{
    NODE *ptr;
    ptr = head;
    int count = 0;
    do
    {
        if(ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
    }while(ptr != head);
    return count;
}
