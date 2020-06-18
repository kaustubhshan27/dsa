#include<stdio.h>

double power(double, int);

int main(void)
{
    puts("Enter the base: ");
    double base;
    scanf("%lf", &base);
    puts("Enter the exponent: ");
    int exponent;
    scanf("%d", &exponent);
    printf("The result is %f\n", power(base, exponent));
    return 0;
}
/*
double power(double base, int exponent)
{
    if(exponent > 0)
        return power(base, exponent - 1)*base;
    else
        return 1;
}
*/
double power(double base, int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent%2 == 0)
        return power(base * base, exponent/2);//number of multiplications is being reduced so number of recusrsion calls is less
    else
        return (base*power(base * base, (exponent-1)/2));//number of multiplications is being reduced so number of recusrsion calls is less
}
