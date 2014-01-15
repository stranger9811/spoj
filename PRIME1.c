#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int A[33000],n,rootn,i,x,j,cases;
long long count;

int main()
{
	n=32000;
	rootn=200;
	int primes[3500];
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
	for(i=0;i<32000;i++)
	{
		if(A[i]==1)
		{
			primes[count]=i;
			count++;
		}
	}
	long long n,m,flag,answer;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf(" %lld %lld",&n,&m);
		for(i=n;i<=m;i++)
		{
			flag=0;
			for(j=0;j<3500;j++)
			{
				if(pow(primes[j],2)>i)
					break;
				if(i%primes[j]==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0&&i!=1)
				printf("%d\n",i);


		}
		printf("\n");

	}
	return 0;	
}


