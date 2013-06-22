#include<string>
#include<cstdio>
#include<iostream>

#define ll long long 

using namespace std;

long long combination(ll n,ll r)
{
	if(r>n|| n<0 || r<0)
		return 0;
	if(r==n)
		return 1;
	if(r > n-r)
		r = n-r;

	ll i,j,k;
	long long ans=1;
	for(i=1;i<=r;i++)
	{
		ans=ans*(n-i+1);
		ans=ans/i;
	}
	return ans;
}
string binary(ll number)
{
	string answer="";
	while(number!=0)
	{
		string a;
		if(number%2==0)
			a="0";
		if(number%2==1)
			a="1";
		answer=a+answer;
		number=number/2;
	}
	return answer;
}
ll find_number(ll number)
{
	ll answer=0;
	ll negative=0;
	string bin;
	bin=binary(number);
	ll len;
	len = bin.length();
	for(int i=0; i<len; i++)
	{
		if(bin[i]=='1')
		{
			int x=len-i-1;
			answer+=combination(x,4-negative);
			answer+=combination(x,7-negative);
			answer+=combination(x,44-negative);
			answer+=combination(x,47-negative);
			negative++;
		}
	}
	return answer;

}
int main()
{
	ll Cases;
	scanf("%lld",&Cases);
	while(Cases--)
	{
		ll a,b,answer,sum1,sum2;
		scanf("%lld %lld",&a,&b);
		sum1=find_number(b+1);
		sum2=find_number(a);
		answer=sum1-sum2;
		printf("%lld\n",answer);
	}
}
