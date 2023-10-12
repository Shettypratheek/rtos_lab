#include <stdio.h>
#include <stdlib.h>
int main( int argc,char*argv[])
{

	
	FILE *fp1,*fp2;
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
	while((ch=getc(fp1))!=EOF){
		putc(ch,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;



}