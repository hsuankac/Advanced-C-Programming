#include<stdio.h>

#define SQUARE(x) (x * x)
#define CUBE(x) (x * x * x)

int main()
{
    int num = 0;

    printf("Enter a number ");
    scanf("%d", &num);

    printf("SQUARE(%d) = %d\n", num, SQUARE(num));
    printf("CUBE(%d) = %d\n", num, CUBE(num));

    return 0;
}