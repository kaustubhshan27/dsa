#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
//infix to postfix when no brackets and R-L associativity involved
struct Node
{
    int data;
    int in_stack_prec;
    struct Node *next;
};
typedef struct Node NODE;
NODE *top = NULL;

struct Eval
{
    int op; //operand to evaluate once the infix expression is converted to a postfix expression
    struct Eval *next;
};
typedef struct Eval EVAL;
EVAL *eval_top = NULL;

void push(char ch);//pushing to stack
char pop(void);//popping from stack
int inStack_calc_prec(char ch);//calculating precedence of character
int outStack_calc_prec(char ch);
void push_eval(int ele);
int pop_eval(void);

const char *expr = "3*5+6/2-4";//sample expression

int main(void)
{
    char *result = (char *)malloc((sizeof(expr)/sizeof(expr[0]))*sizeof(char));//postfix expression stored here
    int res_i = 0;//indexing used for postfix expression string

    for(size_t index = 0; expr[index] != '\0'; index++)//traversing through expression
    {
        if(isdigit(expr[index]))
            result[res_i++] = expr[index];
        else
        {
            int char_precedence = outStack_calc_prec(expr[index]);
            while(top != NULL && (top->in_stack_prec >= char_precedence))//popping stack elements till we can push into stack
            {
                char pop_char = pop();
                if( pop_char != '(')
                    result[res_i++] = pop_char;
            }
            if(expr[index] != ')')
                push(expr[index]);//pushing into stack if stack is empty      
        }
    }
    while(top != NULL)//popping stack elements left in stack after traversing array
        result[res_i++] = pop();

    printf("Postfix form: %s\n", result);

    for(size_t index = 0; result[index] != '\0'; index++)//traversing through postfix expression
    {
        if(isdigit(result[index]))
            push_eval(result[index] - 48);
        else if(result[index] == '+' || result[index] == '-' || result[index] == '*' || result[index] == '/')
        {
            int final_value;
            int value2 = pop_eval();
            int value1 = pop_eval();
            switch(result[index])
            {
                case '+':
                    final_value = value1 + value2;
                    push_eval(final_value);
                    break;
                case '-':
                    final_value = value1 - value2;
                    push_eval(final_value);
                    break;
                case '*':
                    final_value = value1 * value2;
                    push_eval(final_value);
                    break;
                case '/':
                    final_value = value1 / value2;
                    push_eval(final_value);
                    break;
            }
        }
    }
    int final_result = pop_eval();//popping one last time to get final value stored in the stack
    printf("The result of the expression is %d.\n", final_result);
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

void push_eval(int ele)
{
    EVAL *newNode = (EVAL *)malloc(sizeof(EVAL));
    if(newNode != NULL)
    {
        newNode->op = ele;
        
        if(eval_top == NULL)
        {
            newNode->next = NULL;
            eval_top = newNode;
        }
        else
        {
            newNode->next = eval_top;
            eval_top = newNode;
        }
    }
    else
        fputs("STACK OVERFLOW!\n", stdout);
}

int pop_eval()
{
    if(eval_top != NULL)
    {
        int val;
        val = eval_top->op;
        EVAL *temp;
        temp = eval_top->next;
        free(eval_top);
        eval_top = temp;
        return val;
    }
    else
    {
        fputs("STACK UNDERFLOW!\n", stdout);
        return 0;
    }
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
