#include<stdio.h>
#include<stdlib.h>

struct Item
{
    char data;
    int priority;
    struct Item *next;
};
typedef struct Item ITEM;
ITEM *front = NULL;
ITEM *rear = NULL;

void insert(char, int);
int get_highest(void);//returns position of highest priority element in the linked list
char deleteNode(int);

int main(void)
{
    insert('O', 5);
    insert('G', 5);
    insert('V', 2);
    insert('I', 2);
    insert('S', 0);
    insert(' ', 4);
    insert('A', 7);
    insert('N', 7);
    insert('C', 1);
    insert('E', 1);
    insert('D', 3);
    insert('E', 3);
    insert('A', 6);
    insert('L', 6);
    
    for(size_t index = 0; index < 14; index++)
        printf("%c", deleteNode(get_highest()));
    putchar('\n');
    return 0;
}

void insert(char ch, int pri)
{
    ITEM *newNode = (ITEM *)malloc(sizeof(ITEM));
    if(newNode == NULL)
    {
        fputs("Queue is Full!\n", stdout);
        return;
    }
    else
    {
        newNode->data = ch;
        newNode->priority = pri;
        newNode->next = NULL;
        if(front == NULL)
            front = newNode;
        else
            rear->next = newNode;
            
        rear = newNode;
    }
}

int get_highest(void)
{
    int high_pos = 0;
    int count = 1;
    int highest_pri = front->priority;
    ITEM *ptr = front->next;
    while(ptr != NULL)
    {
        if(highest_pri < ptr->priority)
        {
            highest_pri = ptr->priority;
            high_pos = count;
        }
        ptr = ptr->next;
        count++;
    }
    return high_pos;
}

char deleteNode(int pos)
{
    if(front == NULL)
    {
        fputs("PRIORITY QUEUE is empty!\n", stdout);
        return 'X';
    }   
    else
    {
        char ch;
        ITEM *ptr = front;
        if(pos == 0)
        {
            ch = ptr->data;
            front = ptr->next;
            free(ptr); 
            return ch;
        }
        else
        {
            for(size_t count = 1; count < pos; count++)
                ptr = ptr->next;
            ch = ptr->next->data;
            ITEM *targetNode = ptr->next;//targetNode fixing was crucial!
            ptr->next = ptr->next->next;
            free(targetNode);
            return ch;
        }
    }
}
