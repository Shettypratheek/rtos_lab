#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
	long int n;
	printf("Enter the number:\n");
	scanf("%ld",&n);
	printf("The sum of digit %ld is: %d ",n,sum_of_digit(n));
	return 0;
}