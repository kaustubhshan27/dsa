#include<iostream>
#include<cmath>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node NODE;

void swap(int *x, int *y);
void display(int *arr, int size);
void bubbleSort(int *arr, int size);
void insertionSort(int *arr, int size);
void selectionSort(int *arr, int size);
int partition(int *arr, int low, int high);
void quickSort(int *arr, int low, int high);
void merge(int *arr, int low, int mid, int high);
void iterative_mergeSort(int *arr, int size);
void recursive_mergeSort(int *arr, int low, int high);
int findMax(int *arr, int size);
void countSort(int *arr, int size);
void binSort(int *arr, int size);
void radixSort(int *arr, int size);
void shellSort(int *arr, int size);

int main(void)
{
    int arr[] = {8, 3, 7, 4, 9, 2, 6, 10, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    //bubbleSort(arr, size);

    //insertionSort(arr, size);

    //selectionSort(arr, size);

    //quickSort(arr, 0, size - 1);

    //iterative_mergeSort(arr, size);

    //recursive_mergeSort(arr, 0, size - 1);

    //countSort(arr, size);

    //binSort(arr, size);

    //radixSort(arr, size);

    shellSort(arr, size);

    display(arr, size);

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(int *arr, int size)
{
    for(int index = 0; index < size; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
}

void bubbleSort(int *arr, int size)
{
    int flag;

    for(int pass = 0; pass < size - 1; pass++)
    {   
        flag = 0;
        for(int comp = 0; comp < size - 1 - pass; comp++)
        {
            if(arr[comp] > arr[comp + 1])
            {
                flag = 1;
                swap(&arr[comp], &arr[comp + 1]);
            }
        }
        /*
        No swaps performed and bubble sort get over in only one pass with O(n)comparisons. 
        This tweak makes bubble sort adaptive. Thus using a flag, bubble sort is made adaptive.
        */
        if(flag == 0)
            break;
    }
}

void insertionSort(int *arr, int size)
{
    int ele, index_i, index_j;

    /*
    For every iteration of index_i only 1 comparison will be performed if array is already sorted. 
    Therefore, a total of n comparisons => O(n). Insertion Sort is naturally adaptive.
    */
    for(index_i = 1; index_i < size; index_i++)
    {
        ele = arr[index_i];
        index_j = index_i - 1;
        while((index_j >= 0) && (arr[index_j] > ele))
        {
            arr[index_j + 1] = arr[index_j];
            index_j--;
        }
        arr[index_j + 1] = ele;
    }
}

void selectionSort(int *arr, int size)
{
    int index_i, index_j, index_k;

    for(index_i = 0; index_i < size - 1; index_i++)
    {
        index_j = index_i + 1;
        index_k = index_i;
        while(index_j < size)
        {
            if(arr[index_j] < arr[index_k])
                index_k = index_j;
            index_j++;
        }
        /*
        Sorted or not sorted, Selection Sort is always going to take O(n^2) time
        */
        swap(&arr[index_k], &arr[index_i]);
    }
}

int partition(int *arr, int low, int high)
{
    int ele = arr[low];
    int i = low;
    int j = high;

    while(i < j)
    {
        while(ele >= arr[i])
            i++;
        
        while(ele < arr[j])
            j--;

        if(i < j)
            swap(&arr[i], &arr[j]);
    } 
    swap(&arr[low], &arr[j]);

    return j;//returning partition position
}

void quickSort(int *arr, int low, int high)
{
    if(low < high)
    {
        int part = partition(arr, low, high);
        quickSort(arr, low, part - 1);//left side of partition
        quickSort(arr, part + 1, high);//right side of partition
    }
}

void merge(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int arr2[high-low+1];

    while((i <= mid) && (j <= high))
    {
        if(arr[i] < arr[j])
        {
            arr2[k++] = arr[i++];
        }
        else
        {
            arr2[k++] = arr[j++];
        }
    }
    for( ; i <= mid; i++)
    {
        arr2[k++] = arr[i];
    }
    for( ; j <= high; j++)
    {
        arr2[k++] = arr[j];
    }

    for(int index = low, k = 0; index < high + 1; index++, k++)
    {
        arr[index] = arr2[k];
    }
}

void iterative_mergeSort(int *arr, int size)
{
    int pass;
    for(pass = 2; pass <= size; pass = pass*2)
    {
        // (index + pass - 1) --> high index. To check if high index is within the array size
        for(int index = 0; index + pass - 1 < size; index = index + pass) 
        {
            int low = index;
            int high = index + pass - 1;
            int mid = (low + high)/2;

            merge(arr, low, mid, high);
        }
    }

    if(pass/2 < size)
        merge(arr, 0, pass/2 - 1, size-1);
}

void recursive_mergeSort(int *arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        recursive_mergeSort(arr, low, mid);
        recursive_mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int findMax(int *arr, int size)
{
    int max = arr[0];
    for(int index = 1; index < size; index++)
    {
        if(max < arr[index])
            max = arr[index];
    }

    return max;
}

void countSort(int *arr, int size)
{
    int max = findMax(arr, size);

    int c[max + 1];
    for(int index = 0; index < max + 1; index++)
        c[index] = 0;
    
    for(int index = 0; index < size; index++)
        c[arr[index]]++;
    
    int org_index = 0;
    int index = 0;
    while(index < max + 1)
    {
        if(c[index] > 0)
        {
            while(c[index] != 0)
            {
                arr[org_index++] = index;
                c[index]--;
            }
            index++;
        }
        else
            index++;
    }
}

void binSort(int *arr, int size)
{
    int max = findMax(arr, size);

    NODE **bins = new NODE* [max + 1];
    for(int node = 0; node < max + 1; node++)
    {
        bins[node] = NULL;
    }

    for(int index = 0; index < size; index++)
    {
        NODE *newNode = new NODE;
        newNode->data = arr[index];
        newNode->next = NULL;

        if(bins[arr[index]] == NULL)
        {
            bins[arr[index]] = newNode;
        }
        else
        {
            NODE *node = bins[arr[index]];
            while(node->next != NULL)
                node = node->next;
            
            node->next = newNode;
        }
    }

    int node = 0;
    int org_index = 0;
    while(node < max + 1)
    {
        if(bins[node] != NULL)
        {
            while(bins[node] != NULL)
            {
                if(bins[node]->next == NULL)
                {
                    arr[org_index++] = bins[node]->data;
                    delete bins[node];
                    bins[node] = NULL;
                }
                else
                {
                    arr[org_index++] = bins[node]->data;
                    NODE *temp = bins[node];
                    bins[node] = bins[node]->next;
                    delete temp;
                }
            }
            node++;
        }
        else
        {
            node++;
        }
    }

    delete[] bins;
}

void radixSort(int *arr, int size)
{
    //initializing auxilliary array to NULL
    NODE **aux = new NODE* [10];
    for(int index = 0; index < 10; index++)
    {
        aux[index] = NULL;
    }

    //finding the no. of digits in the max element
    int max = findMax(arr, size);
    int digits;
    while(max > 0)
    {
        max = max/10;
        digits++;
    }

    for(int pass = 0; pass < digits; pass++)
    {
        //filling the bin
        for(int index = 0; index < size; index++)
        {
            int number = (int)(arr[index]/pow(10, pass)) % 10;

            NODE *newNode = new NODE;
            newNode->data = arr[index];
            newNode->next = NULL;

            if(aux[number] == NULL)
            {
                aux[number] = newNode;
            }
            else
            {
                NODE *node = aux[number];
                while(node->next != NULL)
                    node = node->next;
                node->next = newNode;
            }
        }

        //emptying the bin
        int index = 0;
        int org_index = 0;
        while(index < 10)
        {
            if(aux[index] != NULL)
            {
                while(aux[index] != NULL)
                {
                    if(aux[index]->next == NULL)
                    {
                        arr[org_index++] = aux[index]->data;
                        delete aux[index];
                        aux[index] = NULL;
                    }
                    else
                    {
                        arr[org_index++] = aux[index]->data;
                        NODE *temp = aux[index];
                        aux[index] = aux[index]->next;
                        delete temp;
                    }
                }
                index++;
            }
            else
            {
                index++;
            }
        }
    }

    delete[] aux;
}

void shellSort(int *arr, int size)
{
    int gap, i, j;

    for(gap = size/2; gap >= 1; gap = gap/2)
    {
        for(i = gap; i < size; i++)
        {
            int temp = arr[i];
            j = i - gap;
            while(j >= 0 && arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j = j - gap;
            }
            arr[j + gap] = temp;
        }
    }
}