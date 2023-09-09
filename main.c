#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
int main(int argc,char *argv[])
{
FILE *fp1,*fp2;
int ch,count_num=0,count_blan=0,count_new=0,count_alpha=0;
fp1=fopen(argv[1],"r");
if(fp1==NULL){
    printf("File could not open");
    exit(-1);
}
while((ch=getc(fp1))!=EOF){
    if(ch==' '){
        count_blan+=1;
        continue;
    }
    if(ch=='\n'){
        count_new+=1;
        continue;
    }
    if(ch>=0 && ch<=9){
        count_num+=1;
        continue;
    }
    count_alpha+=1;
}
fp1=fopen(argv[1],"r");
if(fp1==NULL){
    printf("File could not open");
    exit(-1);
}
fp2=fopen(argv[2],"w");
if(fp2==NULL){
    printf("File couldnot be opened");
    exit(-1);
}
while((ch=getc(fp1))!=EOF){
    if(ch==' '){
        count_blan+=1;
        continue;
    }
    if(ch=='\n'){
        count_new+=1;
        continue;
    }
    if(ch>='0' && ch<='9'){
        count_num+=1;
        continue;
    }
    putc(toupper(ch),fp2);
}
printf("Alphabets %d\n",count_alpha);
printf("Number %d\n",count_num);
printf("Blankspace %d\n",count_blan);
printf("New line %d\n",count_new);
return 0;
}


