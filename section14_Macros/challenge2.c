#include<stdio.h>

#define SUM(x,y) (x+y)

int main()
{
    int num1 = 0;
    int num2 = 0;

    printf("Enter any two numbers ");
    scanf("%d%d", &num1, &num2);

    printf("Sum(%d, %d) = %d\n", num1, num2, SUM(num1, num2));

    return 0;
}