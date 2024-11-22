#include <stdio.h>
#include <string.h>

int main()
{
    char source[] = "Jason";

    char *target = strndup(source, 5);
    printf("%s", target);
    return 0;
}