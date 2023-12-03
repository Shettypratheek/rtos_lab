#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t myMutex=PTHREAD_MUTEX_INITIALIZER;
void *thread_1(void*);
void *thread_2(void*);

int main()
{
    pthread_t thread1,thread2;

    pthread_create(&thread1,NULL,thread_1,NULL);
    pthread_create(&thread2,NULL,thread_2,NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    return 0;

}
void *thread_1(void*arg)
{
    char ch;
    FILE *fp ,*fp_new=NULL;
       

    
    fp=fopen("file.txt","r");
    fp_new=fopen("result.txt","w");
    pthread_mutex_lock(&myMutex);
    while((ch=getc(fp))!=EOF){
        putc(ch,fp_new);
    }
    pthread_mutex_unlock(&myMutex);

    fclose(fp);
    fclose(fp_new);
    
  
    pthread_exit(NULL);


}
void *thread_2(void*arg)
{
    char data[50];
    
    FILE *fp;
    
    
    fp=fopen("result.txt","a");
  pthread_mutex_lock(&myMutex);
    int count=10;
    printf("Enter the string:\n");

   
    fgets(data,sizeof(data),stdin);
     

    
    for(int i=0;i<count;i++){
        int index=0;
        while(data[index]!='\0'){
            putc(data[index],fp);
            index++;
        }
    }
   pthread_mutex_unlock(&myMutex);
    fclose(fp);

    

    pthread_exit(NULL);

}