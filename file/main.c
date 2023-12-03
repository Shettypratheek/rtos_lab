#include <stdio.h>
#include <stdlib.h>

int main()
{
    char file[50],file2[50];
    FILE *fp1,*fp2;
    char ch;
    printf("Enter the file name:\n");
    scanf("%s",file);
    fp1=fopen(file,"r");
    if(fp1==NULL){
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
    fclose(fp1);
    fclose(fp2);
    return 0;


}