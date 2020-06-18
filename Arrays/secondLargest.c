#include<stdio.h>

int main(void)
{
    int arr[] = {0, 3, 1, 5, 9, 9, 6};
    int largest = arr[0];
    for(size_t index = 0; index < sizeof(arr)/sizeof(arr[0]); index++)
    {
        if(arr[index] > largest)
            largest = arr[index];
    }
    int diff = largest - arr[0];
    for(size_t index = 1; index < sizeof(arr)/sizeof(arr[0]); index++)
    {
        if(diff > largest - arr[index] && largest - arr[index] != 0)//if the subtraction is 0, it's the same element
        {
            diff = largest - arr[index];
        }
    }
    printf("The second largest number is %d.\n", largest - diff);
    return 0;
}
