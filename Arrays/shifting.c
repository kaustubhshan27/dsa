#include<stdio.h>
#include<stdlib.h>

struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};

void initialize(struct array *arr);
void Lshift(struct array arr, int places);
void Rshift(struct array arr, int places);
void display(const struct array *arr);

int main(void)
{
    puts("Initialize array: ");
    struct array arr;
    initialize(&arr);
    puts("Enter the number of spaces to shift: ");
    int places;
    scanf("%d", &places);
    puts("Shifting Left...");
    Lshift(arr, places);
    puts("Shifting Right...");
    Rshift(arr, places);
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
void Lshift(struct array arr, int places)
{
    size_t index;
    size_t times;
    for(times = 1; times <= places; times++)
    {
        for(index = 0; index < arr.length - 1; index++)
        {
            arr.arr_ptr[index] = arr.arr_ptr[index + 1];
        }
        arr.arr_ptr[index] = 0;
    }
    display(&arr);
}
void Rshift(struct array arr, int places)
{
    int index;
    size_t times;
    for(size_t times = 1; times <= places; times++)
    {
        for(index = arr.length - 1; index > 0; index--)
        {
            arr.arr_ptr[index] = arr.arr_ptr[index - 1];
        }
        arr.arr_ptr[index] = 0;
    }
    display(&arr);
}
void display(const struct array *arr)
{
    for(size_t index = 0; index < arr->length; index++)
        printf("%d ", arr->arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr->capacity, arr->length);
}
