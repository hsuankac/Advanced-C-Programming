#include <stdio.h>

int findGCD(int a, int b);

int main()
{
    int num1 = 0, num2 = 0, num3 = 0, gcd = 0;

    printf("\n\nRecursion : Find GCD of two numbers : \n");
    printf("------------------------------------------\n");

    printf("Input 1st number: ");
    printf("%d", &num1);

    printf("Input 2nd number: ");
    printf("%d", &num2);

    gcd = findGCD(num1, num2);

    printf("\n The FCD of %d and %d is : %d\n\n", num1, num2, gcd);

    return 0;
}

int findGCD(int a, int b)
{
    while(a != b)
    {
        if(a > b)
            return findGCD(a - b, b);
        else
            return findGCD(a, b - a);
    }

    return a;
}