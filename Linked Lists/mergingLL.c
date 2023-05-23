#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node NODE;
NODE *start1 = NULL;
NODE *start2 = NULL;
NODE *prev;
NODE *third = NULL;

void createLL(NODE **);
void displayLL(NODE *);
/* merging 2 sorted linked lists in a sorted fashion */
void merging(NODE *, NODE *);

int main(void)
{
    prev = NULL;
    fputs("Creating a linked list 1...\n", stdout);
    createLL(&start1);
    prev = NULL;
    fputs("Creating a linked list 2...\n", stdout);
    createLL(&start2);

    fputs("Displaying LL1: \n", stdout);
    displayLL(start1);
    fputs("Displaying LL2: \n", stdout);
    displayLL(start2);
    /* concatenating the 2 linked lists */
    merging(start1, start2);
    fputs("Displaying joined LL: \n", stdout);
    displayLL(third);

    return 0;
}

void createLL(NODE **begin)
{ 
    fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
    char ch;
    while(scanf("%c", &ch) && ch != 'n')
    {
        NODE *newNode;
        newNode = (NODE *)malloc(sizeof(NODE));
        int element;
        fputs("Enter element: ", stdout);
        scanf("%d", &element);
        newNode->data = element;
        if(*begin == NULL)
        {
            *begin = newNode;
            newNode->next = NULL;
        }    
        else
        {
            prev->next = newNode;
            newNode->next = NULL;
        }
        prev = newNode;
        fputs("Enter 'y' to CONTINUE & 'n' to QUIT\n", stdout);
        while(getchar() != '\n')
            continue;
    }
    while(getchar() != '\n')
        continue;
}

void merging(NODE *begin1, NODE *begin2)
{
    NODE *last;

    if(begin1->data < begin2->data) /* for deciding from which LL we take first node */
    {
        third = begin1;
        last = begin1;
        begin1 = begin1->next;
        last->next = NULL;
    }
    else if(begin1->data > begin2->data)
    {
        third = begin2;
        last = begin2;
        begin2 = begin2->next;
        last->next = NULL;
    }
    else
    {
        third = begin1;
        last = begin1;
        begin1 = begin1->next;
        begin2 = begin2->next;
        last->next = NULL;
    }
    
    while(begin1 != NULL && begin2 != NULL)
    {
        if(begin1->data < begin2->data)
        {
            last->next = begin1;
            last = begin1;
            begin1 = begin1->next;
            last->next = NULL;
        }
        else if(begin2->data < begin1->data)
        {
            last->next = begin2;
            last = begin2;
            begin2 = begin2->next;
            last->next = NULL;
        }
        else
        {
            last->next = begin1;
            last = begin1;
            begin1 = begin1->next;
            //begin2 = begin2->next;
            last->next = NULL;
        }
    }

    if(begin1 != NULL)
        last->next = begin1;
    else if(begin2 != NULL)
        last->next = begin2;
}

void displayLL(NODE *begin)
{
    NODE *ptr;
    ptr = begin;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    putchar('\n');
}
