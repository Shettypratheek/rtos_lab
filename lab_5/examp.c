#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
int id=fork();
if(id<0){
    printf("Error\n");
    exit(-1);
}
else if(id==0)
{
printf("Im the child with id=%d and my parent pid is %d\n",getpid(),getppid());

}
else
printf("Im the parent with id=%d and parent is %d\n",getpid(),getppid());
return 0;
}