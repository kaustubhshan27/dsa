#include <stdio.h>
#include <stdlib.h>

double taylor(int exp, int terms);
double power(double base, int exponent);
int fact(int num);

int main()
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
double taylor(int exp, int terms)
{
    if(terms > 0)
    {
        double term = power(exp, terms - 1)/fact(terms - 1);
        return (term + taylor(exp, terms - 1));
    }
    else
        return 0;
}
double power(double base, int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent%2 == 0)
        return power(base * base, exponent/2);
    else
        return (base*power(base * base, (exponent-1)/2));
}
int fact(int num)
{
    if(num > 0)
        return fact(num-1)*num;
    else
        return 1;
}

