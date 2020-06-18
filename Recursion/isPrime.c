#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(int number, int lower_limit, int higher_limit);
bool status = true;

int main(void)
{
    fputs("Enter a number:\n", stdout);
    int number;
    scanf("%d", &number);
    int lower_limit = 2;
    int higher_limit = number / 2;
    if(isPrime(number, lower_limit, higher_limit))
        fputs("\nIt is a prime number.\n", stdout);
    else
        fputs("\nIt is not a prime number.\n", stdout);
}

bool isPrime(int number, int lower_limit, int higher_limit)
{
    if(lower_limit > higher_limit)
    {
        if(!status)
            return false;
        else
            return true; 
    }
    else
    {
        if(number % lower_limit == 0)
            status = false;
        else
        {
            lower_limit++;
            isPrime(number, lower_limit, higher_limit);
        }
    }
}

/*
bool isPrime(int n, int i = 2) 
{ 
    // Base cases 
    if (n <= 2) 
        return (n == 2) ? true : false; 
    if (n % i == 0) 
        return false; 
    if (i * i > n) 
        return true; 
  
    // Check for next divisor 
    return isPrime(n, i + 1); 
} */