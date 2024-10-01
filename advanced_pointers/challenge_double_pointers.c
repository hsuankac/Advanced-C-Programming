#include <stdio.h>

int main()
{
    int num = 123;

    int *singlePointer = NULL;

    int **doublePointer = NULL;

    singlePointer = &num;
    doublePointer = &singlePointer;

    /*Possible ways to find value of variable num*/
    printf("\nValue of num is: %d", num);
    printf("\nValue of num using singlePointer is: %d", *singlePointer);
    printf("\nValue of num using doublePointer is: %d", **doublePointer);

    /*Possible ways to find address of num*/
    printf("\nAddress of num is : %p", &num);
    printf("\nAddress of num using singlePointer is : %p", singlePointer);
    printf("\nAddress of num using doublePointer is : %p", *doublePointer);

    /*Find value of pointer*/
    printf("\nValue of pointer singlePointer is : %p", singlePointer);
    printf("\nValue of pointer singlePointer using doublePointer is : %p", *doublePointer);

    /*Ways to find address of pointer*/
    printf("\nAddress of pointer singlePointer is : %p", &singlePointer);
    printf("\nAddress of pointer singlePointer using doublePointer is : %p", doublePointer);

    /*Double pointer value and address*/
    printf("\nValue of pointer doublePointer is : %p", doublePointer);
    printf("\nAddress of pointer doublePointer is : %p", &doublePointer);

    return 0;
}