#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{

    if (argc == 1)
    {
        printf("Usage: time <command>\n");
        exit(0);
    }


    int ticksX = 0;
    int ticks1 = 0; 
    int ticks2 = 0;

    int pid = fork();

    ticks1 = ticks();

    if (pid == 0)
    {
        exec(argv[1], argv+1);
        exit(0);
    } else if (pid > 0) {
        wait(0);
        ticks2 = ticks();
    } else {
        printf("fork error\n");
        exit(0);    
    }


    ticksX = ticks2 - ticks1;

    fprintf(2, "Real-time in ticks: %d\n", ticksX);

  exit(0);
}