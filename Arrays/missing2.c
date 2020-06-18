#include<stdio.h>

int main(void)
{
    int arr[] = {6, 8, 9, 10, 11, 15, 17};
    int low = arr[0];
    int high = arr[sizeof(arr)/sizeof(arr[0]) - 1];
    int diff = low - 0;

    for(size_t index = 0; index < sizeof(arr)/sizeof(arr[0]); index++)
    {
        if(arr[index] - index != diff)
        {
            int count = diff;
            diff = arr[index] - index;
            while(count < diff)
            {
                printf("Missing element is %d\n", index + count);
                count++;
            }
        }
    }
}