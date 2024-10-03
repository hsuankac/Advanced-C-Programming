#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void hdl(int sig, siginfo_t *siginfo, void *context){
    printf("Sending PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);
}

int main()
{
    struct sigaction act;
    memset(&act, '\0', sizeof(act));
    act.sa_sigaction = &hdl;
    /*The SA_SIGINFO flag tells sigaction() to use the sa_sigaction function*/
    act.sa_flags = SA_SIGINFO;

    if(sigaction(SIGINT, &act, NULL) < 0){
        perror("sigaction");
        return 1;
    }
    while(1)
        sleep(3);
    return 0;
}
