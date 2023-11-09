#include <stdio.h>
#include <pthread.h>

#include <unistd.h>
#include <sys/types.h>
int n;
void *thread(void *arg)
{
char *word=((char*)arg);
int i;
for(i=0;i<n;i++)
    printf("%s\n",word);

}


int main()
{
    pthread_t t1,t2,t3;

    char mssg1[100];
    char mssg2[100];
    char mssg3[100];
    printf("Enter the value of n:\n");
    scanf("%d",&n);
        
    printf("Message1:\n");
    
    fgets(mssg1,sizeof(mssg1),stdin);
   //fgets(mssg1, sizeof(mssg1), stdin);
    printf("Message2:\n");
    scanf("%s",mssg2);
    printf("Message3:\n");
    scanf("%s",mssg3);
        
    pthread_create(&t1,NULL,thread,&mssg1);
    pthread_create(&t2,NULL,thread,&mssg2);
    pthread_create(&t3,NULL,thread,&mssg3);
    

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);


    return 0;
}