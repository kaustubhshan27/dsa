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

const char *expr = "((a+b)*(c+d))";//not balanced

bool balanced(const char *);//do not want the contents of the character array to be changed in the function hence used 'const'

int main(void)
{
    if(balanced(expr))
        fputs("The expression is balanced!\n", stdout);
    else
        fputs("The expression is not balanced!\n", stdout);
}

bool balanced(const char *expr)
{
    for(size_t index = 0; expr[index] != '\0'; index++)
    {
        if(expr[index] == '(')
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
        else if(expr[index] == ')')//pop procedure
        {
            if(top != NULL)
            {
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
