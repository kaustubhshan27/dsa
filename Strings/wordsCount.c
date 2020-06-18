#include<stdio.h>

int main(void)
{
    char arr[] = "How are you?";
    int count = 1;
    for(size_t index = 0; arr[index] != '\0'; index++)
    {
        if(arr[index] != ' ' && arr[index + 1] == ' ')
            count++;
    }
    printf("Number of words are: %d\n", count);
}
