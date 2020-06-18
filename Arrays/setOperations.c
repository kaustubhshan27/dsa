#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct array
{
    int *arr_ptr;
    int capacity;
    int length;
};

void initialize(struct array *arr);
int checkSorted(struct array *arr);
void unionSort(struct array *arr1, struct array *arr2);
void unionUnsort(struct array *arr1, struct array *arr2);
void interSort(struct array *arr1, struct array *arr2);
void interUnsort(struct array *arr1, struct array *arr2);

int main(void)
{
    puts("Initialize array 1: ");
    struct array arr1;
    initialize(&arr1);
    puts("Initialize array 2: ");
    struct array arr2;
    initialize(&arr2);
    if(checkSorted(&arr1) == 0 && checkSorted(&arr2) == 0)
        {
            unionSort(&arr1, &arr2);//sorted
            interSort(&arr1, &arr2);
        }
    else
        {
            unionUnSort(&arr1, &arr2);//unsorted
            interUnSort(&arr1, &arr2);
        }
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
void unionSort(struct array *arr1, struct array *arr2)
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
    puts("Printing the Union: ");
    arr3.length = arr3.length - count;
    for(size_t index = 0; index < arr3.length; index++)
        printf("%d ", arr3.arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr3.capacity, arr3.length);
}
void unionUnsort(struct array *arr1, struct array *arr2)
{
    struct array arr3;
    arr3.length = arr1->length + arr2->length;
    arr3.capacity = arr1->capacity + arr2->capacity;
    arr3.arr_ptr = (int *)malloc(arr3.capacity*sizeof(int));
    memcpy(arr3.arr_ptr, arr1->arr_ptr, arr1->length*sizeof(int));
    int copy_index = arr1->length;
    bool status;
    int count = 0;
    for(size_t index2 = 0; index2 < arr2->length; index2++)
    {
        status = true;
        for(size_t index3 = 0; index3 < arr1->length; index3++)//checking if element already present
        {
            if(arr3.arr_ptr[index3] == arr2->arr_ptr[index2])
            {
                    status = false;
                    count++;//number of elements common to both the arrays
                    break;
            }
        }
        if(status == true)
        {
            arr3.arr_ptr[copy_index] = arr2->arr_ptr[index2];//appending elements to array after the last index 
            copy_index++;//incrementing appending index
        }
    }
    puts("Printing the Union: ");
    arr3.length = arr3.length - count;
    for(size_t index = 0; index < arr3.length; index++)
        printf("%d ", arr3.arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr3.capacity, arr3.length);
    free(arr3.arr_ptr);
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
void interSort(struct array *arr1, struct array *arr2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    struct array arr3;
    arr3.length = (arr1->length > arr2->length) ? arr2->length : arr1->length;
    arr3.capacity = (arr1->capacity > arr2->capacity) ? arr2->capacity : arr1->capacity;
    arr3.arr_ptr = (int *)malloc(arr3.capacity*sizeof(int));
    while(i < (arr1->length) && j < (arr2->length))
    {
        if(arr1->arr_ptr[i] < arr2->arr_ptr[j])
        {
            i++;
        }
        else if(arr1->arr_ptr[i] > arr2->arr_ptr[j])
        {
            j++;
        }
        else
        {
            arr3.arr_ptr[k++] = arr2->arr_ptr[j++];
            i++;
            count++;
        }
    }
    puts("Printing the Intersection: ");
    for(size_t index = 0; index < count; index++)
        printf("%d ", arr3.arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr3.capacity, arr3.length);
}
void interUnsort(struct array *arr1, struct array *arr2)
{
    struct array arr3;
    arr3.length = (arr1->length > arr2->length) ? arr2->length : arr1->length;
    arr3.capacity = (arr1->capacity > arr2->capacity) ? arr2->capacity : arr1->capacity;
    arr3.arr_ptr = (int *)malloc(arr3.capacity*sizeof(int));
    bool status;
    int copy_index = 0;
    for(size_t index2 = 0; index2 < arr2->length; index2++)
    {
        status = false;
        for(size_t index1 = 0; index1 < arr1->length; index1++)
        {
            if(arr1->arr_ptr[index1] == arr2->arr_ptr[index2])
            {
                    status = true;
                    break;
            }
        }
        if(status == true)
        {
            arr3.arr_ptr[copy_index] = arr2->arr_ptr[index2];
            copy_index++;
        }
    }
    puts("Printing the Intersection: ");
    for(size_t index = 0; index < copy_index; index++)
        printf("%d ", arr3.arr_ptr[index]);
    printf("\nCapacity of array is = %d\nLength of array is = %d\n", arr3.capacity, arr3.length);
    free(arr3.arr_ptr);
}
