#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

void lowercase(char arr[]);
bool findAnagram(char *arr1, char *arr2);
//not the best way to find anagram. We use bit map here which is capable of only giving info if letter
//present or not and not about its' frequency.
//To store frequency and presence its' better to use a conventional hash table for more robust checking 
//of anagrams.
int main(void)
{
    char arr1[] = "aab";//problem - aab & abb
    char arr2[] = "abb";
    lowercase(arr1);
    lowercase(arr2);
    if(strlen(arr1) == strlen(arr2))
    {
        if(findAnagram(arr1, arr2))
            puts("They are Anagram.");
        else
            puts("They are not Anagram.");
    }
    else
        puts("They are not Anagram.");
    return 0;
}
void lowercase(char arr[])
{
    for(size_t index = 0; index < strlen(arr); index++)
        arr[index] = tolower(arr[index]);
}
bool findAnagram(char *arr1, char *arr2)
{
    unsigned int x = 0;
    unsigned int lower_bits = 0;
    for(size_t index = 0; index < strlen(arr1); index++)
    {
        x = 1;
        x = x << (arr1[index] - 97);
        if((x & lower_bits) == 0)
            lower_bits = lower_bits | x;
    }
    for(size_t index = 0; index < strlen(arr2); index++)
    {
        x = 1;
        x = x << (arr2[index] - 97);
        if((x & lower_bits) == 0)
        {
            return false;
        }
    }
    return true;
}
