#include <stdio.h>
#include <stdio.h>

#include "header.h"

int main()
{ 
	/*int size,k;
	printf("Enter the size of array:\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the array elemnts :\n");
	for(int i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("The smalles elements in the array is: %d\n",smallest(arr,size));
	
	for(int i=0;i<size;i++)
		printf("%d \t",arr[i]);
	printf("\nEnter the scaling factor:\n");
	scanf("%d",&k);

	scaling(arr,k,size);
	for(int i=0;i<size;i++)
		printf("%d\t",arr[i]);

	char str[]="Pratheek";
	printf("The lengt of the string is:\n");
	printf("%d",stringlength(str));
	printf("\n");*/
	char str[100];
	printf("Enter the string:\n");
	fgets(str,100,stdin);
	int count1=0,count2=0,count3=0;
	/*character_count(str,&count1,&count2);
	printf("Count of character a and b is %d and %d",count1,count2);*/
	string_alpha_2(str,&count1,&count2,&count3);
	printf("total number of character is %d and blank space is %d and new line is %d",count1,count2,count3);

	return 0;
}