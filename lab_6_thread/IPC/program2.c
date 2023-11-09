/*To demonstrate the usage of the various shared memory system 
calls- WAP which creates a shared memory segment of length 100 bytes
and writes 'A' to 'Z' to it. 
Next, let the same program access the segment area and display its 
contents to the screen (all 100 bytes).Let the program next convert 
the case of the alphabets in the segment to lowercase. Finally let 
the program access the same area and display the segment contents 
once again to the screen. Observe the output.
*/

#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <ctype.h>

int main()
{
int seg_id;
int i;
char *sm;
const int len=100;

seg_id=shmget(IPC_PRIVATE,len,S_IRUSR|S_IWUSR);

sm=(char*)shmat(seg_id,NULL,0);

for(i=0;i<26;i++)
    sm[i]='A'+i;
for(i=0;i<26;i++)
    printf("%c\n",sm[i]);
printf("\n");
//coverting the upper to lower
for(i=0;i<26;i++)
    sm[i]=tolower(sm[i]);
for(i=0;i<26;i++)
    printf("%c\n",sm[i]);
printf("\n");
shmdt(sm);
shmctl(seg_id,IPC_RMID,NULL);
return 0;

}