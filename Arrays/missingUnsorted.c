#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int arr[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int largest = arr[0];
    int smallest = arr[0];
    for(size_t index = 1; index < size; index++)
    {
        if(arr[index] > largest)
            largest = arr[index];
        else if(arr[index] < smallest)
            smallest = arr[index];
    }
    int *temp_arr = (int *)calloc(largest, sizeof(int));
    for(size_t index = 0; index < size; index++)//traversing through data array and setting has table
    {
        temp_arr[arr[index]] = -1;//setting hash table values
    }
    for(size_t index = smallest; index < largest; index++)//traversing through hash table
    {
        if(temp_arr[index] == 0)
        {
            printf("The missing element is %ld.\n", index);
        }
    }
    return 0;
}
