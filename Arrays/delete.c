#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};


void initialize(struct array *arr);

void deleter(struct array *arr, int position);

void display(const struct array *arr);

int main(void)
{
    puts("Initialize array: ");
    struct array arr;
    initialize(&arr);
    printf("Enter position to delete element (<=%d):\n", arr.length);
    int position;
    while(scanf("%d", &position) && arr.length < position)
        printf("Please enter valid position (<=%d):\n", arr.length);
    puts("Deleting element...");
    deleter(&arr, position - 1);//adjusting index for user
    puts("Displaying the modified array :");
    display(&arr);
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

void deleter(struct array *arr, int position)
{
    for(int index = position; index < arr->length - 1; index++)
    {
        arr->arr_ptr[index] = arr->arr_ptr[index + 1];
    }
    arr->length--;
    puts("DELETION COMPLETE!");
}

void display(const struct array *arr)
{
    for(size_t index = 0; index < arr->length; index++)
        printf("%d ", arr->arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr->capacity, arr->length);
}

