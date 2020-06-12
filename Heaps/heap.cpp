#include<iostream>
using namespace std;

void swap(int *ele1, int *ele2);
void displayHeap(int *heap, int size);//T(n) = O(n)
void insert_MaxHeap(int *heap, int index);//works for heaps with duplicate elements - T(n) = O(logn)
void create_MaxHeap(int *heap, int size);//works for heaps with duplicate elements - T(n) = O(nlogn)
void delete_MaxHeap(int *heap, int *size);//works for heaps with duplicate elements - T(n) = O(logn)
void max_heapSort(int *heap, int size);//works for heaps with duplicate elements - T(n) = O(nlogn)
void max_heapify(int *heap, int size, int index);//works for heaps with duplicate elements - T(n) = O(logn)

int main(void)
{
    //the same elements in a different order may produce a different heap structure
    int heap1[] = {5, 10, 30, 20, 35, 40, 15, 15, 10, 40};
    int size1 = sizeof(heap1)/sizeof(heap1[0]);

    //create max heap 
    create_MaxHeap(heap1, size1);//works for heaps with duplicate elements
    displayHeap(heap1, size1);

    //deleting 2 elements from the heap. "size" variable is being decremented after every deletion
    delete_MaxHeap(heap1, &size1);//works for heaps with duplicate elements
    displayHeap(heap1, size1);
    delete_MaxHeap(heap1, &size1);
    displayHeap(heap1, size1);

    int heap2[] = {5, 10, 30, 20, 35, 40, 15, 15, 10, 40};
    int size2 = sizeof(heap2)/sizeof(heap2[0]);

    /*
    Steps of heap sorting:
        1. create the heap
        2. delete all elements one by one
    Resulting array is sorted
    */
    max_heapSort(heap2, size2);//works for heaps with duplicate elements
    displayHeap(heap2, size2);

    int heap3[] = {5, 10, 30, 20, 35, 40, 15, 15, 10, 40, 35, 100};
    int size3 = sizeof(heap3)/sizeof(heap3[0]);
    //creating max heap using heapify
    //"index" starts from parent of last child
    for(int index = (size3-1)/2; index >= 0; index--)//this build process time complexity is - T(n) = O(n)
        max_heapify(heap3, size3, index);
    displayHeap(heap3, size3);

    return 0;
}

void swap(int *ele1, int *ele2)
{
    int temp = *ele1;
    *ele1 = *ele2;  
    *ele2 = temp;
}

void displayHeap(int *heap, int size)
{
    for(int index = 0; index < size; index++)
    {
        cout << heap[index] << " ";
    }
    cout << endl;
}

void insert_MaxHeap(int *heap, int index)
{
    int temp = heap[index];
    while((index > 0) && (heap[(index-1)/2] < temp))
    {
        heap[index] = heap[(index-1)/2];
        index = (index-1)/2;
    }
    heap[index] = temp;
}

void create_MaxHeap(int *heap, int size)
{
    for(int index = 1; index < size; index++)
    {
        insert_MaxHeap(heap, index);
    }
}

void delete_MaxHeap(int *heap, int *size)
{
    int last_index = (*size) - 1;
    swap(&heap[0], &heap[last_index]);//root element is replaced by the last element of the heap array, the root element is "deleted"

    *size = *size - 1;//after deleting the root reducing the size of heap by 1 
    last_index = (*size) - 1;//after deleting the root, the last index should be decremented

    int current_index = 0;

    while(current_index < last_index)//if (index == (*size)) there is no further going so just stop
    {
        int lchild_index = 2*current_index + 1;
        int rchild_index = 2*current_index + 2;
        int selected_child_index;

        if(lchild_index <= last_index && rchild_index <= last_index)//both left and right child present
            selected_child_index = (heap[rchild_index] > heap[lchild_index]) ? rchild_index:lchild_index;
        else if(lchild_index <= last_index && rchild_index > last_index)
            selected_child_index = lchild_index;//no right child
        else if(lchild_index > last_index && rchild_index > last_index)
            break;//no child
        //a case of no left child and presence of right childis not possible because 
        //then the heap will not be a complete binary tree

        if(heap[current_index] < heap[selected_child_index])
        {
            //swap elements
            swap(&heap[current_index], &heap[selected_child_index]);

            //change the current index
            current_index = selected_child_index; 
        }
        else
        {
            /*
            Assume that in the right subtree of the root node, all elements are equal (it is still a 
            valid max heap) and the left child of the root is lesser than all those elements. In this
            case "else" condition will be triggered. Here we don't have to interchange any nodes. We 
            just have to break from the loop.
            */
            break;
        }
    }
}

void max_heapSort(int *heap, int size)
{
    create_MaxHeap(heap, size);
    //displayHeap(heap, size);
    int num_of_elements = size;

    for(int times = 0; times < num_of_elements; times++)//delete each element. The end product is a sorted heap(array)
    {
        delete_MaxHeap(heap, &size);
    }
}

void max_heapify(int *heap, int size, int index)
{
    int selected_index = index;
    int lchild = 2*index + 1;
    int rchild = 2*index + 2;

    if(lchild < size)
    {
        if(rchild < size)//both left and right child exist. Choose the greater one
        {
            selected_index = (heap[lchild] > heap[rchild]) ? lchild:rchild;
        }
        else//only lchild exists
        {
            selected_index = lchild;
        }
    }

    if((selected_index != index) && (heap[selected_index] > heap[index]))
    {
        swap(&heap[index], &heap[selected_index]);
        max_heapify(heap, size, selected_index);
    }
}