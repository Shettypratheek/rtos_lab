#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int id=fork();
    if(id<0){
        printf("Process not created");
        exit(1);
    }
    else if(id==0){
        sleep(8);
        printf("Im the child\n");
    }
    else{
        printf("Im the parent\n");
        wait(NULL);
    }
    return 0;
}