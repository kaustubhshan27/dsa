#include<stdio.h>

void fibo(int, int, int);

int main(void)
{
    puts("Enter the limit: ");
    int n;
    scanf("%d", &n);
    printf("%d %d ", 0, 1);
    fibo(n - 2, 0, 1);
    return 0;
}
void fibo(int n, int fterm, int sterm)
{
    if(n > 0)
    {
        int nextTerm = fterm + sterm;
        printf("%d ", nextTerm);
        fibo(n-1, sterm, nextTerm);
    }
    else
        return 0;
}
