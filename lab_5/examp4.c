#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int id=fork();
    int status;

    if(id<0){
        printf("process not created");
        exit(-1);
    }
    else if(id==0){
        printf("Pratheek Shetty\n");
        exit(255);
    }
    else{
        wait(&status);
        if(WIFEXITED(status)){
            printf("Child process completed and exited with value %d\n",WEXITSTATUS(status));

        }
        else
        printf("Child process not executed");
    }
    return 0;
}