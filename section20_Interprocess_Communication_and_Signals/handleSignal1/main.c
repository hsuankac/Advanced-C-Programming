#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void hanlder_dividebyzero(int signum);

int main()
{
    int result = 0;
    int v1 = 0, v2 = 0;
    void(*sigHandlerReturn)(int);

    sigHandlerReturn = signal(SIGFPE, hanlder_dividebyzero);

    if(sigHandlerReturn == SIG_ERR){
        perror("Signal Error: ");
        return 1;
    }

    v1 = 121;
    v2 = 0;
    result = v1 / v2;
    printf("Result of Divide by zero is %d\n", result);
    return 0;
}

void hanlder_dividebyzero(int signum)
{
    if(signum == SIGFPE){
        printf("Received SIGFPE, Divide by zero exception\n");
        exit(0);
    }else{
        printf("Received %d signal\n", signum);
        return;
    }
}
