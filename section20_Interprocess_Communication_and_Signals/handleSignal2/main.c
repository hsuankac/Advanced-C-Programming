#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void signalHanlder(int signalValue);


int main()
{
    int i;
    int x;

    signal(SIGINT, signalHanlder);
    srand(clock());

    for(int i = 1; i <= 100; i++){
        x = 1 + rand() % 50;
        if(x == 25){
            raise(SIGINT);
        }

        printf("%4d", i);

        if(i % 10 == 0){
            printf("\n");
        }
    }
    return 0;
}


void signalHanlder(int signalValue)
{
    int response;

    printf("%s%d%s\n%s", "\nInterrupt signal ( ", signalValue, " ) received.", "Do you wish to continue (1 = yes or 2 = no) ");
    scanf("%d", &response);

    while(response != 1 && response != 2){
        printf("( 1 = yes or 2 = no )? " );
        scanf("%d", &response);
    }
    if(response == 1){
        signal(SIGINT, signalHanlder);
    }
    else{
        exit(EXIT_SUCCESS);
    }
}
