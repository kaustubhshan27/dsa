#include<stdio.h>

int main(void)
{
    int arr[] = {3, 4, 6, 8, 10, 11, 12};
    int i = 0;
    int j = (sizeof(arr)/sizeof(arr[0])) - 1;
    while(i < j)
    {
        if(arr[i] + arr[j] > 10)
            j--;
        else if(arr[i] + arr[j] < 10)
            i++;
        else
        {
            printf("The 2 elements to sum 10 are: %d and %d.\n", arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return 0;
}
