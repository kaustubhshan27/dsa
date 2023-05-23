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
int countNodes();

int main(void)
{
    fputs("Create a linked list...\n", stdout);
    createLL();
    printf("Sum of nodes = %d\n", countNodes());
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

int countNodes()
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr = start;
    int sum = 0;
    while(ptr != NULL)
    {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}
