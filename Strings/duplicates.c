#include<stdio.h>
#include<string.h>

int main(void)
{
    char arr[] = "FFinding";
    int upper_bits = 0;
    int lower_bits = 0;
    int x = 0;
    for(size_t index = 0; index < strlen(arr); index++)
    {
        x = 1;
        if(arr[index] > 65 && arr[index] < 90)
        {
            x = x << (arr[index] - 65);
            if((x & upper_bits) > 0)
                printf("%c is a duplicate.\n", arr[index]);
            else
                upper_bits = upper_bits | x;
        }
        else if(arr[index] > 97 && arr[index] < 122)
        {
            x = x << (arr[index] - 97);
            if((x & lower_bits) > 0)
                printf("%c is a duplicate.\n", arr[index]);
            else
                lower_bits = lower_bits | x;
        }
    }
}
