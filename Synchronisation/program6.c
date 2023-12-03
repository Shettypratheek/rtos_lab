#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 4

int buffer[SIZE];
int in=0;
int out=0;
 
pthread_mutex_t myMutex;
sem_t full,empty;

void*producer(void*);
void*consumer(void*);
int main()
{
    pthread_t thread1,thread2;
    pthread_mutex_init(&myMutex,NULL);
    sem_init(&full,0,0);
    sem_init(&empty,0,SIZE);

    pthread_create(&thread1,NULL,producer,NULL);
    pthread_create(&thread2,NULL,consumer,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    pthread_mutex_destroy(&myMutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    return 0;

}
void*producer(void*arg)
{
    int item,i;
     printf("\n");
    for(i=0;i<10;i++){
    item=rand()%100;
    sem_wait(&empty);
    //pthread_mutex_lock(&myMutex);

    buffer[in]=item;
    in=(in+1)%SIZE;
    printf("\nProduced item:%d\n",item);
    //pthread_mutex_unlock(&myMutex);
    sem_post(&full);
    }
    pthread_exit(NULL);
    printf("\n");

}
void*consumer(void*arg)
{
    int item,i;
    for(i=0;i<10;i++){
        sem_wait(&full);
     //  pthread_mutex_lock(&myMutex);

        item=buffer[out];
        out=(out+1)%SIZE;

        printf("Consumed item is:%d\t",item);

       // pthread_mutex_unlock(&myMutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
    printf("\n");
}

