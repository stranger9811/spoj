#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int A[100000],n,rootn,i,x,j,cases;
long long count;

long long power(long long i,long long j,long long MOD)
{
	if(j==0)
		return 1;
	long long d;
	d=power(i,j/(long long)2,MOD);
	if(j%2==0)
		return (d*d)%MOD;
	else
		return ((d*d)%MOD * i)%MOD;
}

int main()
{
	int num,no_of_primes;
	n=100000;
	rootn=1000;
	int primes[10000];
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
	for(i=0;i<100000;i++)
	{
		if(A[i]==1)
		{
			primes[count]=i;
			count++;
		}
	}
	no_of_primes=count;
	long long p,n,m,r,p1,count,i;
	int flag;
	while(1){
		int factor[32],count=0;
		scanf("%lld %lld",&p,&n);
		if(p==0)
			break;
		num=p-1;
		for(i=0;i<no_of_primes;i++)
		{
			if(num%primes[i]==0)
				count++;
			while(num%primes[i]==0)
			{
				factor[count-1]=primes[i];
				num=num/primes[i];
			}
			if(num==1)
				break;
		}
		if(num!=0)
		{
			factor[count]=num;
			count++;
		}
			


		while(n--)
		{
			scanf("%lld",&r);
			int flag=0;
			num  = p-1;
			for(i=0;i<count;i++)
			{
				if(power(r,num/factor[i],p)==1)
				{
					if(factor[i]>1)
					{
						flag=1;
						break;
					}
				}
			}

			if(flag)
				printf("NO\n");
			else
				printf("YES\n");
			//printf("%lld\n",p);
		}
	}
	return 0;	
}




