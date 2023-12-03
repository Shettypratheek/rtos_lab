/*(First Readers-Writers problem; using pthreads, and mutex locks for the CS region)
Create five threads of which three are reader threads and two are writer threads. Each of the reader threads reads all the words of a common sample text file and writes the same to a new file (you can name the output files as one.txt, two.txt, and three.txt respectively from the from three reader threads ). One of the writer threads appends "Hello world" message 10 times to the sample file, while the other writer appends "Hello everyone" message 25 times to the same sample file.  
Ensure synchronisation by implementing your solution based on the "First-readers-writers problem". 
Run your code as many times as possible and observe the results.
Also remove the locks and observe the result.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t myMutex=PTHREAD_MUTEX_INITIALIZER;

void *reader_1(void*);
void *reader_2(void*);
void *reader_3(void*);
void *writer_1(void*);
void *writer_2(void*);

int main()
{
    pthread_t tr1,tr2,tr3,tr4,tr5;

    pthread_create(&tr1,NULL,reader_1,NULL);
    pthread_create(&tr2,NULL,reader_2,NULL);
    pthread_create(&tr3,NULL,reader_3,NULL);
    pthread_create(&tr4,NULL,writer_1,NULL);
    pthread_create(&tr5,NULL,writer_2,NULL);

    pthread_join(tr5,NULL);
    pthread_join(tr4,NULL);
    pthread_join(tr3,NULL);
    pthread_join(tr2,NULL);
    pthread_join(tr1,NULL);
    

    pthread_mutex_destroy(&myMutex);
   
   
   

    return 0;
}
void *reader_1(void*arg)
{
    
    FILE *fp,*fp_new;
    char ch;
    
    fp=fopen("sample.txt","r");
    fp_new=fopen("one.txt","w");

    pthread_mutex_lock(&myMutex);

    while((ch=getc(fp))!=EOF)
        putc(ch,fp_new);

  pthread_mutex_unlock(&myMutex);
    fclose(fp);
    fclose(fp_new);
    pthread_exit(NULL);
}
void *reader_2(void* arg)
{
    
    FILE *fp,*fp_new;
    char ch;
    
    fp=fopen("sample.txt","r");
    fp_new=fopen("two.txt","w");

   pthread_mutex_lock(&myMutex);

    while((ch=getc(fp))!=EOF)
        putc(ch,fp_new);

   pthread_mutex_unlock(&myMutex);
    fclose(fp);
    fclose(fp_new);
    pthread_exit(NULL);
    
    }
void *reader_3(void* arg)
{
    
    FILE *fp,*fp_new;
    char ch;
    
    fp=fopen("sample.txt","r");
    fp_new=fopen("three.txt","w");

    pthread_mutex_lock(&myMutex);

    while((ch=getc(fp))!=EOF)
        putc(ch,fp_new);

    pthread_mutex_unlock(&myMutex);
    fclose(fp);
    fclose(fp_new);
    pthread_exit(NULL);
    

}

void *writer_1(void* arg)
{
    
    FILE *fp;
    
    fp=fopen("sample.txt","w");

   pthread_mutex_lock(&myMutex);

    for(int i=0;i<10;i++)
    fprintf(fp,"Hello world\n");

   pthread_mutex_unlock(&myMutex);
    fclose(fp);
    pthread_exit(NULL);
    
}
void *writer_2(void* arg)
{

    
    FILE *fp;
    fp=fopen("sample.txt","w");

   pthread_mutex_lock(&myMutex);

    for(int i=0;i<25;i++)
        fprintf(fp,"Hello Everyone\n");

    pthread_mutex_unlock(&myMutex);
    fclose(fp);
    pthread_exit(NULL);
    
}