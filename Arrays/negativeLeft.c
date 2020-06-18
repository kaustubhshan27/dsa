#include<stdio.h>
#include<stdlib.h>

struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};

void initialize(struct array *arr);
void negLeft(struct array *arr);
void display(const struct array *arr);
void swap(int *ele_prev, int *ele_current);

static int i, j;

int main(void)
{
    struct array arr;
    puts("Initializing array:");
    initialize(&arr);
    puts("Modifying array...");
    i = 0;
    j = arr.length - 1;
    while(i < j)
    {
        negLeft(&arr);
    }
    puts("The array is:");
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
void swap(int *ele_prev, int *ele_current)
{
    int temp;
    temp = *ele_prev;
    *ele_prev = *ele_current;
    *ele_current = temp;
    i++;
    j--;
}
void negLeft(struct array *arr)
{
    while(arr->arr_ptr[i] < 0)
        i++;
    while(arr->arr_ptr[j] >= 0)
        j--;
    if(i < j)
        swap(&arr->arr_ptr[i], &arr->arr_ptr[j]);
}
void display(const struct array *arr)
{
    for(size_t index = 0; index < arr->length; index++)
        printf("%d ", arr->arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr->capacity, arr->length);
}
