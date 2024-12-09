#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid = fork();


    if (pid != 0) /* pid is non-zero, so I must be the parent */
    {
        while(1)
            sleep(10);
        
    }
    else /* pid is zero, so I must be the child */
    {
            while(1) {
                printf("%d: Pich Sintornswat\n", getpid());
                sleep(10);
                fflush(stdout);
            }
            exit(42); /* exit with any number */
    }
}