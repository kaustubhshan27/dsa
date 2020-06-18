#include<stdio.h>

double horner(int e_exp, int max_pow);

int main(void)
{
/*
    puts("Enter the exponent: ");
    int exp;
    scanf("%d", &exp);
    puts("Enter the max power: ");
    int max_pow;
    scanf("%d", &max_pow);
*/
    horner(2, 10);
    printf("The value of e^%d = %f\n", 2, horner(2, 10));
    return 0;
}


double horner(int e_exp, int max_pow)
{
    static double current_term = 1;
    if(max_pow == 0)
        return current_term;
    else
    {
        current_term = current_term*e_exp/max_pow + 1;
        return horner(e_exp, max_pow-1);
    }
}

