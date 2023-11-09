#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

void *thread1(void *arg);
void *thread2(void *arg);
struct arrayinfo
{
    int arr[10];
    int length;

};
typedef struct arrayinfo Arry;

int main()
{
    Arry data={{12,20,31,43,52,63,77,81,94,100},10};
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread1,&data);
    pthread_create(&t2,NULL,thread2,&data);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);


    

    return 0;
}

void *thread1(void *arg)
{
    Arry data =*(Arry*)arg;
    int sum=0;
    for(int i=0;i<data.length;i++)
        sum+=data.arr[i];
    printf("The sum of array elements is :%d\n",sum);

    pthread_exit(NULL);

}
void *thread2(void *arg)
{
    Arry data=*(Arry*)arg;
    printf("The odd elements in the array are:\n");
    for(int i=0;i<data.length;i++){
        if(data.arr[i]%2==1)
            printf("%d\t",data.arr[i]);
    }
    pthread_exit(NULL);
}