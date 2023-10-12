#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int id1,id2,id3;
    id1=fork();
    if(id1<0){
        printf("Process not created\n");
        exit(-1);
    }
    else if(id1==0){
       execl("/bin/ls","ls",NULL);
        printf("Child executed ls command\n");
        exit(1);
    }
    
    id2=fork();
    if(id2<0){
        printf("Process not created\n");
        exit(-1);
    }
    else if(id2==0){
        execl("/bin/date","date",NULL);
        printf("Child executed  date \n");
        exit(1);
    }
    id3=fork();
    
    if(id3<0){
        printf("Process not created\n");
        exit(-1);
    }
    else if(id3==0){
        execl("/bin/pwd","pwd",NULL);
        printf("Child executed present workig directory \n");
        exit(1);
    }
    wait(NULL);
       wait(NULL);
          wait(NULL);
          printf("Parent saying all child process completed\n");
    return 0;

}