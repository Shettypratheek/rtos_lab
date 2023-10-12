
int sum_n_number(int n)
{
	int i,sum=0;
	for(i=1;i<=n;i++)
		sum=sum+i;
	return sum;
}

int sum_of_digit(long int num)
{
	int sum=0,rem;
	while(num>0)
	{
		rem=num%10;
		sum=sum+rem;
		num=num/10;
	}
	return sum;
}