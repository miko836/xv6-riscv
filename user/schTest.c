#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define LIMIT 50000
#define MAX_PROCESS 12


int isPrime(int n){
    for(int i=2; i<=n/2; ++i){
            if(n%i == 0){
                return 0;
            }
    }
    return 1;
}

int primeCount(){
    int num=0;
    for(int i=2; i<LIMIT; i++){
        if(isPrime(i)){
            num++;
        }
    }
    return num;
}

int main(){

    int pid = 0;
    printf("===== schTest ===== \nMAX_PROCESS=12, LIMIT=50000 \nParent process running. PID= %d\n", getpid());


    for(int i=1; i<=MAX_PROCESS; i++){
        pid = fork();
        if(pid == 0){
            //child process
            int count = primeCount();
            printf("Child process %d finished. PID=%d, Count=%d\n", i, getpid(), count);
            exit(0);
        }else if(pid<0){
             //error
            printf("fork fail");
            exit(1);
        }
    }


    while (wait(0) > 0);

    printf("PIDs of last 32 processes scheduled (most recent to least recent): ");

    int *addr = (int *)malloc(32 * sizeof(int));

    int startIndex = schedDisp((uint64)addr);

    for (int i = 31; i >= 0; i--) {
        printf("%d ", addr[(startIndex + i) % 32]);
    }

    printf(" \n ");




    exit(0);

}