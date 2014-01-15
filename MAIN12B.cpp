#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long prime[100000][2],factor[1000][2];
vector <long long> v;
long long A[1000007][2];
using namespace std;
int prime_finder(long long n)
{
        long long rootn,i,j,size;
        rootn=sqrt(n)+100;
        for(i=0;i<n;i++)
                A[i][0]=1;
        for(i=2;i<rootn;i++)
        {
                if(A[i][0]==1)
                {
                        for(j=(i*i);j<n;j=j+i)
                                A[j][0]=0;
                }
        }
        A[1][0]=0;
        A[0][0]=0;
	j=0;
	for(i=0;i<n;i++)
	{
		if(A[i][0])
		{
			prime[j][0]=i;
			A[i][1]=j;
			j++;
		}
	}
	return j;
}
int factor_finder(long long number,long long size)
{
	long long i,j;
	
	j=0;
	for(i=0;i<size;i++)
	{
	
		if(number<1000007)
		{
			if(A[number][0]==1)
			{
				
				prime[A[number][1]][1]=1;
				break;
			}
		}
		if(number==1)
			break;
		//modify your code by checking number is prime or not
		if(number%prime[i][0]==0)
			j++;
		while(number%prime[i][0]==0)
		{
			
			number=number/prime[i][0];
			prime[i][1]=1;
			
		}
		
			
	}
	if(number!=1)
	{
		
		if(number>=1000007)
		{
			int m=0,flag=0;
			for(m=0;m<v.size();m++)
			{
				if(v[m]==number)
					flag=1;
			}
			if(flag==0)		
				v.push_back(number);
		}
	}
	return j;


}
int main()
{
	long long i,j,x,size,cases,n,no_of_primes,number;
	no_of_primes=prime_finder(1000007);
	scanf("%lld",&cases);
	for(x=1 ; x<=cases;x++)
	{
		
		scanf("%lld",&n);
		v.clear();
		for(i=0;i<no_of_primes;i++)
		{
			prime[i][1]=0;
		
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&number);
			factor_finder(number,no_of_primes);
		}
		sort(v.begin(),v.end());
		long long counter=0,size;
		for(i=0;i<no_of_primes;i++)
		{
			if(prime[i][1]!=0)
			{
				counter++;
			}
	
		}
		size=v.size();
		//printf("size=%d\n",size);
		counter=counter+size;
		printf("Case #%lld: %lld\n",x,counter);
		for(i=0;i<no_of_primes;i++)
		{
			if(prime[i][1]!=0)
			{
				printf("%lld\n",prime[i][0]);
			}
	
		}
		for(i=0;i<v.size();i++)
		{
			printf("%lld\n",v[i]);

		}
		
		

	}

}


