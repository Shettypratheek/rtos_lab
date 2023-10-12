#include<stdio.h>
#include <stdlib.h>

 int main(int argc, char const *argv[])
{
	FILE *fp1,*fp2,*fp3;
	int ch;
	fp1=fopen(argv[1],"r");
	if(fp1==NULL){
		printf("File Does not exist");
		exit(-1);
	}
	fp2=fopen(argv[2],"w");
	if(fp2==NULL){
		printf("File Does not exist");
		exit(-1);
	}
	while((ch=getc(fp1))!=EOF)
		putc(ch,fp2);
	//fclose(fp2);
	//fclose(fp1);
	fp3=fopen(argv[3],"a");
	if(fp3==NULL){
		printf("File Does not exist");
		exit(-1);
	}
	while((ch=getc(fp2))!=EOF){
		printf("\n");
		putc(ch,fp3);
	}
	fclose(fp2);
	fclose(fp3);
	return 0;
}