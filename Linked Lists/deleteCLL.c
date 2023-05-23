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

void create(void);
void delete(int);
void display(void);

int main(void)
{
    fputs("Creating circular linked list..\n", stdout);
    create();
    fputs("Enter position to delete node: \n", stdout);
    int pos;
    scanf("%d", &pos);
    delete(pos);
    fputs("Displaying modified linked list...\n", stdout);
    display();

    return 0;
}

void create(void)
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

void display(void)
{
    NODE *ptr;
    ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void delete(int pos)
{
    if(pos == 0)
    {
        NODE *ptr = head;
        if(ptr == ptr->next)
            free(ptr);
        else
        {
            do
            {
                ptr = ptr->next;
            }while (ptr->next != head);
            ptr->next = head->next;
            free(head);
            head = ptr->next;
        }
    }
    else
    {
        NODE *ptr = head;
        for(int pos_count = 0; pos_count < pos - 1; pos_count++)
            ptr = ptr->next;
        NODE *qtr = ptr->next;
        ptr->next = qtr->next;
        free(qtr);
    }
}
