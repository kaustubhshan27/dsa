#include<stdio.h>

void perm(char str[], int low, int high);
void swap(char *a, char *b);

int main(void)
{
    char str[] = "ABC";
    puts("The permutations are: ");
    perm(str, 0, strlen(str) - 1);
    return 0;
}
void perm(char str[], int low, int high)
{
    if(low == high)
        printf("%s\n", str);
    else
    {
        for(size_t index = low; index <= high; index++)
        {
            swap(&str[low], &str[index]);
            perm(str, low + 1, high);
            swap(&str[low], &str[index]);
        }
    }
}
void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

