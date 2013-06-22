/*
	Ashok Kumar
	Algorithm: Principle of Inclusion Exclusion
*/
#include<vector>
#include<cstdio>
#include<cmath>

using namespace std;

vector <long long > comb;
vector <long long > factor;

long long b,answer;
long long gcd(long long  m, long long n)
{
        long long tmp;
        while(m) { tmp = m; m = n % m; n = tmp; }       
        return n;
}
 
long long lcm(long long m, long long n)
{
        return m / gcd(m, n) * n;
}
long long  combinations(vector <long long > numbers,long long  start,long long  size,long long  length,long long  orignal_length)
{
	long long  i,multiple=1;
	if(((orignal_length-length)%2==1)&&comb.size())
	{
		
		long long  q=comb.size();
                for(i=0; i<q; i++)
                        multiple=lcm(multiple,comb[i]);
		answer=answer-b/multiple;	
	}
	else if(comb.size())
	{
		long long  q=comb.size();
                for(i=0; i<q; i++)
                        multiple=lcm(multiple,comb[i]);
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
int  main()
{
	
	long long  cases,no_of_prime;

	long long a,B,N,D;
	scanf("%lld",&cases);
	for(int x=0; x<cases; x++)
	{
		factor.clear();
		scanf("%lld %lld %lld %lld",&a,&B,&N,&D);
		answer=B;
		factor.push_back(N);factor.push_back(N+D);
		factor.push_back(N+2*D);factor.push_back(N+3*D);factor.push_back(N+4*D);
		b=B;
		comb.clear();
		combinations(factor,0,factor.size(),factor.size(),factor.size());
		long long sum1=answer;
		answer=a-1;
		b=a-1;
		comb.clear();
		combinations(factor,0,factor.size(),factor.size(),factor.size());
		long long sum2=answer;
		printf("%lld\n",sum1-sum2);
	}
}


