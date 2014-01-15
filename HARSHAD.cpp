/*
   	Ashok Kumar
	Algo: sieve()
 */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 1000007

using namespace std;

int B[MAX];
vector <int> dev_prime;

int prime_finder(int n)
{
	int A[MAX],rootn,i,j,size;
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
	for(i=2;i<n;i++)
		if(A[i]&&B[i]==0)
			dev_prime.push_back(i);
}	
int main()
{
	for(int i=0; i<MAX; i++)
		B[i]=0;
	for(int i=0; i<MAX; i++)
	{
		int temp=i,sum=0;
		while(temp!=0)
		{
			sum=sum+temp%10;
			temp/=10;
		}
		if(sum+i<MAX)
			B[sum+i]=1;		
	}
	prime_finder(MAX);
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		printf("%d\n",(int)(lower_bound(dev_prime.begin(),dev_prime.end(),B+1)-lower_bound(dev_prime.begin(),dev_prime.end(),A)));
	}
	return 0;
}
