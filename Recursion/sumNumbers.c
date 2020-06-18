#include<stdio.h>

int sumN(int n);

int main(void)
{
    puts("Enter the limit number");
    int n;
    scanf("%d", &n);
    printf("The sum to %d is %d\n", n, sumN(n));
    return 0;
}
int sumN(int n)
{
/*
    static int sum = 0;
    if(n > 0)
        {
            sum = sum + n;
            sumN(n-1);
        }
    else
        return sum;
*/

    if(n == 0)
        return 0;
    else
        return n+sumN(n-1);
}
