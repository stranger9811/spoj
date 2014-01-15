#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include <utility>

using namespace std;

vector < pair<int,int> > factor[1001];
int MOD= 10000007;
int prime[1007],A[1007];

int prime_finder(int n)
{
	int rootn,i,j,size;
	rootn=sqrt(n)+10;
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
int factor_finder(int number,int size)
{
	int i,j,answer=1,count,flag=0;
	int k=number;
	j=0;
	for(i=0;i<size;i++)
	{
		count=0;
		flag=0;
		if(A[number] == 1 || prime[i]>40)
			break;
		while(number%prime[i]==0)
		{
			flag=1;
			count++;
			number=number/prime[i];
		}
		if(flag==1)
		{
			factor[k].push_back(make_pair(prime[i],count));

		}

	}
	if(number!=1)
	{
		factor[k].push_back(make_pair(number,1));
	}
}
int main()
{
	int i,size,number_of_prime,cases,n;
	int count[1001];
	number_of_prime=prime_finder(1007);
	for(i=1;i<=1000;i++)
		factor_finder(i,number_of_prime);
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		if(n==0)
		{
			printf("1\n");
			continue;
		}
		if(n==1)
		{
			printf("A+B\n");
			continue;
		}
		int dino=n,num=1;
		if(n==1)
			printf("A");
		else 
			printf("A^%d+",n);
		for(int i=0; i<1001; i++)
			count[i]=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<factor[dino].size(); j++)
				count[factor[dino][j].first]=count[factor[dino][j].first]+factor[dino][j].second;
			for(int j=0; j<factor[num].size(); j++)
				count[factor[num][j].first]=count[factor[num][j].first]-factor[num][j].second;
			for(int j=0; j<number_of_prime; j++)
			{
				if(count[prime[j]]==1)
					printf("%dx",prime[j]);
				else if(count[prime[j]]>1)
					printf("%d^%dx",prime[j],count[prime[j]]);
			}
			if((n-num)==1)
				printf("A");
			else if((n-num)>1)
				printf("A^%d",n-num);
			if(num==1)
				printf("B");
			else if(num>1)
				printf("B^%d",num);
			if(num!=n)
				printf("+");
			num++;
			dino--;

		}
		printf("\n");
	}
	return 0;
}

