#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    // create first child
    int n1 = fork();

    // create second child, first child also executes this line
    int n2 = fork();

    if(n1 > 0 && n2 > 0){
        printf("parent\n");
        printf("%d %d \n", n1, n2);
        printf(" my id is %d \n", getpid());
        printf(" my parent id is %d \n", getppid());
    }
    else if(n1 == 0 && n2 > 0){
        printf("\nFirst child\n");
        printf("%d %d \n", n1, n2);
        printf(" my id is %d \n", getpid());
        printf(" my parent id is %d \n", getppid());
    }
    else if(n1 > 0 && n2 == 0){
        printf("\nSecond child\n");
        printf("%d %d \n", n1, n2);
        printf(" my id is %d \n", getpid());
        printf(" my parent id is %d \n", getppid());
    }
    else{
        printf("\nThird child\n");
        printf("%d %d \n", n1, n2);
        printf(" my id is %d \n", getpid());
        printf(" my parent id is %d \n", getppid());
    }
    return 0;
}
