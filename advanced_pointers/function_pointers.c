#include <stdio.h>

void func1(int);
void func2(int);

/*declare function type, not normal function pointer style*/
typedef void functype(int);

int main()
{
    functype *func_ptr = NULL;
    func_ptr = func1;
    (*func1)(100);
    func_ptr = func2;
    (*func2)(200);
    return 0;
}

void func1(int arg)
{
    printf("Func1 got an argument of %d\n", arg);
}

void func2(int arg)
{
    printf("Func2 got an argument of %d\n", arg);
}