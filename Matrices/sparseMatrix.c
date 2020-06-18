#include<stdio.h>
#include<stdlib.h>

struct Element
{
    int i;//row no. of element
    int j;//column no. of element
    int ele;
};
struct Sparse
{
    int m;//total no. of rows
    int n;//total no. of columns
    int num;//total no. of non-zero elements
    struct Element *column;//column for each element in the coordinate list 
};
void setSparse(struct Sparse *sp)
{
    puts("Enter the number of rows: ");
    scanf("%d", &sp->m);
    puts("Enter the number of columns: ");
    scanf("%d", &sp->n);
    puts("Enter the number of non-zero elements: ");
    scanf("%d", &sp->num);
    int k = 0;
    sp->column = (struct Element *)malloc(sp->num * sizeof(struct Element));
    puts("Enter all the elements: ");
    for(size_t index_i = 0; index_i < sp->m; index_i++)
    {
        for(size_t index_j = 0; index_j < sp->n; index_j++)
        {
            int val;
            if(scanf("%d", &val) && val != 0)
            {
                sp->column[k].i = index_i;
                sp->column[k].j = index_j;
                sp->column[k].ele = val;
                k++;
            }
        }
    }
}
void display(const struct Sparse *sp)
{
    int k = 0;
    for(size_t index_i = 0; index_i < sp->m; index_i++)
    {
        for(size_t index_j = 0; index_j < sp->n; index_j++)
        {
            if(sp->column[k].i == index_i && sp->column[k].j == index_j)
            {
                printf("%d ", sp->column[k].ele);
                k++;
            }
            else
                printf("%d ", 0);
        }
        fputs("\n", stdout);
    }
}
void addSparse(struct Sparse *matA, struct Sparse *matB)
{
    struct Sparse matC;
    if(matA->m != matB->m || matA->n != matB->n)
    {
        puts("Cannot add two matrices.");
        return;
    }
    else
    {
        matC.m = matA->m;
        matC.n = matB->n;
        matC.column = (struct Element *)malloc((matA->num + matB->num) * sizeof(struct Element));
        int index_A = 0, index_B = 0, index_C = 0;
        while(index_A < matA->num && index_B < matB->num)
        {
            if(matA->column[index_A].i < matB->column[index_B].i)
                matC.column[index_C++] = matA->column[index_A++];   //assigning the whole struct
            else if(matA->column[index_A].i > matB->column[index_B].i)
                matC.column[index_C++] = matB->column[index_B++];   //assigning the whole struct
            else
            {
                if(matA->column[index_A].j < matB->column[index_B].j)
                    matC.column[index_C++] = matA->column[index_A++];//assigning the whole struct
                else if(matA->column[index_A].j > matB->column[index_B].j)
                    matC.column[index_C++] = matB->column[index_B++];//assiging the whole struct
                else
                {
                    matC.column[index_C] = matA->column[index_A];//assigning the whole struct
                    matC.column[index_C].ele += matB->column[index_B].ele;
                    index_A++;
                    index_B++;
                    index_C++;
                }
            }
        }
        while(index_A < matA->num)
            matC.column[index_C++] = matA->column[index_A++];
        while(index_B < matB->num)
            matC.column[index_C++] = matB->column[index_B++];
    }
    puts("Sum of the matrices are:");
    display(&matC);
}
int main(void)
{
    struct Sparse matA;
    struct Sparse matB;
    puts("Enter details of Matrix A: ");
    setSparse(&matA);
    puts("The matrix A is: ");
    display(&matA);
    puts("Enter details of Matrix B: ");
    setSparse(&matB);
    puts("The matrix B is: ");
    display(&matB);
    addSparse(&matA, &matB);
    return 0;
}
