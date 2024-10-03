#include <stdio.h>
#include <string.h>


int main()
{
    int i = 10;
    float f = 2.34;
    char ch = 'k';

    void *vptr = NULL;
    vptr = &i;
    printf("Value of i = %d\n", *(int*)vptr);
    vptr = &f;
    printf("Value of i = %.2f\n", *(float*)vptr);
    vptr = &ch;
    printf("Value of i = %c\n", *(char*)vptr);

    int aiData[3] = {100, 200, 300};
    void *pvData = &aiData[1]; //200
    pvData += sizeof(int);
    printf("%d", *(int*)pvData);
    return 0;
}