#include<stdio.h>
#include<stdlib.h>
//Merging only for sorted arrays
struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};

void initialize(struct array *arr);
void merge(struct array *arr1, struct array *arr2);

int main(void)
{
    puts("Initialize array 1: ");
    struct array arr1;
    initialize(&arr1);
    puts("Initialize array 2: ");
    struct array arr2;
    initialize(&arr2);
    puts("Merging the arrays:");
    merge(&arr1, &arr2);
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
void merge(struct array *arr1, struct array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    struct array arr3;
    arr3.length = arr1->length + arr2->length;
    arr3.capacity = arr1->capacity + arr2->capacity;
    arr3.arr_ptr = (int *)malloc(arr3.capacity*sizeof(int));
    while(i < (arr1->length) && j < (arr2->length))
    {
        if(arr1->arr_ptr[i] < arr2->arr_ptr[j])
            arr3.arr_ptr[k++] = arr1->arr_ptr[i++];
        else if(arr1->arr_ptr[i] > arr2->arr_ptr[j])
            arr3.arr_ptr[k++] = arr2->arr_ptr[j++];
        else
        {
            arr3.arr_ptr[k++] = arr2->arr_ptr[j++];
            i++;
            count++;
        }
    }
    for( ; i < arr1->length; i++)
        arr3.arr_ptr[k++] = arr1->arr_ptr[i];
    for( ; j < arr2->length; j++)
        arr3.arr_ptr[k++] = arr2->arr_ptr[j];
    puts("Printing the merged array: ");
    arr3.length = arr3.length - count;
    for(size_t index = 0; index < arr3.length; index++)
        printf("%d ", arr3.arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr3.capacity, arr3.length);
}
