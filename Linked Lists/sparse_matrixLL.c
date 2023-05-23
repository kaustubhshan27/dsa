#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    int col;
    struct Node *next;
};
typedef struct Node NODE;
/* array of pointers to NODE. Each element for a particular row in the matrix */
NODE *arr1;/* user entered matrix 1 */
NODE *arr2;/* user entered matrix 2 */
NODE *arr3;/* sum of matrices */

/* pointer to pointer for the purpose of performing */ 
/* manipulation and access operations on the same matrix */
void createSparse(NODE **, int, int);
void displaySparse(NODE **, int, int);
void addSparse(NODE **, NODE **, int, int);

int main(void)
{
    int rows, columns;
    fputs("Enter the number of rows: \n", stdout);
    scanf("%d", &rows);
    
    fputs("Enter the number of columns: \n", stdout);
    scanf("%d", &columns);
    
    fputs("Creating Sparse Matrix 1: \n", stdout);
    /* passing address of pointer */
    createSparse(&arr1, rows, columns);
    
    fputs("Displaying Sparse Matrix 1: \n", stdout);
    displaySparse(&arr1, rows, columns);

    fputs("Creating Sparse Matrix 2: \n", stdout);
    createSparse(&arr2, rows, columns);

    fputs("Displaying Sparse Matrix 2: \n", stdout);
    displaySparse(&arr2, rows, columns);

    fputs("Adding the sparse matrices: \n", stdout);
    addSparse(&arr1, &arr2, rows, columns);

    fputs("Displaying the summed matrix: \n", stdout);
    displaySparse(&arr3, rows, columns);
    return 0;
}

void createSparse(NODE **arr, int rows, int columns)
{
    *arr = (NODE *)malloc(rows*sizeof(NODE)); /* creating array of structures with array size = no. of rows */
    for(size_t index_row = 0; index_row < rows; index_row++)
        (*arr)[index_row].next = NULL; /* initializing "next" of each element of the array(struct) as NULL */
    int element;
    fputs("Enter the elements: \n", stdout);
    for(size_t index_row = 0; index_row < rows; index_row++) /* getting the non-zero elements */
    {
        NODE *prev = NULL;
        for(size_t index_col = 0; index_col < columns; index_col++)
        {
            scanf("%d", &element);
            if(element != 0)
            {
                NODE *newNode;
                newNode = (NODE *)malloc(sizeof(NODE));
                newNode->data = element;
                newNode->col = index_col;
                newNode->next = NULL;

                if((*arr)[index_row].next == NULL) /* checking to see if it is the first element to be entered */
                    (*arr)[index_row].next = newNode;
                else
                    prev->next = newNode;

                prev = newNode;
            }
        }
    }
}

void displaySparse(NODE **arr, int rows, int columns)
{
    NODE *ptr;
    for(size_t index_row = 0; index_row < rows; index_row++)
    {
        ptr = (*arr)[index_row].next;
        
        for(size_t index_col = 0; index_col < columns; index_col++)
        {   
            if(ptr != NULL && index_col == ptr->col) /* to prevent invalid access in the case of ptr == NULL */
            {
                printf("%d ", ptr->data);
                    ptr = ptr->next;
            }
            else
                printf("0 ");
        }
        putchar('\n');    
    }
}

/* merging is not used [O(n)]. We could have used merging if the coordinate list was defined differently. Here we have O(n^2) */
void addSparse(NODE **arr1, NODE **arr2, int rows, int columns)
{
    arr3 = (NODE *)malloc(rows*sizeof(NODE));
    for(size_t index_row = 0; index_row < rows; index_row++)
        arr3[index_row].next = NULL;
    NODE *ptr1, *ptr2;

    for(size_t index_row = 0; index_row < rows; index_row++)
    {
        ptr1 = (*arr1)[index_row].next;
        ptr2 = (*arr2)[index_row].next;
        NODE *prev = NULL;
        for(size_t index_col = 0; index_col < columns; index_col++)
        {
            if((ptr1 != NULL && ptr1->col == index_col) || (ptr2 != NULL && ptr2->col == index_col)) /* precaution for segmentation fault */
            {
                NODE *newNode;
                newNode = (NODE *)malloc(sizeof(NODE));
                if((ptr1 != NULL && ptr1->col == index_col) && (ptr2 != NULL && ptr2->col != index_col)) /* precaution for segmentation fault */
                {
                    newNode->data = ptr1->data;
                    if(ptr1->next != NULL)
                        ptr1 = ptr1->next;
                }
                else if((ptr2 != NULL && ptr2->col == index_col) &&(ptr1 != NULL && ptr1->col != index_col)) /* precaution for segmentation fault */
                {
                    newNode->data = ptr2->data;
                    if(ptr2->next != NULL)
                        ptr2 = ptr2->next;
                }
                else if((ptr1 != NULL && ptr1->col == index_col) && (ptr2 != NULL && ptr2->col == index_col)) /* precaution for segmentation fault */
                {
                    newNode->data = ptr1->data + ptr2->data;
                    if(ptr1->next != NULL)
                        ptr1 = ptr1->next;
                    if(ptr2->next != NULL)
                        ptr2 = ptr2->next;
                }
                newNode->col = index_col;
                newNode->next = NULL;

                if(arr3[index_row].next == NULL)
                    arr3[index_row].next = newNode;
                else
                    prev->next = newNode;

                prev = newNode;
            }
        }
    }
}
