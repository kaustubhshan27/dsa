#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Tracing the logic gives us a tree.
//And we have to do backtracking to obtain all results.
//The above two suggest that we have to use tree recursion(multiple recursive calls in one function call).
void perm(char str[], int k);

int main(void)
{
    char str[] = "ABC";
    printf("The permutations of %s are:\n", str);
    perm(str, 0);
    return 0;
}
void perm(char str[], int k)
{
    static int A[sizeof(str)/sizeof(str[0]) + 1] = {0};
    static char result[sizeof(str)/sizeof(str[0]) + 1];
    if(str[k] == '\0')
    {
        result[k] = '\0';
        printf("%s\n", result);
    }
    else
    {
        for(size_t index = 0; str[index] != '\0'; index++)
        {
            if(A[index] == 0)
            {
                result[k] = str[index];
                A[index] = 1;
                perm(str, k + 1);
                A[index] = 0;
            }
        }
    }
}
