#include<stdio.h>

#define IS_UPPER(x) (x >= 'A' && x <= 'Z')
#define IS_LOWER(x) (x >= 'a' && x <= 'z')

int main()
{
    char ch = '\0';

    printf("Enter any character: ");
    ch = getchar();
    if(IS_UPPER(ch))
        printf("'%c' is uppercase\n", ch);
    else if(IS_LOWER(ch))
        printf("'%c' is lowercase \n", ch);
    else
        printf("Enter character is not alphabet");

    return 0;
}