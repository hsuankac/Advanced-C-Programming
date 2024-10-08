#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define     MAX_COUNT       10
#define     BUF_SIZE        100

int main()
{
    pid_t pid;
    char buf[BUF_SIZE];

    // make two processes which run same program after this instruction
    fork();
    pid = getpid();
    for(int i = 1; i <= MAX_COUNT; i++){
        sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
        write(1, buf, strlen(buf));
    }

    return 0;
}
