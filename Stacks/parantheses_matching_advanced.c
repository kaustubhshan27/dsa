#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    char ch;
    struct Node *next;
};
typedef struct Node NODE;
NODE *top = NULL;

char *expr = "{[(a+b)]*[(c+d)]}";//balanced

bool balanced(char *);

int main(void)
{
    if(balanced(expr))
        fputs("The expression is balanced!\n", stdout);
    else
        fputs("The expression is not balanced!\n", stdout);
}

bool balanced(char *expr)
{
    for(size_t index = 0; expr[index] != '\0'; index++)
    {
        if(expr[index] == '(' || expr[index] == '[' || expr[index] == '{')
        {
            NODE *newNode = (NODE *)malloc(sizeof(NODE));
            if(newNode != NULL)//push procedure
            {
                newNode->ch = expr[index];
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
                fputs("Stack Overflow!\n", stdout);
        }
        else if(expr[index] == ')' || expr[index] == ']' || expr[index] == '}')
        {   
            if(top != NULL)
            {
                char type = expr[index];
                switch (type)
                {
                case ')':
                    if(top->ch != '(')
                        return false;
                    break;
                case ']':
                    if(top->ch != '[')
                        return false;
                    break;
                case '}':
                    if(top->ch != '{')
                        return false;
                    break;
                }
                NODE *temp;
                temp = top->next;
                free(top);
                top = temp;
            }
            else
            {
                fputs("Stack Underflow!\n", stdout);
                return false;//unbalanced when no. of opening brackets < no. of closing brackets
            }
        }
    }
    if(top != NULL)
        return false;//unbalanced when no. of opening brackets > no. of closing brackets
    else
        return true;//top == NULL after traversing through full string results in balanced expression
}
