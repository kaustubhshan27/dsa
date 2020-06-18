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

void insert(struct array *arr, int position, int element);

void display(struct array *arr);

int main(void)
{
    puts("Initialize array: ");
    struct array arr;
    initialize(&arr);
    printf("Enter position to insert element (<=%d):\n", arr.length);
    int position;
    while(scanf("%d", &position) && arr.length < position)
        printf("Please enter valid position (<=%d):\n", arr.length);
    puts("Enter the element");
    int element;
    scanf("%d", &element);
    puts("Inserting element...");
    insert(&arr, position - 1, element);//adjusting index for user
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
    printf("Enter the number of elements to be entered (<=%d): \n", arr->capacity);
     while(scanf("%d", &arr->length) && arr->length > arr->capacity)
        printf("Please enter valid length (<=%d):\n", arr->capacity);
    puts("Enter the elements: ");
    for(size_t index = 0; index < arr->length; index++)
        scanf("%d", &arr->arr_ptr[index]);
    puts("INITIALIZATION COMPLETE!");
}

void insert(struct array *arr, int position, int element)
{
    if(arr->capacity == arr->length)//if length = capacity we need to increase array capacity by 1 to accomodate the new element
        {
            arr->capacity = arr->capacity + 1;
            int *temp_ptr;
            temp_ptr = (int *)malloc(arr->capacity*sizeof(int));
            memcpy(temp_ptr, arr->arr_ptr, sizeof(int) * arr->length);
            free(arr->arr_ptr);
            arr->arr_ptr = temp_ptr;
            temp_ptr = NULL;
        }
    for(int index = arr->length - 1; index >= position; index--)
    {
        arr->arr_ptr[index + 1] = arr->arr_ptr[index];
    }
    arr->arr_ptr[position] = element;
    arr->length++;
    puts("INSERTION COMPLETE!");
}

void display(struct array *arr)
{
    for(size_t index = 0; index < arr->length; index++)
        printf("%d ", arr->arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr->capacity, arr->length);
}
