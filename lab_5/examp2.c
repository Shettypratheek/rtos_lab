#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int id=fork();
    int counter=0;
    int status;
    if(id<0){
        printf("fork not created\n");
        exit(-1);
    }
    else if(id==0){
        while(counter<100)
            counter++;
        exit(255);

    }
    else{
        waitpid(id,&status,0);
        //wait(NULL);
        if(WIFEXITED(status))
        printf("child process completed  and exited with value %d\n",WEXITSTATUS(status));
    
    else 
        printf("Child process didnot execute\n");
    }
    return 0;
}