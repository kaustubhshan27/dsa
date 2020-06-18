#include<stdio.h>

int main(void)
{
    puts("Enter the exponent: ");
    int exp;
    scanf("%d", &exp);
    puts("Enter the max power: ");
    int max_pow;
    scanf("%d", &max_pow);

    double ans = 1.0;
    for(size_t i = max_pow; i > 0; i--)
    {
        ans = 1 + ans*(exp/i);
    }
    printf("The value of e^%d = %f\n", exp, ans);
    return 0;
}
