#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
//infix to postfix when no brackets and R-L associativity involved
struct Node
{
    int data;
    int precedence;
    struct Node *next;
};
typedef struct Node NODE;
NODE *top = NULL;

void push(char ch);//pushing to stack
char pop(void);//popping from stack
int calc_precedence(char ch);//calculating precedence of character

const char *expr = "a+b*c+d";//sample expression

int main(void)
{
    //struct Node stack;//Not needed at all
    char *result = (char *)malloc((sizeof(expr)/sizeof(expr[0]))*sizeof(char));//postfix expression stored here
    int res_i = 0;//indexing used for postfix expression string

    for(size_t index = 0; expr[index] != '\0'; index++)//traversing through expression
    {
        int char_precedence = calc_precedence(expr[index]);
        while(top != NULL && (top->precedence >= char_precedence))//popping stack elements till we can push into stack
            result[res_i++] = pop();

        /*
        Below checking not required since we're already checking the conditions above
        if(top != NULL)//after checking for popping, push into stack if stack is empty
        {
            if(char_precedence > top->precedence)//condition for pushing into stack
                push(&stack, expr[index]);
        }
        else
            push(&stack, expr[index]);//pushing into stack if stack is empty
        */

        push(expr[index]);//pushing into stack after removing the item with >= precedence
    }
    while(top != NULL)//popping stack elements left in stack after traversing array
        result[res_i++] = pop();

    printf("Postfix form: %s\n", result);
    return 0;
}

void push(char ch)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode != NULL)
    {
        newNode->data = ch;

        newNode->precedence = calc_precedence(ch);
        
        if(top == NULL)
        {
            newNode->next = NULL;
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    else
        fputs("STACK OVERFLOW!\n", stdout);
}

char pop(void)
{
    if(top != NULL)
    {
        char ch = top->data;
        NODE *temp;
        temp = top->next;
        free(top);
        top = temp;
        return ch;
    }
    else
    {
        fputs("STACK UNDERFLOW!\n", stdout);
        return 0;
    }
}

int calc_precedence(char ch)
{
    int prec;
    if(isalpha(ch))
        prec = 3;//assigning precedence to operands, 2nd method. 1st method is to put operand directly into resultant string
    else
    {
        if(ch == '*' || ch == '/')
            prec = 2;
        else if(ch == '+' || ch == '-')
            prec = 1;
    }
    return prec;
}