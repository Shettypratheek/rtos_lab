/* Let a parent process create a segment of adequate length and 
write 0 to 9 as well as 'a' to 'z' to it.Next, let the parent fork a 
child.Let the child increment all the integers by a value 100. Also 
let it convert all the characters to upper case. Once the child 
completes, let the parent access the shared area and display their 
contents to the screen.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int seg_id;
    int i;
    char *sm;
    const int len=100;
    int id=fork();
    seg_id=shmget(IPC_PRIVATE,len,S_IRUSR|S_IWUSR);

    sm=(char*)shmat(seg_id,NULL,0);
    for(i=0;i<36;i++){
        if(i<26)
            sm[i]='a'+i;
        else if(i>=26)
            sm[i]=i-26;
    }
    
    if(id<0)
        {
            printf("Process not created\n");
            exit(-1);
        }
        
    else if(id==0){
        for(i=0;i<36;i++)
        if(i<=25)
            sm[i]=toupper(sm[i]);
        else 
            sm[i]=sm[i]+100;
            

    }
    for(i=0;i<36;i++){
        if(i<=25)
            printf("%c\n",sm[i]);
        else
            printf("%d\n",sm[i]);
    }
    


        shmdt(sm);
        shmctl(seg_id,IPC_RMID,NULL);
        return 0;
}