#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

void *thread1(void *arg);
void *thread2(void *arg);

int main()
{
    pthread_t t1,t2;
    int n1,n2;

    printf("Im the main thread\n");
    printf("Enter the value of n1 and n2:\n");
    scanf("%d %d",&n1,&n2);

    pthread_create(&t1,NULL,thread1,&n1);
    pthread_create(&t2,NULL,thread2,&n2);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}

void *thread1(void *arg)
{
    int n=*(int*)arg;
    for(int i=0;i<n;i++)
        printf("Hello thread1, here\n");
}
void *thread2(void *arg)
{
    int n=*(int*)arg;
    for(int i=0;i<n;i++)
        printf("Hello thread2 here\n");
}