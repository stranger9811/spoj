/*
        Ashok Kumar
        Algo : Inclusion Exclusion,sieve
*/
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std;

vector <long long > comb;
vector <long long > factor;

long long b,answer;
long long  size_of_comb[10];
long long  prime[100000],A[100000];
long long  combinations(vector <long long > numbers,long long  start,long long  size,long long  length,long long  orignal_length)
{
	long long  i,multiple=1;
	if(((orignal_length-length)%2==1)&&comb.size())
	{
		
		long long  q=comb.size();
		size_of_comb[q]++;
                for(i=0; i<q; i++)
                        multiple=comb[i]*multiple;
		answer=answer-b/multiple;	
	}
	else if(comb.size())
	{
		long long  q=comb.size();
                size_of_comb[q]++;
                for(i=0; i<q; i++)
                        multiple=comb[i]*multiple;
                answer=answer+b/multiple;
	}
	if(length==0)
	{
		return 0;
	}
	for(i=start; i<size;i++)
	{
		comb.push_back(numbers[i]);
		combinations(numbers,i+1,size,length-1,orignal_length);
		comb.pop_back();
	}

}

long long  prime_finder(long long  n)
{
	long long  rootn,i,j,size;
	rootn=sqrt(n)+100;
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
	j=0;
	for(i=0;i<n;i++)
	{
		if(A[i])
		{
			prime[j]=i;
			j++;
		}
	}
	return j;
}
long long  factor_finder(long long  number,long long  size)
{
	long long  i,j;
	j=0;
	for(i=0;i<size;i++)
	{
		if(number<100000)
			if(A[number]==1)
				break;
		if(number%prime[i]==0)
		{
			factor.push_back(prime[i]);
		}
		while(number%prime[i]==0)
		{
			number=number/prime[i];
		}
	}
	if(number!=1)
	{
		factor.push_back(number);
	}
	return j;


}
int  main()
{
	
	long long  cases,no_of_prime;

	long long a,B,N;
	scanf("%lld",&cases);
	no_of_prime=prime_finder(100000);
	for(int x=0; x<cases; x++)
	{
		factor.clear();
		scanf("%lld %lld %lld",&a,&B,&N);
		answer=B;
		factor_finder(N,no_of_prime);
		b=B;
		comb.clear();
		combinations(factor,0,factor.size(),factor.size(),factor.size());
		long long sum1=answer;
		answer=a-1;
		b=a-1;
		comb.clear();
		combinations(factor,0,factor.size(),factor.size(),factor.size());
		long long sum2=answer;
		printf("Case #%d: %lld\n",x+1,sum1-sum2);
	}
}
