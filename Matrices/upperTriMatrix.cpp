#include<iostream>

using namespace std;
//Used Row major
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
    if(i <= j)
        cout << A[n*(i - 1) - ((i-1)*(i-2)/2) + j - i] << endl;
    else
        cout << 0 << endl;
}
void Matrix::setter(int i, int j, int x)
{
    if(i <= j)
        A[n*(i - 1) - ((i-1)*(i-2)/2) + j - i] = x;
}
void Matrix::display()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            {
                if(i <= j)
                    cout << A[n*(i - 1) - ((i-1)*(i-2)/2) + j - i] << " ";
                else
                    cout << 0 <<" ";
            }
        cout << "\n";
    }
}
int main(void)
{
    Matrix m;
    m.setter(3, 3, 1);m.setter(1, 3, 2);m.setter(2, 3, 3);m.setter(2, 2, 4);m.setter(1, 1, 5);m.setter(1, 2, 6);
    m.getter(3, 3);
    m.display();
    return 0;
}

