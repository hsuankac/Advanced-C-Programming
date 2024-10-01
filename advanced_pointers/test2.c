#include <stdio.h>
#include <string.h>
#include <malloc.h>

void foo(char **ptr){
    *ptr = malloc(255);
    strcpy(*ptr, "Hello Word");
}


int main()
{
    char *ptr = NULL;
    foo(&ptr);
    printf("%s\n", ptr);
    free(ptr);
    return 0;
}