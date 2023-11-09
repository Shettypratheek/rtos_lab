/*Let a parent process create a segment of length 2k and write n 
strings to the area. Let the value of n be passed as a commandline 
argument. Next, let the parent fork a child.Let the child capitalise 
the first character of each string.Once the child completes let the 
parent access the shared area and display their contents to the 
screen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include<sys/wait.h>
#include <ctype.h>
#include <unistd.h>

int main(int arg,char*argv[])
{

    int n=atoi(argv[1]);
    int seg_id;
    int i;
    char *sm;
    const int len=2*1024;
    seg_id=shmget(IPC_PRIVATE,len,S_IRUSR|S_IWUSR);

    sm=(char*)shmat(seg_id,NULL,0);
    for(i=0;i<n;i++)
        sprintf(sm+i,"string%d",i+1);
    for(i=0;i<n;i++)
        printf("%s\n",sm+i);
    shmdt(sm);
    shmctl(seg_id,IPC_RMID,NULL);
    


    return 0;
}