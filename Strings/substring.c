#include<stdio.h>
#include<string.h>

int main()
{
    char str[100],word[20];
    int i,j=0,lstr,lword,freq=0,store;
    int pos;
    printf("\nENTER A SENTENCE\n");
    gets(str);
    printf("\nENTER THE WORD TO BE SEARCHED\n");
    gets(word);
    lstr=strlen(str);
    lword=strlen(word);
    for(i=0;i<lstr;i++)
    {
        if(str[i]==word[j])
        {
            j++;
        }
        if(j==lword)
        {
            store=j;
            freq++;
            pos=i-lword+2;
            printf("POSITION OF THE WORD IS %d\n",pos);
            j=0;
        }
    }
    if(store==lword)
        printf("\nTHE WORD IS PRESENT IN THE SENTENCE\n");
    else
        printf("IT IS NOT PRESENT IN THE SENTENCE\n");
    printf("THE FREQUENCY OF THE WORD IS %d",freq);
    return 0;
}
