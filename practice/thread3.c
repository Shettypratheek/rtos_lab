#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void *thread(void *arg);

int main()
{
    pthread_t t1,t2;
    int n1,n2;
    printf("Enter the value of n1 and n2:\n");
    scanf("%d %d",&n1,&n2);

    pthread_create(&t1,NULL,thread,&n1);
    pthread_create(&t2,NULL,thread,&n2);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;

}

void *thread(void *arg)
{
    int n=*(int*)arg;
    char mssg[100];
    printf("Enter the message:\n");
    scanf("%s",mssg);
    for(int i=0;i<n;i++);
        printf("%s",mssg);
}