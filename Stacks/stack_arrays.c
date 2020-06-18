#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *stk;
};
typedef struct Stack STACK;

void push(STACK *, int);
int pop(STACK *);
int peek(STACK *, int);

int main(void)
{
    STACK st;
    int popped;
    st.top = -1;//initiliazing top as -1, top refers to the index in the array
    fputs("Enter size of stack:\n", stdout);
    scanf("%d", &st.size);
    st.stk = (int *)malloc(sizeof(int)*st.size);//allocating space
    push(&st, 10);
    fputs("PUSHED!\n",stdout);
    push(&st, 11);
    fputs("PUSHED!\n",stdout);
    push(&st, 12);
    fputs("PUSHED!\n",stdout);
    /*
    popped = pop(&st);
    printf("POPPED = %d\n", popped);
    popped = pop(&st);
    printf("POPPED = %d\n", popped);
    popped = pop(&st);
    printf("POPPED = %d\n", popped);
    popped = pop(&st);
    printf("POPPED = %d\n", popped);
    */
    int peeker;
    peeker = peek(&st, 1);
    printf("PEEKED 1 = %d\n", peeker);
    peeker = peek(&st, 2);
    printf("PEEKED 2 = %d\n", peeker);
    peeker = peek(&st, 3);
    printf("PEEKED 3 = %d\n", peeker);
    return 0;
}

void push(STACK *st, int ele)
{
    if(st->top != st->size - 1)
        st->stk[++st->top] = ele;
    else
        fputs("Stack is FULL!\n", stdout);
}

int pop(STACK *st)
{
    if(st->top != -1)
        return st->stk[st->top--]; 
    else
    {
        fputs("Stack is EMPTY!\n", stdout);
        return -1;
    }
}

int peek(STACK *st, int pos)//stack position starting from 1 from the top
{
    if((st->top - pos + 1) >= 0)
        return st->stk[st->top - pos + 1];
    else
    {
        fputs("Invalid position!\n", stdout);
        return -1;
    }   
}