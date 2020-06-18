#include<stdio.h>

struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};

void initialize(struct array *arr);
int checkSorted(struct array *arr);

int main(void)
{
    struct array arr;
    puts("Initializing array:");
    initialize(&arr);
    puts("Checking if array is sorted...");
    if(checkSorted(&arr) == -1)
        puts("Array is not sorted.");
    else
        puts("Array is sorted.");
    return 0;
}
void initialize(struct array *arr)
{
    puts("Enter the capacity of the array: ");
    scanf("%d", &arr->capacity);
    arr->arr_ptr = (int *)malloc(arr->capacity*sizeof(int));
    printf("Enter the number of elements to be entered (<=%d): \n",arr->capacity);
     while(scanf("%d", &arr->length) && arr->length > arr->capacity)
        printf("Please enter valid length (<=%d):\n", arr->capacity);
    puts("Enter the elements: ");
    for(size_t index = 0; index < arr->length; index++)
        scanf("%d", &arr->arr_ptr[index]);
    puts("INITIALIZATION COMPLETE!");
}
int checkSorted(struct array *arr)
{
    for(size_t index = 0; index < arr->length - 1; index++)
    {
        if(arr->arr_ptr[index] > arr->arr_ptr[index + 1])
            return -1;
    }
    return 0;
}

