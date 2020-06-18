#include<stdio.h>
//Duplicates in sorted array
int main(void)
{
    int arr[] = {8, 8, 8, 9, 10, 15,15,15};
    int count = 1;
    int index;
    for(index = 0; index < sizeof(arr)/sizeof(arr[0]) - 1; index++)
    {
        /* 
        if(arr[index] == arr[index + 1] && count == 0)
        {
            count++;
        }
        */
        if(arr[index] == arr[index + 1])
        {
            count++;
        }
        /* 
        if(arr[index] == arr[index + 1] && count >= 1)
        {
            count++;
        }
        */
        else if(arr[index] != arr[index + 1] && count > 1)
        {
            printf("%d was duplicated %d times.\n", arr[index], count);
            count = 1;
        }
    }
    if(count > 1)
         printf("%d was duplicated %d times.\n", arr[index], count);

    return 0;
}
