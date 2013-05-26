#include<stdio.h>

int main()
{
int A[150000],k,rootn,i,x,j,cases;
long long count,n;
int num,no_of_primes;
	n=150000;
	rootn=1000;
	int primes[20000];
	for(i=0;i<n;i++)
		A[i]=1;
	for(i=2;i<rootn;i++)
	{
		if(A[i]==1)
		{
			for(j=(i*i);j<n;j=j+i)
				A[j]=0;
		}
	}
	A[1]=0;
	A[0]=0;
	count=0;
	for(i=0;i<150000;i++)
	{
		if(A[i]==1)
		{
			primes[count]=i;
			count++;
		}
	}
//	no_of_primes=count;
//	printf("%d\n",no_of_primes);
//for(i=0;i<no;i++)
//	printf("%d ",primes[i]);
//printf("\n");
scanf("%d",&cases);
while(cases--)
{
	scanf("%lld %d",&n,&k);
	count=0;
	i=0;
	if(k>0){
		i=k-1;
		}
	else
		{
		i=0;
		count = (n*(n-1))/(long long)2;
		printf("%lld\n",count);
		continue;
		}
//	printf("i = %d\n",i);
	while(primes[i] <= n)
	{
//		printf("i=%d prime=%d\n",i,primes[i]);
		count += n-primes[i]+1;
		if(primes[i+1] <= n)
		{
			count += (primes[i-k+2] - primes[i-k+1] - 1)*(n-primes[i+1]+1);
			i++;
		}
		else
		{
			break;
		}
	}
	printf("%lld\n",count);
}
return 0;
}


