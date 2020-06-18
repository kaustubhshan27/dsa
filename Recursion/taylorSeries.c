#include<stdio.h>
double taylor(int exp, int num);
int main(void)
{
    puts("Enter the exponent: ");
    int exponent;
    scanf("%d", &exponent);
    puts("Enter the number of terms to be calculated upto: ");
    int terms;
    scanf("%d", &terms);
    printf("The result of e^%d = %f\n", exponent, taylor(exponent, terms));
    return 0;
}
double taylor(int exp, int num)
{
    static int pow = 1, fact = 1;
    double r;
    if(num == 0)
        return 1;
    else
    {
        r = taylor(exp, num - 1);
        pow = pow*exp;
        fact = fact*num;
        return (r + pow/fact);
    }
}
