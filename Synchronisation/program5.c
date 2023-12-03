#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch;
    fp=fopen("my_file","w");
    char data[]="Hey Im Shetty";
    for(int i=0;i<sizeof(data);i++){
        int index=0;
        while(data[index]!='\0'){
            putc(data[index],fp);
            
            index++;
        }
        fprintf(fp,"\n");
    }
    return 0;
}