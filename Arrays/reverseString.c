#include<stdio.h>

int main(void)
{
    char arr[] = "Python";
    int size = strlen(arr);
    int i = 0;
    int j = size - 1;
    char temp;
    while(i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    puts("Reversed string is: ");
    fputs(arr, stdout);
    return 0;
}
