#include<stdio.h>

int fibo(int n)
{
    if(n > 1)
        return fibo(n-1)+fibo(n-2);
    else
        return n;
}

int main(void)
{
    int n;
    puts("Enter sequence limit:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", fibo(i));
    }
}
