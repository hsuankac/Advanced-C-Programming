#include <stdio.h>
#include <malloc.h>

void mallocMemory(int **ptr){
    *ptr = (int*)malloc(sizeof(int));

}


int main()
{
    int *ptr = NULL;
    mallocMemory(&ptr);
    *ptr = 20;
    printf("%d\n", *ptr);
    free(ptr);
    return 0;
}