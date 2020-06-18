#include<stdio.h>
#include<stdlib.h>

struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};

void initialize(struct array *arr);
int *linear_search(const struct array *arr, int element);
void swap(int *ele_prev, int *ele_current);
void display(const struct array *arr);

int main(void)
{
    puts("Initialize array: ");
    struct array arr;
    initialize(&arr);
    puts("Enter the element to be searched:");
    int element;
    scanf("%d", &element);
    int *return_index;
    return_index = linear_search(&arr, element);
    if(*return_index == -1)
        puts("Element not found.");
    else
        printf("The element is found at position %d", *return_index + 1);
    free(return_index);
    return_index = NULL;
    puts("\nDisplaying the array (for optimized linear search):");
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
int *linear_search(const struct array *arr, int element)
{
    int *index;
    index = (int *)malloc(sizeof(int) * 1);
    for(*index = 0; *index < arr->length; (*index)++)
        if(arr->arr_ptr[*index] == element)
            {
                swap(&arr->arr_ptr[*index], &arr->arr_ptr[*index - 1]);//Optimize linear search
                return index;
            }
    *index = -1;
    return index;
}
void swap(int *ele_prev, int *ele_current)
{
    int temp;
    temp = *ele_prev;
    *ele_prev = *ele_current;
    *ele_current = temp;
}
void display(const struct array *arr)
{
    for(size_t index = 0; index < arr->length; index++)
        printf("%d ", arr->arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr->capacity, arr->length);
}
