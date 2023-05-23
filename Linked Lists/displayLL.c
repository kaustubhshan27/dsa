#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
static NODE *start = NULL;
static NODE *prev = NULL;

void createLL();
void displayLL();

int main(void)
{
    fputs("Create a linked list...\n", stdout);
    createLL();
    fputs("Displaying linked list...\n", stdout);
    displayLL();
}

void createLL(void)
{
    NODE *ptr;
    char str[4];

    fputs("Enter 'YES' to create a node...\n", stdout);
    fputs("Enter 'NO' to quit...\n", stdout);
    scanf("%s", str);
    str[0] = tolower(str[0]);

    while(str[0] != 'n')
    {
        ptr = (NODE *)malloc(sizeof(NODE));
        fputs("Enter data to be entered: ", stdout);
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

        fputs("Enter 'YES' to create a node...\n", stdout);
        fputs("Enter 'NO' to quit...\n", stdout);   
        scanf("%s", str);
        str[0] = tolower(str[0]);
    }
}

void displayLL()
{
    NODE *ptr = start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    putchar('\n');
}
