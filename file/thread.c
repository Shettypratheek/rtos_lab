#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *thread1(void *arg)
{
    char *file=(void *)arg;
    FILE *fp2,*fp1;
    char ch;
    char file2[50];
    fp1=fopen(file,"r");
    if(fp1==NULL)
    {
        printf("file not opned");
        exit(-1);
    }  

    printf("Enter the output file:\n");
    scanf("%s",file2);
    fp2=fopen(file2,"w");
    if(fp2==NULL){
        printf("file not opned");
        exit(-1);
    }
    while((ch=getc(fp1))!=EOF){
        putc(ch,fp2);
    }
    
    pthread_exit(NULL);


}

int main()
{
    pthread_t thread;
    char file[50];
    printf("Enter the file name:\n");
    scanf("%s",file);

    pthread_create(&thread,NULL,thread1,&file);

    pthread_join(thread,NULL);
}