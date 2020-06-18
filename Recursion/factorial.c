#include<stdio.h>

int fact(int n)
{
    if(n > 1)
        return fact(n-1)*n;
    else
        return 1;
}
int main(void)
{
    puts("Enter the number: ");
    int n;
    scanf("%d", &n);
    printf("The factorial is %d\n", fact(n));
    return 0;
}
