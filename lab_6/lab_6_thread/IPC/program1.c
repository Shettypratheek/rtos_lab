/** Create a 4096 bytes length shared memory segment. Attach it to a process, write 
hello to it, read from it & display the contents to the screen, detach the process 
from the memory segment and finally remove the memory segment from 
memory***/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/shm.h>

int main()
{
    int seg_id;
    char *sm;
    const int len=4096;

    seg_id=shmget(IPC_PRIVATE,len,S_IRUSR|S_IWUSR);//CREATING A SHARED MEMORY

    sm=(char*)shmat(seg_id,NULL,0); /**ATTACH NULL-INDICATES  Create a 4096 bytes length shared memory segment. Attach it to a process, write 
                                                hello to it, read from it & display the contents to the screen, detach the process 
                                                from the memory segment and finally remove the memory segment from 
                                                memory***/
    sprintf(sm,"Hello....how are u whats up then nothing everything and so on\n"); //writing hello to the shared memory
    
    printf("%s",sm);
    printf("%s",sm);
    shmdt(sm);//detatching the shared memory from the process
    shmctl(seg_id,IPC_RMID,NULL); //DEALLOCATING THE SEGMENT FROM THE MEMORY AREA
    
    return 0;
}