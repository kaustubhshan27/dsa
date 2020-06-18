#include<stdio.h>

struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};

void initialize(struct array *arr);
void insert(struct array *arr, int element);
void display(const struct array *arr);

int main(void)
{
    puts("Enter the element to be inserted in sorted array: ");
    int element;
    scanf("%d", &element);
    struct array arr;
    puts("Initializing array:");
    initialize(&arr);
    insert(&arr, element);
    puts("Displaying array...");
    display(&arr);
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
void insert(struct array *arr, int element)
{
    int index;
    for(index = arr->length - 1; arr->arr_ptr[index] > element; index--)
    {
        arr->arr_ptr[index + 1] = arr->arr_ptr[index];
    }
    arr->arr_ptr[index + 1] = element;
    arr->length++;
}
void display(const struct array *arr)
{
    for(size_t index = 0; index < arr->length; index++)
        printf("%d ", arr->arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr->capacity, arr->length);
}
