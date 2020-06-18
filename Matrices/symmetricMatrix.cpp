#include<iostream>
using namespace std;
//Lower Matrix, Row major
class Matrix
{
private:
    int n;
    int *A;
public:
    Matrix()
    {
        n = 3;
        A = new int[n*(n+1)/2];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void getter(int i, int j);
    void setter(int i, int j, int x);
    void display();
    ~Matrix(){delete []A;}
};
void Matrix::getter(int i, int j)
{
    if(i >= j)
        cout << A[(i*(i - 1)/2) + (j - 1)] << endl;
    else if(i < j)
        cout << A[(j*(j - 1)/2) + (i - 1)] << endl;
    else
        cout << 0 << endl;
}
void Matrix::setter(int i, int j, int x)
{
    if(i >= j)
        A[(i*(i - 1)/2) + (j - 1)] = x;
    else if(i < j)
        A[(j*(j - 1)/2) + (i - 1)] = x;
}
void Matrix::display()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            {
                if(i >= j)
                    cout << A[(i*(i - 1)/2) + (j - 1)] << " ";
                else if(i < j)
                    cout << A[(j*(j - 1)/2) + (i - 1)] << " ";
            }
        cout << "\n";
    }
}
int main(void)
{
    Matrix m(3);
    m.setter(1, 1, 1);m.setter(1, 2, 2);m.setter(1, 3, 4);m.setter(2, 1, 2);m.setter(2, 2, 3);m.setter(2, 3, 5);m.setter(3, 1, 4);m.setter(3, 2, 5);m.setter(3, 3, 6);
    m.display();
    return 0;
}

