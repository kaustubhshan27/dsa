#include<iostream>

using namespace std;

int reverse(int num);

int main(void)
{
    int no;
    cout<<"ENTER A NUMBER"<<endl;
    cin>>no;
    cout<<"THE REVERSED NUMBER IS "<<reverse(no)<<endl;
    return 0;
}
int reverse(int num)
{
    static int sum=0;
    if(num!=0)
    {
        sum=(sum*10)+(num%10);
        reverse(num/10);
    }
    else
        return(sum); 
}