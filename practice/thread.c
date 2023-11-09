#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
void *thread1(void *arg)
{
    int upperlimit=*((int *)arg);
    int sum=0;
printf("Im the thread my thread id %lu\n",pthread_self());
for(int i=1;i<=upperlimit;i++)
    sum+=i;
printf("The sum of the first 25 number is %d\n",sum);



}
int main()
{ pthread_t t1;
    
    int n;
    printf("Enter the upper limit\n");
    scanf("%d",&n);

    printf("Im the main process my id is %d\n",getpid());
    pthread_create(&t1,NULL,thread1,&n);

    //pthread_create(&t2,NULL,thread2,NULL);
    
    pthread_join(t1,NULL);
  //  pthread_join(t2,NULL);
    return 0;

}