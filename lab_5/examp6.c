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
        exit(-1);
    }
    else if(id==0){
        execl("/bin/ls","ls","-l",NULL);
        printf("Executed");
        exit(1);
    }
    else{
        wait(NULL);
        printf("Parent saying child process executed\n");
    }
    return 0;
}