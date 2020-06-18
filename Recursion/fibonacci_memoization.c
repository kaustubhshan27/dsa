#include<stdio.h>

int fibo(int num);
int check[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int main(void)
{
    puts("Enter the limit: ");
    int num;
    scanf("%d", &num);//num <= 10
    for(size_t index = 0; index <= num; index++)
    {
        printf("%d ", fibo(index));
    }
    return 0;
}
int fibo(int num)
{
    if(num <= 1)
    {
        check[num] = num;
        return num;
    }
    else
    {
        
        if(check[num - 2] == -1)
            check[num - 2] = fibo(num - 2);
        if(check[num - 1] == -1)
            check[num - 1] = fibo(num - 1);
        return check[num-2] + check[num - 1];//memoization
        /*Below is also correct but then it's not recursion
        check[num] = check[num-2] + check[num-1];
        return check[num];
        */
    }
}
