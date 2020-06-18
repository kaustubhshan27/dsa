#include<iostream>
using namespace std;

struct Matrix{
    int m;
    int n;
    int *arr;
};
typedef struct Matrix MAT;
MAT *mat1, *mat2;

void initialize_matrix(MAT **mat);
void multiply(MAT *mat1, MAT *mat2);
void display(MAT **mat);

int main(void)
{
    mat1 = new MAT;
    mat2 = new MAT;
    cout<< "Initialize matrix 1..."<<endl;
    initialize_matrix(&mat1);
    cout<< "Matrix 1..."<<endl;
    display(&mat1);
    cout<<"Initialize matrix 2..."<<endl;
    initialize_matrix(&mat2);
    cout<< "Matrix 1..."<<endl;
    display(&mat1);
    if(mat1->n != mat2->m)
        cout<<"They cannot be multiplied"<<endl;
    else
    {
        cout<<"Multiplying the two matrices..."<<endl;
        multiply(mat1, mat2);
    }

}

void initialize_matrix(MAT **mat)
{
    cout<<"Enter the number of rows:"<<endl;
    cin>>(*mat)->m;
    cout<<"Enter the number of columns:"<<endl;
    cin>>(*mat)->n;
    (*mat)->arr = new int [((*mat)->m) * ((*mat)->n)];
    cout<<"Enter the elements:"<<endl;
    for(int index_i = 0; index_i < (*mat)->m; index_i++)
    {
        for(int index_j = 0; index_j < (*mat)->n; index_j++)
            cin>>(*mat)->arr[((*mat)->n)*index_i + index_j];
    }
}

void multiply(MAT *mat1, MAT *mat2)
{
    MAT *mat3 = new MAT;
    mat3->m = mat1->m;
    mat3->n = mat2->n;
    mat3->arr = new int [(mat3->m) * (mat3->n)];
    for(int index_i = 0; index_i < mat1->m; index_i++)
    {
        for(int index_j = 0; index_j < mat2->n; index_j++)
        {
            mat3->arr[index_i*mat3->n + index_j] = 0;
            for(int index_k = 0; index_k < mat2->n; index_k++)
            {
                mat3->arr[index_i*mat3->n + index_j] += mat1->arr[index_i*mat1->n + index_k] * mat2->arr[index_k*mat2->n + index_j];
            }
        }
    }
    display(&mat3);
}

void display(MAT **mat)
{
    for(int index_i = 0; index_i < (*mat)->m; index_i++)
    {
        for(int index_j = 0; index_j < (*mat)->n; index_j++)
            cout<<(*mat)->arr[((*mat)->n)*index_i + index_j]<<" ";
        cout<<endl;
    }
}
