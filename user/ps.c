#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(){

    printf("name\tpid\tstate    \tmemory\tVirtual address of kernel stack\n");

    shprocs();

    return 0;


}