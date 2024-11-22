#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // char a[10] = "3.14";
    // float value = atof(a);
    // printf("Value = %f\n", value);

    // char a[] = "123.456xyz", *end;
    // double value = 0;

    // value = strtod(a, &end);
    // printf("Value = %lf\n", value);

    // char a[] = "365.25 7.0", *end;
    // float value = strtof(a, &end);
    // float value2 = strtof(end, NULL);
    // printf("Value1 = %f\n", value);
    // printf("Value2 = %f\n", value2);

    char str[30] = "2030300 This is test";
    char *ptr = NULL;
    long ret = 0;
    ret = strtol(str, &ptr, 10);
    printf("size of long = %d\n", sizeof(long));
    printf("The number unsigned long integer is %ld\n", ret);
    printf("String part is |%s|", ptr);

    return 0;
}