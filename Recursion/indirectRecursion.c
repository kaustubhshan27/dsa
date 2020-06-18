#include <stdio.h>

void funcA(int n);
void funcB(int n);

int main()
{
    funcA(20);
    return 0;
}
void funcA(int n)
{
    if(n > 0)
    {
        printf("%d ", n);
        funcB(n-1);
    }
}
void funcB(int n)
{
    if(n > 0)
    {
        printf("%d ", n);
        funcA(n/2);
    }
}


