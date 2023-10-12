#include <stdio.h>
#include <string.h>
int smallest(int *arr,int len)
{
	int i,smallest=arr[0];
	for(i=0;i<len;i++)
	{
		if(smallest>arr[i])
			smallest=arr[i];
	}
	return smallest;
}
int scaling(int *arr,int k,int len)
{
	for(int i=0;i<len;i++)
		arr[i]=arr[i]+k;
	return 0;}

int stringlength(char *str)
{
	int i=1;
	while(str[i++]!='\0');
		
		return i-1;		
} 
int character_count(char *str,int *count1,int *count2)
{
	int i=0;
	
	for(i=0;i<strlen(str);i++){
		if(str[i]=='a')
			(*count1)++;
		else if(str[i]=='b')
			(*count2)++;
	}
	
	return 0;
}
int string_alpha(char *str,int *count_a,int *count_s)
{
	int i=0;
	for(i=0;i<stringlength(str);i++){
		if((str[i]>= 'a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
			(*count_a)++;
		else if(str[i]==' ')
			(*count_s)++;
	}
	return 0;
}
int string_alpha_2(char *str,int *count_a,int *count_s,int *count_n)
{
	int i=0;
	for(i=0;i<stringlength(str);i++){
		if((str[i]>= 'a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
			(*count_a)++;
		else if(str[i]==' ')
			(*count_s)++;
		else if(str[i]=='\n')
			(*count_n)++;
	}
	return 0;
}