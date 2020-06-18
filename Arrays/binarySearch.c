#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};

void initialize(struct array *arr);
int binary_search(const struct array *arr, int element, int low, int high);
bool binarySearch(const struct array *arr, int element, int low, int high);

static int low, high, mid = 0;

int main(void)
{
    puts("Initialize array: ");
    struct array arr;
    initialize(&arr);
    puts("Enter the element to be searched:");
    int element;
    scanf("%d", &element);
    int return_index;
    low = 0;
    high = arr.length - 1;
    if(!binarySearch(&arr, element, low, high))
        puts("Element not found.");
    else
        printf("The element is found.");
    puts("Thank You!");
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

/*
int binary_search(const struct array *arr, int element, int low, int high)
{
    if(low <= high)
    {
        mid = (low + high)/2;
        if(arr->arr_ptr[mid] == element)
            return mid;
        else if(arr->arr_ptr[mid] < element)
            return binary_search(arr, element, mid + 1, high);
        else
            return binary_search(arr, element, low, mid - 1);
    }
    return -1;
}
*/

bool binarySearch(const struct array *arr, int element, int low, int high)
{
    if(low > high)
        return false;
    else
    {
        mid = (low + high) / 2;
        if(arr->arr_ptr[mid] == element)
            return true;
        else if(arr->arr_ptr[mid] > element)
            return binarySearch(arr, element, low, mid - 1);
        else 
            return binarySearch(arr, element, mid + 1, high);
    }
}


