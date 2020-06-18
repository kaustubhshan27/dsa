#include<stdio.h>
#include<stdbool.h>
//Multiple missing element in array of natural no.s
int main(void)
{
    int arr[] = {6, 8, 9, 10, 11, 14, 16, 17};
    int size = sizeof(arr)/sizeof(int);
    bool status = false;
    int residue;
    for(size_t index = 0; index < size - 1; index++)
    {
        if((residue = arr[index+1] - arr[index]) != 1)
        {
            status = true;
            int counter = 0;
            while((counter++) < residue - 1)
                printf("The missing element is %d.\n", arr[index] + counter);
        }
    }
    if(status == false)
        puts("There are no missing elements.");
    return 0;
}
//We can also do n(n+1)/2 - sum of array elements to find missing element -- Only if we have first N natural numbers in the array. Otherwise this
//will not work.
