#include <pthread.h>
#include <stdio.h>

#define MAX_SIZE 20

int arr[MAX_SIZE];
int length;

void *computesum(void*arg);
void *oddnum(void *arg);

int main()
{
    pthread_t t1,t2;
    printf("Enter the lenght of array:\n");
    scanf("%d",&length);
    printf("Enter the array element:\n");
    for(int i=0;i<length;i++)
        scanf("%d",&arr[i]);
    pthread_create(&t1,NULL,computesum,NULL);
    pthread_create(&t2,NULL,oddnum,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;

}

void *computesum(void*arg)
{
    int sum=0;
    for(int i=0;i<length;i++)
        sum+=arr[i];
    printf("The sum of array element is :%d\n",sum);

    pthread_exit(NULL);
}
void *oddnum(void *arg)
{
    printf("Odd elements in the array are:\n");
    for(int i=0;i<length;i++){
        if(!(arr[i]%2==0))
            printf("%d\t",arr[i]);
    }
    pthread_exit(NULL);
}