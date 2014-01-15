#include<stdio.h>
long long MOD= 1000000007;
long long mod=MOD;
long long power(long long i,long long j)
{
	if(j==0)
		return 1;
	long long d;
	d=power(i,j/(long long)2);
	if(j%2==0)
		return (d*d)%MOD;
	else
		return ((d*d)%MOD * i)%MOD;
}
long long f(long long a,long long b)
{
	if(a < b)
		return 0;
	if(a == b)
		return 1;
	long long inverse = power(2,mod-2);
	long long answer = a-b+2;
	answer = (answer*(a-b+1))%mod;
	answer = (answer*inverse)%mod;
	return answer;
}
int main()
{
	int cases;
	long long N,min_a,max_c,max_b,max_a,min_b,min_c,answer;
	scanf("%d",&cases);
	while(cases--)
	{
		answer=0;
		scanf("%lld",&N);
		scanf("%lld %lld",&min_a,&max_a);
		scanf("%lld %lld",&min_b,&max_b);
		scanf("%lld %lld",&min_c,&max_c);
		answer=answer+f(N,min_a+min_b+min_c);
		answer=(answer-(f(N,max_a+min_b+1+min_c)+f(N,min_a+1+max_b+min_c)+f(N,min_a+1+min_b+max_c)))%MOD;
		answer=(answer+f(N,max_a+max_b+2+min_c)+f(N,min_a+max_b+2+max_c)+f(N,max_a+min_b+2+max_c))%MOD;
		answer=(answer-f(N,max_a+max_b+max_c+3))%MOD;
		if(answer>=0)
			printf("%lld\n",answer);
		else
			printf("%lld\n",answer+mod);
	}
	return 0;
}
