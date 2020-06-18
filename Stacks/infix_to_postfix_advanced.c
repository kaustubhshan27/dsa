#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
//infix to postfix when brackets and R-L associativity involved
struct Node
{
    int data;
    int in_stack_prec;
    struct Node *next;
};
typedef struct Node NODE;
NODE *top = NULL;

void push(char ch);//pushing to stack
char pop(void);//popping from stack
int inStack_calc_prec(char ch);//calculating precedence of character
int outStack_calc_prec(char ch);

const char *expr = "((a+b)*c)-d^e^f";//sample expression

int main(void)
{
    //struct Node stack;//not required at all 
    char *result = (char *)malloc((sizeof(expr)/sizeof(expr[0]))*sizeof(char));//postfix expression stored here
    int res_i = 0;//indexing used for postfix expression string

    for(size_t index = 0; expr[index] != '\0'; index++)//traversing through expression
    {
        if(isalpha(expr[index]))
            result[res_i++] = expr[index];//if a variable, directly put in resultant string
        else
        {
            int char_precedence = outStack_calc_prec(expr[index]);
            while(top != NULL && (top->in_stack_prec >= char_precedence))//popping stack elements till we can push into stack
            {
                char pop_char = pop();
                if(pop_char != '(')
                    result[res_i++] = pop_char;
            }

            /*
            if(top != NULL)//after checking for popping, push into stack if stack is empty
            {
                if((char_precedence > top->in_stack_prec) && expr[index] != ')')//condition for pushing into stack
                    push(&stack, expr[index]);
            }
            else
            {
                if(expr[index] != ')')
                    push(&stack, expr[index]);//pushing into stack if stack is empty 
            }
            */

           if(expr[index] != ')')
                push(expr[index]);//pushing into stack if stack is empty

        }
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

        newNode->in_stack_prec = inStack_calc_prec(ch);
        
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

char pop()
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

int inStack_calc_prec(char ch)
{
    int prec;
    if(ch == '+' || ch == '-')
        prec = 2;
    else if(ch == '*' || ch == '/')
        prec = 4;
    else if(ch == '^')
        prec = 5;
    else if(ch == '(')
        prec = 1;
    //No instack precedence for ')'
    return prec;
}

int outStack_calc_prec(char ch)
{
    int prec;
    if(ch == '+' || ch == '-')
        prec = 1;
    else if(ch == '*' || ch == '/')
        prec = 3;
    else if(ch == '^')
        prec = 6;
    else if(ch == '(')
        prec = 7;
    else if(ch == ')')
        prec = 0;
    return prec;
}