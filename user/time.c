#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;
  int j;

//   if(argc < 2){
//     fprintf(2, "Usage: mkdir files...\n");
//     exit(1);
//   }

    int ticksX;
    int ticks1; 
    int ticks2;

    int pid = fork();
    int ticks1 = ticks();


    
    for (int i = 2; i >= 0; i--) {
        argv[i + 1] = argv[i];
    }

    // Set the new first argument
    argv[0] = "NewCommand";
    


    if (pid == 0)
    {
        exec("/bin/echo", argv);
        ticks2 = ticks();
        exit(0);
    } else if (pid > 0) {
        wait(0);
        ticks();
    } else {
        printf("fork error\n");
    }

    ticksX = ticks2 - ticks1;

    printf("Real-time in ticks: %d", ticksX);


  exit(0);
}
